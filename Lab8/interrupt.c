/***********************************
 * interrupt_timer0.c
 *
 * Created: 10/31/2023 8:29:37 PM
 * Author : caiden Moreno
 ***************************/ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "interrupt_timer0.h"

//500ms delay function 
void init_timer0(void)
{
	
	TCCR0A = 0; 
	TCCR0B = (1<<CS02) | (0<<CS01) | (0<<CS00);//prescaler 256
	TCNT0 = 200; // Set the initial value of Timer0 to 200
	TIMSK0=(1<<TOIE0); // Enable Timer0 overflow interrupt
	
}
/*
void delay_ms(uint8_t ms)
{
	for (uint8_t i = ms; i > 0; i--)// Loop to create a delay of 'ms'
	{
		TCCR0B = (1<<CS02) | (1<<CS00); // Set prescaler to 1024
		while((TIFR0 & (1<<TOV0))==0); // Wait for Timer 0 overflow flag
		TCCR0B =0; // Stop Timer 0
		TIFR0 |= (1<<TOV0); // Clear the Timer 0 overflow flag
		TCNT0 = 240; //set TCNT0 to 240 for a 1ms delay
	}
}
*/
//interrupt service routine for timer0 500ms LED
ISR(TIMER0_OVF_vect)
{
	TCNT0=200;  // Reset Timer0 to 200
	tick++;//tick increases by 1
}


//ADC
void init_ADC(){
	ADCSRA |= (1<<ADEN)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADPS2);//prescaler 128, enable adc
	ADMUX |= (1<<REFS0) | (1<<ADLAR);//reference voltage 5v left adjusted
	ADCSRB = 0x00;
	ADCSRA |= (1<<ADIE); //enable interrupt bit
	ADMUX = (ADMUX & (0xE0))|0;//selects channel 0
}

//interrupt service routine for ADC 
ISR(ADC_vect) {
	
	adc_read = ADCH; //read potentiometer input
      
}

//encoder
void init_encoder(){
	
	EIMSK = (1<<INT0); //uses PD0 for external input pin
	EICRA = (1<<ISC01); // Configure external interrupts for falling edge on INT0
}

// Interrupt Service Routine for INT0
ISR(INT0_vect){
if(PINC & 0x01)//check if PINC is high 
{
 CCW_flag=1; //if PINC is high set counter clockwise flag to 1
}
else
{
 CW_flag=1; //if PINC is low set clockwise flag to 1
}
}