/*
 **************************************************************************

	Purpose	:	Providing Delay_ms function
	Author	:	THAI VIET LE
	Updated	:	1/7/2021
	
 ************************************************************************** 
 	Copyright (C) 2021 by THAI VIET LE
 ************************************************************************** 
*/
/**************************** STEPS TO FOLLOW *****************************
 * 1.	RESET the COUNTER
 * 2.	Wait for the Counter to reach the entered value. (~1uS)
 **************************************************************************
*/

#ifndef __DELAY_H__
#define __DELAY_H__

#include "hw_platform.h"

extern void Delay_ms(uint16_t ms);

#endif
