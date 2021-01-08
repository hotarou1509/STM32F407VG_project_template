/*
***************************************************************************
*
*	Purpose	:	Setup GPIO for STM32F40&VF
*	Author	:	THAI VIET LE
*	Updated	:	1/7/2021
*	
*************************************************************************** 
 	Copyright (C) 2021 by THAI VIET LE
 ************************************************************************** 
*/
/**************************** STEPS TO FOLLOW *****************************
* 1.	Enable GPIO Clock
* 2.	Set Pin as output mode
* 3.	Configure the Output mode
***************************************************************************
*/

#include "gpio.h"

void GPIO_Init(void){
	// 1. Enable GPIOD clock
	RCC->AHB1ENR |= (1<<3);

	// 2. Set the PIN PD13 as OUTPUT
	GPIOD->MODER |= (1<<24); // PD12
	GPIOD->MODER |= (1<<26); // PD13
	GPIOD->MODER |= (1<<28); // PD14
	GPIOD->MODER |= (1<<30); // PD115

	// 3. Configure the output mode
	GPIOD->OTYPER &= ~(1<<13); // bit 5=0 => Output push pull
	GPIOD->OSPEEDR |= (1<<27); // Pin PD13 as Fast Speed (1:0)
	GPIOD->PUPDR &= ~((1<<26) | (1<<27));
}

void Set_Pin(uint8_t level, uint8_t pin){
	if (level == HIGH){
		GPIOD->BSRR |= (1<<pin);
	} else if (level == LOW){
		GPIOD->BSRR |= ((1<<pin) <<16);
	} else return;
}