/**************************************************************************
*
*	Purpose	:	Managing project's C file
*	Author	:	THAI VIET LE
*	Updated	:	1/7/2021
*	
***************************************************************************
*	Copyright (C) 2021 by THAI VIET LE
***************************************************************************
/**************************** STEPS TO FOLLOW *****************************
* 1.	Enable Timer Clock
* 2.	Set the prescalar and the ARR
* 3.	Enable the Timer and wait for the Update Flag to Set
**************************************************************************/

#include "timer.h"

void Timer_Init(void){
	// 1.	Enable Timer Clock
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;	// Enable the timer6 clock

	// 2.	Set the prescalar and the ARR
	TIM6->PSC = 84-1; 	//	84MHz/84 = 1MHz => 1us
	TIM6->ARR = 0xffff;	//	MAX ARR value

	// 3.	Enable the Timer and wait for the Update Flag to set
	TIM6->CR1 |= TIM_CR1_CEN; // Enable the Counter
	while (!(TIM6->SR & TIM_SR_UIF)); // UIF: Update interrupt flag
}