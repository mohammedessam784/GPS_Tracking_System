#include "APP/system_init.h"

void System_Init(void)
{
   MCAL_SYSTICK_Init(16000,SYSTICK_INT_ENABLE);
	 MCAL_SYSTICK_SetCallback(MY_Systick_Function);
	
	MCAL_UART_INIT(UART0_ID, 9600);
  MCAL_UART_INIT(UART5_ID, 9600);
  MCAL_UART_Enable_RX_Interrupt(UART5_ID);
	MCAL_EEPROM_Init();
	 ADC0_Init();
	__enable_irq();
	
	 
	
    HAL_LED_INIT( PORTF_ID,PIN_1 );
	  HAL_LED_INIT( PORTF_ID,PIN_2 );
	  HAL_LED_INIT( PORTF_ID,PIN_3 );
	HAL_BUTTON_INIT(PORTF_ID,PIN_0, Pull_up);
	HAL_BUTTON_INIT(PORTF_ID,PIN_4, Pull_up);
	
	HAL_LCD_INIT(); 
 	HAL_LCD_CGRAM_MY_CHARACTERS();
            

}


