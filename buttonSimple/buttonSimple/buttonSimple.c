/*
 * buttonSimple.c
 *
 * Created: 3/9/2016 10:29:32 PM
 *  Author: Sili
 *
 * Description: This project will illustrate the basics of using the push button on the development board
 */ 

#define F_CPU 11059200UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB |= (1<<0) | (1<<1) | (1<<2);
	PORTB = (1<<PB0) & (1<<PB1) & (1<<PB2);
	
	DDRD = 1 << PD7;
	PORTD = 1 << PD7;
	while(1)
	{
		if(!(PIND & (1<<PD7)))
		{
			PORTB = (1<<PB0) | (1<<PB1) | (1<<PB2);
		}
		else{
			PORTB = 0x00;
		}
	}
}