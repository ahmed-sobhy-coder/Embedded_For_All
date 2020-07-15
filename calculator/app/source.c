#include "app.h"
#include "bluetooth.h"
#include "calc.h"
uint32_t sysclock;
UART_INIT_TYPE huart0;
UART_INIT_TYPE huart2;
int32_t previous = 0;

int main(void)
{
    PLL_init(CLK_40MHZ);
    sysclock = 40000000;
#if (LCD_4BIT_INTERFACE == 1)
    GPIO_PortInit(LCD_PORT, OUTPUT); //initialize portB as output
#else
                  GPIO_PortInit(LCD_DATA_PORT, OUTPUT); //initialize portB as output
            GPIO_PinInit(LCD_CONTROL_PORT, LCD_REGISTER_SELECT, OUTPUT);
            GPIO_PinInit(LCD_CONTROL_PORT, LCD_RW, OUTPUT);
            GPIO_PinInit(LCD_CONTROL_PORT, LCD_ENABLE, OUTPUT);
            LCD_4BIT_INTERFACE == 1
#endif
    RGB_Init(ALL);
    LCD_Init();
    huart0.BAUD_RATE = 9600; //baud rate
    huart0.CHAR_LEN = 8; //int8_tlength
    huart0.NSTOP_BIT = 1; //number of stop bits
    huart0.PARITY_BIT = 0; //parity is diabled
    huart0.TYPE = BOTH; //activate both RX & TX

    huart2.BAUD_RATE = 9600; //baud rate
    huart2.CHAR_LEN = 8; //int8_tlength
    huart2.NSTOP_BIT = 1; //number of stop bits
    huart2.PARITY_BIT = 0; //parity is diabled
    huart2.TYPE = BOTH; //activate both RX & TX

    Uart_Init(UT0, &huart0); //initalize uart 0
    Uart_Init(UT2, &huart2); //initialize uart2

    Uart_SendStrRcNl(UT0, "tiva 1 is ready.."); //print that TIVA is ready
    LCD_SendStr("tiva 1 is ready..");
    RGB_Out(LED_RED, HIGH);
    HC05_init(DATA_MODE);
    double result;
    int8_t str[20];
    int8_t opers[10];
    double fnums[10];
    double x=4,y=5;
    while (1)
    {
  /*      UART_GetStrRcNl(UT0, str, 20);
        if (rules(str) == 1)
        {
            handleParenthesis(str);
            if ((strIsContain(str, "ans") == 1)
                    || (strIsContain(str, "ANS")) == 1)
            {
                opers[0] = '$';
                extractOpers(str + strLen("ans"), opers + 1);
                extractFnums(str + strLen("ans"), fnums + 1, opers + 1);
            }
            else
            {
                extractOpers(str, opers);
            extractFnums(str, fnums, opers);
            }
           strCalc(fnums, opers);
           if (isFloat(fnums[0]))
            {
                Uart_SendFloat(UT0, fnums[0], 2);
            }
            else
            {
                Uart_SendInt(UT0, (int32_t) fnums[0]);
            }

        }
        else
        {
            print("try again\n");
        }*/
       // result=strToFloat("44.5");
    Uart_SendStr(UT0,floatToStrWithReturn(4.655, 3) );
        RGB_Out(LED_BLUE, HIGH);
       msDelay(1000);
       RGB_DisAll();
       msDelay(1000);
       RGB_Out(LED_RED, HIGH);
       msDelay(1000);
            RGB_DisAll();
            msDelay(1000);
            Uart_SendStr(UT0,floatToStrWithReturn(4.655, 3) );

    }


}
