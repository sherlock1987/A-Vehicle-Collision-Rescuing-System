#include "sys.h"

volatile uint32_t systickcnt=0;

void sys_Init()//system init
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	
}

void systick_Init()
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
	if (SysTick_Config(SystemCoreClock / 1000000)) // 1us interrupt gap
	{
	 	while(1);
	}
	systick_Disable();

}
void systick_Enable()
{
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}
void systick_Disable()
{
	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;
}


void delaynus(int num)
{
	systickcnt=num;
	systick_Enable();
	while(systickcnt);	
}
void SetThreshodnus(int num)
{
	systickcnt=num;
	systick_Enable();

}
void SetThreshodnms(int num)
{
	systickcnt=num*1000;
	systick_Enable();

}

void delaynms(int num)
{
	systickcnt=num*1000;
	systick_Enable();
	while(systickcnt);	
}

void delayrus( unsigned int num) //软件计数延时
{
	char cnt;
	while(num--)
	{
		for(cnt=0;cnt<9;cnt++)
		{
		}

	}
}
void delayrms( unsigned int num) //软件计数延时
{
	while(num--)
	{
		delayrus(1000);
	}
	
}


/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval : None
  */
void SysTick_Handler(void)
{
	if(systickcnt>0)systickcnt--;
	else 
	{
	  	systickcnt=0;
		systick_Disable();
	}
	
}
