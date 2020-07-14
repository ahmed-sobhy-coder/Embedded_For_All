#ifndef __UART_H__
#define __UART_H__
#include "stdint.h"
#include "tm4c123io.h"
#include "bitManip.h"
#include "stringManip.h"
#include "NVIC.h"
#include "rgb.h"
//#define CR   0x0D
#define LF   0x0A
#define BS   0x08

#define NEW_LINE        LF
#define wheelsRIAGE_RETURN CR
#define BACK_SPACE    BS


#define RX        0
#define TX        1
#define BOTH      2

#define U0RX  PA0	
#define U0TX  PA1
#define U1RX  PB0
#define U1TX  PB1
#define U2RX  PD6
#define U2TX  PD7	
#define U3RX  PC6
#define U3TX  PC7	
#define U4RX  PC4
#define U4TX  PC5
#define U5RX  PE4
#define U5TX  PE5 
#define U6TX  PD4 //USB
#define U6RX  PD5 //USB
#define U7RX  PE0;
#define U7TX  PE1;	



#define SYSTEM_CLOCK                 16000000U
#define BAUD_9600                      9600U

#define BAUDINT(BAUD)           (SYSTEM_CLOCK/(16*BAUD))
#define BAUDFLOAT(BAUD)         (int)((((((double)SYSTEM_CLOCK/(16*BAUD))- BAUDINT(BAUD))* 64)+0.5))  
#define charcter_bits(bits)          (bits-5)

#define UARTEN  0
#define WLEN    5 
#define STP2    3
#define FEN     4
#define CS   0
#define HSE   5
#define TXE   8
#define RXE   9
#define TXFF  5
#define RXFE  4
#define UT0    0
#define UT1    1
#define UT2    2
#define UT3    3
#define UT4    4
#define UT5    5
#define UT6    6
#define UT7    7
#define RXIM     4
#define TXIM  	 5
#define RXMIS    4
#define RXIC    4
#define TXMIS   5
#define TXIC    5

#define UART0_VECTOR   5
void Uart_Init(uint8_t uartn,uint32_t baudRate,uint8_t both);
void Uart_Send_Char(uint8_t uartn, int8_t character) ;
void Uart_Send_String(uint8_t uartn, int8_t* string) ;
int8_t Uart_Receive_Char(uint8_t uartn) ;
void UART_Receive_String(uint8_t uartn, int8_t* string, uint32_t max);
void Uart_Send_Integer(uint8_t uartn,uint32_t num);
void Uart_Send_Float(uint32_t uartn,double float_num,uint8_t precision);
void Uart_Send_Float(uint32_t uartn,double float_num,uint8_t precision);
void UART_Interrupt_Init(uint8_t uartn, uint32_t baudRate, uint8_t both);
void UART_AT_Resp_Receive(uint8_t uartn, int8_t* string, uint32_t max);

#endif  
