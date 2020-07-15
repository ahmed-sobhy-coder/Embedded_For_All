#ifndef _BLUETOOTH__H_
#define _BLUETOOTH__H_
#include "uart.h"

#define COMMAND_MODE   1
#define DATA_MODE      2
void HC05_init(uint8_t mode);
#endif
