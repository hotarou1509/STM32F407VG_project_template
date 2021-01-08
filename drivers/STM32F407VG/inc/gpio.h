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

#ifndef __GPIO_H__
#define __GPIO_H__

#include "hw_platform.h"

extern void GPIO_Init(void);
extern void Set_Pin(uint8_t level, uint8_t pin);

#endif
