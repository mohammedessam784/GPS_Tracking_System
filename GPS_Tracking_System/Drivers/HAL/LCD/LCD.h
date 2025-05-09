#ifndef LCD
#define LCD

#include "MCAL/GPIO/GPIO.h"
#include "MCAL/SYSTICK/SYSTICK.h"

#define LCD_REGISTER_DATA         PORTB_ID

#define LCD_PIN0_ID               PIN_0
#define LCD_PIN1_ID               PIN_1
#define LCD_PIN2_ID               PIN_2
#define LCD_PIN3_ID               PIN_3
#define LCD_PIN4_ID               PIN_4
#define LCD_PIN5_ID               PIN_5
#define LCD_PIN6_ID               PIN_6
#define LCD_PIN7_ID               PIN_7

#define LCD_REGISTER_CONTROL       PORTA_ID

#define LCD_RS                         PIN_6
#define LCD_EN                         PIN_7

#define LCD_8_BIT_MODE             0
#define LCD_4_BIT_MODE             1

#define CLEAR                      0x01
#define RETURN_HOME                0x02
#define INCREMENT_1                0x06
#define DISPLAY_OFF_CONTROL        0x08
#define DISPLAY_ON_CONTROL         0x0c 
#define GO_TO_1ST_POS              0x80
#define SHIFT_LEFT                 0x18
#define SHIFT_RIGHT                0x1C
#define SET_FUNCTOIN               0x38
#define CG_RAM                     0x40
#define FRIST_LINE_INDEX_0         0x80
#define SECOND_LINE_INDEX_0        0xC0

extern volatile uint32_t LCD_DELAY;
void HAL_LCD_INIT(void);
void HAL_LCD_SEND_COMMAND(uint8_t Copy_u8VALUE);
void HAL_LCD_SEND_DATA(uint8_t Copy_u8VALUE);
void HAL_LCD_SEND_STRING(const char* str);
void HAL_LCD_SET_CURSOR(uint8_t row, uint8_t col);       
void HAL_LCD_WRITE_AT(uint8_t row, uint8_t col, const char* str);
void HAL_LCD_CGRAM_CreateChar( uint8_t loc,  uint8_t *msg);
void HAL_LCD_CGRAM_MY_CHARACTERS(void);

/*


void IntToStr(u8 Copy_u8S [],u32 Copy_u32I);
   
void LCD_voidCGRAM_CreateChar( u8 loc, u8 *msg);
void LCD_voidCGRAM_MY_CHARACTERS();
*/
#endif /* LCD */

