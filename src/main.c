/**************************************************************************
*
*	Purpose	:	Project's Main C File
*	Author	:	THAI VIET LE
*	Updated	:	1/7/2021
*	
***************************************************************************
*	Copyright (C) 2021 by THAI VIET LE
**************************************************************************/

#include "project.h"

#define LED_ORANGE 3
#define LED_GREEN 4
#define LED_RED 5
#define LED_BLUE 6

void _init(void)
{
	/* INITIALIZING */
	Clock_Init();
	Timer_Init();
	GPIO_Init();
	UART_Init();
}

int main(void)
{
	/* INITIALIZING */
	_init();

	int arr[4] = {LED_ORANGE, LED_GREEN, LED_BLUE, LED_RED};

	/* MAIN LOOP */
	while (1)
	{
		for (int i = 0; i < 4; i++)
		{
			led_on(arr[i]);
			Delay_ms(250);
		}

		UART_SendChar('G');

		for (int i = 0; i < 4; i++)
		{
			led_off(arr[i]);
			Delay_ms(250);
		}
		// uint8_t data = UART_GetChar();
		// UART_SendChar(data);
	}
}
