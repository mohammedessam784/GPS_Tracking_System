#ifndef GPIO_HEADER
#define GPIO_HEADER

// libraries needed
#include "LIB/BIT_MATHS.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/tm4c123gh6pm.h" 
////////////////////////////////

//general defines
#define SYSTEM_CLOCK  16000000


#define PIN_0							0
#define PIN_1							1
#define PIN_2							2
#define PIN_3							3
#define PIN_4							4
#define PIN_5							5
#define PIN_6							6
#define PIN_7							7

////////////////////////////////

// for initing GPIO
#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3
#define PORTE_ID 4
#define PORTF_ID 5 

//for init a pin

#define Pull_down 0
#define Pull_up   1
#define Floating  2


#define Input    0
#define Output   1


#define Clear    0
#define Set      1

#define low       0
#define high      1

/////////////////////////////////////////////////////////////////////////////////
//API's
void MCAL_GPIO_INIT(uint8_t GPIO_SEL); // just give clock to the GPIO
void MCAL_GPIO_DIGITAL_INIT(uint8_t GPIO_SEL,uint8_t pin);// enable one pin as an input digital
void MCAL_GPIO_DIGITAL_PIN_MODE(uint8_t Port,uint8_t pin, uint8_t Mode, uint8_t Polarity);

void MCAL_GPIO_WRITE_PIN(uint8_t GPIO_SEL, uint8_t pin, uint8_t data); // Write a value on a pin
void MCAL_GPIO_WRITE_PORT(uint8_t GPIO_SEL, uint8_t data);
uint8_t MCAL_GPIO_READ_PIN(uint8_t GPIO_SEL, uint8_t pin); //Read the input data of a specific pin
uint8_t MCAL_GPIO_READ_PORT(uint8_t GPIO_SEL);
void MCAL_GPIO_TOGGLE_PIN(uint8_t GPIO_SEL, uint8_t pin);

#endif
