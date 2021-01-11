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

/* PIN Address Definition */
#define PIN_1	2
#define PIN_2	4
#define PIN_3	6
#define PIN_4	8
#define PIN_5	10
#define PIN_6	12
#define PIN_7	14
#define PIN_8	16
#define PIN_9	18
#define PIN_10	20
#define PIN_11	22
#define PIN_12	24
#define PIN_13	26
#define PIN_14	28
#define PIN_15	30

/* GPIO Mode Definition */
#define INPUT_MODE	0
#define OUTPUT_MODE	1
#define ALT_MODE	2
#define ANALOG_MODE	3

/* GPIO Output Speed */
#define LOW_SPEED			0
#define MEDIUM_SPEED		1
#define HIGH_SPEED			2
#define VERY_HIGH_SPEED		3

void GPIO_Init(void){
	// 1. Enable GPIO clock
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable the GPIOA CLock
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; // Enable the GPIOD CLock

	// 2. Set PIN as Desire Mode
	/* PORT_A */
	GPIOA->MODER |= (ALT_MODE<<PIN_2);	// PA2 as Alt Function
	GPIOA->MODER |= (ALT_MODE<<PIN_3);	// PA3 as Alt Function
	/* PORT_D */
	GPIOD->MODER |= (OUTPUT_MODE<<PIN_12); // PD12 as output
	GPIOD->MODER |= (OUTPUT_MODE<<PIN_13); // PD13 as output
	GPIOD->MODER |= (OUTPUT_MODE<<PIN_14); // PD14 as output
	GPIOD->MODER |= (OUTPUT_MODE<<PIN_15); // PD115 as output

	// 3. Configure the output mode
	
	/* PORT_A */
	GPIOA->OSPEEDR |= (VERY_HIGH_SPEED<<PIN_2) | (VERY_HIGH_SPEED<<PIN_3);
	
	GPIOA->AFR[0] |= (7<<8); // Bytes (11:10:9:8) = (0:1:1:1) --> AF7 Alternate function for USART2 at Pin PA2
	GPIOA->AFR[0] |= (7<<12); // Bytes (15:14:13:12) = (0:1:1:1) -> AF7 Alternative function for USART2 at Pin PA3

	/* PORT_D */
	GPIOD->OTYPER &= ~(1<<13); // bit 5=0 => Output push pull
	GPIOD->OSPEEDR |= (HIGH_SPEED<<PIN_13); // Pin PD13 as Fast Speed (1:0)
	GPIOD->PUPDR &= ~((1<<26) | (1<<27));
}

void Set_Pin(uint8_t level, uint8_t pin){
	if (level == HIGH){
		GPIOD->BSRR |= (1<<pin);
	} else if (level == LOW){
		GPIOD->BSRR |= ((1<<pin) <<16);
	} else return;
}
