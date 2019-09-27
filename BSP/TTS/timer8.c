#include "timer8.h"

static TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
static TIM_OCInitTypeDef  		TIM_OCInitStructure;
static uint16_t 				T8TimerPeriod = 0;
//static uint16_t T8Channel1Pulse = 0, T8Channel2Pulse = 0; 
uint16_t T8Channel3Pulse = 0, T8Channel4Pulse = 0;

static void RCC_Configuration(void);
static void GPIO_Configuration(void);

void timer8_PWMInit()
{
	/* System Clocks Configuration */
	RCC_Configuration();
	
	/* GPIO Configuration */
	GPIO_Configuration();
	
	T8TimerPeriod = 10000 - 1;

	T8Channel3Pulse = 1520;
	T8Channel4Pulse = 1520;
	
	/* Time Base configuration */
	TIM_TimeBaseStructure.TIM_Prescaler = 72-1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = T8TimerPeriod;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	
	TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure);
	
	/* Channel 1, 2,3 and 4 Configuration in PWM mode */
	TIM_OCInitStructure.TIM_OCMode 		= TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState= TIM_OutputNState_Disable;
	TIM_OCInitStructure.TIM_OCPolarity 	= TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
	TIM_OCInitStructure.TIM_OCNIdleState= TIM_OCIdleState_Reset;
	

	TIM_OCInitStructure.TIM_Pulse = T8Channel3Pulse;
	TIM_OC3Init(TIM8, &TIM_OCInitStructure);
	
	TIM_OCInitStructure.TIM_Pulse = T8Channel4Pulse;
	TIM_OC4Init(TIM8, &TIM_OCInitStructure);
	
	/* TIM1 counter enable */
	TIM_Cmd(TIM8, ENABLE);
	
	/* TIM1 Main Output Enable */
	TIM_CtrlPWMOutputs(TIM8, ENABLE);
}
void PWM8Ch3WidthAdj(signed int offset)
{
	T8Channel3Pulse +=offset;
	if(T8Channel3Pulse>2120)T8Channel3Pulse=2120;
	if(T8Channel3Pulse<920)T8Channel3Pulse=920;	

	/* Channel 1, 2,3 and 4 Configuration in PWM mode */
	TIM_OCInitStructure.TIM_OCMode 		= TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState= TIM_OutputNState_Disable;
	TIM_OCInitStructure.TIM_OCPolarity 	= TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
	TIM_OCInitStructure.TIM_OCNIdleState= TIM_OCIdleState_Reset;
	

	TIM_OCInitStructure.TIM_Pulse = T8Channel3Pulse;
	TIM_OC3Init(TIM8, &TIM_OCInitStructure);			
}
void PWM8Ch3WidthSet( int value)
{
	if(value>2120)value=2120;
	if(value<920)value=920;	
	T8Channel3Pulse=value;
	/* Channel 1, 2,3 and 4 Configuration in PWM mode */
	TIM_OCInitStructure.TIM_OCMode 		= TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState= TIM_OutputNState_Disable;
	TIM_OCInitStructure.TIM_OCPolarity 	= TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
	TIM_OCInitStructure.TIM_OCNIdleState= TIM_OCIdleState_Reset;
	

	TIM_OCInitStructure.TIM_Pulse = T8Channel3Pulse;
	TIM_OC3Init(TIM8, &TIM_OCInitStructure);			
}
void PWM8Ch4WidthAdj(signed int offset)
{
	T8Channel4Pulse +=offset;
	if(T8Channel4Pulse>2120)T8Channel4Pulse=2120;
	if(T8Channel4Pulse<920) T8Channel4Pulse=920;	

	/* Channel 1, 2,3 and 4 Configuration in PWM mode */
	TIM_OCInitStructure.TIM_OCMode 		= TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState= TIM_OutputNState_Disable;
	TIM_OCInitStructure.TIM_OCPolarity 	= TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
	TIM_OCInitStructure.TIM_OCNIdleState= TIM_OCIdleState_Reset;
	
	TIM_OCInitStructure.TIM_Pulse = T8Channel4Pulse;
	TIM_OC4Init(TIM8,&TIM_OCInitStructure);
			
}
void PWM8Ch4WidthSet( int value)
{
	if(value>2120)value=2120;
	if(value<920)value=920;	
	T8Channel4Pulse=value;

	/* Channel 1, 2,3 and 4 Configuration in PWM mode */
	TIM_OCInitStructure.TIM_OCMode 		= TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState= TIM_OutputNState_Disable;
	TIM_OCInitStructure.TIM_OCPolarity 	= TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
	TIM_OCInitStructure.TIM_OCNIdleState= TIM_OCIdleState_Reset;
	
	TIM_OCInitStructure.TIM_Pulse = T8Channel4Pulse;
	TIM_OC4Init(TIM8,&TIM_OCInitStructure);
			
}




static void RCC_Configuration(void)
{
  /* TIM1, GPIOA, GPIOB, GPIOE and AFIO clocks enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);
}

static void GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* GPIOC Configuration: Channel 1, 2 and 3 as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


}







