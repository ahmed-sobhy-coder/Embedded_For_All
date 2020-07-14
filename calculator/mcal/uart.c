#include "uart.h"

void Uart_Init(uint8_t uartn, uint32_t baudRate, uint8_t both) {
	switch (uartn) {
	case UT0: //U0RX  PA0 , U0TX PA1
		ST1B(SYSCTL->RCGCGPIO, PORTA);
		ST1B(SYSCTL->RCGCUART, UT0);
		switch (both) {
		case TX:
			ST1B(GPIOA->AFSEL, PA1);
			CLR1B(GPIOA->AMSEL, PA1);
			ST4B4MI(GPIOA->PCTL, PA1, 1); //PA1 works as Tx
			ST1B(GPIOA->DEN, PA1);
			CLR1B(UART0->CTL, UARTEN);
			STV(UART0->IBRD, BAUDINT(baudRate));//BAUDINT(baudRate);
			STV6BI(UART0->FBRD, BIT0, BAUDFLOAT(baudRate));
			STV2BI(UART0->LCRH, WLEN, charcter_bits(8));
			CLR1B(UART0->LCRH, STP2);
			CLR1B(UART0->LCRH, FEN);
			STV4BI(UART0->CC, CS, 0);
			CLR1B(UART0->CTL, HSE);
		    ST1B(UART0->IM,TXIM);
		    NVIC_Enable_IRQ(UART0_VECTOR,0);
			ST1B(UART0->CTL, TXE);
			ST1B(UART0->CTL, UARTEN);
			break;
		case RX:
			ST1B(GPIOA->AFSEL, PA0);
			CLR1B(GPIOA->AMSEL, PA0);
			ST4B4MI(GPIOA->PCTL, PA0, 1); //PA1 works as Tx
			ST1B(GPIOA->DEN, PA0);
			CLR1B(UART0->CTL, UARTEN);
			STV(UART0->IBRD, BAUDINT(baudRate));//BAUDINT(baudRate);
			STV6BI(UART0->FBRD, BIT0, BAUDFLOAT(baudRate));
			STV2BI(UART0->LCRH, WLEN, charcter_bits(8));
			CLR1B(UART0->LCRH, STP2);
			ST1B(UART0->LCRH, FEN);
			STV4BI(UART0->CC, CS, 0);
			CLR1B(UART0->CTL, HSE);
			ST1B(UART0->CTL, RXE);
			ST1B(UART0->CTL, UARTEN);
			break;
		case BOTH:
			ST1B(GPIOA->AFSEL, PA1);
			ST1B(GPIOA->AFSEL, PA0);
			CLR1B(GPIOA->AMSEL, PA1);
			CLR1B(GPIOA->AMSEL, PA0);
			ST4B4MI(GPIOA->PCTL, PA1, 1); //PA1 works as Tx
			ST4B4MI(GPIOA->PCTL, PA0, 1); //PA1 works as Tx
			ST1B(GPIOA->DEN, PA1);
			ST1B(GPIOA->DEN, PA0);
			CLR1B(UART0->CTL, UARTEN);
			STV(UART0->IBRD, BAUDINT(baudRate));//BAUDINT(baudRate);
			STV6BI(UART0->FBRD, BIT0, BAUDFLOAT(baudRate));
			STV2BI(UART0->LCRH, WLEN, charcter_bits(8));
			CLR1B(UART0->LCRH, STP2);
			STV4BI(UART0->CC, CS, 0);
			CLR1B(UART0->CTL, HSE);
			ST1B(UART0->CTL, TXE);
			ST1B(UART0->CTL, RXE);
			ST1B(UART0->CTL, UARTEN);
		}
		break;
	case UT1: // U1RX  PB0 , U1TX  PB1
		switch (both) {
		case TX:
			ST1B(SYSCTL->RCGCGPIO, PORTB);
			ST1B(SYSCTL->RCGCUART, PORTB);
			ST1B(GPIOB->AFSEL, PB1);
			CLR1B(GPIOB->AMSEL, PB1);
			ST4B4MI(GPIOB->PCTL, PB1, 1); //PA1 works as Tx
			ST1B(GPIOB->DEN, PB1);
			CLR1B(UART1->CTL, UARTEN);
			STV(UART1->IBRD, BAUDINT(baudRate));//BAUDINT(baudRate);
			STV6BI(UART1->FBRD, BIT0, BAUDFLOAT(baudRate));
			STV2BI(UART1->LCRH, WLEN, charcter_bits(8));
			CLR1B(UART1->LCRH, STP2);
			ST1B(UART1->LCRH, FEN);
			STV4BI(UART1->CC, CS, 0);
			CLR1B(UART1->CTL, HSE);
			ST1B(UART1->CTL, TXE);
			ST1B(UART1->CTL, UARTEN);
			break;
		case RX:
			ST1B(SYSCTL->RCGCGPIO, PORTB);
			ST1B(SYSCTL->RCGCUART, PORTB);
			ST1B(GPIOB->AFSEL, PB0);
			CLR1B(GPIOB->AMSEL, PB0);
			ST4B4MI(GPIOB->PCTL, PB0, 1); //PA1 works as Tx
			ST1B(GPIOB->DEN, PB0);
			CLR1B(UART1->CTL, UARTEN);
			STV(UART1->IBRD, BAUDINT(baudRate));//BAUDINT(baudRate);
			STV6BI(UART1->FBRD, BIT0, BAUDFLOAT(baudRate));
			STV2BI(UART1->LCRH, WLEN, charcter_bits(8));
			CLR1B(UART1->LCRH, STP2);
			ST1B(UART1->LCRH, FEN);
			STV4BI(UART1->CC, CS, 0);
			CLR1B(UART1->CTL, HSE);
			ST1B(UART1->CTL, RXE);
			ST1B(UART1->CTL, UARTEN);

			break;
		case BOTH:
			ST1B(SYSCTL->RCGCGPIO, PORTB);
			ST1B(SYSCTL->RCGCUART, UT1);
			ST1B(GPIOB->AFSEL, PB1);
			ST1B(GPIOB->AFSEL, PB0);
			CLR1B(GPIOB->AMSEL, PB1);
			CLR1B(GPIOB->AMSEL, PB0);
			ST4B4MI(GPIOB->PCTL, PB1, 1); //PA1 works as Tx
			ST4B4MI(GPIOB->PCTL, PB0, 1); //PA0 works as Rx
			ST1B(GPIOB->DEN, PB1);
			ST1B(GPIOB->DEN, PB0);
			CLR1B(GPIOB->DIR, PB1);
			CLR1B(GPIOB->DIR, PB0);
			CLR1B(UART1->CTL, UARTEN);
			STV(UART1->IBRD, BAUDINT(baudRate));//BAUDINT(baudRate);
			STV6BI(UART1->FBRD, BIT0, BAUDFLOAT(baudRate));
			STV2BI(UART1->LCRH, WLEN, charcter_bits(8));
			CLR1B(UART1->LCRH, STP2);
			CLR1B(UART1->LCRH, FEN); //fifo is diabled
			STV4BI(UART1->CC, CS, 0);
			CLR1B(UART1->CTL, HSE);
		    ST1B(UART0->IM,RXIM);
		    NVIC_Enable_IRQ(UART0_VECTOR,0);
			ST1B(UART1->CTL, TXE);
			ST1B(UART1->CTL, RXE);
			ST1B(UART1->CTL, UARTEN);

			break;
		}
		break;
	}

}
void Uart_Send_Char(uint8_t uartn, int8_t character) {
	switch (uartn) {
	case UT0:
		while (RD1B(UART0->FR, TXFF) == 1) {
		}
		;  // wait until Tx buffer not full 
		UART0->DR = character;
		break;
	case UT1:
		while (RD1B(UART1->FR, TXFF) == 1) {
		}
		;  // wait until Tx buffer not full 
		UART1->DR = character;
		break;
	}
}
void Uart_Send_String(uint8_t uartn, int8_t* string){
	uint8_t counter = 0;
	switch (uartn) {
	case UT0:
		while (string[counter] != '\0') {
			Uart_Send_Char(UT0, string[counter]);
			counter++;
		}
		break;
	case UT1:
		while (string[counter] != '\0') {
			Uart_Send_Char(UT1, string[counter]);
			counter++;
		}
		break;
	}
}
int8_t Uart_Receive_Char(uint8_t uartn) {
	int8_t data;
	switch (uartn) {
	case UT0:
		while (RD1B(UART0->FR, RXFE) == 1) { // do nothing if the fifo is empty
		}
		;
		data = UART0->DR;
		break;
	case UT1:
		while (RD1B(UART1->FR, RXFE) == 1) { // do nothing if the fifo is empty
		}
		;
		data = UART1->DR;
		break;
	case UT2:
		while (RD1B(UART2->FR, RXFE) == 1) { // do nothing if the fifo is empty
		}
		;
		data = UART2->DR;
		break;
	case UT3:
		while (RD1B(UART3->FR, RXFE) == 1) { // do nothing if the fifo is empty
		}
		;
		data = UART3->DR;
		break;
	case UT4:
		while (RD1B(UART4->FR, RXFE) == 1) { // do nothing if the fifo is empty
		}
		;
		data = UART4->DR;
		break;
	case UT5:
		while (RD1B(UART5->FR, RXFE) == 1) { // do nothing if the fifo is empty
		}
		;
		data = UART5->DR;
		break;
	case UT7:
		while (RD1B(UART7->FR, RXFE) == 1) { // do nothing if the fifo is empty
		}
		;
		data = UART7->DR;
		break;
	}
	return data;
}
//------------UART_InString------------
// Accepts ASCII characters from the serial port
//    and adds them to a string until <enter> is typed
//    or until max length of the string is reached.
// It echoes each character as it is inputted.
// If a backspace is inputted, the string is modified
//    and the backspace is echoed
// terminates the string with a null character
// uses busy-waiting synchronization on RDRF
// Input: pointer to empty buffer, size of buffer
// Output: Null terminated string
// -- Modified by Agustinus Darmawan + Mingjie Qiu --
void UART_Receive_String(uint8_t uartn, int8_t* string, uint32_t max) {
	int8_t length = 0;
	int8_t character;
	switch (uartn) {
	case UT0:
		while (((character = Uart_Receive_Char(UT0)) != '\r') && length < max) {
				*string++ = character;
				length++;
			}
		break;
	case UT1:
		while (((character = Uart_Receive_Char(UT0)) != '\n') && length < max) {
			if (character == '\r') break; //when you press \n before it \r is going to be considered as a character
			else {
				*string++ = character;
				length++;
			}
		}
		break;
	}
    character = Uart_Receive_Char(UT0);//remove \n
	*string = '\0';
}
void UART_AT_Resp_Receive(uint8_t uartn, int8_t* string, uint32_t max) {
	int8_t length = 0;
	int8_t character;
	switch (uartn) {
	case UT1:
		while (length < max) {
			character = Uart_Receive_Char(UT1);
			*string++ = character;
			length++;
			if (character == 'O') {
				character = Uart_Receive_Char(UT1);
				*string++ = character;
				length++;
				if (character == 'K') {
					character = Uart_Receive_Char(UT1);
					*string++ = character; //store '\r'
					length++;
					if (character == '\r') {
						character = Uart_Receive_Char(UT1);
						*string++ = character;  // store '\n'
						length++;
						if (character == '\n') {
							*string = '\0';
							length++;
							break;
						}
					}
				}
			}
		}
		break;
	}
}
void Uart_Send_Integer(uint8_t uartn, uint32_t num) {
	Uart_Send_String(uartn, Int_To_string_conversion(num));
}
void Uart_Send_Float(uint32_t uartn, double float_num, uint8_t precision) {
	Uart_Send_String(uartn, Float_To_string_conversion(float_num, precision));
}
void UART_Interrupt_Init(uint8_t uartn, uint32_t baudRate, uint8_t both){
	switch (uartn) {
	case UT0: //U0RX  PA0 , U0TX PA1
		ST1B(SYSCTL->RCGCGPIO, PORTA);
		ST1B(SYSCTL->RCGCUART, UT0);
		switch (both) {
		case TX:
			ST1B(GPIOA->AFSEL, PA1);
			CLR1B(GPIOA->AMSEL, PA1);
			ST4B4MI(GPIOA->PCTL, PA1, 1); //PA1 works as Tx
			ST1B(GPIOA->DEN, PA1);
			CLR1B(UART0->CTL, UARTEN);
			STV(UART0->IBRD, BAUDINT(baudRate));//BAUDINT(baudRate);
			STV6BI(UART0->FBRD, BIT0, BAUDFLOAT(baudRate));
			STV2BI(UART0->LCRH, WLEN, charcter_bits(8));
			CLR1B(UART0->LCRH, STP2);
			ST1B(UART0->LCRH, FEN);
			STV4BI(UART0->CC, CS, 0);
			CLR1B(UART0->CTL, HSE);
		    ST1B(UART0->IM,TXIM);
		    NVIC_Enable_IRQ(UART0_VECTOR,0);
			ST1B(UART0->CTL, TXE);
			ST1B(UART0->CTL, UARTEN);
			break;
		case RX:
			ST1B(GPIOA->AFSEL, PA0);
			CLR1B(GPIOA->AMSEL, PA0);
			ST4B4MI(GPIOA->PCTL, PA0, 1); //PA1 works as Tx
			ST1B(GPIOA->DEN, PA0);
			CLR1B(UART0->CTL, UARTEN);
			STV(UART0->IBRD, BAUDINT(baudRate));//BAUDINT(baudRate);
			STV6BI(UART0->FBRD, BIT0, BAUDFLOAT(baudRate));
			STV2BI(UART0->LCRH, WLEN, charcter_bits(8));
			CLR1B(UART0->LCRH, STP2);
			ST1B(UART0->LCRH, FEN);
			STV4BI(UART0->CC, CS, 0);
			CLR1B(UART0->CTL, HSE);
			ST1B(UART0->IM,RXIM);
		    NVIC_Enable_IRQ(UART0_VECTOR,0);
			ST1B(UART0->CTL, RXE);
			ST1B(UART0->CTL, UARTEN);
			break;
		case BOTH:
			ST1B(GPIOA->AFSEL, PA1);
			ST1B(GPIOA->AFSEL, PA0);
			CLR1B(GPIOA->AMSEL, PA1);
			CLR1B(GPIOA->AMSEL, PA0);
			ST4B4MI(GPIOA->PCTL, PA1, 1); //PA1 works as Tx
			ST4B4MI(GPIOA->PCTL, PA0, 1); //PA1 works as Tx
			ST1B(GPIOA->DEN, PA1);
			ST1B(GPIOA->DEN, PA0);
			CLR1B(UART0->CTL, UARTEN);
			STV(UART0->IBRD, BAUDINT(baudRate));//BAUDINT(baudRate);
			STV6BI(UART0->FBRD, BIT0, BAUDFLOAT(baudRate));
			STV2BI(UART0->LCRH, WLEN, charcter_bits(8));
			CLR1B(UART0->LCRH, STP2);
			//	ST1B(UART0->LCRH,FEN);
			STV4BI(UART0->CC, CS, 0);
			CLR1B(UART0->CTL, HSE);
			ST1B(UART0->IM, RXIM);
			ST1B(UART0->CTL, TXE);
			ST1B(UART0->CTL, RXE);
			NVIC_Enable_IRQ(UART0_VECTOR, 1);
			ST1B(UART0->CTL, UARTEN);
		}
	}
}



