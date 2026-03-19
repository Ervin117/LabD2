/*
 * Lab6D2nano.c
 *
 * Created: 3/12/2026 8:17:27 PM
 * Author : razer
 */ 
/****************************************/
// Encabezado
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "UART_lib/UARTLib.h"

volatile uint8_t bot = 0; 
/****************************************/
// Function prototypes
void PinChange(void);

/****************************************/
// Main Function
int main(void)
{
	DDRD &= ~0b11111100; 
	PORTD |= 0b11111100; 
	serialUART(); 
	PinChange(); 
    sei(); 
    while (1) 
    {
		if (bot == 1)
		{
			serialLet('1'); 
			bot = 0; 
		}
		if (bot == 2)
		{
			serialLet('2'); 
			bot = 0; 
		}
		if (bot == 3)
		{
			serialLet('3');
			bot = 0;  
		}
		if (bot == 4)
		{
			serialLet('4');
			bot = 0;  
		}
		if (bot == 5)
		{
			serialLet('5');
			bot = 0;  
		}
		if (bot == 6)
		{
			serialLet('6');
			bot = 0;  
		}
    }
}
/****************************************/
// NON-Interrupt subroutines
void PinChange()
{
	PCICR |= (1 << PCIE2);
	PCMSK2 |= 0b11111100;
}

/****************************************/
// Interrupt routines
ISR(PCINT2_vect)
{
	if (!(PIND & (1 << PORTD2)))
	{
		bot = 1; 
	}
	if (!(PIND & (1 << PORTD3)))
	{
		bot = 2;
	}
	if (!(PIND & (1 << PORTD4)))
	{
		bot = 3;
	}
	if (!(PIND & (1 << PORTD5)))
	{
		bot = 4;
	}
	if (!(PIND & (1 << PORTD6)))
	{
		bot = 5;
	}
	if (!(PIND & (1 << PORTD7)))
	{
		bot = 6;
	}
	
}