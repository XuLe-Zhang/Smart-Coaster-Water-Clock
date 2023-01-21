#include "stm32f10x.h"                  // Device header
#include "Delay.h" 
#include "OLED.h" 
#include "Key.h"
#include "Timer.h"
#include "CountSensor.h"
#include "xianshi.h"
#include "JBP.h"

uint8_t Num;
uint16_t Seconds;
float Mark;

int main(void)
	
{
CountSensor_Init();	

OLED_Init();	
Timer_Init();
TIM_Cmd(TIM2, DISABLE);	
Key_Init();
OnUart_GPIO();	
OLED_ShowString(1,3,"Main Interface");
OLED_ShowString(4,1,"Sec:");	
OLED_ShowString(3,1,"Time:");	
Mark = 0;
	while(1)
	{
		
OLED_ShowNum(4,5,Seconds,5);
		Num =Key_Scan();
		if (Num == 1)
		{
			Mark += 1;
			OLED_WATCH(Mark);
			if (Mark > 3)
			{
				Mark = 0;
			}

		}
		
       Sound_Sensor(Seconds);
		
	}

}

void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		Seconds ++;
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}

void EXTI15_10_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line14) == SET)
	{
		/*如果出现数据乱跳的现象，可再次判断引脚电平，以避免抖动*/
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 1)//TCRT5000无反射
			{

			
        
				TIM_Cmd(TIM2, DISABLE);
				Seconds = 0;
			}
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0)//TCRT5000有反射
			{
			TIM2->CNT = 0;
		TIM_Cmd(TIM2, ENABLE);		
		
		
			}
EXTI_ClearITPendingBit(EXTI_Line14);
	}
}

