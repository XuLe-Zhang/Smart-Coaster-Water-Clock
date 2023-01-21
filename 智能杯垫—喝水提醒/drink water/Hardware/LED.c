#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;//创建结构体（局部变量）
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//开启时钟
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//输出模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;//选择引脚
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//输出速度
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	//GPIO_SetBits(GPIOC,GPIO_Pin_13);//设置高电平
	//GPIO_ResetBits(GPIOC,GPIO_Pin_13);//设置低电平
	//GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_RESET);//设置低电平
}

void LED_ON(void)
{
GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_SET);

}

void LED_OFF(void)
{
GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_RESET);

}

