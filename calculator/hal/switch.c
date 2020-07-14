#include "switch.h"
#include "RGB.h"
void SWITCH_Init(uint32_t sw) {
	switch (sw) {
	case SWITCH_1:
		GPIO_Pin_Init(PORTF, SWITCH_1, DIGITAL_INPUT_INERNAL_PULLUP);
		break;
	case SWITCH_2:
		GPIO_Pin_Init(PORTF, SWITCH_2, DIGITAL_INPUT_INERNAL_PULLUP);
		break;
	}
}

void SWITCH_App1(void){
	RGB_Led_Init(ALL);
	SWITCH_Init(SWITCH_2);
	while (1) {
		RGB_Led_Output(LED_RED,OFF);
		if (RD1B(GPIOF->DATA,SWITCH_2)== DIGITAL_LOW) {
			RGB_Led_Output(LED_RED,ON);
			while(RD1B(GPIOF->DATA,SWITCH_2)==0);
		}
	}
}
void SWITCH_App2(void){
  RGB_Led_Init(ALL);
	SWITCH_Init(SWITCH_1);
	SWITCH_Init(SWITCH_2);
	while (1) {
		if(RD1B(GPIOF->DATA,SWITCH_2)== DIGITAL_LOW) {
			RGB_Led_Output(LED_RED,ON);
			while(RD1B(GPIOF->DATA,SWITCH_2)==0);
		}
		if(RD1B(GPIOF->DATA,SWITCH_1)== DIGITAL_LOW) {
			RGB_Led_Output(LED_RED,OFF);
			while(RD1B(GPIOF->DATA,SWITCH_1)==0);
		}
	}
}
uint8_t SWITCH_Is_Pressed(uint8_t sw){
	uint8_t state=0;
	switch(sw){
	case SWITCH_1:
		if(RD1B(SWITCH_PORT ,SWITCH_1)== DIGITAL_LOW) state=1;
		break;
	case SWITCH_2:
		if(RD1B(SWITCH_PORT ,SWITCH_2)== DIGITAL_LOW) state=1;
		break;
	}	
	return state;
}
void SWITCH_Interrpt_Init(uint8_t sw){
	switch(sw){
		case SWITCH_1:
			break;
		case SWITCH_2:
			break;
	}
}
