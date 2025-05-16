/*#include "APP/system_init.h"
#include "APP/main_app.h"

int main(void) {
	
	// System_Init();
	
 
	
	while(1)
	{ 
		
	  //App_Main_Loop();
		 
	}
			
}

*/

/*
#include <stdint.h>
#include "tm4c123gh6pm.h"  // ??? ????? ????? ?? TM4C123

#define RED_LED_PIN 0x02  // ????? ????? ?????? ??? LED (??? ???? ?????? PF1)
#define yellow_LED_PIN 0x04
void delay(void) {
	uint32_t i=0;
	for(i=0;i<20000000;i++)
			{
				;
		}
}

int main(void) {
    // ????? ???? Port F
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;  // ????? Port F

    // ???????? ??? ??? ????? ??????
    while ((SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5) == 0) {}

    // ????? ??? PF1 ? PF2 ?? Output
    GPIO_PORTF_DIR_R |= RED_LED_PIN;  // ????? ??? PF1 ?? Output
    GPIO_PORTF_DEN_R |= RED_LED_PIN;  // ????? ??? PF1
		GPIO_PORTF_DIR_R |= yellow_LED_PIN;
		GPIO_PORTF_DEN_R |=	yellow_LED_PIN;

    while (1) {
        // ????? ??? LED
        GPIO_PORTF_DATA_R |= RED_LED_PIN;  // ????? ??? LED
			  GPIO_PORTF_DATA_R &= ~yellow_LED_PIN;
        delay();
			
        GPIO_PORTF_DATA_R &= ~RED_LED_PIN;  // ????? ??? LED
			  GPIO_PORTF_DATA_R &= ~yellow_LED_PIN;
        delay();
        // ????? ??? LED
        GPIO_PORTF_DATA_R &= ~RED_LED_PIN;  // ????? ??? LED
			  GPIO_PORTF_DATA_R |= yellow_LED_PIN;
        delay();
    }
}
*/

#include <stdint.h>
#include "tm4c123gh6pm.h"

int main(void)
{
    SYSCTL_RCGCGPIO_R |= (1U << 5);     // Enable clock for Port F
    GPIO_PORTF_DIR_R |= (1U << 1);      // Set PF1 as output
    GPIO_PORTF_DEN_R |= (1U << 1);      // Enable digital function for PF1

    while (1)
    {
        GPIO_PORTF_DATA_R |= (1U << 1); // Turn on LED
       
    }
}
