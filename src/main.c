/**************************************************************************
*
*	Purpose	:	Project's Main C File
*	Author	:	THAI VIET LE
*	Updated	:	1/7/2021
*	
***************************************************************************
*	Copyright (C) 2021 by THAI VIET LE
**************************************************************************/

#include "stm32f407xx.h"
#include "project.h"

void _init(void){}

int main(void){
	/* INITIALLIZING */
	Clock_Init();
	Timer_Init();
	GPIO_Init();

	while(1){
		GPIOD->BSRR |= (1<<13); // Set the pin PD13
		Delay_ms(250);
		GPIOD->BSRR |= ((1<<13) <<16); // Reset the pin PD13
		Delay_ms(250);
	}
}
