//
//    FILE: BD16939.cpp
//  AUTHOR: Chris Gaiser
// VERSION: 0.1.0
// PURPOSE: Arduino library for SPI triple H-Bridge driver from Rhom
//     URL:
//
//  HISTORY:
//  0.1.0   2022-06-24  initial version

#include "BD16939.h"

using namespace BD16939;

bool Driver::begin(SPIClass *extspi, uint8_t ss)
{
    spi = extspi;
    sspin = ss;
    spi->setHwCs(false);
    pinMode(sspin, OUTPUT);
    spi->beginTransaction(spisettings);
    digitalWrite(sspin, LOW);
    bool result = spi->transfer16(0);
    digitalWrite(sspin, HIGH);
    spi->endTransaction();

    if (result)
        state = OK;
    else
        state = INIT_ERROR;        
    return result;
}

bool Driver::begin(SPIClass *extspi, uint8_t ss, uint32_t freq)
{
    spisettings._clock = freq;
    return begin(extspi, ss);
}

uint16_t Driver::send(uint16_t val)
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
