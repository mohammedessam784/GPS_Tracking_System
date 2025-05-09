
#ifndef MCAL_EEPROM_H_
#define MCAL_EEPROM_H_

#include <stdint.h>


#include "MCAL/tm4c123gh6pm.h" 
#include "LIB/BIT_MATHS.h"
#include "LIB/STD_TYPES.h"
// Total EEPROM blocks and offsets
#define EEPROM_TOTAL_BLOCKS    32
#define EEPROM_TOTAL_OFFSETS   16

// Status Codes
#define EEPROM_OK        0
#define EEPROM_BUSY      1
#define EEPROM_ERROR     2
#define EEPROM_INVALID   3



// EEPROM Error Bit Definitions (if missing from CMSIS header)
#ifndef EEPROM_EEDONE_FAIL
#define EEPROM_EEDONE_FAIL   (1U << 1)
#endif

#ifndef EEPROM_EEDONE_NOPERM
#define EEPROM_EEDONE_NOPERM (1U << 2)
#endif

#ifndef EEPROM_EEDONE_WRBUSY
#define EEPROM_EEDONE_WRBUSY (1U << 3)
#endif

#ifndef EEPROM_EEDONE_WORKING
#define EEPROM_EEDONE_WORKING (1U << 0)
#endif


// Function Prototypes
void MCAL_EEPROM_Init(void);
uint8_t MCAL_EEPROM_Write(uint32_t block, uint8_t offset, uint32_t data);
uint8_t MCAL_EEPROM_Read(uint32_t block, uint8_t offset, uint32_t* data);

#endif /* MCAL_EEPROM_H_ */

