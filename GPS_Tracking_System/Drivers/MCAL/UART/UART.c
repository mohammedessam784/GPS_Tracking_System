#include "MCAL/UART/UART.h"


void MCAL_UART_INIT(uint8_t UART_SEL, uint32_t baud_rate) {
    uint32_t BRD;

    switch (UART_SEL) {
        case UART0_ID:
            SET_BIT(SYSCTL_RCGCUART_R, UART0_ID);
            while (GET_BIT(SYSCTL_PRUART_R, UART0_ID) == low);
            SET_BIT(SYSCTL_RCGCGPIO_R, PORTA_ID);
            while (GET_BIT(SYSCTL_PRGPIO_R, PORTA_ID) == low);

            CLR_BIT(UART0_CTL_R, CTL_UARTEN);
            BRD = SYSTEM_CLOCK / (16 * baud_rate);
            UART0_IBRD_R = BRD;
            UART0_FBRD_R = (uint32_t)(((SYSTEM_CLOCK / (16.0 * baud_rate)) - BRD) * 64 + 0.5);
            UART0_LCRH_R = LCRH_WLEN_8;
            UART0_CTL_R = (1 << CTL_UARTEN) | (1 << CTL_TXE) | (1 << CTL_RXE);

            SET_MASK(GPIO_PORTA_AFSEL_R, 0x03);
            CLR_MASK(GPIO_PORTA_PCTL_R, 0xFF);
            SET_MASK(GPIO_PORTA_PCTL_R, 0x11);
            CLR_MASK(GPIO_PORTA_AMSEL_R, 0x03);
            SET_MASK(GPIO_PORTA_DEN_R, 0x03);
            break;

        case UART1_ID:
            SET_BIT(SYSCTL_RCGCUART_R, UART1_ID);
            while (GET_BIT(SYSCTL_PRUART_R, UART1_ID) == low);
            SET_BIT(SYSCTL_RCGCGPIO_R, PORTB_ID);
            while (GET_BIT(SYSCTL_PRGPIO_R, PORTB_ID) == low);

            CLR_BIT(UART1_CTL_R, CTL_UARTEN);
            BRD = SYSTEM_CLOCK / (16 * baud_rate);
            UART1_IBRD_R = BRD;
            UART1_FBRD_R = (uint32_t)(((SYSTEM_CLOCK / (16.0 * baud_rate)) - BRD) * 64 + 0.5);
            UART1_LCRH_R = LCRH_WLEN_8;
            UART1_CTL_R = (1 << CTL_UARTEN) | (1 << CTL_TXE) | (1 << CTL_RXE);

            SET_MASK(GPIO_PORTB_AFSEL_R, 0x03);
            CLR_MASK(GPIO_PORTB_PCTL_R, 0xFF);
            SET_MASK(GPIO_PORTB_PCTL_R, 0x11);
            CLR_MASK(GPIO_PORTB_AMSEL_R, 0x03);
            SET_MASK(GPIO_PORTB_DEN_R, 0x03);
            break;

        case UART2_ID:
            SET_BIT(SYSCTL_RCGCUART_R, UART2_ID);
            while (GET_BIT(SYSCTL_PRUART_R, UART2_ID) == low);
            SET_BIT(SYSCTL_RCGCGPIO_R, PORTD_ID);
            while (GET_BIT(SYSCTL_PRGPIO_R, PORTD_ID) == low);

            CLR_BIT(UART2_CTL_R, CTL_UARTEN);
            BRD = SYSTEM_CLOCK / (16 * baud_rate);
            UART2_IBRD_R = BRD;
            UART2_FBRD_R = (uint32_t)(((SYSTEM_CLOCK / (16.0 * baud_rate)) - BRD) * 64 + 0.5);
            UART2_LCRH_R = LCRH_WLEN_8;
            UART2_CTL_R = (1 << CTL_UARTEN) | (1 << CTL_TXE) | (1 << CTL_RXE);

            SET_MASK(GPIO_PORTD_AFSEL_R, 0xC0);
            CLR_MASK(GPIO_PORTD_PCTL_R, 0xFF000000);
            SET_MASK(GPIO_PORTD_PCTL_R, 0x11000000);
            CLR_MASK(GPIO_PORTD_AMSEL_R, 0xC0);
            SET_MASK(GPIO_PORTD_DEN_R, 0xC0);
            break;

        case UART3_ID:
            SET_BIT(SYSCTL_RCGCUART_R, UART3_ID);
            while (GET_BIT(SYSCTL_PRUART_R, UART3_ID) == low);
            SET_BIT(SYSCTL_RCGCGPIO_R, PORTC_ID);
            while (GET_BIT(SYSCTL_PRGPIO_R, PORTC_ID) == low);

            CLR_BIT(UART3_CTL_R, CTL_UARTEN);
            BRD = SYSTEM_CLOCK / (16 * baud_rate);
            UART3_IBRD_R = BRD;
            UART3_FBRD_R = (uint32_t)(((SYSTEM_CLOCK / (16.0 * baud_rate)) - BRD) * 64 + 0.5);
            UART3_LCRH_R = LCRH_WLEN_8;
            UART3_CTL_R = (1 << CTL_UARTEN) | (1 << CTL_TXE) | (1 << CTL_RXE);

            SET_MASK(GPIO_PORTC_AFSEL_R, 0xC0);
            CLR_MASK(GPIO_PORTC_PCTL_R, 0xFF000000);
            SET_MASK(GPIO_PORTC_PCTL_R, 0x11000000);
            CLR_MASK(GPIO_PORTC_AMSEL_R, 0xC0);
            SET_MASK(GPIO_PORTC_DEN_R, 0xC0);
            break;

        case UART4_ID:
            SET_BIT(SYSCTL_RCGCUART_R, UART4_ID);
            while (GET_BIT(SYSCTL_PRUART_R, UART4_ID) == low);
            SET_BIT(SYSCTL_RCGCGPIO_R, PORTC_ID);
            while (GET_BIT(SYSCTL_PRGPIO_R, PORTC_ID) == low);

            CLR_BIT(UART4_CTL_R, CTL_UARTEN);
            BRD = SYSTEM_CLOCK / (16 * baud_rate);
            UART4_IBRD_R = BRD;
            UART4_FBRD_R = (uint32_t)(((SYSTEM_CLOCK / (16.0 * baud_rate)) - BRD) * 64 + 0.5);
            UART4_LCRH_R = LCRH_WLEN_8;
            UART4_CTL_R = (1 << CTL_UARTEN) | (1 << CTL_TXE) | (1 << CTL_RXE);

            SET_MASK(GPIO_PORTC_AFSEL_R, 0x30);
            CLR_MASK(GPIO_PORTC_PCTL_R, 0x00FF0000);
            SET_MASK(GPIO_PORTC_PCTL_R, 0x00110000);
            CLR_MASK(GPIO_PORTC_AMSEL_R, 0x30);
            SET_MASK(GPIO_PORTC_DEN_R, 0x30);
            break;

        case UART5_ID:
            SET_BIT(SYSCTL_RCGCUART_R, UART5_ID);
            while (GET_BIT(SYSCTL_PRUART_R, UART5_ID) == low);
            SET_BIT(SYSCTL_RCGCGPIO_R, PORTE_ID);
            while (GET_BIT(SYSCTL_PRGPIO_R, PORTE_ID) == low);

            CLR_BIT(UART5_CTL_R, CTL_UARTEN);
            BRD = SYSTEM_CLOCK / (16 * baud_rate);
            UART5_IBRD_R = BRD;
            UART5_FBRD_R = (uint32_t)(((SYSTEM_CLOCK / (16.0 * baud_rate)) - BRD) * 64 + 0.5);
            UART5_LCRH_R = LCRH_WLEN_8;
            UART5_CTL_R = (1 << CTL_UARTEN) | (1 << CTL_TXE) | (1 << CTL_RXE);

            SET_MASK(GPIO_PORTE_AFSEL_R, 0x30);
            CLR_MASK(GPIO_PORTE_PCTL_R, 0x00FF0000);
            SET_MASK(GPIO_PORTE_PCTL_R, 0x00110000);
            CLR_MASK(GPIO_PORTE_AMSEL_R, 0x30);
            SET_MASK(GPIO_PORTE_DEN_R, 0x30);
            break;

        case UART6_ID:
            SET_BIT(SYSCTL_RCGCUART_R, UART6_ID);
            while (GET_BIT(SYSCTL_PRUART_R, UART6_ID) == low);
            SET_BIT(SYSCTL_RCGCGPIO_R, PORTD_ID);
            while (GET_BIT(SYSCTL_PRGPIO_R, PORTD_ID) == low);

            CLR_BIT(UART6_CTL_R, CTL_UARTEN);
            BRD = SYSTEM_CLOCK / (16 * baud_rate);
            UART6_IBRD_R = BRD;
            UART6_FBRD_R = (uint32_t)(((SYSTEM_CLOCK / (16.0 * baud_rate)) - BRD) * 64 + 0.5);
            UART6_LCRH_R = LCRH_WLEN_8;
            UART6_CTL_R = (1 << CTL_UARTEN) | (1 << CTL_TXE) | (1 << CTL_RXE);

            SET_MASK(GPIO_PORTD_AFSEL_R, 0x30);
            CLR_MASK(GPIO_PORTD_PCTL_R, 0x00FF0000);
            SET_MASK(GPIO_PORTD_PCTL_R, 0x00110000);
            CLR_MASK(GPIO_PORTD_AMSEL_R, 0x30);
            SET_MASK(GPIO_PORTD_DEN_R, 0x30);
            break;

        case UART7_ID:
            SET_BIT(SYSCTL_RCGCUART_R, UART7_ID);
            while (GET_BIT(SYSCTL_PRUART_R, UART7_ID) == low);
            SET_BIT(SYSCTL_RCGCGPIO_R, PORTE_ID);
            while (GET_BIT(SYSCTL_PRGPIO_R, PORTE_ID) == low);

            CLR_BIT(UART7_CTL_R, CTL_UARTEN);
            BRD = SYSTEM_CLOCK / (16 * baud_rate);
            UART7_IBRD_R = BRD;
            UART7_FBRD_R = (uint32_t)(((SYSTEM_CLOCK / (16.0 * baud_rate)) - BRD) * 64 + 0.5);
            UART7_LCRH_R = LCRH_WLEN_8;
            UART7_CTL_R = (1 << CTL_UARTEN) | (1 << CTL_TXE) | (1 << CTL_RXE);

            SET_MASK(GPIO_PORTE_AFSEL_R, 0xC0);
            CLR_MASK(GPIO_PORTE_PCTL_R, 0xFF000000);
            SET_MASK(GPIO_PORTE_PCTL_R, 0x11000000);
            CLR_MASK(GPIO_PORTE_AMSEL_R, 0xC0);
            SET_MASK(GPIO_PORTE_DEN_R, 0xC0);
            break;

        default:
            return;
    }
}


void MCAL_UART_TX(uint8_t UART_SEL, uint8_t data){
    switch(UART_SEL){
        case UART0_ID:
            while(GET_BIT(UART0_FR_R, TXFF));
            UART0_DR_R = data;
            break;
        case UART1_ID:
            while(GET_BIT(UART1_FR_R, TXFF));
            UART1_DR_R = data;
            break;
        case UART2_ID:
            while(GET_BIT(UART2_FR_R, TXFF));
            UART2_DR_R = data;
            break;
        case UART3_ID:
            while(GET_BIT(UART3_FR_R, TXFF));
            UART3_DR_R = data;
            break;
        case UART4_ID:
            while(GET_BIT(UART4_FR_R, TXFF));
            UART4_DR_R = data;
            break;
        case UART5_ID:
            while(GET_BIT(UART5_FR_R, TXFF));
            UART5_DR_R = data;
            break;
        case UART6_ID:
            while(GET_BIT(UART6_FR_R, TXFF));
            UART6_DR_R = data;
            break;
        case UART7_ID:
            while(GET_BIT(UART7_FR_R, TXFF));
            UART7_DR_R = data;
            break;
    }
}

uint8_t MCAL_UART_RX(uint8_t UART_SEL){
    switch(UART_SEL){
        case UART0_ID:
            while(GET_BIT(UART0_FR_R, RXFE));
            return (uint8_t)(UART0_DR_R & 0xFF);
        case UART1_ID:
            while(GET_BIT(UART1_FR_R, RXFE));
            return (uint8_t)(UART1_DR_R & 0xFF);
        case UART2_ID:
            while(GET_BIT(UART2_FR_R, RXFE));
            return (uint8_t)(UART2_DR_R & 0xFF);
        case UART3_ID:
            while(GET_BIT(UART3_FR_R, RXFE));
            return (uint8_t)(UART3_DR_R & 0xFF);
        case UART4_ID:
            while(GET_BIT(UART4_FR_R, RXFE));
            return (uint8_t)(UART4_DR_R & 0xFF);
        case UART5_ID:
            while(GET_BIT(UART5_FR_R, RXFE));
            return (uint8_t)(UART5_DR_R & 0xFF);
        case UART6_ID:
            while(GET_BIT(UART6_FR_R, RXFE));
            return (uint8_t)(UART6_DR_R & 0xFF);
        case UART7_ID:
            while(GET_BIT(UART7_FR_R, RXFE));
            return (uint8_t)(UART7_DR_R & 0xFF);
    }
    return 0;
}

void MCAL_UART_TX_STRING(uint8_t UART_SEL, const char *str){
    while(*str){
        MCAL_UART_TX(UART_SEL, *str++);
    }
}

void MCAL_UART_RX_STRING(uint8_t UART_SEL, char *str, char terminator){
    char ch;
    do {
        ch = MCAL_UART_RX(UART_SEL);  
        *str = ch;                    
        str++;
    } while(ch != terminator);        
    *(str - 1) = '\0';                
}


void MCAL_UART_Enable_RX_Interrupt(uint8_t UART_SEL) {
    switch(UART_SEL) {
        case UART0_ID:
            UART0_IM_R |= (1 << 4);     // Enable RX interrupt
            UART0_ICR_R |= (1 << 4);    // Clear RX interrupt flag
            NVIC_EN0_R |= (1U << (UART0_IRQ % 32)); // Enable UART0 interrupt in NVIC
            break;
        case UART1_ID:
            UART1_IM_R |= (1 << 4);
            UART1_ICR_R |= (1 << 4);
            NVIC_EN0_R |= (1U << (UART1_IRQ % 32));
            break;
        case UART2_ID:
            UART2_IM_R |= (1 << 4);
            UART2_ICR_R |= (1 << 4);
            NVIC_EN1_R |= (1U << (UART2_IRQ % 32));   // IRQ33
            break;
        case UART3_ID:
            UART3_IM_R |= (1 << 4);
            UART3_ICR_R |= (1 << 4);
            NVIC_EN1_R |= (1U << (UART3_IRQ % 32));  // IRQ59
            break;
        case UART4_ID:
            UART4_IM_R |= (1 << 4);
            UART4_ICR_R |= (1 << 4);
            NVIC_EN1_R |= (1U << (UART4_IRQ % 32));  // IRQ60
            break;
        case UART5_ID:
            UART5_IM_R |= (1 << 4);
            UART5_ICR_R |= (1 << 4);
            NVIC_EN1_R |= (1U << (UART5_IRQ % 32));  // IRQ61
            break;
        case UART6_ID:
            UART6_IM_R |= (1 << 4);
            UART6_ICR_R |= (1 << 4);
            NVIC_EN1_R |= (1U << (UART6_IRQ % 32));  // IRQ62
            break;
        case UART7_ID:
            UART7_IM_R |= (1 << 4);
            UART7_ICR_R |= (1 << 4);
            NVIC_EN1_R |= (1U << (UART7_IRQ % 32));  // IRQ63
            break;
    }
}
