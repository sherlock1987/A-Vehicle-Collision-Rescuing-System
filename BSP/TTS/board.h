#ifndef _STM32_BOARD_H
#define _STM32_BOARD_H

#include "stm32f10x.h"
#include "sys.h"

#define				LED0_Pin		GPIO_Pin_15//PA15

void board_Init(void);
void trig_Init(void);

#define				LED0_On()		{GPIO_ResetBits(GPIOA,GPIO_Pin_15);}
#define				LED0_Off()		{GPIO_SetBits(GPIOA,GPIO_Pin_15);}

#endif //_STM32_BOARD_H
