#include "board.h"


// void board_Init()
// {
// 	GPIO_InitTypeDef GPIO_InitStructure;
// 	//初始化输出控制IO PA15
// 	//开启IO口的时钟
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO|RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
// 						   RCC_APB2Periph_GPIOC ,ENABLE);
// 	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//启动普通IO口功能   一般PB3 PB4 和PA15这三个引脚的时候才需要用到这个功能
// 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
// 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
// 	GPIO_Init(GPIOA, &GPIO_InitStructure);
// }
// //中断触发
// void trig_Init()
// {

// 	GPIO_InitTypeDef GPIO_InitStructure; 
// 	EXTI_InitTypeDef EXTI_InitStructure;
// 	NVIC_InitTypeDef NVIC_InitStructure;

// 	/* config the extiline(PB0) clock and AFIO clock */
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO,ENABLE);

// 	/* 配置P[A|B|C|D|E]0为中断源 */
// 	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;//外部中断线0中断
// 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;//抢占优先级
// 	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//响应优先级
// 	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
// 	NVIC_Init(&NVIC_InitStructure);	
// 	
// 	//中断触发引脚
// 	/* EXTI line gpio config(PB0) */	
// 	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;       
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	 // 上拉输入
// 	GPIO_Init(GPIOB, &GPIO_InitStructure);
// 	
// 	/* EXTI line(PB0) mode config */
// 	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0); //选择B0管教为事件输出
// 	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
// 	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
// 	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿中断
// 	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
// 	EXTI_Init(&EXTI_InitStructure); 


// 	/* Configure one bit for preemption priority */
// //	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

// 	
// 	//中断数据接收引脚
// 	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;       
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	 // 上拉输入
// 	GPIO_Init(GPIOA, &GPIO_InitStructure);
// 	
// 	
// }
