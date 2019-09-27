#ifndef STM32_TIMER8_H
#define STM32_TIMER8_H
// ‰»Î≤∂ªÒ
#include "stm32f10x.h"


void timer8_PWMInit(void);
void PWM8Ch3WidthAdj(signed int offset);
void PWM8Ch4WidthAdj(signed int offset);
void PWM8Ch3WidthSet( int value);
void PWM8Ch4WidthSet( int value);

extern uint16_t Channel3Pulse, Channel4Pulse;



#endif //STM32_TIMER8_H
