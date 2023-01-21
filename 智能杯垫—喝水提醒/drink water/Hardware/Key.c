#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Key.h"
uint8_t KeyNum = 0;
void Key_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

u8 Key_Scan(void)
{
	static u8 key_up=1;//按键按松开标志
	if (key_up && KEY1 == 0)//按键按下
	{
		Delay_ms(10);
		key_up = 0;
		if (KEY1 == 0)
		{
			return KEY1_PRES;
//		Delay_ms(50);
//		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8) == 1);
//		Delay_ms(50);
		}
		
	}
else if(KEY1 == 0)key_up = 1;

return 0;

	
}

//uint8_t Get_Num(void)
//{
//return KeyNum;
//}
