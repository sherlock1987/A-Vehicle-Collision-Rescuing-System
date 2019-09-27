#include "syn6288.h"
#include "board.h"

char syn_state=0;
void syn_Delaynms(unsigned char n);


void syn6288_Init()
{
	USART3_Init();
}

void syn6288_SpeakStr(char *text,char MusicID)	//MusicIDΪ��Ҫ���ŵı������ֱ仯��0������  
{
	char FrameHead[5];		//?						 
	int  cnt=0;          //?
	char length=0;       //?          
	char check=0;	       //?         

	length=strlen(text);           

	FrameHead[0]=0xfd;		 //������֡ͷ  
	FrameHead[1]=0x00;		   //�������������ȵĸ��ֽ�
	FrameHead[2]=length+3;	   //�������������ȵĵ��ֽ�
	FrameHead[3]=01;		      //���������ֺϳɲ�������
	FrameHead[4]=00+(MusicID<<3);	//GB2312			   
  
	for(cnt=0;cnt<5;cnt++)		  //���η��͹������֡ͷ���ֽ�	   
	{
		check=check^(FrameHead[cnt]);   //�Է����ֽڽ������У��
		syn6288_SendByte(FrameHead[cnt]);	
	}	
	   
	for(cnt=0;cnt<length;cnt++)		  //���η��ʹ��ϳɵ��ı�����  
	{
		check=check^(*text);			 //�Է����ı��ֽڽ������У��  	
		syn6288_SendByte(*text);				
		text++;          
	}
	syn6288_SendByte(check);	//�����У���ֽ�	
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

// 		uchar speakID[]={�������Ƽ���ѧ��¥���������Ƽ���ѧ18�ᣬ�������Ƽ���ѧͼ���}��
// double jd[]={"36.0255456"};
void syn_Release()    //�ͷ�
{
	syn_state=0;//idle
}

static char u2recdat;    //��̬ �ַ��� 
char ledstate=0;
//�����жϣ�������Ӧsyn6288��������
void USART3_IRQHandler()
{
	if(USART_GetITStatus(USART3,USART_IT_RXNE)!= RESET) //ȷ���Ƿ�������ж�  
	{  	   
		u2recdat=USART_ReceiveData(USART3);

		if(u2recdat==SYN6288_ACK_IDLE)
		{
			syn_state=0;//idle
	
		}
	}

}
