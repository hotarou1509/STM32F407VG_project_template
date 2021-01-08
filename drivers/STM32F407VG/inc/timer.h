/**************************************************************************
*
*	Purpose	:	Managing project's header file
*	Author	:	THAI VIET LE
*	Updated	:	1/7/2021
*	
***************************************************************************
*	Copyright (C) 2021 by THAI VIET LE
***************************************************************************
/**************************** STEPS TO FOLLOW *****************************
* 1.	Enable Timer Clock
* 2.	Set the prescalar and the ARR
* 3.	Enable the Timer and wait for the Update Flag to Set
**************************************************************************/

#ifndef __TIMER_H__
#define __TIMER_H__

#include "hw_platform.h"

extern void Timer_Init(void);

#endif