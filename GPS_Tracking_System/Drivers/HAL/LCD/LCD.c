#include "HAL/LCD/LCD.h"

 volatile uint32_t LCD_DELAY=0;

void HAL_LCD_INIT(void)
{
	MCAL_GPIO_INIT(LCD_REGISTER_DATA);
	
	MCAL_GPIO_INIT(LCD_REGISTER_CONTROL);
	
	MCAL_GPIO_DIGITAL_INIT(LCD_REGISTER_DATA,LCD_PIN0_ID );
	MCAL_GPIO_DIGITAL_INIT(LCD_REGISTER_DATA,LCD_PIN1_ID );
	MCAL_GPIO_DIGITAL_INIT(LCD_REGISTER_DATA,LCD_PIN2_ID );
	MCAL_GPIO_DIGITAL_INIT(LCD_REGISTER_DATA,LCD_PIN3_ID );
	MCAL_GPIO_DIGITAL_INIT(LCD_REGISTER_DATA,LCD_PIN4_ID );
	MCAL_GPIO_DIGITAL_INIT(LCD_REGISTER_DATA,LCD_PIN5_ID );
	MCAL_GPIO_DIGITAL_INIT(LCD_REGISTER_DATA,LCD_PIN6_ID );
	MCAL_GPIO_DIGITAL_INIT(LCD_REGISTER_DATA,LCD_PIN7_ID );
	
	MCAL_GPIO_DIGITAL_INIT(LCD_REGISTER_CONTROL,LCD_RS );
	MCAL_GPIO_DIGITAL_INIT(LCD_REGISTER_CONTROL,LCD_EN );
	
	 MCAL_GPIO_DIGITAL_PIN_MODE (LCD_REGISTER_DATA ,  LCD_PIN0_ID,Output ,Floating);
	 MCAL_GPIO_DIGITAL_PIN_MODE (LCD_REGISTER_DATA ,  LCD_PIN1_ID,Output ,Floating);
	 MCAL_GPIO_DIGITAL_PIN_MODE (LCD_REGISTER_DATA ,  LCD_PIN2_ID, Output ,Floating);
	 MCAL_GPIO_DIGITAL_PIN_MODE (LCD_REGISTER_DATA ,  LCD_PIN3_ID,Output ,Floating);
	 MCAL_GPIO_DIGITAL_PIN_MODE (LCD_REGISTER_DATA ,  LCD_PIN4_ID, Output ,Floating);
	 MCAL_GPIO_DIGITAL_PIN_MODE (LCD_REGISTER_DATA ,  LCD_PIN5_ID,Output ,Floating);
	 MCAL_GPIO_DIGITAL_PIN_MODE (LCD_REGISTER_DATA ,  LCD_PIN6_ID,Output ,Floating);
	 MCAL_GPIO_DIGITAL_PIN_MODE (LCD_REGISTER_DATA ,  LCD_PIN7_ID,Output ,Floating);
	 
	 MCAL_GPIO_DIGITAL_PIN_MODE (LCD_REGISTER_CONTROL  , LCD_RS, Output,Floating);
	 MCAL_GPIO_DIGITAL_PIN_MODE (LCD_REGISTER_CONTROL  , LCD_EN, Output,Floating );
	 //////init
//	 delay(100);
	// MCAL_SYSTICK_Delay_ms(100);
	 LCD_DELAY=0;
	 while(LCD_DELAY<100);
	 HAL_LCD_SEND_COMMAND(SET_FUNCTOIN);
	 
	 HAL_LCD_SEND_COMMAND(SET_FUNCTOIN);
	 
	 HAL_LCD_SEND_COMMAND(SET_FUNCTOIN);
	 
	 HAL_LCD_SEND_COMMAND(DISPLAY_OFF_CONTROL);
	 HAL_LCD_SEND_COMMAND(CLEAR);
	 HAL_LCD_SEND_COMMAND(INCREMENT_1);
	// delay(100);
//	MCAL_SYSTICK_Delay_ms(100);
   LCD_DELAY=0;
	 while(LCD_DELAY<100);
	 HAL_LCD_SEND_COMMAND(DISPLAY_ON_CONTROL);
	

}


void HAL_LCD_SEND_COMMAND(uint8_t Copy_u8VALUE)
{
	
	// Send the command to the data port in 8-bit mode
	MCAL_GPIO_WRITE_PORT(LCD_REGISTER_DATA, Copy_u8VALUE);

	// Set RS to 0 to indicate a command, not data
	MCAL_GPIO_WRITE_PIN(LCD_REGISTER_CONTROL, LCD_RS, low );

	// Trigger the enable pin to latch the data/command
	MCAL_GPIO_WRITE_PIN(LCD_REGISTER_CONTROL, LCD_EN, high);
	// delay(2);
	// MCAL_SYSTICK_Delay_ms(2);
	 LCD_DELAY=0;
	 while(LCD_DELAY<2);
	//_delay_ms(2); // Wait for the LCD to process the command
	MCAL_GPIO_WRITE_PIN(LCD_REGISTER_CONTROL, LCD_EN, low);

	
}
void HAL_LCD_SEND_DATA(uint8_t Copy_u8VALUE)
{
	
	MCAL_GPIO_WRITE_PORT (LCD_REGISTER_DATA ,  Copy_u8VALUE);
	MCAL_GPIO_WRITE_PIN (LCD_REGISTER_CONTROL  , LCD_RS , high);

	MCAL_GPIO_WRITE_PIN(LCD_REGISTER_CONTROL  , LCD_EN , high);
  	// delay(2);
	// MCAL_SYSTICK_Delay_ms(2);
	 LCD_DELAY=0;
	 while(LCD_DELAY<2);
	MCAL_GPIO_WRITE_PIN(LCD_REGISTER_CONTROL  , LCD_EN , low);
	
}

void HAL_LCD_SEND_STRING(const char* str)
{
    while(*str != '\0')  // loop until the null terminator
    {
        HAL_LCD_SEND_DATA((uint8_t)*str);
        str++;
    }
}

void HAL_LCD_SET_CURSOR(uint8_t row, uint8_t col)
{
    uint8_t address;

    switch(row)
    {
        case 0:
            address = 0x00 + col;
            break;
        case 1:
            address = 0x40 + col;
            break;
        default:
            address = 0x00 + col;
            break;
    }

    HAL_LCD_SEND_COMMAND(0x80 | address);  // 0x80 is the base command for setting DDRAM address
}

void HAL_LCD_WRITE_AT(uint8_t row, uint8_t col, const char* str)
{
    HAL_LCD_SET_CURSOR(row, col);
    HAL_LCD_SEND_STRING(str);
}
void HAL_LCD_CGRAM_CreateChar( uint8_t loc,  uint8_t *msg)
{
	  uint8_t  i = 0;
    if (loc < 8)
    {
        HAL_LCD_SEND_COMMAND(0x40 + (loc * 8));  // Set CGRAM address for character location

        for (i = 0; i < 8; i++)
        {
            HAL_LCD_SEND_DATA(msg[i]);  // Write 8 bytes to define the character
        }
    }
}

void HAL_LCD_CGRAM_MY_CHARACTERS(void)
{
    uint8_t Character1[8] = {
  0x0E,
  0x0A,
  0x0A,
  0x1F,
  0x11,
  0x15,
  0x11,
  0x1F
};
    uint8_t Character2[8] = {
  0x00,
  0x01,
  0x01,
  0x01,
  0x1F,
  0x00,
  0x04,0x00};
    uint8_t Character3[8] = {
  0x15,
  0x01,
  0x1D,
  0x15,
  0x1D,
  0x00,
  0x00,0x00};
    uint8_t Character4[8] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x13,
  0x12,
  0x1E,0x00};
    uint8_t Character5[8] = {
  0x10,
  0x10,
  0x17,
  0x14,
  0x1F,
  0x00,
  0x00,0x00};
    uint8_t Character6[8] = {
  0x00,
  0x0F,
  0x09,
  0x09,
  0x1F,
  0x00,
  0x00,0x00};
    uint8_t Character7[8] = {
  0x05,
  0x00,
  0x01,
  0x01,
  0x1F,
  0x00,
  0x00,0x00};
    uint8_t Character8[8] = {
  0x00,
  0x00,
  0x00,
  0x04,
  0x07,
  0x04,
  0x08,0x10};

    HAL_LCD_CGRAM_CreateChar(0, Character1);   // Create custom character at position 0
    HAL_LCD_CGRAM_CreateChar(1, Character2);   // Create custom character at position 1
    HAL_LCD_CGRAM_CreateChar(2, Character3);   // Create custom character at position 2
    HAL_LCD_CGRAM_CreateChar(3, Character4);   // Create custom character at position 3
    HAL_LCD_CGRAM_CreateChar(4, Character5);   // Create custom character at position 4
    HAL_LCD_CGRAM_CreateChar(5, Character6);   // Create custom character at position 5
    HAL_LCD_CGRAM_CreateChar(6, Character7);   // Create custom character at position 6
    HAL_LCD_CGRAM_CreateChar(7, Character8);   // Create custom character at position 7
}

/*


void IntToStr(u8 Copy_u8S [],u32 Copy_u32I)
{
	u8 x=0;
	do
	{
		Copy_u8S[x]=Copy_u32I%10+48;
		Copy_u32I/=10;
		x++;
	}while(Copy_u32I);
	for(u8 j=0;j<x/2;j++)   //swp
	{
		u8 temp= Copy_u8S[x-1-j];
		Copy_u8S[x-1-j]=Copy_u8S[j];
		Copy_u8S[j]=temp;
	}
}
void LCD_voidCGRAM_CreateChar( u8 loc, u8 *msg)
{
   
    if(loc<8)
    {
     LCD_voidSendCommand (0x40 + (loc*8));  // Command 0x40 and onwards forces 
                                       //the device to point CGRAM address 
	 
       for( unsigned char i=0;i<8;i++)
	   {  // Write 8 byte for generation of 1 character 
           LCD_voidSendData(msg[i]);
	   }
		         
    }   
}


void LCD_voidCGRAM_MY_CHARACTERS()
{
	
	u8 Character1[8] = { 0x00,0x00,0x07,0x08,0x08,0x1F,0x00,0x00}; // Custom char set for alphanumeric LCD Module 
	u8 Character2[8] = { 0x00,0x00,	0x00,	0x06,0x09,	0x1F,0x00,0x00};
	u8 Character3[8] = {  0x00,0x08,0x08,0x08,0x09,0x0F,0x00,0x00};
	u8 Character4[8] = { 0x00,0x00,0x07,0x05,0x0F,0x08,0x08,0x08	};
	u8 Character5[8] = { 0x01, 0x03, 0x05, 0x09, 0x09, 0x0B, 0x1B, 0x18 };
	u8 Character6[8] = { 0x0A, 0x0A, 0x1F, 0x11, 0x11, 0x0E, 0x04, 0x04 };
	u8 Character7[8] = { 0x00, 0x00, 0x0A, 0x00, 0x04, 0x11, 0x0E, 0x00 };
	u8 Character8[8] = { 0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00 };

	LCD_voidCGRAM_CreateChar(0, Character1);   // ?     Build Character1 at position 0 
	LCD_voidCGRAM_CreateChar(1, Character2);  //  ?     Build Character2 at position 1 
	LCD_voidCGRAM_CreateChar(2, Character3);  //  ?     Build Character3 at position 2 
	LCD_voidCGRAM_CreateChar(3, Character4);  // ?     Build Character4 at position 3 
	LCD_voidCGRAM_CreateChar(4, Character5);  // /      Build Character5 at position 4 
	LCD_voidCGRAM_CreateChar(5, Character6);  //       Build Character6 at position 5 
	LCD_voidCGRAM_CreateChar(6, Character7);  // /      Build Character6 at position 6 
	LCD_voidCGRAM_CreateChar(7, Character8);  //      Build Character6 at position 7 
}


*/

