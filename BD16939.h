/*******************************************************************************
 *   $FILE:  BD16939.h
 *   Brief:  Header file for the BD16939 SPI triple H-Bridge
 *   CGProjects:  https:/www.cgprojects.it
 *   Support email:  support@cgprojects.it
 ******************************************************************************/

/******************************************************************************
                           Rhom BD16939 Description
*******************************************************************************

[Datasheet](https://fscdn.rohm.com/en/products/databook/datasheet/ic/motor/dc/bd16939aefv-c-e.pdf)

The BD16939 has six individually commandable half-bridges.
It uses an SPI-interface with the following properties:
- frequency up to 4MHz (tested and stable at 1MHz..)
- SPI_MODE1 => CPOL=0 CPHA=1
- MSBFIRST

*******************************************************************************
                           Library Description
*******************************************************************************

This library is intendet to be an abstraction for the BD16939 main features.
Since the six half-bridges are mostly used eighter as high/low-side switches
or as three full-bridges to command dc-motors, this library focuses on those
use cases.

The naming convention for the six half bridges is bound to the use case, so
whenever the library is used to command the single bridges, they will be
called hb1, hb2 ...hb6. If used to command motors, the bridges will be named
motA (hb1+hb2) , motB (hb3+hb4) and motC (hb5 + hb6).

*/

#pragma once

#include <Arduino.h>
#include <SPI.h>
#include "BD16939_registers.h"

#define BD16939_LIB_VERSION (F("0.1.0"))

// STATUS/ERROR CODES
#define OK 1
#define UNDEFINED 0
#define GENERAL_ERROR -1
#define INIT_ERROR -2
#define ERROR_WRITE -3
#define ERROR_READ -4

namespace BD16939
{
  enum halfbridge
  {
    hb1=1,
    hb2,
    hb3,
    hb4,
    hb5,
    hb6,
  };

  enum fullbridge
  {
    motA=1,
    motB,
    motC,
    all,
  };

  enum switchstate
  {
    low = 0,
    high = 1,
    on = 1,
    highZ,
    off,
    offHigh,
    offLow,
    left,
    right,
  };

  class Driver
  {
  private:
    SPIClass *spi;
    SPISettings spisettings;
    uint8_t sspin;
    int8_t state;
    uint16_t reg_in1;
    uint16_t reg_in2;
    uint16_t reg_out1;
    uint16_t reg_out2;
    uint16_t reg_out3;
    uint16_t reg_out4;

    void updateregs(); // Sends the input-registers and recieves all four output-registers
    

  public:
    Driver() : spi(nullptr),
               spisettings(SPISettings(1000000 /*1MHz*/, MSBFIRST, SPI_MODE1)),
               sspin(-1),
               state(UNDEFINED)
    {
    }

    bool begin(SPIClass * /*pSPIClass*/, uint8_t /*SS*/, uint32_t /*SPI-Frequency*/);
    bool begin(SPIClass * /*pSPIClass*/, uint8_t /*SS*/);

    uint16_t send(uint16_t); // ..just for debugging purposes..
    int8_t setbridge(halfbridge /*hb-number(1->6)*/, switchstate);
    int8_t setmotor(fullbridge /*Motor*/, switchstate);
    int8_t getstate();
    void printstate(); // print out driver state..
    void printregs(); // print out all input and output register..
    void reset(); // reset driver
  };
};

/*============================================================================
  END OF FILE
============================================================================*/