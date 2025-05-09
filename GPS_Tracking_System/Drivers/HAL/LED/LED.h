#ifndef HAL_LED_H_
#define HAL_LED_H_

#include "MCAL/GPIO/GPIO.h"

void HAL_LED_INIT(uint8_t port, uint8_t pin);
void HAL_LED_ON(uint8_t port, uint8_t pin);
void HAL_LED_OFF(uint8_t port, uint8_t pin);
void HAL_LED_TOGGLE(uint8_t port, uint8_t pin);

#endif
