//
//    FILE: BD16939.cpp
//  AUTHOR: Chris Gaiser
// VERSION: 0.1.0
// PURPOSE: Arduino library for SPI triple H-Bridge BD16939 from Rhom
//     URL:
//
//  HISTORY:
//  0.1.0   2022-06-24  initial version

#include "BD16939.h"

bool BD16939::getreg(regbit reg)
{
    switch (reg)
    {
        // ovps,       // Over Voltage Protection Status
    case regbit::ovps:
        return (uint8_t)bitRead(reg_out3, OVPS);
        break;
        // uvlos,      // Under-Voltage-Lock-Out Status
    case regbit::uvlos:
        return (uint8_t)bitRead(reg_out3, UVLOS);
        break;
        // tsds,       // Thermal Shutdown Status
    case regbit::tsds:
        return (uint8_t)bitRead(reg_out2, TSDS);
        break;
        // tws,        // Thermal Warning Status
    case regbit::tws:
        return (uint8_t)bitRead(reg_out2, TWS);
        break;
        // hss1,       // Status High Side 1 (OUT1)
    case regbit::hss1:
        return (uint8_t)bitRead(reg_out1, HSS1);
        break;
        // hss2,       // Status High Side 2 (OUT2)
    case regbit::hss2:
        return (uint8_t)bitRead(reg_out1, HSS2);
        break;
        // hss3,       // Status High Side 3 (OUT3)
    case regbit::hss3:
        return (uint8_t)bitRead(reg_out1, HSS3);
        break;
        // hss4,       // Status High Side 4 (OUT4)
    case regbit::hss4:
        return (uint8_t)bitRead(reg_out1, HSS4);
        break;
        // hss5,       // Status High Side 5 (OUT5)
    case regbit::hss5:
        return (uint8_t)bitRead(reg_out3, HSS5);
        break;
        // hss6,       // Status High Side 6 (OUT6)
    case regbit::hss6:
        return (uint8_t)bitRead(reg_out3, HSS6);
        break;
        // lss1,       // Status Low Side 1 (OUT1)
    case regbit::lss1:
        return (uint8_t)bitRead(reg_out1, LSS1);
        break;
        // lss2,       // Status Low Side 2 (OUT2)
    case regbit::lss2:
        return (uint8_t)bitRead(reg_out1, LSS2);
        break;
        // lss3,       // Status Low Side 3 (OUT3)
    case regbit::lss3:
        return (uint8_t)bitRead(reg_out1, LSS3);
        break;
        // lss4,       // Status Low Side 4 (OUT4)
    case regbit::lss4:
        return (uint8_t)bitRead(reg_out1, LSS4);
        break;
        // lss5,       // Status Low Side 5 (OUT5)
    case regbit::lss5:
        return (uint8_t)bitRead(reg_out3, LSS5);
        break;
        // lss6,       // Status Low Side 6 (OUT6)
    case regbit::lss6:
        return (uint8_t)bitRead(reg_out3, LSS6);
        break;
        // ocps,       // Over Current Protection Status
    case regbit::ocps:
        return (uint8_t)bitRead(reg_out3, OCPS);
        break;
        // ocph1,      // Over Current Protection High Side Status OUT1
    case regbit::ocph1:
        return (uint8_t)bitRead(reg_out2, OCPH1);
        break;
        // ocph2,      // Over Current Protection High Side Status OUT2
    case regbit::ocph2:
        return (uint8_t)bitRead(reg_out2, OCPH2);
        break;
        // ocph3,      // Over Current Protection High Side Status OUT3
    case regbit::ocph3:
        return (uint8_t)bitRead(reg_out2, OCPH3);
        break;
        // ocph4,      // Over Current Protection High Side Status OUT4
    case regbit::ocph4:
        return (uint8_t)bitRead(reg_out2, OCPH4);
        break;
        // ocph5,      // Over Current Protection High Side Status OUT5
    case regbit::ocph5:
        return (uint8_t)bitRead(reg_out4, OCPH5);
        break;
        // ocph6,      // Over Current Protection High Side Status OUT6
    case regbit::ocph6:
        return (uint8_t)bitRead(reg_out4, OCPH6);
        break;
        // ocpl1,      // Over Current Protection Low Side Status OUT1
    case regbit::ocpl1:
        return (uint8_t)bitRead(reg_out2, OCPL1);
        break;
        // ocpl2,      // Over Current Protection Low Side Status OUT2
    case regbit::ocpl2:
        return (uint8_t)bitRead(reg_out2, OCPL2);
        break;
        // ocpl3,      // Over Current Protection Low Side Status OUT3
    case regbit::ocpl3:
        return (uint8_t)bitRead(reg_out2, OCPL3);
        break;
        // ocpl4,      // Over Current Protection Low Side Status OUT4
    case regbit::ocpl4:
        return (uint8_t)bitRead(reg_out2, OCPL4);
        break;
        // ocpl5,      // Over Current Protection Low Side Status OUT5
    case regbit::ocpl5:
        return (uint8_t)bitRead(reg_out4, OCPL5);
        break;
        // ocpl6,      // Over Current Protection Low Side Status OUT6
    case regbit::ocpl6:
        return (uint8_t)bitRead(reg_out4, OCPL6);
        break;
        // underloads, // Under Loads Status
    case regbit::underloads:
        return (uint8_t)bitRead(reg_out3, UNDERLOADS);
        break;
        // underload1, // Under Load Status OUT1
    case regbit::underload1:
        return (uint8_t)bitRead(reg_out2, UNDERLOAD1);
        break;
        // underload2, // Under Load Status OUT2
    case regbit::underload2:
        return (uint8_t)bitRead(reg_out2, UNDERLOAD2);
        break;
        // underload3, // Under Load Status OUT3
    case regbit::underload3:
        return (uint8_t)bitRead(reg_out2, UNDERLOAD3);
        break;
        // underload4, // Under Load Status OUT4
    case regbit::underload4:
        return (uint8_t)bitRead(reg_out2, UNDERLOAD4);
        break;
        // underload5, // Under Load Status OUT5
    case regbit::underload5:
        return (uint8_t)bitRead(reg_out4, UNDERLOAD5);
        break;
        // underload6, // Under Load Status OUT6
    case regbit::underload6:
        return (uint8_t)bitRead(reg_out4, UNDERLOAD6);
        break;
    }
    state = ERROR_READ;
    return false;
}

uint16_t BD16939::getregint(Register rn)
{
    switch (rn)
    {
    case Register::in1:
        return reg_in1;
        break;
    case Register::in2:
        return reg_in2;
        break;
    case Register::out1:
        return reg_out1;
        break;
    case Register::out2:
        return reg_out2;
        break;
    case Register::out3:
        return reg_out3;
        break;
    case Register::out4:
        return reg_out4;
        break;

    default:
        return 0;
        break;
    }
}

void BD16939::writeregs()
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
void BD16939::readregs()
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

String BD16939::getstate()
{
    String ret = "State: ";

    switch (state)
    {
    case OK:
        ret +="OK";
        break;
    case UNDEFINED:
        ret +="UNDEFINED";
        break;
    case GENERAL_ERROR:
        ret +="GENERAL_ERROR";
        break;
    case INIT_ERROR:
        ret +="INIT_ERROR";
        break;
    case ERROR_WRITE:
        ret +="ERROR_WRITE";
        break;
    case ERROR_READ:
        ret +="ERROR_READ";
        break;
    }
    return ret;
}
void BD16939::reset()
{
    bitWrite(reg_in1, SSR, 1);
    bitWrite(reg_in2, SSR, 1);
    writeregs();    
    bitWrite(reg_in1, SSR, 0);
    bitWrite(reg_in2, SSR, 0);
    readregs();
}

bool BD16939::begin(SPIClass *extspi, uint8_t ss)
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

    // serial->print("Driver init..");
    if (reg_out1 | reg_out2 | reg_out3 | reg_out4)
    {
        state = OK;
        // serial->println("OK!");
        return true;
    }
    else
    {
        state = INIT_ERROR;
        // serial->println("ERROR!");
        return false;
    }
}

bool BD16939::begin(SPIClass *extspi, uint8_t ss, uint32_t freq)
{
    spisettings._clock = freq;
    return begin(extspi, ss);
}

uint16_t BD16939::send(uint16_t val)
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

int8_t BD16939::setmotor(fullbridge motor /*Motor*/, switchstate swstate)
{
    switch (motor)
    {

    case fullbridge::motA:
        switch (swstate)
        {
        case switchstate::left:
            bitWrite(reg_in1, HSC2, 1);
            bitWrite(reg_in1, LSC2, 0);
            bitWrite(reg_in1, HSC1, 0);
            bitWrite(reg_in1, LSC1, 1);
            break;
        case switchstate::right:
            bitWrite(reg_in1, HSC2, 0);
            bitWrite(reg_in1, LSC2, 1);
            bitWrite(reg_in1, HSC1, 1);
            bitWrite(reg_in1, LSC1, 0);
            break;
        case switchstate::highZ:
        case switchstate::off:
        case switchstate::offLow:
            bitWrite(reg_in1, HSC2, 0);
            bitWrite(reg_in1, LSC2, 0);
            bitWrite(reg_in1, HSC1, 0);
            bitWrite(reg_in1, LSC1, 0);
            break;
        case switchstate::offHigh:
            bitWrite(reg_in1, HSC2, 1);
            bitWrite(reg_in1, LSC2, 0);
            bitWrite(reg_in1, HSC1, 1);
            bitWrite(reg_in1, LSC1, 0);
            break;
        }
        break;

    case fullbridge::motB:
        switch (swstate)
        {
        case switchstate::left:
            bitWrite(reg_in1, HSC4, 1);
            bitWrite(reg_in1, LSC4, 0);
            bitWrite(reg_in1, HSC3, 0);
            bitWrite(reg_in1, LSC3, 1);
            break;
        case switchstate::right:
            bitWrite(reg_in1, HSC4, 0);
            bitWrite(reg_in1, LSC4, 1);
            bitWrite(reg_in1, HSC3, 1);
            bitWrite(reg_in1, LSC3, 0);
            break;
        case switchstate::highZ:
        case switchstate::off:
        case switchstate::offLow:
            bitWrite(reg_in1, HSC4, 0);
            bitWrite(reg_in1, LSC4, 0);
            bitWrite(reg_in1, HSC3, 0);
            bitWrite(reg_in1, LSC3, 0);
            break;
        case switchstate::offHigh:
            bitWrite(reg_in1, HSC4, 1);
            bitWrite(reg_in1, LSC4, 0);
            bitWrite(reg_in1, HSC3, 1);
            bitWrite(reg_in1, LSC3, 0);
            break;
        }
        break;

    case fullbridge::motC:
        switch (swstate)
        {
        case switchstate::left:
            bitWrite(reg_in2, HSC6, 1);
            bitWrite(reg_in2, LSC6, 0);
            bitWrite(reg_in2, HSC5, 0);
            bitWrite(reg_in2, LSC5, 1);
            break;
        case switchstate::right:
            bitWrite(reg_in2, HSC6, 0);
            bitWrite(reg_in2, LSC6, 1);
            bitWrite(reg_in2, HSC5, 1);
            bitWrite(reg_in2, LSC5, 0);
            break;
        case switchstate::highZ:
        case switchstate::off:
        case switchstate::offLow:
            bitWrite(reg_in2, HSC6, 0);
            bitWrite(reg_in2, LSC6, 0);
            bitWrite(reg_in2, HSC5, 0);
            bitWrite(reg_in2, LSC5, 0);
            break;
        case switchstate::offHigh:
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