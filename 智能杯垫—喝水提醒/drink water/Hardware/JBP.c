#include "stm32f10x.h"
#include "JBP.h"
#include "delay.h"

 
///
//函	  OnUart_GPIO(void)
//功	  能：语音模块一线串口IO口
//输入参数: void
//输出参数: void
//说	  明：
//
void OnUart_GPIO(void)
{
	//GPIO_InitTypeDef GPIO_InitStructure;
 
		RCC->APB2ENR|=1<<3;   //GPIOB
		
		//GPIOB.11
		GPIOB->CRH&=0xFFFF0FFF;     //清零 
		GPIOB->CRH|=0x00003000;     //推挽输出	50MHZ
		GPIOB->ODR=~(1<<11);        //B.11低	
 
	
}
///
//函	  数：SendData(u8 addr)
//功	  能：语音模块一线串口
//输入参数: addr要发送的0x数
//输出参数: void
//说	  明：
//
void SendData ( u8 addr )//发送函数。
{
    u8 i;
 
     /*发送时关掉中断，防止中断影响时序  */
    SDA = 1; /*开始拉高*/
    Delay_us ( 1000 );
    SDA = 0; /*开始引导码*/
    Delay_us ( 3200 );/*此处延时最少要大于2ms*/
    for ( i = 0; i < 8; i++ ) /*总共8位数据  */
    {
        SDA = 1;
        if ( addr & 0x01 ) /*3:1表示数据位1,每个位用两个脉冲表示  */
        {
            Delay_us ( 600 );
            SDA = 0;
            Delay_us ( 200 );
        }
        else              /*1：3表示数据位0 ,每个位用两个脉冲表示  */
        {
            Delay_us ( 200 );
            SDA = 0;
            Delay_us ( 600 );
        }
        addr >>= 1;
    }
    SDA = 1;
    
		//恢复中断
}
