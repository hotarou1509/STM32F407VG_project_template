/************************** STEPS TO FOLLOW ***************************
 * 1.	RESET the COUNTER
 * 2.	Wait for the Counter to reach the entered value. (~1uS)
 **********************************************************************/

void Delay_us(uint16_t us){
	TIM6->CNT = 0;
	while (TIM6->CNT < us);
}

void Delay_ms(uint16_t ms){
	for (uint16_t i=0; i<ms; i++){
		Delay_us(1000);
	}
}
