#include "HAL/LED/LED.h"

void HAL_LED_INIT(uint8_t port, uint8_t pin){
	MCAL_GPIO_INIT(port);
	MCAL_GPIO_DIGITAL_INIT(port, pin);
	MCAL_GPIO_DIGITAL_PIN_MODE(port, pin, Output, Floating);
}

void HAL_LED_ON(uint8_t port, uint8_t pin){
	MCAL_GPIO_WRITE_PIN(port, pin, high);
}

void HAL_LED_OFF(uint8_t port, uint8_t pin){
	MCAL_GPIO_WRITE_PIN(port, pin, low);
}

void HAL_LED_TOGGLE(uint8_t port, uint8_t pin){
	MCAL_GPIO_TOGGLE_PIN(port , pin);
	
}

