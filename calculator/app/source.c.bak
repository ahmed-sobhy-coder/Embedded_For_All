#include "app.h"
#include "servo.h"
uint32_t sysclock;
/*
   lcd string rotation function 
*/

void LCD_StrRot(int8_t*str)
{
	uint8_t lstChrIndx= strLen(str)-1;
	uint8_t strLength = strLen(str);
	uint8_t nodots =16;
	uint8_t count=0,temp;
	uint8_t count3=0;
	uint8_t lstChrDot= nodots-strLength;
	uint8_t count2=0;
	int8_t flag=0;
	while(str[count]!='\0')
	{
	   LCD_SendChr(str[count++]);
		 msDelay(1);
	}
  for(count=0;count<16;count++)
  {
		if(count==lstChrDot+1){
		LCD_SendCmd((0x80 | (0x67-(count-1))) );//0x80 it is a command to set ddram address,
										 //row is the address of the second location in the row
		usDelay(37);//command execution time 
		LCD_SendChr(str[lstChrIndx-count2++]);
			LCD_ShiftDisplay(1);
					 msDelay(500);	
		
		}
		else if(count>lstChrDot)
    {
	  LCD_SendCmd((0x80 | (0x67-2)) );//0x80 it is a command to set ddram address,
										 //row is the address of the second location in the row
		usDelay(37);//command execution time 
		LCD_SendChr(str[lstChrIndx-count2++]);
					//	LCD_ShiftDisplay(1);
					 msDelay(500000);	
		}
		else{
	   LCD_ShiftDisplay(1);
		 msDelay(500);	
		}
	}
}
/*             lstnde    loop
   ahmed            4      0
    ahmed           5      1
     ahmed          6      2
      ahmed         7      3 
       ahmed        8      4 
        ahmed       9      5
         ahmed      10     6
          ahmed     11     7
           ahmed    12     8
            ahmed   13     9
             ahmed  14     10
              ahmed 15     11
               ahme 16     12
*/

int main(void)
{
	PLL_init(CLK_40MHZ);
	sysclock = 40000000;
#if (LCD_4BIT_INTERFACE == 1)
//	GPIO_Port_Init(LCD_PORT, DIGITAL_OUTPUT);//initialize portB as output
#else
	GPIO_Port_Init(LCD_DATA_PORT, DIGITAL_OUTPUT);//initialize portB as output
	GPIO_Pin_Init(LCD_CONTROL_PORT, LCD_REGISTER_SELECT, DIGITAL_OUTPUT);
	GPIO_Pin_Init(LCD_CONTROL_PORT, LCD_RW, DIGITAL_OUTPUT);
	GPIO_Pin_Init(LCD_CONTROL_PORT, LCD_ENABLE, DIGITAL_OUTPUT);
	LCD_4BIT_INTERFACE == 1
#endif 
  LCD_Init();
	RGB_Led_Init(ALL);
	GPIO_Port_Init(PORTB,DIGITAL_OUTPUT);
	GPIO_Pin_Init(PORTD,PD0,DIGITAL_OUTPUT);
	GPIO_Pin_Init(PORTD,PD1,DIGITAL_OUTPUT);
  GPIO_Pin_Init(PORTD,PD2,DIGITAL_OUTPUT);
	GPIO_Pin_Init(PORTD,PD3,DIGITAL_OUTPUT);
	GPIO_Pin_Init(PORTC,PC4,DIGITAL_OUTPUT);
	GPIO_Pin_Init(PORTC,PC5,DIGITAL_OUTPUT);
  GPIO_Pin_Init(PORTC,PC6,DIGITAL_OUTPUT);
	GPIO_Pin_Init(PORTC,PC7,DIGITAL_OUTPUT);


while (1) {
    GPIO_Port_Output(PORTB,DIGITAL_LOW);
GPIO_INDEX_Output(PORTD,PD0,DIGITAL_HIGH);
GPIO_INDEX_Output(PORTD,PD1,DIGITAL_HIGH);
GPIO_INDEX_Output(PORTD,PD2,DIGITAL_LOW);
GPIO_INDEX_Output(PORTD,PD3,DIGITAL_LOW);
GPIO_INDEX_Output(PORTC,PC4,DIGITAL_LOW);
GPIO_INDEX_Output(PORTC,PC5,DIGITAL_LOW);
GPIO_INDEX_Output(PORTC,PC6,DIGITAL_LOW);
GPIO_INDEX_Output(PORTC,PC7,DIGITAL_LOW);
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

