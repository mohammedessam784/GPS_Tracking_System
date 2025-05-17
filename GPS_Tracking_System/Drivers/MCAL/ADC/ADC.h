
#ifndef MCAL_ADC_H
#define MCAL_ADC_H

#include <stdint.h>
#include "MCAL/tm4c123gh6pm.h" 
void ADC0_Init(void);                   
uint16_t ADC0_Read_Channel(uint8_t ch);  

#endif 
