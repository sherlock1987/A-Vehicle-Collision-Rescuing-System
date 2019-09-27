#ifndef _STM32_SYN6288_H
#define _STM32_SYN6288_H
/*	
	syn6288.h
	
*/
#include "stm32f10x.h"
#include "usart.h"
#include "string.h"

#define syn6288_SendByte(x)		usart3_SendByte(x)
#define syn6288_SendStr(x)		usart3_SendStr(x)

#define SYN6288_CMD_SPEAK		0x01
#define SYN6288_CMD_STOP		0x02
#define SYN6288_CMD_PAUSE		0x03
#define SYN6288_CMD_RESTART		0x04
#define SYN6288_CMD_QUERY		0x21
#define SYN6288_CMD_POWERDOWN	0x88
#define SYN6288_CMD_SETBAULD	0x31	

#define SYN6288_ACK_INIOK		0X4A	
#define SYN6288_ACK_RECOK		0X41
#define SYN6288_ACK_RECERR		0X45
#define SYN6288_ACK_SPEAK		0X4E			
#define SYN6288_ACK_IDLE		0X4F			

void syn6288_SpeakStr(char *text,char MusicID);//MusicID为需要播放的背景音乐变化，0不播放  
void syn_Release(void);

void syn6288_Init(void);

typedef		unsigned char	uchar;


#endif //_STM32_SYN6288_H
