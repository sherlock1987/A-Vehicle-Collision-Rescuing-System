#ifndef __USART1_H
#define	__USART1_H

#include "stm32f10x.h"
#include <stdio.h>
/****************************************
 * 文件名  ：usart1.c
 * 实验平台：野火STM32开发板
 * 硬件连接：------------------------
 *          | PA9  - USART1(Tx)      |
 *          | PA10 - USART1(Rx)      |
 *          | PA2  - USART2(Tx)      |
 *          | PA3  - USART2(Rx)      |
 *          | PB10 - USART3(Tx)      |
 *          | PB11 - USART3(Rx)      |
 *           ------------------------
**********************************************************************************/

void USART1_Init(void);
void USART2_Init(void);
void USART3_Init(void);

void usart1_SendStr(char *p);
void usart1_SendByte(char dat);
void usart2_SendByte(char dat);
void usart2_SendStr(char *p);
void usart3_SendByte(char dat);
void usart3_SendStr(char *p);

int fputc(int ch, FILE *f);


#endif /* __USART1_H */
