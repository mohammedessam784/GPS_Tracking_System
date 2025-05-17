#include "MCAL/ADC/ADC.h"
void ADC0_Init(void) {
    SYSCTL_RCGCADC_R |= 0x01;     // Enable ADC0 clock
    SYSCTL_RCGCGPIO_R |= 0x10;    // Enable clock for Port E
    while ((SYSCTL_PRGPIO_R & 0x10) == 0);  // ????? ??? ??? ????? Port E

    GPIO_PORTE_AFSEL_R |= 0x08;   // Enable alternate function for PE3 (AIN0)
    GPIO_PORTE_DEN_R &= ~0x08;    // Disable digital on PE3
    GPIO_PORTE_AMSEL_R |= 0x08;   // Enable analog mode on PE3

    ADC0_ACTSS_R &= ~0x0008;      // Disable SS3 during configuration
    ADC0_EMUX_R &= ~0xF000;       // Software trigger
    ADC0_SSMUX3_R = 0;            // Select AIN0 (PE3)
    ADC0_SSCTL3_R = 0x0006;       // Single-ended, end of sequence
    ADC0_ACTSS_R |= 0x0008;       // Enable SS3
}

uint16_t ADC0_Read_Channel(uint8_t ch) {
	  uint16_t result;
    ADC0_SSMUX3_R = ch;               
    ADC0_PSSI_R = 0x0008;             
    while ((ADC0_RIS_R & 0x08) == 0); 
    result = ADC0_SSFIFO3_R & 0xFFF;  
    ADC0_ISC_R = 0x0008;              // Clear completion flag
    return result;
}

