#ifndef system_init
#define system_init
#include "MCAL/GPIO/GPIO.h"
#include "MCAL/UART/UART.h"
#include "MCAL/SYSTICK/SYSTICK.h"
#include "MCAL/EEPROM/EEPROM.h"
#include "MCAL/ADC/ADC.h"

#include "HAL/BUTTON/BUTTON.h"
#include "HAL/LED/LED.h"
#include "HAL/GPS/GPS.h"
#include "HAL/LCD/LCD.h"

#include "APP/main_app.h"

void System_Init(void);


#endif
