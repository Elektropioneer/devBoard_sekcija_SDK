/*
 * servo.c
 *
 * Created: 3/10/2016 10:34:58 PM - 12:46 AM
 *  Author: Sili
 */ 
#define F_CPU 11059200UL
#define PRESCALER 8

#include <avr/io.h>
#include <util/delay.h>

void servo(unsigned char dutyCycle)
{
	OCR2B = ((double)ICR1 / 255) * dutyCycle + 0.5;
}
int main(void)
{
	DDRD |= (1 << PD3); 
	
	TCCR2A |= (1 << COM2A1) | (1 << COM2B1) | (1 << WGM10);
	
	TCNT2 = 0;
	
	OCR2B = 0;
	
	//fpwm = fcpu/n(1+top)
	ICR1 = ((double)F_CPU) / (PRESCALER * 50) - 1;//27ms 50Hz
	
	TCCR2B |= (1 << CS21) | (1 << CS22);//345kHz
	
	_delay_ms(100);
	
    while(1)
    {
		servo(234);
		_delay_ms(2000);
		servo(220);
		_delay_ms(2000);
    }
}