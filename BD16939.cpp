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

bool Device::getreg(regbit reg)
{
    switch (reg)
    {
        // ovps,       // Over Voltage Protection Status
    case ovps:
        return (uint8_t)bitRead(reg_out3, OVPS);
        break;
        // uvlos,      // Under-Voltage-Lock-Out Status
    case uvlos:
        return (uint8_t)bitRead(reg_out3, UVLOS);
        break;
        // tsds,       // Thermal Shutdown Status
    case tsds:
        return (uint8_t)bitRead(reg_out2, TSDS);
        break;
        // tws,        // Thermal Warning Status
    case tws:
        return (uint8_t)bitRead(reg_out2, TWS);
        break;
        // hss1,       // Status High Side 1 (OUT1)
    case hss1:
        return (uint8_t)bitRead(reg_out1, HSS1);
        break;
        // hss2,       // Status High Side 2 (OUT2)
    case hss2:
        return (uint8_t)bitRead(reg_out1, HSS2);
        break;
        // hss3,       // Status High Side 3 (OUT3)
    case hss3:
        return (uint8_t)bitRead(reg_out1, HSS3);
        break;
        // hss4,       // Status High Side 4 (OUT4)
    case hss4:
        return (uint8_t)bitRead(reg_out1, HSS4);
        break;
        // hss5,       // Status High Side 5 (OUT5)
    case hss5:
        return (uint8_t)bitRead(reg_out3, HSS5);
        break;
        // hss6,       // Status High Side 6 (OUT6)
    case hss6:
        return (uint8_t)bitRead(reg_out3, HSS6);
        break;
        // lss1,       // Status Low Side 1 (OUT1)
    case lss1:
        return (uint8_t)bitRead(reg_out1, LSS1);
        break;
        // lss2,       // Status Low Side 2 (OUT2)
    case lss2:
        return (uint8_t)bitRead(reg_out1, LSS2);
        break;
        // lss3,       // Status Low Side 3 (OUT3)
    case lss3:
        return (uint8_t)bitRead(reg_out1, LSS3);
        break;
        // lss4,       // Status Low Side 4 (OUT4)
    case lss4:
        return (uint8_t)bitRead(reg_out1, LSS4);
        break;
        // lss5,       // Status Low Side 5 (OUT5)
    case lss5:
        return (uint8_t)bitRead(reg_out3, LSS5);
        break;
        // lss6,       // Status Low Side 6 (OUT6)
    case lss6:
        return (uint8_t)bitRead(reg_out3, LSS6);
        break;
        // ocps,       // Over Current Protection Status
    case ocps:
        return (uint8_t)bitRead(reg_out3, OCPS);
        break;
        // ocph1,      // Over Current Protection High Side Status OUT1
    case ocph1:
        return (uint8_t)bitRead(reg_out2, OCPH1);
        break;
        // ocph2,      // Over Current Protection High Side Status OUT2
    case ocph2:
        return (uint8_t)bitRead(reg_out2, OCPH2);
        break;
        // ocph3,      // Over Current Protection High Side Status OUT3
    case ocph3:
        return (uint8_t)bitRead(reg_out2, OCPH3);
        break;
        // ocph4,      // Over Current Protection High Side Status OUT4
    case ocph4:
        return (uint8_t)bitRead(reg_out2, OCPH4);
        break;
        // ocph5,      // Over Current Protection High Side Status OUT5
    case ocph5:
        return (uint8_t)bitRead(reg_out4, OCPH5);
        break;
        // ocph6,      // Over Current Protection High Side Status OUT6
    case ocph6:
        return (uint8_t)bitRead(reg_out4, OCPH6);
        break;
        // ocpl1,      // Over Current Protection Low Side Status OUT1
    case ocpl1:
        return (uint8_t)bitRead(reg_out2, OCPL1);
        break;
        // ocpl2,      // Over Current Protection Low Side Status OUT2
    case ocpl2:
        return (uint8_t)bitRead(reg_out2, OCPL2);
        break;
        // ocpl3,      // Over Current Protection Low Side Status OUT3
    case ocpl3:
        return (uint8_t)bitRead(reg_out2, OCPL3);
        break;
        // ocpl4,      // Over Current Protection Low Side Status OUT4
    case ocpl4:
        return (uint8_t)bitRead(reg_out2, OCPL4);
        break;
        // ocpl5,      // Over Current Protection Low Side Status OUT5
    case ocpl5:
        return (uint8_t)bitRead(reg_out4, OCPL5);
        break;
        // ocpl6,      // Over Current Protection Low Side Status OUT6
    case ocpl6:
        return (uint8_t)bitRead(reg_out4, OCPL6);
        break;
        // underloads, // Under Loads Status
    case underloads:
        return (uint8_t)bitRead(reg_out3, UNDERLOADS);
        break;
        // underload1, // Under Load Status OUT1
    case underload1:
        return (uint8_t)bitRead(reg_out2, UNDERLOAD1);
        break;
        // underload2, // Under Load Status OUT2
    case underload2:
        return (uint8_t)bitRead(reg_out2, UNDERLOAD2);
        break;
        // underload3, // Under Load Status OUT3
    case underload3:
        return (uint8_t)bitRead(reg_out2, UNDERLOAD3);
        break;
        // underload4, // Under Load Status OUT4
    case underload4:
        return (uint8_t)bitRead(reg_out2, UNDERLOAD4);
        break;
        // underload5, // Under Load Status OUT5
    case underload5:
        return (uint8_t)bitRead(reg_out4, UNDERLOAD5);
        break;
        // underload6, // Under Load Status OUT6
    case underload6:
        return (uint8_t)bitRead(reg_out4, UNDERLOAD6);
        break;
    }
    state = ERROR_READ;
    return false;
}

uint16_t Device::getregint(regname rn)
{
    switch (rn)
    {
    case regin1:
        return reg_in1;
        break;
    case regin2:
        return reg_in2;
        break;
    case regout1:
        return reg_out1;
        break;
    case regout2:
        return reg_out2;
        break;
    case regout3:
        return reg_out3;
        break;
    case regout4:
        return reg_out4;
        break;

    default:
        return 0;
        break;
    }
}

void Device::writeregs()
{
    spi->beginTransaction(spisettings);

    digitalWrite(sspin, LOW);
    spi->transfer16(reg_in1); // Write input-register 1 and read output register A0
    digitalWrite(sspin, HIGH);
    delayMicroseconds(20);
    digitalWrite(sspin, LOW);
    spi->transfer16(reg_in2); // Write input-register 2 and read output register B0
    digitalWrite(sspin, HIGH);
    delayMicroseconds(20);

    spi->endTransaction();
}
void Device::readregs()
{ 
    spi->beginTransaction(spisettings);

    digitalWrite(sspin, LOW);
    reg_out1 = spi->transfer16(OUTPUT_REGA0); // Write nothing and read output register A0
    digitalWrite(sspin, HIGH);
    delayMicroseconds(20);
    digitalWrite(sspin, LOW);
    reg_out2 = spi->transfer16(OUTPUT_REGA1); // Write nothing and read output register A1
    digitalWrite(sspin, HIGH);
    delayMicroseconds(20);
    digitalWrite(sspin, LOW);
    reg_out3 = spi->transfer16(OUTPUT_REGB0); // Write nothing and read output register B0
    digitalWrite(sspin, HIGH);
    delayMicroseconds(20);
    digitalWrite(sspin, LOW);
    reg_out4 = spi->transfer16(OUTPUT_REGB1); // Write nothing and read output register B1
    digitalWrite(sspin, HIGH);
    delayMicroseconds(20);

    spi->endTransaction();
}

void Device::printstate()
{
    serial->print("State: ");
    switch (state)
    {
    case OK:
        serial->println("OK");
        break;
    case UNDEFINED:
        serial->println("UNDEFINED");
        break;
    case GENERAL_ERROR:
        serial->println("GENERAL_ERROR");
        break;
    case INIT_ERROR:
        serial->println("INIT_ERROR");
        break;
    case ERROR_WRITE:
        serial->println("ERROR_WRITE");
        break;
    case ERROR_READ:
        serial->println("ERROR_READ");
        break;
    }
}

void Device::reset()
{
    bitWrite(reg_in1, SSR, 1);
    bitWrite(reg_in2, SSR, 1);
    writeregs();    
    bitWrite(reg_in1, SSR, 0);
    bitWrite(reg_in2, SSR, 0);
    readregs();
}

bool Device::begin(SPIClass *extspi, uint8_t ss)
{
    // ---------- prepare input register A --------------
    reg_in1 = INPUT_REGA; // set base address
    bitWrite(reg_in2, RD_AD, 0);
    bitWrite(reg_in1, SSR, 1);       // Reset all faults
    bitWrite(reg_in1, UNDERLOAD, 1); // Underload detection off
    bitWrite(reg_in1, TSDSTH, 1);    // Thermal Shutdown Self Recovery on
    bitWrite(reg_in1, PSSTH, 1);     // Over-Voltage and Under-Voltage Self Recovery on

    // ---------- prepare input register B --------------
    reg_in2 = INPUT_REGB;
    bitWrite(reg_in2, RD_AD, 1);
    bitWrite(reg_in2, OVPSEL, 0); // set Overvoltage-Threshold to 36V
    bitWrite(reg_in2, SSR, 1);    // Reset all faults

    spi = extspi;
    sspin = ss;
    spi->setHwCs(false);
    pinMode(sspin, OUTPUT);

    writeregs();
    readregs();
    //reset();    

    serial->print("Driver init..");
    if (reg_out1 | reg_out2 | reg_out3 | reg_out4)
    {
        state = OK;
        serial->println("OK!");
        return true;
    }
    else
    {
        state = INIT_ERROR;
        serial->println("ERROR!");
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

    writeregs();
    readregs();

    return state;
}