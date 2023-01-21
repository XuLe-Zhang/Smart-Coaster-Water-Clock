#ifndef __KEY_H
#define __KEY_H

void Key_Init(void);
u8 Key_Scan(void);
//uint8_t Get_Num(void);

#define KEY1 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)
#define KEY1_PRES 	1	//KEY0按下
#endif
