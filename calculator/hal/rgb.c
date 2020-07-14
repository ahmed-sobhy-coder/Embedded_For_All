#include "rgb.h"

void RGB_Init(uint8_t led){
  switch(led){
    case LED_RED:
      GPIO_PinInit(RGB ,LED_RED,DIGITAL_OUTPUT);
      break;
    case LED_BLUE:
      GPIO_PinInit(RGB ,LED_BLUE,DIGITAL_OUTPUT);
      break;
    case LED_GREEN:
      GPIO_PinInit(RGB ,LED_GREEN,DIGITAL_OUTPUT);
      break;
    default:
      GPIO_PinInit(RGB,LED_RED,DIGITAL_OUTPUT);
      GPIO_PinInit(RGB,LED_BLUE,DIGITAL_OUTPUT);
      GPIO_PinInit(RGB,LED_GREEN,DIGITAL_OUTPUT);
  }
}
void RGB_Output(uint8_t led,uint8_t state){
  switch(led){
    case LED_RED:
      switch(state){
        case ON:
          GPIO_PinOut(RGB,LED_RED,HIGH);
          break;
        case OFF:
          GPIO_PinOut(RGB,LED_RED,LOW);
          break;
      }
    break;
    case LED_BLUE:
      switch(state){
        case ON:
          GPIO_PinOut(RGB,LED_BLUE,HIGH);
          break;
        case OFF:
          GPIO_PinOut(RGB,LED_BLUE,LOW);
          break;
      }
    break;
    case LED_GREEN:
      switch(state){
        case ON:
          GPIO_PinOut(RGB,LED_GREEN,HIGH);
          break;
        case OFF:
          GPIO_PinOut(RGB,LED_GREEN,LOW);
          break;
      }
    break;
  }
}

void RGB_DisAll(void){
	RGB_Output(LED_RED,OFF);
	RGB_Output(LED_GREEN,OFF);
	RGB_Output(LED_BLUE,OFF);
}
void RGB_Toggle(uint8_t led){
	switch(led){
		case LED_RED:
			TOG1B(RGB_PORT ,LED_RED);
		break;
		case LED_GREEN:
			TOG1B(RGB_PORT ,LED_GREEN);
		break;
		case LED_BLUE:
			TOG1B(RGB_PORT ,LED_BLUE);
		break;
	}
}
