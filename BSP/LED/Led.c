/**********************************************************************************
 * 文件名  ：led.c
 * 描述    ：led 应用函数库         
 * 实验平台：NiRen_TwoHeart系统板
 * 硬件连接：  PB5 -> LED1     
 *             PB6 -> LED2     
 *             PB7 -> LED3    
 *             PB8 -> LED3    
 * 库版本  ：ST_v3.5
**********************************************************************************/

#include "Led.h"
#include "usart.h"
	   
/*******************************************************************************
* 函数名  : GPIO_Config
* 描述    : LED 和PWR_MG323 IO配置
* 输入    : 无
* 输出    : 无
* 返回    : 无 
* 说明    : LED(1~4)的IO口分别是:PB12 PB13 PB14
						A7初始化：           A1,PWM脉冲开机
																 A4,RESET
*******************************************************************************/
void Led_GPIO_Config(void)/////LED:  PB12,PB13,PB14//////继电器 a11 a12
{
	/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED的外设时钟*/
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA, ENABLE); 
									   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  	/* 开漏输出 */
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  	/* 开漏输出 */
		GPIO_Init(GPIOA, &GPIO_InitStructure);
			
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  	/* 开漏输出 */
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  	/* 开漏输出 */
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  	/* 开漏输出 */
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		GPIO_ResetBits(GPIOB,GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14);//关闭ALL_LED 
		GPIO_ResetBits(GPIOA,GPIO_Pin_1|GPIO_Pin_6|GPIO_Pin_11|GPIO_Pin_12);
		GPIO_ResetBits(GPIOA,GPIO_Pin_6);

}

/*点亮LED1.PB0*/
void LED1_ON(void) 
{
	GPIO_ResetBits(LED_PORT,LED1);
}

/*关闭LED1.PB0*/
void LED1_OFF(void)
{
	GPIO_SetBits(LED_PORT,LED1);
}

/*点亮LED2.PB6*/
void LED2_ON(void)  
{
	GPIO_ResetBits(GPIOC,GPIO_Pin_4);
}

/*关闭LED2.PB6*/
void LED2_OFF(void)
{
	GPIO_SetBits(GPIOC,GPIO_Pin_4);
}

/*点亮LED3.PB7*/
void LED3_ON(void)   
{
	GPIO_ResetBits(GPIOC,GPIO_Pin_3);
}

/*关闭LED3.PB7*/
void LED3_OFF(void)  
{
	GPIO_SetBits(GPIOC,GPIO_Pin_3);
}







/*点亮LED4.PB8*/
void LED4_ON(void) 
{
	GPIO_SetBits(LED_PORT,LED4);
}

/*关闭LED4.PB8*/
void LED4_OFF(void) 
{
	GPIO_ResetBits(LED_PORT,LED4); 
}

/*点亮ALL_LED*/
void LED_ALL_ON(void)
{
	GPIO_SetBits(LED_PORT,LED_ALL);
}
/*关闭ALL_LED*/
void LED_ALL_OFF(void)  
{
	GPIO_ResetBits(LED_PORT,LED_ALL); 
}

