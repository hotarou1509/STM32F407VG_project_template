#include "uart.h"

#define CLEAR_ALL_REG 0x00

void UART_Init(void)
{

	// 1. Setup the Tx and Rx Pin (in GPIO_Init)
	// 2. Enable the USART Clock
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN; // Enable the UART2 CLK

	// 3. Enable the USART by writing the UE bit in USART_CR1 register to 1
	USART2->CR1 |= CLEAR_ALL_REG; // Clear all Reg
	USART2->CR1 |= USART_CR1_UE;  // UE = 1 ... Enable USART

	// 4. Program the M bit in USART_CR1 to define the word length
	USART2->CR1 |= USART_CR1_M; // M = 0 <-> 8 bit word length

	// 5. Selecting Baud rate
	USART2->BRR = (13 << USART_BRR_DIV_Fraction_Pos) | (22 << USART_BRR_DIV_Mantissa_Pos); // Baud rate of 115200, PCLK1 at 42MHz

	// 6. Enable the Tx/Rx by Setting TE and RE bits in USART_CR1 Reg
	USART2->CR1 |= USART_CR1_RE; // RE=1 <-> Enable the Receiver
	USART2->CR1 |= USART_CR1_TE; // TE=1 <-> Enable the Transmitter
}

void UART_SendChar(uint8_t character)
{
	USART2->DR = character; // Load data to register
	while (!(USART2->SR & USART_SR_TC)); // Wait for TC to Set <-> Transmission Complete
}

void UART_SendString(char *string)
{
	while (*string)
		UART_SendChar(*string++);
}

uint8_t UART_GetChar(void)
{
	uint8_t temp;
	while (!(USART2->SR) & USART_SR_RXNE);	// Wait for RXNE to be set
	temp = USART2->DR; // Read the data from Data Register, this clears RXNE also
	return temp;
}