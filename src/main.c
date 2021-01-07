#include "stm32f407xx.h"

void sysClockConfig(void){
	/********************>>>>> STEPS FOLLOWED <<<<*********************/
	/*	1. ENABLE HSE and wait for HSE become ready
	 	2. Set the POWER ENABLE and VOLTAGE REGULATOR
		3. Configure the FLASH PREFETCH and the Latency Related Setting
		4. Configure the PRESCALARS HCLK, PCLK1, PCLK2
		5. Configure the main PLL
		6. Enable PLL and wait for it become ready
		7. Select the Clock Source and wait for it to be set
	 ******************************************************************/

	#define PLL_M	4
	#define PLL_N	168
	#define PLL_P	0 // PLLP = 2 (cannot set directly)

	//	1. ENABLE HSE and wait for HSE become ready
	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY));

	//	2. Set the POWER ENABLE and VOLTAGE REGULATOR
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;
	PWR->CR |= PWR_CR_VOS;

	//	3. Configure the FLASH PREFETCH and the Latency Related Setting
	FLASH->ACR = FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN | FLASH_ACR_LATENCY_5WS;
	
	//	4. Configure the PRESCALARS HCLK, PCLK1, PCLK2
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1; // AHB
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV4; // APB1
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV2; // APB2

	//	5. Configure the main PLL
	RCC->PLLCFGR |= (PLL_M << 0) | (PLL_N << 6) | (PLL_P << 16) | (RCC_PLLCFGR_PLLSRC_HSE);

	//	6. Enable the PLL and wait for it become ready
	RCC->CR |= RCC_CR_PLLON;
	while (!(RCC->CR & RCC_CR_PLLRDY));

	//	7. Select the Clock Source and wait for it to be set
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
}

void gpioConfig(void){
	/***************** STEPS FOLLOWED *****************
	 *	1. Enable the GPIO CLOCK
	 *	2. Set the Pin as OUTPUT
	 *	3. Configure the OUTPUT MODE
	 * ************************************************/

	//	1. Enable the GPIOD CLOCK
	RCC->AHB1ENR |= (1<<3);

	//	2. Set the pin as OUTPUT
	GPIOD->MODER |= (1<<26); // Pin PD13 (bits 27:26) as Output (01)

	//	3. Configure the OUTPUT MODE
	GPIOD->OTYPER = 0;
	GPIOD->OSPEEDR = 0;
}

void delay(uint32_t time){
	while (time--);
}

void _init(void){}
//void _exit(void){}

int main(void){
	/* INITIALLIZING */
	sysClockConfig();
	gpioConfig();

	while(1){
		GPIOD->BSRR |= (1<<13); // Set the pin PD13
		delay(5000000);
		GPIOD->BSRR |= ((1<<13) <<16); // Reset the pin PD13
		delay(5000000);
	}
}
