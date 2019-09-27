/**********************************************************************************
 * 文件名  ：key.c
 * 描述    ：按键扫描(系统滴答时钟SysTick实现扫描延时)
 * 实验平台：NiRen_TwoHeart系统板
 * 硬件连接：  PC10 -> KEY1     
 *             PC11 -> KEY2       
 * 库版本  ：ST_v3.5
**********************************************************************************/

#include "key.h" 
#include "SysTick.h"
#include "Led.h"

/*******************************************************************************
* 函数名  : Key_GPIO_Config
* 描述    : KEY IO配置
* 输入    : 无
* 输出    : 无
* 返回    : 无 
* 说明    : KEY(1~2)的IO口分别是:PC10,PC11
*******************************************************************************/
void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启按键端口（PC）的时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4; 
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	

}

void RCC_Configuration(void)
{
    SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
}


void EXTI_Configuration(void)
{
  EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_ClearITPendingBit(EXTI_Line4);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource4); 
	EXTI_InitStructure.EXTI_Line=EXTI_Line4;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	EXTI_ClearITPendingBit(EXTI_Line5);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource5); 
	EXTI_InitStructure.EXTI_Line=EXTI_Line5;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
//	EXTI_ClearITPendingBit(EXTI_Line0);
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource0); 
//	EXTI_InitStructure.EXTI_Line=EXTI_Line0;
//	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
//	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
//	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
//	EXTI_Init(&EXTI_InitStructure);
}

void NVIC_Configuration(void)
{
   	NVIC_InitTypeDef NVIC_InitStructure; 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 

	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);
	
//	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn; 
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
//	NVIC_Init(&NVIC_InitStructure);
}


/*******************************************************************************
* 函数名  : Key_Detection
* 描述    : 按键按下检测
* 输入    : GPIOx：按键对应的GPIO，GPIO_Pin：对应按键端口
* 输出    : 无
* 返回    : KEY_DOWN(0):对应按键按下，KEY_UP(1):对应按键没按下
* 说明    : KEY(1~2)的IO口分别是:PC10,PC11
*******************************************************************************/
u8 Key_Down_Detection(GPIO_TypeDef* GPIOx, u16 GPIO_Pin)
{			
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN)	//检测是否有按键按下 
	{	   
		Delay_nMs(10);	//延时消抖		
		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN)	//检测是否有按键按下   
		{	 
			while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN);	//等待按键释放  
			return KEY_DOWN;	 
		}
		else
		{
			return KEY_UP;
		}
	}
	else
	{
		return KEY_UP;
	}
}

uint8_t Key_Scan(GPIO_TypeDef* GPIOx,u16 GPIO_Pin,uint8_t Down_state)
{			
	/*检测是否有按键按下 */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == Down_state ) 
	{	   
		/*延时消抖*/
		Key_Delay(10000);		
//		LED1_ON();
		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == Down_state )  
		{	 
			/*等待按键释放 */
			while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == Down_state);   
			return 	1;	 
		}
		else
			return 0;
	}
	else
		return 0;
}
/*******************************************************************************
* 函数名  : Key_Down_Scan
* 描述    : 按键按下扫描
* 输入    : 无
* 输出    : 0：没有按键按下，1：按键按下
* 返回    : 无 
* 说明    : KEY(1~2)的IO口分别是:PC10,PC11
*******************************************************************************/
u8 Key_Down_Scan(void)
{
	u16 downflag=0;
	u8 value=0;

  	downflag=GPIO_ReadInputData(KEY_PORT);
	if((downflag & 0x0c00) != 0x0c00)	//检测是否有按键按下 
	{	   
		Delay_nMs(10);	//延时消抖	
		downflag = GPIO_ReadInputData(KEY_PORT) & 0x0c00;	
		if(downflag != 0x0c00 )	//检测是否有按键按下   
		{	 
			if((downflag & 0x0400) == 0) value |= 0x01;
			if((downflag & 0x0800) == 0) value |= 0x02; 	 
		}		
	}	

	return value;
}
static void Key_Delay(__IO u32 nCount)
{
	for(; nCount != 0; nCount--);
} 



