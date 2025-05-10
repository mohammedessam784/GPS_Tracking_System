
#include "MCAL/SYSTICK/SYSTICK.h"



static void (*SYSTICK_Callback)(void) = 0;

void  MCAL_SYSTICK_Init(uint32_t ticks, uint8_t enable_interrupt) {
    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = ticks - 1;
    NVIC_ST_CURRENT_R = 0;
	
		SET_BIT(NVIC_ST_CTRL_R,CTRL_CLK_SRC );
    SET_BIT(NVIC_ST_CTRL_R,CTRL_ENABLE );	
	  

    if (enable_interrupt==SYSTICK_INT_ENABLE ) {
        SET_BIT(NVIC_ST_CTRL_R , CTRL_INTEN);
    }
}

void  MCAL_SYSTICK_Start(void) {
    
	SET_BIT(NVIC_ST_CTRL_R,CTRL_ENABLE);
}

void  MCAL_SYSTICK_Stop(void) {
     
	CLR_BIT(NVIC_ST_CTRL_R,CTRL_ENABLE);
}

void  MCAL_SYSTICK_SetCallback(void (*ptr)(void)) {
    SYSTICK_Callback = ptr;
}

void  SysTick_Handler(void) {
    if (SYSTICK_Callback != 0) {
        SYSTICK_Callback();
    }
}

void MCAL_SYSTICK_Delay_ms(uint32_t delay) {
	uint32_t i ;
    for ( i = 0; i < delay; i++) {
        MCAL_SYSTICK_Init(SYSTEM_CLOCK/1000, SYSTICK_INT_DISABLE); // 16MHz clock = 1ms
        while (GET_BIT(NVIC_ST_CTRL_R ,CTRL_COUNT) == low);
    }
}
