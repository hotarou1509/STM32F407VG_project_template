#ifndef __UART_H__
#define __UART_H__

#include "hw_platform.h"

extern void UART_Init(void);
extern void UART_SendChar(uint8_t character);
extern void UART_SendString(char *string);
extern uint8_t UART_GetChar(void);

#endif
