//
//    FILE: BD16939.cpp
//  AUTHOR: Chris Gaiser
// VERSION: 0.1.0
// PURPOSE: Arduino library for SPI triple H-Bridge Device from Rhom
//     URL:
//
//  HISTORY:
//  0.1.0   2022-06-24  initial version

#include "BD16939.h"

using namespace BD16939;

void Device::printstate()
{
    Serial.print("State: ");
    switch (state)
    {
    case OK:
        Serial.println("OK");
        break;
    case UNDEFINED:
        Serial.println("UNDEFINED");
        break;
    case GENERAL_ERROR:
        Serial.println("GENERAL_ERROR");
        break;
    case INIT_ERROR:
        Serial.println("INIT_ERROR");
        break;
    case ERROR_WRITE:
        Serial.println("ERROR_WRITE");
        break;    
    case ERROR_READ:
        Serial.println("ERROR_READ");
        break;   
    }
}

void Device::updateregs()
{
    spi->beginTransaction(spisettings);

    digitalWrite(sspin, LOW);
    reg_out1 = spi->transfer16(reg_in1); // Write input-register 1 and read output register A0
    digitalWrite(sspin, HIGH);
    delayMicroseconds(10);
    digitalWrite(sspin, LOW);
    reg_out3 = spi->transfer16(reg_in2); // Write input-register 2 and read output register B0
    digitalWrite(sspin, HIGH);
    delayMicroseconds(10);
    digitalWrite(sspin, LOW);
    reg_out2 = spi->transfer16(OUTPUT_REGA1); // Write nothing and read output register A1
    digitalWrite(sspin, HIGH);
    delayMicroseconds(10);
    digitalWrite(sspin, LOW);
    reg_out4 = spi->transfer16(OUTPUT_REGB1); // Write nothing and read output register B1
    digitalWrite(sspin, HIGH);

    spi->endTransaction();

    printregs();
}

void Device::printregs()
{
    Serial.print(" in1: ");
    Serial.print(reg_in1);
    Serial.print(" in2: ");
    Serial.println(reg_in2);
    Serial.print(" out1: ");
    Serial.print(reg_out1);
    Serial.print(" out2: ");
    Serial.print(reg_out2);
    Serial.print(" out3: ");
    Serial.print(reg_out3);
    Serial.print(" out4: ");
    Serial.println(reg_out4);
}

void Device::reset()
{
    bitWrite(reg_in1, SSR, 1);
    bitWrite(reg_in2, SSR, 1);
    updateregs();
    bitWrite(reg_in1, SSR, 0);
    bitWrite(reg_in2, SSR, 0);
}

bool Device::begin(SPIClass *extspi, uint8_t ss)
{
    spi = extspi;
    sspin = ss;
    spi->setHwCs(false);
    pinMode(sspin, OUTPUT);

    // ---------- prepare input register A --------------
    reg_in1 = INPUT_REGA; // set base address
    // bitWrite(reg_in1, SSR, 1);       // Reset all faults
    bitWrite(reg_in1, UNDERLOAD, 1); // Underload detection off
    bitWrite(reg_in1, TSDSTH, 1);    // Thermal Shutdown Self Recovery on
    bitWrite(reg_in1, PSSTH, 1);     // Over-Voltage and Under-Voltage Self Recovery on

    // ---------- prepare input register B --------------
    reg_in2 = INPUT_REGB;
    bitWrite(reg_in2, RD_AD, 1);
    // bitWrite(reg_in2, SSR, 1); // Reset all faults

    reset();

    Serial.print("Driver init..");
    if (reg_out1 | reg_out2 | reg_out3 | reg_out4)
    {
        state = OK;
        Serial.println("OK!");
        return true;
    }
    else
    {
        state = INIT_ERROR;
        Serial.println("ERROR!");
        return false;
    }
}

bool Device::begin(SPIClass *extspi, uint8_t ss, uint32_t freq)
{
    spisettings._clock = freq;
    return begin(extspi, ss);
}

uint16_t Device::send(uint16_t val)
{
    if (spi != nullptr)
    {
        spi->beginTransaction(spisettings);
        digitalWrite(sspin, LOW);
        uint16_t ret = spi->transfer16(val);
        digitalWrite(sspin, HIGH);
        spi->endTransaction();
        return ret;
    }
    return 255;
}

int8_t Device::setmotor(fullbridge motor /*Motor*/, switchstate swstate)
{
    switch (motor)
    {

    case motA:
        switch (swstate)
        {
        case left:
            bitWrite(reg_in1, HSC2, 1);
            bitWrite(reg_in1, LSC2, 0);
            bitWrite(reg_in1, HSC1, 0);
            bitWrite(reg_in1, LSC1, 1);
            break;
        case right:
            bitWrite(reg_in1, HSC2, 0);
            bitWrite(reg_in1, LSC2, 1);
            bitWrite(reg_in1, HSC1, 1);
            bitWrite(reg_in1, LSC1, 0);
            break;
        case highZ:
        case off:
        case offLow:
            bitWrite(reg_in1, HSC2, 0);
            bitWrite(reg_in1, LSC2, 0);
            bitWrite(reg_in1, HSC1, 0);
            bitWrite(reg_in1, LSC1, 0);
            break;
        case offHigh:
            bitWrite(reg_in1, HSC2, 1);
            bitWrite(reg_in1, LSC2, 0);
            bitWrite(reg_in1, HSC1, 1);
            bitWrite(reg_in1, LSC1, 0);
            break;
        }
        break;

    case motB:
        switch (swstate)
        {
        case left:
            bitWrite(reg_in1, HSC4, 1);
            bitWrite(reg_in1, LSC4, 0);
            bitWrite(reg_in1, HSC3, 0);
            bitWrite(reg_in1, LSC3, 1);
            break;
        case right:
            bitWrite(reg_in1, HSC4, 0);
            bitWrite(reg_in1, LSC4, 1);
            bitWrite(reg_in1, HSC3, 1);
            bitWrite(reg_in1, LSC3, 0);
            break;
        case highZ:
        case off:
        case offLow:
            bitWrite(reg_in1, HSC4, 0);
            bitWrite(reg_in1, LSC4, 0);
            bitWrite(reg_in1, HSC3, 0);
            bitWrite(reg_in1, LSC3, 0);
            break;
        case offHigh:
            bitWrite(reg_in1, HSC4, 1);
            bitWrite(reg_in1, LSC4, 0);
            bitWrite(reg_in1, HSC3, 1);
            bitWrite(reg_in1, LSC3, 0);
            break;
        }
        break;

    case motC:
        switch (swstate)
        {
        case left:
            bitWrite(reg_in2, HSC6, 1);
            bitWrite(reg_in2, LSC6, 0);
            bitWrite(reg_in2, HSC5, 0);
            bitWrite(reg_in2, LSC5, 1);
            break;
        case right:
            bitWrite(reg_in2, HSC6, 0);
            bitWrite(reg_in2, LSC6, 1);
            bitWrite(reg_in2, HSC5, 1);
            bitWrite(reg_in2, LSC5, 0);
            break;
        case highZ:
        case off:
        case offLow:
            bitWrite(reg_in2, HSC6, 0);
            bitWrite(reg_in2, LSC6, 0);
            bitWrite(reg_in2, HSC5, 0);
            bitWrite(reg_in2, LSC5, 0);
            break;
        case offHigh:
            bitWrite(reg_in2, HSC6, 1);
            bitWrite(reg_in2, LSC6, 0);
            bitWrite(reg_in2, HSC5, 1);
            bitWrite(reg_in2, LSC5, 0);
            break;
        }
        break;
    }

    updateregs();

    return state;
}