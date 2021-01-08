/****************************************************************************
*
*	Purpose	:	Setting up System Clock
*	Author	:	THAI VIET LE
*	Updated	:	1/7/2021
*	
*************************************************************************** 
*	Copyright (C) 2021 by THAI VIET LE
***************************************************************************/

/*
 **************************************************************************
 *	
 *	@brief	System Clock Configuration:
 *		System Clock Source				=	PLL (HSE)
 *		SYSCLK (MHz)					=	168
 *		HCLK (MHz)						=	168
 *		AHB Prescaler					=	1
 *		APB1 Prescaler					=	4
 *		APB2 Prescaler					=	2
 *		HSE Frequency (MHz)				=	8
 *		PLL_M							=	4
 *		PLL_N							=	168
 *		PLL_P							=	2
 *		VDD (V)							=	3.3
 *		Main regulator output voltage	=	Scale1 mode
 *		Flash Latency					=	5
 *	@param	None
 *	
 *	@retval	None
 **************************************************************************
 * */

#include "clock.h"

void Clock_Init(void){	
	
	#define PLL_M	4
	#define PLL_N	168
	#define PLL_P	0	// PLLP = 2

	// 1.	ENABLE HSE and wait for the HSE to become Ready
	RCC->CR	|=	RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY));

	// 2.	Set the POWER ENABLE CLOCK and VOLTAGE REGULATOR
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;
	PWR->CR |= PWR_CR_VOS;

	// 3.	Configure the FLASH PREFETCH and the LATENCY Related Settings
	FLASH->ACR = FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN | FLASH_ACR_LATENCY_5WS;

	// 4.	Configure the PRESCALERS HCLK, PCLK1, PCLK2
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1; 	// AHB
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV4; 	// APB1
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV2; 	// APB2

	// 5.	Configure the MAIN PLL
	RCC->PLLCFGR = (PLL_M<<0) | (PLL_N<<6) | (PLL_P<<16) | (RCC_PLLCFGR_PLLSRC_HSE);

	// 6.	Enable the PLL and wait for it to become ready
	RCC->CR |= RCC_CR_PLLON;
	while (!(RCC->CR & RCC_CR_PLLRDY));

	// 7.	Select the Clock Source and wait for it to be set
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
}