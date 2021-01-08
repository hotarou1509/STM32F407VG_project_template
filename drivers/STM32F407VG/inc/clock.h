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

#ifndef __CLOCK_H__
#define __CLOCK_H__

#include "hw_platform.h"

extern void Clock_Init(void);

#endif /* __CLOCK_H__ */


