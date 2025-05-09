#include "MCAL/EEPROM/EEPROM.h"


void MCAL_EEPROM_Init(void) {
    SET_BIT(SYSCTL_RCGCEEPROM_R, 0); // Enable EEPROM clock
    while (EEPROM_EEDONE_R & EEPROM_EEDONE_WORKING); // Wait for ready
}

uint8_t MCAL_EEPROM_Write(uint32_t block, uint8_t offset, uint32_t data) {
    if (block >= EEPROM_TOTAL_BLOCKS || offset >= EEPROM_TOTAL_OFFSETS)
        return EEPROM_INVALID;

    while (EEPROM_EEDONE_R & EEPROM_EEDONE_WORKING); // Wait if busy

    EEPROM_EEBLOCK_R = block;
    EEPROM_EEOFFSET_R = offset;
    EEPROM_EERDWR_R = data;

    while (EEPROM_EEDONE_R & EEPROM_EEDONE_WORKING); // Wait for write complete

    if (EEPROM_EEDONE_R & EEPROM_EEDONE_WRBUSY)
        return EEPROM_BUSY;

    if (EEPROM_EEDONE_R & (EEPROM_EEDONE_NOPERM | EEPROM_EEDONE_FAIL))
        return EEPROM_ERROR;

    return EEPROM_OK;
}

uint8_t MCAL_EEPROM_Read(uint32_t block, uint8_t offset, uint32_t* data) {
    if (block >= EEPROM_TOTAL_BLOCKS || offset >= EEPROM_TOTAL_OFFSETS || data == 0)
        return EEPROM_INVALID;

    while (EEPROM_EEDONE_R & EEPROM_EEDONE_WORKING); // Wait if busy

    EEPROM_EEBLOCK_R = block;
    EEPROM_EEOFFSET_R = offset;
    *data = EEPROM_EERDWR_R;

    if (EEPROM_EEDONE_R & (EEPROM_EEDONE_NOPERM | EEPROM_EEDONE_FAIL))
        return EEPROM_ERROR;

    return EEPROM_OK;
}
