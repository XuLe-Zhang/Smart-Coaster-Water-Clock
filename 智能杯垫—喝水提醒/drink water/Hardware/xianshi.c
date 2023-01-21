#include "stm32f10x.h"                  // Device header
#include "OLED.h" 
#include "JBP.h"
#include "Delay.h" 


void OLED_WATCH(float Mark)
{

			if (Mark == 1)
			{
		SendData(0x0a);
		SendData(0x03);
		SendData(0x0b);
		Delay_ms(500);
		OLED_ShowString(3,5,"10Seconds");		
			}
			else if (Mark == 2)
			{
		SendData(0x0a);
		SendData(0x04);
		SendData(0x0b);
		Delay_ms(500);
		OLED_ShowString(3,1,"Time:30minutes");		
			}
			else if (Mark == 3)
			{
		SendData(0x0a);
		SendData(0x05);
		SendData(0x0b);
		Delay_ms(500);
		OLED_ShowString(3,1,"Time:60minutes");
			}			

}

void Sound_Sensor(uint16_t Seconds)
{
extern float Mark;
		if (Seconds < 10)
		{
         OLED_ShowString(2,1,"  Healthy Life  ");

		}
		else if (Mark == 1)
		{
			if (Seconds >= 10 & Seconds < 1800)
			{
			SendData(0x0a);
			SendData(0x02);
			SendData(0x0b);
			Delay_ms(1000);	
			OLED_ShowString(2,1,"PleaseDrinkWater");		
			}

		}
		else if (Mark == 2)
		{
			if (Seconds >= 1800 & Seconds < 3600)
			{
			SendData(0x0a);
			SendData(0x02);
			SendData(0x0b);
			Delay_ms(1000);
	        OLED_ShowString(2,1,"PleaseDrinkWater");			
			}
	
		}
		else if (Mark == 3)
		{
			if (Seconds >= 3600)
			{
			SendData(0x0a);
			SendData(0x02);
			SendData(0x0b);
			Delay_ms(1000);	
			OLED_ShowString(2,1,"PleaseDrinkWater");		
			}

		}
}
