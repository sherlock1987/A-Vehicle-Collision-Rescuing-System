#ifndef __UART4_H
#define	__UART4_H

#include "stm32f10x.h"
#include <stdio.h>





void UART4_Config(void);
//int fputc(int ch, FILE *f);
void UART4_printf(USART_TypeDef* USARTx, char *Data,...);


extern char *get_rebuff(uint8_t *len);
extern void clean_rebuff(void);

#endif /* __UART4_H */
