#ifndef __RGB_H__
#define __RGB_H__
#include "tm4c123io.h"
#define  OFF 0
#define  ON  1
#define  LED_RED               PF1
#define  LED_BLUE              PF2
#define  LED_GREEN             PF3
#define  ALL                   0x0D
#define RGB                  PORTF
#define RGB_PORT            (GPIOF->DATA)
void RGB_Led_Init(uint8_t led);
void RGB_Led_Output(uint8_t led,uint8_t state);
void RGB_Disable_All(void);
void RGB_Led_Toggle(uint8_t led);
#endif
