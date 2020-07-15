#include "bluetooth.h"
#define TEST_CMD   "AT"
#define RESET_CMD  "AT+RESET"
void HC05_init(uint8_t mode)
{
    UART_INIT_TYPE huart;
    huart.CHAR_LEN = 8; //int8_tlength
    huart.NSTOP_BIT = 1; //number of stop bits
    huart.PARITY_BIT = 0; //parity is diabled
    huart.TYPE = BOTH; //activate both RX & TX
    switch(mode)
    {
    case COMMAND_MODE:
        huart.BAUD_RATE = 38400; //baud rate
        break;
    case DATA_MODE:
        huart.BAUD_RATE = 9600; //baud rate
        break;
    }
    Uart_Init(UT3, &huart); //initialize uart3
}
