#include "app.h"
#include "servo.h"
uint32_t sysclock;
int main(void)
{
	PLL_init(CLK_40MHZ);
	sysclock = 40000000;
#if (LCD_4BIT_INTERFACE == 1)
//	GPIO_PortInit(LCD_PORT, OUT);//initialize portB as output
#else
	GPIO_PortInit(LCD_DATA_PORT, OUT);//initialize portB as output
	GPIO_PinInit(LCD_CONTROL_PORT, LCD_REGISTER_SELECT, OUT);
	GPIO_PinInit(LCD_CONTROL_PORT, LCD_RW, OUT);
	GPIO_PinInit(LCD_CONTROL_PORT, LCD_ENABLE, OUT);
	LCD_4BIT_INTERFACE == 1
#endif 
  LCD_Init();
	RGB_LedInit(ALL);
	GPIO_PortInit(PORTB,OUT);
	GPIO_PinInit(PORTD,PD0,OUT);
	GPIO_PinInit(PORTD,PD1,OUT);
  GPIO_PinInit(PORTD,PD2,OUT);
	GPIO_PinInit(PORTD,PD3,OUT);
	GPIO_PinInit(PORTC,PC4,OUT);
	GPIO_PinInit(PORTC,PC5,OUT);
  GPIO_PinInit(PORTC,PC6,OUT);
	GPIO_PinInit(PORTC,PC7,OUT);


while (1) {
    GPIO_PortOutput(PORTB,DIGITAL_LOW);
GPIO_PinOut(PORTD,PD0,HIGH);
GPIO_PinOut(PORTD,PD1,HIGH);
GPIO_PinOut(PORTD,PD2,DIGITAL_LOW);
GPIO_PinOut(PORTD,PD3,DIGITAL_LOW);
GPIO_PinOut(PORTC,PC4,DIGITAL_LOW);
GPIO_PinOut(PORTC,PC5,DIGITAL_LOW);
GPIO_PinOut(PORTC,PC6,DIGITAL_LOW);
GPIO_PinOut(PORTC,PC7,DIGITAL_LOW);
}
}
































/*int main(void)
{
	PLL_init(CLK_40MHZ);
  sysclock=40000000;
	SERVO_Init(PORTD,M1PWM0,angle_0);
	uint16_t counter;
	while(1){
		for(counter=700;counter<2350;counter+=50)
		{
	  SERVO_AngleUpdate(PORTD,M1PWM0,counter);
	  _delay_S_(1);
		}

		SERVO_AngleUpdate(PORTD,M1PWM0,angle_0);
		_delay_ms_(1000);
	  SERVO_AngleUpdate(PORTD,M1PWM0,angle_90);
		_delay_ms_(1000);
		SERVO_AngleUpdate(PORTD,M1PWM0,angle_0);
		_delay_ms_(1000);
		SERVO_AngleUpdate(PORTD,M1PWM0,angle_neg_90);
		_delay_ms_(1000);
	}

}*/
/*//=================== .const ===============================//
  volatile static const long mmalt_const=1000;//.const
  volatile static const long mmmalt_const=1000;//.const
  //==========================data======================//
  volatile char mmmmalt_data=5;//.data
   volatile long mmmmmalt_data=5;//.data
//============================= .bss ===============/
  volatile char mmmalt_bss;//.bss
  volatile const long malt_bss;   //.bss
//=====================================================/

int main(void)
{
	 volatile const char x=5 ;
	 volatile int y =malt_bss ;
	 volatile int z=100+mmalt_const;
	 z++;
	 volatile int l=100;
	 l++;
	 y++;
	 mmmalt_bss+=malt_bss+malt_bss+mmalt_const;
	 mmmmalt_data++;
	 mmmmmalt_data++;
   //mmmalt=-mmalt;
	 mmmmmalt_data=mmmalt_const+mmmalt_bss;
	 y++;
	 y++;
	 y++;
  return 0;
}
*/

