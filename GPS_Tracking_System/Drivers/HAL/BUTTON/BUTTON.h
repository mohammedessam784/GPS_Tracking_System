#ifndef HAL_BUTTON_H_
#define HAL_BUTTON_H_

#include "MCAL/GPIO/GPIO.h"

void HAL_BUTTON_INIT(uint8_t port, uint8_t pin, uint8_t polarity);
uint8_t HAL_BUTTON_READ(uint8_t port, uint8_t pin);

#endif
