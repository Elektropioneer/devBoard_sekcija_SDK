/*
 * buttonAdvanced.c
 *
 * Created: 3/9/2016 10:29:32 PM
 *  Author: Sili
 *
 * Description: This project will illustrate a bit more advanced usage of buttons on our development board
 */ 

#define F_CPU 11059200UL

#include <avr/io.h>
#include <util/delay.h>
/*
* Funkcija reset-uje LED diode kad ih previse shift-ujemo
*/
void regulation()
{
	_delay_ms(100);
	if(PORTB == 0b00001000)
	{
		PORTB = 0b00000001;
	}
	else if(PORTB == 0b00000000)
	{
		PORTB = 0b00000100;
	}
}
int main(void)
{
	DDRB |= (1<<0) | (1<<1) | (1<<2);
	PORTB = (1<<PB0) & (1<<PB1) & (1<<PB2);
	
	DDRD |= (1 << PD6) | (1 << PD5);
	PORTD |= (1 << PD6) | (1 << PD5);
	
	PORTB |= (1 << PB0);
	
	while(1)
	{
		if(!(PIND & (1<<PD7)))
		{
			_delay_ms(100);
			PORTB = (PORTB >> 1);
		} 
		else if(!(PIND & (1<<PD5)))
		{
			_delay_ms(100);
			PORTB = (PORTB << 1);
		}
		regulation();
	}
}