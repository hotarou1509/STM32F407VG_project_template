void GPIO_Init(void){
	// 1. Enable GPIOD clock
	RCC->AHB1ENR |= (1<<3);

	// 2. Set the PIN PD13 as OUTPUT
	GPIOD->MODER |= (1<<26);

	// 3. Configure the output mode
	GPIOD->OTYPER &= ~(1<<13); // bit 5=0 => Output push pull
	GPIOD->OSPEEDR |= (1<<27); // Pin PD13 as Fast Speed (1:0)
	GPIOD->PUPDR &= ~((1<<26) | (1<<27));
}
