/*
 * ADC.c
 *
 * Created: 10/22/2023 4:54:02 PM
 * Author : moren
 */ 

#include <avr/io.h>
void ADCtenbitvalue(uint16_t channel);
void init_ADC(void);

void init_ADC(void){
	
ADCSRA = (1<<ADEN)|(1<<ADPS1)|(1<<ADPS0);

ADMUX = (1<<REFS0);

ADCSRB = 0x00;
}

void ADCtenbitvalue(uint16_t channel){

uint16_t result = 0;

ADMUX = (ADMUX & 0x00) | channel;
ADCSRB = (ADCSRB & 0xf7) | (channel >>2);
ADCSRA |= (1<<ADSC);

while((ADCSRA & (1<<ADSC))==1)
{
	//do nothing
}

result=ADCL;
result=result| (ADCH<<8);

return result/1024;
}


