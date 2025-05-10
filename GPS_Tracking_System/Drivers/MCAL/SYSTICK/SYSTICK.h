#ifndef SYSTICK_h
#define SYSTICK_h

#include <stdint.h>
#include "LIB/BIT_MATHS.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/tm4c123gh6pm.h" 
#include "MCAL/GPIO/GPIO.h"

#define CTRL_ENABLE   0
#define CTRL_INTEN    1
#define CTRL_CLK_SRC  2
#define CTRL_COUNT  16



#define SYSTICK_INT_DISABLE  0
#define SYSTICK_INT_ENABLE   1

void  MCAL_SYSTICK_Init(uint32_t ticks, uint8_t enable_interrupt);
void  MCAL_SYSTICK_Start(void);
void  MCAL_SYSTICK_Stop(void);
void  MCAL_SYSTICK_SetCallback(void (*ptr)(void));
//void  MCAL_SYSTICK_Delay_ms(uint32_t delay);


#endif
