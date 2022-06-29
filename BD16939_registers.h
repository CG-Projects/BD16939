/*******************************************************************************
 *   $FILE:  BD16939_registers.h
 *   Brief:  contains register configuration for BD16939
 *   CGProjects:  https:/www.cgprojects.it
 *   Support email:  support@cgprojects.it
 ******************************************************************************/

/******************************************************************************
                             Register Description
*******************************************************************************

The Driver has two input-registers (in this Document called A and B) and four 
output-registers. Since in SPI-Mode every Write-Register-Operation simultaniously 
returns a Value, in this case the return value can be chosen to be one of two available
"pages" (in this Document numbered as 0 and 1). By selecting the Read-Address,
every write or read on address A or B will return only one of the two possible pages.
Therefore, to retrieve all available status information, at least four SPI-transfers
are necessary.

Best Combination could eventually be:
1) Write REGA -> Read Page A0
2) Read Page A1
3) Write REGB -> Read Page B
4) Read Page B1
The sequence is not critical though..

*/
#pragma once

// Input-Registers -> Value means base-address without settings
#define INPUT_REGA 0x8000
#define INPUT_REGB 0xC000
#define OUTPUT_REGA0 0x0000
#define OUTPUT_REGA1 0x2000
#define OUTPUT_REGB0 0x4000
#define OUTPUT_REGB1 0x6000
// **** Write-Bits A & B ****
// (Value means Bit-positions in 16Bit MSB-first)
#define WRITE_ENABLE 15
#define WRITE_ADDRESS 14 // REG A/B
#define READ_ADDRESS 13  // REG-PAGE 0/1
// **** Write-Reg.A ****
#define STATUS_RESET 12 // Status Reset Register (This bit will self-clear)
#define HIGHSIDE4 11
#define LOWSIDE4 10
#define HIGHSIDE3 9
#define LOWSIDE3 8
#define HIGHSIDE2 7
#define LOWSIDE2 6
#define HIGHSIDE1 5
#define LOWSIDE1 4
#define UNDERLOAD 3 // Under Loads Register Mode (OUT1 to OUT6)
#define TSDSTH 2    // Thermal-Shut-DOwn Register Mode
#define PSSTH 1
// **** Write-Reg.B ****
#define HIGHSIDE6 7
#define LOWSIDE6 6
#define HIGHSIDE5 5
#define LOWSIDE5 4
#define OVPSEL 3 // Over-Voltage-Proteciton threshold SElect
// **** Read-Reg.A0 ****
#define TSDS 14      // Thermal Shutdown Status
#define TWS 13       // Thermal Warning Status
#define HSS4 11      // Status High Side 4 (OUT4)
#define LSS4 10      // Status Low Side 4 (OUT4)
#define HSS3 9       // Status High Side 3 (OUT3)
#define LSS3 8       // Status Low Side 3 (OUT3)
#define HSS2 7       // Status High Side 2 (OUT2)
#define LSS2 6       // Status Low Side 2 (OUT2)
#define HSS1 5       // Status High Side 1 (OUT1)
#define LSS1 4       // Status Low Side 1 (OUT1)
#define OCPS 3       // Over Current Protection Status
#define UNDERLOADS 2 // Under Loads Status
#define OVPS 1       // Over Voltage Protection Status
#define UVLOS 0      // Under-Voltage-Lock-Out Status
// **** Read-Reg.A1 ****
#define UNDERLOAD4 11 // Under Load Status OUT4
#define UNDERLOAD3 10 // Under Load Status OUT3
#define UNDERLOAD2 9 // Under Load Status OUT2
#define UNDERLOAD1 8 // Under Load Status OUT1
#define OCPH4 7 // Over Current Protection High Side Status OUT4
#define OCPL4 6 // Over Current Protection Low Side Status OUT4
#define OCPH3 5 // Over Current Protection High Side Status OUT3
#define OCPL3 4 // Over Current Protection Low Side Status OUT3
#define OCPH2 3 // Over Current Protection High Side Status OUT2
#define OCPL2 2 // Over Current Protection Low Side Status OUT2
#define OCPH1 1 // Over Current Protection High Side Status OUT1
#define OCPL1 0 // Over Current Protection Low Side Status OUT1
// **** Read-Reg.B0 ****
#define HSS6 7       // Status High Side 6 (OUT6)
#define LSS6 6       // Status Low Side 6 (OUT6)
#define HSS5 5       // Status High Side 5 (OUT5)
#define LSS5 4       // Status Low Side 5 (OUT5)
// **** Read-Reg.B1 ****
#define UNDERLOAD6 9 // Under Load Status OUT6
#define UNDERLOAD5 8 // Under Load Status OUT5
#define OCPH6 3 // Over Current Protection High Side Status OUT6
#define OCPL6 2 // Over Current Protection Low Side Status OUT6
#define OCPH5 1 // Over Current Protection High Side Status OUT5
#define OCPL5 0 // Over Current Protection Low Side Status OUT5

/*============================================================================
  END OF FILE
============================================================================*/