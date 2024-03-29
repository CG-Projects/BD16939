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

class BD16939
{
private:
   enum class Register
   {
      in1,
      in2,
      out1,
      out2,
      out3,
      out4,
   };

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

public:
   enum class regbit
   {
      // ****************************************************************
      // ********************** WRITE-REGISTERS *************************
      // ****************************************************************
      we,        // Write-Enable
      wr_ad,     // REG A/B
      rd_ad,     // REG-PAGE 0/1
      ssr,       // Status Reset Register (This bit will self-clear)
      underload, // Under Loads Register Mode (OUT1 to OUT6)
      tsdsth,    // Thermal-Shut-Down Register Mode
      pssth,     // Over-Voltage-Protection/Under-Voltage-Detection
      hsc1,      // High Side 1 Set (OUT1)
      hsc2,      // High Side 2 Set (OUT2)
      hsc3,      // High Side 3 Set (OUT3)
      hsc4,      // High Side 4 Set (OUT4)
      hsc5,      // High Side 5 Set (OUT5)
      hsc6,      // High Side 6 Set (OUT6)
      lsc1,      // Low Side 1 Set (OUT1)
      lsc2,      // Low Side 2 Set (OUT2)
      lsc3,      // Low Side 3 Set (OUT3)
      lsc4,      // Low Side 4 Set (OUT4)
      lsc5,      // Low Side 5 Set (OUT5)
      lsc6,      // Low Side 6 Set (OUT6)

      // ****************************************************************
      // ********************** READ-REGISTERS **************************
      // ****************************************************************
      ovps,       // Over Voltage Protection Status
      uvlos,      // Under-Voltage-Lock-Out Status
      tsds,       // Thermal Shutdown Status
      tws,        // Thermal Warning Status
      hss1,       // Status High Side 1 (OUT1)
      hss2,       // Status High Side 2 (OUT2)
      hss3,       // Status High Side 3 (OUT3)
      hss4,       // Status High Side 4 (OUT4)
      hss5,       // Status High Side 5 (OUT5)
      hss6,       // Status High Side 6 (OUT6)
      lss1,       // Status Low Side 1 (OUT1)
      lss2,       // Status Low Side 2 (OUT2)
      lss3,       // Status Low Side 3 (OUT3)
      lss4,       // Status Low Side 4 (OUT4)
      lss5,       // Status Low Side 5 (OUT5)
      lss6,       // Status Low Side 6 (OUT6)
      ocps,       // Over Current Protection Status
      ocph1,      // Over Current Protection High Side Status OUT1
      ocph2,      // Over Current Protection High Side Status OUT2
      ocph3,      // Over Current Protection High Side Status OUT3
      ocph4,      // Over Current Protection High Side Status OUT4
      ocph5,      // Over Current Protection High Side Status OUT5
      ocph6,      // Over Current Protection High Side Status OUT6
      ocpl1,      // Over Current Protection Low Side Status OUT1
      ocpl2,      // Over Current Protection Low Side Status OUT2
      ocpl3,      // Over Current Protection Low Side Status OUT3
      ocpl4,      // Over Current Protection Low Side Status OUT4
      ocpl5,      // Over Current Protection Low Side Status OUT5
      ocpl6,      // Over Current Protection Low Side Status OUT6
      underloads, // Under Loads Status
      underload1, // Under Load Status OUT1
      underload2, // Under Load Status OUT2
      underload3, // Under Load Status OUT3
      underload4, // Under Load Status OUT4
      underload5, // Under Load Status OUT5
      underload6, // Under Load Status OUT6
   };
   enum class halfbridge
   {
      hb1 = 1,
      hb2,
      hb3,
      hb4,
      hb5,
      hb6,
   };

   enum class fullbridge
   {
      motA = 1,
      motB,
      motC,
      all,
      none,
   };

   enum class switchstate
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

   BD16939() : spi(nullptr),
               spisettings(SPISettings(1000000 /*1MHz*/, MSBFIRST, SPI_MODE1)),
               sspin(-1),
               state(UNDEFINED){};

   // Sends the input-registers
   void writeregs();
   // Recieves all four output-registers
   void readregs();
   // Sets the SPI-Class for the Device: [param1=SPIClass-Pointer], [param2=SlaveSelectPin],
   // [param3=SPI-frequency(Hz)]
   bool begin(SPIClass * /*pSPIClass*/, uint8_t /*SS*/, uint32_t /*SPI-Frequency*/);

   // Sets the SPI-Class for the Device: [param1=SPIClass-Pointer], [param2=SlaveSelectPin]
   bool begin(SPIClass * /*pSPIClass*/, uint8_t /*SS*/);

   uint16_t send(uint16_t); // ..just for debugging purposes..
   int8_t setbridge(halfbridge /*hb-number(1->6)*/, switchstate);
   int8_t setmotor(fullbridge /*Motor*/, switchstate);
   uint16_t getregint(Register); // get specified Register content as integer value
   bool getreg(regbit);          // get specified Register-bit as bool value
   String getstate();            // print out driver state..
   void printregs();             // print out all input and output register..
   void reset();                 // reset driver
};

/*============================================================================
  END OF FILE
============================================================================*/