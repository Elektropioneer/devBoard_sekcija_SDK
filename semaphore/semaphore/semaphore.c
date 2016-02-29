/*
 * semaphore.c
 *
 * Created: 2/27/2016 11:14:53 PM
 * Author: cpku
 *
 * Description: program illustrate how traffic signal(semaphore) works on development board 
 */
#define F_CPU 11059200UL

#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	DDRB |= (1<<0) | (1<<1) | (1<<2);
	PORTB = (0<<PB0) & (0<<PB1) & (0<<PB2);
	
    while(1)
    {
		PORTB = (1<<PB0);
		_delay_ms(3000);
		
		PORTB = (0<<PB0) | (1<<PB1);
		_delay_ms(2000);
		
		PORTB = (0<<PB0) | (0<<PB1) | (1<<PB2);
		_delay_ms(5000);		
    }
}