#include "board.h"


// void board_Init()
// {
// 	GPIO_InitTypeDef GPIO_InitStructure;
// 	//��ʼ���������IO PA15
// 	//����IO�ڵ�ʱ��
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO|RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
// 						   RCC_APB2Periph_GPIOC ,ENABLE);
// 	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//������ͨIO�ڹ���   һ��PB3 PB4 ��PA15���������ŵ�ʱ�����Ҫ�õ��������
// 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
// 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
// 	GPIO_Init(GPIOA, &GPIO_InitStructure);
// }
// //�жϴ���
// void trig_Init()
// {

// 	GPIO_InitTypeDef GPIO_InitStructure; 
// 	EXTI_InitTypeDef EXTI_InitStructure;
// 	NVIC_InitTypeDef NVIC_InitStructure;

// 	/* config the extiline(PB0) clock and AFIO clock */
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO,ENABLE);

// 	/* ����P[A|B|C|D|E]0Ϊ�ж�Դ */
// 	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;//�ⲿ�ж���0�ж�
// 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;//��ռ���ȼ�
// 	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//��Ӧ���ȼ�
// 	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
// 	NVIC_Init(&NVIC_InitStructure);	
// 	
// 	//�жϴ�������
// 	/* EXTI line gpio config(PB0) */	
// 	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;       
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	 // ��������
// 	GPIO_Init(GPIOB, &GPIO_InitStructure);
// 	
// 	/* EXTI line(PB0) mode config */
// 	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0); //ѡ��B0�ܽ�Ϊ�¼����
// 	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
// 	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
// 	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //�½����ж�
// 	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
// 	EXTI_Init(&EXTI_InitStructure); 


// 	/* Configure one bit for preemption priority */
// //	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

// 	
// 	//�ж����ݽ�������
// 	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;       
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	 // ��������
// 	GPIO_Init(GPIOA, &GPIO_InitStructure);
// 	
// 	
// }
