/*
 * adc.c
 *
 * Created: 3/11/2016 7:57:26 AM
 *  Author: Sili
 */ 
#define F_CPU 11059200UL

#include <avr/io.h>
#include <util/delay.h>

void setup()
{
	DDRB = 0x01;
	ADMUX |= (1 << REFS0);//voltage refrence
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);//enable & 64 prescaler
}
uint16_t ReadADC()
{
	ADCSRA |= (1 << ADSC);//start conversion
	while(!(ADCSRA & (1 << ADIF)));//wait until the conversion is finished
	ADCSRA |= (1 << ADIF);//we reset the adif with a 1 
	return (ADC);//we return the 16 bit (2 * 8bit) register
}
int main(void)
{
	setup();
	uint16_t result;
	while(1)
	{
		result = ReadADC();
		if(result > 512)
		{
			PORTB = 0x01;
		}
		else{
			PORTB = 0x00;
		}
	}
}