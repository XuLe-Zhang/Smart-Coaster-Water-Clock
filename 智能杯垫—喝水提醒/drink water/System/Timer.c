#include "stm32f10x.h"                  // Device header

void Timer_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;//时基单元结构体
	NVIC_InitTypeDef NVIC_InitStructure;//NVIC结构体
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//开启时钟
	
	TIM_InternalClockConfig(TIM2);
	
	
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 10000 - 1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200 - 1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);//初始化时基单元
	
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);//清除TIMx的挂起标志
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//启用或禁用指定的TIM中断
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM2, ENABLE);
}

/*
void TIM2_IRQHandler(void)//定时器2的中断函数
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)//TIM_GetITStatus获取中断标志位
	{
		//语音播报播报
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
*/
