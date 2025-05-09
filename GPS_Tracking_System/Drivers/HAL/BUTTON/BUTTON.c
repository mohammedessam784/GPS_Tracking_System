#include "HAL/BUTTON/BUTTON.h"

void HAL_BUTTON_INIT(uint8_t port, uint8_t pin, uint8_t polarity){
	MCAL_GPIO_INIT(port);
	MCAL_GPIO_DIGITAL_INIT(port, pin);
	MCAL_GPIO_DIGITAL_PIN_MODE(port, pin, Input, polarity);
}

uint8_t HAL_BUTTON_READ(uint8_t port, uint8_t pin){
	return MCAL_GPIO_READ_PIN(port, pin);
}
