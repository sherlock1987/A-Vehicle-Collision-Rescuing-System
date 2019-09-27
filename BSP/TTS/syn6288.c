#include "syn6288.h"
#include "board.h"

char syn_state=0;
void syn_Delaynms(unsigned char n);


void syn6288_Init()
{
	USART3_Init();
}

void syn6288_SpeakStr(char *text,char MusicID)	//MusicID为需要播放的背景音乐变化，0不播放  
{
	char FrameHead[5];		//?						 
	int  cnt=0;          //?
	char length=0;       //?          
	char check=0;	       //?         

	length=strlen(text);           

	FrameHead[0]=0xfd;		 //构造针帧头  
	FrameHead[1]=0x00;		   //构造数据区长度的高字节
	FrameHead[2]=length+3;	   //构造数据区长度的低字节
	FrameHead[3]=01;		      //构成命令字合成播放命令
	FrameHead[4]=00+(MusicID<<3);	//GB2312			   
  
	for(cnt=0;cnt<5;cnt++)		  //依次发送构造五个帧头的字节	   
	{
		check=check^(FrameHead[cnt]);   //对发送字节进行异或校验
		syn6288_SendByte(FrameHead[cnt]);	
	}	
	   
	for(cnt=0;cnt<length;cnt++)		  //依次发送待合成的文本数据  
	{
		check=check^(*text);			 //对发送文本字节进行异或校验  	
		syn6288_SendByte(*text);				
		text++;          
	}
	syn6288_SendByte(check);	//最后发送校检字节	
	syn_state=1;
	while(syn_state);
	syn_Delaynms(8);
	
}

void syn_Delaynms(unsigned char n)
{
	int x;
	while(n--)
	{
		for(x=0;x<20000;x++)
		{
			
		}		
	}

}

// 		uchar speakID[]={黑龙江科技大学主楼，黑龙江科技大学18舍，黑龙江科技大学图书馆}；
// double jd[]={"36.0255456"};
void syn_Release()    //释放
{
	syn_state=0;//idle
}

static char u2recdat;    //静态 字符型 
char ledstate=0;
//串口中断，用于响应syn6288返回命令
void USART3_IRQHandler()
{
	if(USART_GetITStatus(USART3,USART_IT_RXNE)!= RESET) //确保是否产生了中断  
	{  	   
		u2recdat=USART_ReceiveData(USART3);

		if(u2recdat==SYN6288_ACK_IDLE)
		{
			syn_state=0;//idle
	
		}
	}

}
