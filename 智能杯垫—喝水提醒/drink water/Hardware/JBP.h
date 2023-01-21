#ifndef __ONEUART_H
#define __ONEUART_H
 
#include "sys.h"
 
#define SDA PBout(11)
 
void SendData ( u8 addr );    //发送函数。
void OnUart_GPIO(void);       //GPIO
 
#endif
