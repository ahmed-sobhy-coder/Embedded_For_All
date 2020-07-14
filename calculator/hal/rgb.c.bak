#include "rgb.h"

void RGB_Led_Init(uint8_t led){
  switch(led){
    case LED_RED:
      GPIO_Pin_Init(RGB ,LED_RED,DIGITAL_OUTPUT);
      break;
    case LED_BLUE:
      GPIO_Pin_Init(RGB ,LED_BLUE,DIGITAL_OUTPUT);
      break;
    case LED_GREEN:
      GPIO_Pin_Init(RGB ,LED_GREEN,DIGITAL_OUTPUT);
      break;
    default:
      GPIO_Pin_Init(RGB,LED_RED,DIGITAL_OUTPUT);
      GPIO_Pin_Init(RGB,LED_BLUE,DIGITAL_OUTPUT);
      GPIO_Pin_Init(RGB,LED_GREEN,DIGITAL_OUTPUT);
  }
}
void RGB_Led_Output(uint8_t led,uint8_t state){
  switch(led){
    case LED_RED:
      switch(state){
        case ON:
          GPIO_INDEX_Output(RGB,LED_RED,DIGITAL_HIGH);
          break;
        case OFF:
          GPIO_INDEX_Output(RGB,LED_RED,DIGITAL_LOW);
          break;
      }
    break;
    case LED_BLUE:
      switch(state){
        case ON:
          GPIO_INDEX_Output(RGB,LED_BLUE,DIGITAL_HIGH);
          break;
        case OFF:
          GPIO_INDEX_Output(RGB,LED_BLUE,DIGITAL_LOW);
          break;
      }
    break;
    case LED_GREEN:
      switch(state){
        case ON:
          GPIO_INDEX_Output(RGB,LED_GREEN,DIGITAL_HIGH);
          break;
        case OFF:
          GPIO_INDEX_Output(RGB,LED_GREEN,DIGITAL_LOW);
          break;
      }
    break;
  }
}

void RGB_Disable_All(void){
	 RGB_Led_Output(LED_RED,OFF);	
	 RGB_Led_Output(LED_GREEN,OFF);	
	 RGB_Led_Output(LED_BLUE,OFF);
}
void RGB_Led_Toggle(uint8_t led){
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
