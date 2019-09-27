/**********************************************************************************
 * �ļ���  ��key.c
 * ����    ������ɨ��(ϵͳ�δ�ʱ��SysTickʵ��ɨ����ʱ)
 * ʵ��ƽ̨��NiRen_TwoHeartϵͳ��
 * Ӳ�����ӣ�  PC10 -> KEY1     
 *             PC11 -> KEY2       
 * ��汾  ��ST_v3.5
**********************************************************************************/

#include "key.h" 
#include "SysTick.h"
#include "Led.h"

/*******************************************************************************
* ������  : Key_GPIO_Config
* ����    : KEY IO����
* ����    : ��
* ���    : ��
* ����    : �� 
* ˵��    : KEY(1~2)��IO�ڷֱ���:PC10,PC11
*******************************************************************************/
void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*���������˿ڣ�PC����ʱ��*/
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
* ������  : Key_Detection
* ����    : �������¼��
* ����    : GPIOx��������Ӧ��GPIO��GPIO_Pin����Ӧ�����˿�
* ���    : ��
* ����    : KEY_DOWN(0):��Ӧ�������£�KEY_UP(1):��Ӧ����û����
* ˵��    : KEY(1~2)��IO�ڷֱ���:PC10,PC11
*******************************************************************************/
u8 Key_Down_Detection(GPIO_TypeDef* GPIOx, u16 GPIO_Pin)
{			
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN)	//����Ƿ��а������� 
	{	   
		Delay_nMs(10);	//��ʱ����		
		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN)	//����Ƿ��а�������   
		{	 
			while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN);	//�ȴ������ͷ�  
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
	/*����Ƿ��а������� */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == Down_state ) 
	{	   
		/*��ʱ����*/
		Key_Delay(10000);		
//		LED1_ON();
		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == Down_state )  
		{	 
			/*�ȴ������ͷ� */
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
* ������  : Key_Down_Scan
* ����    : ��������ɨ��
* ����    : ��
* ���    : 0��û�а������£�1����������
* ����    : �� 
* ˵��    : KEY(1~2)��IO�ڷֱ���:PC10,PC11
*******************************************************************************/
u8 Key_Down_Scan(void)
{
	u16 downflag=0;
	u8 value=0;

  	downflag=GPIO_ReadInputData(KEY_PORT);
	if((downflag & 0x0c00) != 0x0c00)	//����Ƿ��а������� 
	{	   
		Delay_nMs(10);	//��ʱ����	
		downflag = GPIO_ReadInputData(KEY_PORT) & 0x0c00;	
		if(downflag != 0x0c00 )	//����Ƿ��а�������   
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



