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

#define LD3 3
#define LD4 4
#define	LD5	5
#define LD6 6

void _init(void){}

int main(void){
	/* INITIALLIZING */
	Clock_Init();
	Timer_Init();
	GPIO_Init();
	
	int arr[4] = {LD3, LD4, LD6, LD5};

	while(1){
		
		for (int i=0; i<4; i++){
			led_on(arr[i]);
			Delay_ms(250);
		}

		for (int i=0; i<4; i++){
			led_off(arr[i]);
			Delay_ms(250);
		}
	}
}
