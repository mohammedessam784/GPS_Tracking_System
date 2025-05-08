#ifndef MCAL_UART_H_
#define MCAL_UART_H_

#include <stdint.h>
#include "LIB/BIT_MATHS.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/tm4c123gh6pm.h" 
#include "MCAL/GPIO/GPIO.h"

#define UART0_ID 0
#define UART1_ID 1
#define UART2_ID 2
#define UART3_ID 3
#define UART4_ID 4
#define UART5_ID 5
#define UART6_ID 6
#define UART7_ID 7

// Bit position macros for UART_CTL register
#define CTL_UARTEN   0   // UART Enable
#define CTL_TXE      8   // Transmit Enable
#define CTL_RXE      9   // Receive Enable

#define LCRH_WLEN_8     (0x3 << 5)   // 8-bit word length
#define LCRH_WLEN_7     (0x2 << 5)
#define LCRH_WLEN_6     (0x1 << 5)
#define LCRH_WLEN_5     (0x0 << 5)

#define LCRH_FEN        (1 << 4)     // Enable FIFOs
#define LCRH_STP2       (1 << 3)     // Two stop bits
#define LCRH_EPS        (1 << 2)     // Even parity
#define LCRH_PEN        (1 << 1)     // Parity enable
#define LCRH_BRK        (1 << 0)     // Send break

#define TXFF   5  // Transmit FIFO Full
#define RXFE   4  // Receive FIFO Empty

#define UART0_IRQ   5
#define UART1_IRQ   6
#define UART2_IRQ   33
#define UART3_IRQ   59
#define UART4_IRQ   60
#define UART5_IRQ   61
#define UART6_IRQ   62
#define UART7_IRQ   63


// Function Prototypes

void MCAL_UART_INIT(uint8_t UART_SEL, uint32_t baud_rate);//, uint32_t baud_rate

void MCAL_UART_TX(uint8_t UART_SEL, uint8_t data);
uint8_t MCAL_UART_RX(uint8_t UART_SEL);

void MCAL_UART_TX_STRING(uint8_t UART_SEL, const char *str);
void MCAL_UART_RX_STRING(uint8_t UART_SEL, char *str, char terminator);
void MCAL_UART_Enable_RX_Interrupt(uint8_t UART_SEL);

#endif
