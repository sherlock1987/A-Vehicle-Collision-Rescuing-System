#include "timer1.h"

TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
TIM_OCInitTypeDef  		TIM_OCInitStructure;
uint16_t T1TimerPeriod = 0;
uint16_t T1Channel1Pulse = 0, T1Channel2Pulse = 0, T1Channel3Pulse = 0, T1Channel4Pulse = 0;

static void RCC_Configuration(void);
static void GPIO_Configuration(void);

void timer1_PWMInit()
{
	/* System Clocks Configuration */
	RCC_Configuration();
	
	/* GPIO Configuration */
	GPIO_Configuration();
	
	/*The objective is to generate 7 PWM signal at 17.57 KHz:
	 - TIM1_Period = (SystemCoreClock / 17570) - 1
	The channel 1 and channel 1N duty cycle is set to 50%
	The channel 2 and channel 2N duty cycle is set to 37.5%
	The channel 3 and channel 3N duty cycle is set to 25%
	The channel 4 duty cycle is set to 12.5%
	The Timer pulse is calculated as follows:
	 - ChannelxPulse = DutyCycle * (TIM1_Period - 1) / 100
	----------------------------------------------------------------------- */
	/* Compute the value to be set in ARR regiter to generate signal frequency at 17.57 Khz */
	T1TimerPeriod = 800 - 1;
	/* Compute CCR1 value to generate a duty cycle at 50% for channel 1 and 1N */
	T1Channel1Pulse = 50;
	/* Compute CCR2 value to generate a duty cycle at 37.5%  for channel 2 and 2N */
	T1Channel2Pulse = 100;
	/* Compute CCR3 value to generate a duty cycle at 25%  for channel 3 and 3N */
	T1Channel3Pulse = 500;
	/* Compute CCR4 value to generate a duty cycle at 12.5%  for channel 4 */
	T1Channel4Pulse = 700;
	
	/* Time Base configuration */
	TIM_TimeBaseStructure.TIM_Prescaler = 72-1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = T1TimerPeriod;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	
	/* Channel 1, 2,3 and 4 Configuration in PWM mode */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 	T1Channel1Pulse;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset;
	
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);

	
	TIM_OCInitStructure.TIM_Pulse = T1Channel4Pulse;
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);
	
	/* TIM1 counter enable */
	TIM_Cmd(TIM1, ENABLE);
	
	/* TIM1 Main Output Enable */
	TIM_CtrlPWMOutputs(TIM1, ENABLE);
		
}

/**
  * @brief  Configures the different system clocks.
  * @param  None
  * @retval None
  */
static void RCC_Configuration(void)
{
  /* TIM1, GPIOA, GPIOB, GPIOE and AFIO clocks enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1 | RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOE|
                         RCC_APB2Periph_GPIOB |RCC_APB2Periph_AFIO, ENABLE);
}

/**
  * @brief  Configure the TIM1 Pins.
  * @param  None
  * @retval None
  */
static void GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* GPIOA Configuration: Channel 1, 2 and 3 as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* GPIOB Configuration: Channel 1N, 2N and 3N as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

}







