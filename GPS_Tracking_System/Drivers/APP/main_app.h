#ifndef main_app_H
#define main_app_H

#include <stdint.h>

#include "MCAL/GPIO/GPIO.h"
#include "MCAL/UART/UART.h"
#include "MCAL/SYSTICK/SYSTICK.h"
#include "MCAL/EEPROM/EEPROM.h"
#include "MCAL/ADC/ADC.h"

#include "HAL/BUTTON/BUTTON.h"
#include "HAL/LED/LED.h"
#include "HAL/GPS/GPS.h"
#include "HAL/LCD/LCD.h"

void App_Main_Loop(void);
void MY_Systick_Function(void);
void LED_Blink_Task(void );
void GPS_Task(void);
void ADC_Task(void);
void GUI_Task(void);

#endif
