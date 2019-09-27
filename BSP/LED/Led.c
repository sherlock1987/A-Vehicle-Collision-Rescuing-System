/**********************************************************************************
 * �ļ���  ��led.c
 * ����    ��led Ӧ�ú�����         
 * ʵ��ƽ̨��NiRen_TwoHeartϵͳ��
 * Ӳ�����ӣ�  PB5 -> LED1     
 *             PB6 -> LED2     
 *             PB7 -> LED3    
 *             PB8 -> LED3    
 * ��汾  ��ST_v3.5
**********************************************************************************/

#include "Led.h"
#include "usart.h"
	   
/*******************************************************************************
* ������  : GPIO_Config
* ����    : LED ��PWR_MG323 IO����
* ����    : ��
* ���    : ��
* ����    : �� 
* ˵��    : LED(1~4)��IO�ڷֱ���:PB12 PB13 PB14
						A7��ʼ����           A1,PWM���忪��
																 A4,RESET
*******************************************************************************/
void Led_GPIO_Config(void)/////LED:  PB12,PB13,PB14//////�̵��� a11 a12
{
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED������ʱ��*/
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA, ENABLE); 
									   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  	/* ��©��� */
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  	/* ��©��� */
		GPIO_Init(GPIOA, &GPIO_InitStructure);
			
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  	/* ��©��� */
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  	/* ��©��� */
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  	/* ��©��� */
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		GPIO_ResetBits(GPIOB,GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14);//�ر�ALL_LED 
		GPIO_ResetBits(GPIOA,GPIO_Pin_1|GPIO_Pin_6|GPIO_Pin_11|GPIO_Pin_12);
		GPIO_ResetBits(GPIOA,GPIO_Pin_6);

}

/*����LED1.PB0*/
void LED1_ON(void) 
{
	GPIO_ResetBits(LED_PORT,LED1);
}

/*�ر�LED1.PB0*/
void LED1_OFF(void)
{
	GPIO_SetBits(LED_PORT,LED1);
}

/*����LED2.PB6*/
void LED2_ON(void)  
{
	GPIO_ResetBits(GPIOC,GPIO_Pin_4);
}

/*�ر�LED2.PB6*/
void LED2_OFF(void)
{
	GPIO_SetBits(GPIOC,GPIO_Pin_4);
}

/*����LED3.PB7*/
void LED3_ON(void)   
{
	GPIO_ResetBits(GPIOC,GPIO_Pin_3);
}

/*�ر�LED3.PB7*/
void LED3_OFF(void)  
{
	GPIO_SetBits(GPIOC,GPIO_Pin_3);
}







/*����LED4.PB8*/
void LED4_ON(void) 
{
	GPIO_SetBits(LED_PORT,LED4);
}

/*�ر�LED4.PB8*/
void LED4_OFF(void) 
{
	GPIO_ResetBits(LED_PORT,LED4); 
}

/*����ALL_LED*/
void LED_ALL_ON(void)
{
	GPIO_SetBits(LED_PORT,LED_ALL);
}
/*�ر�ALL_LED*/
void LED_ALL_OFF(void)  
{
	GPIO_ResetBits(LED_PORT,LED_ALL); 
}

