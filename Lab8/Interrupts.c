/****************************************************************************************
*
* Project name: Interrupts.c
* Created: 10/31/2023 6:41:30 PM
* Author: Caiden Moreno
* Overview: This program uses interrupt service routines to execute a 500ms delay with timer0 on one LED, display the ADC MSB values on 8 LEDS, 
* and use an encoder to display the LEDS on and off one at a time. 
*
* Hardware:
* Arduino ATmega2560 micro controller
* Inputs:
* LED outputs      = PORTA
* 500ms LED output = PINB.7
* ADC              = ADC0
* Encoder clk      = INT0
* Encoder DT       = PINC.0
****************************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Debugger.h"
#include "interrupt_timer0.h"
#define Mode_switcher (PINL & 0x01) //PINL.0

//function prototypes
void io_init(void);
void init_timer0(void);

//global variables
volatile uint16_t tick;  
volatile uint16_t adc_read; 
volatile uint8_t CW_flag;
volatile uint8_t CCW_flag;
volatile uint8_t volume;



int main(void)
{
	//call functions
	io_init();
	init_timer0();
	initDebug(); 
	init_ADC(); 
    init_encoder();
    sei();
	
    while (1) 
    {
		
		//500ms timer
		if(tick>500){ //check if tick is larger than 500
			PORTB ^=(1<<PB7);//toggle LED
			tick=0; //reset tick to 0
		}
		
		
		//adc
		ADCSRA |= (1<<ADSC); //start conversion
		PORTA = adc_read; //reads the adc value and outputs to PORTA
	      
		//encoder
		if(CW_flag==1){ 
			volume |= (volume<<1); //shift the output by one
			PORTA=volume; //output to LEDS 
			CW_flag=0; //reset the flag 
		}
		
		if(CCW_flag==1){
			volume= (volume>>1); ///shit the output by one
			PORTA=volume; //output to LEDS
			CCW_flag=0; //reset the flag
		}
		
		//check if volume is 0 
		if(volume==0) 
		{
			volume=0x01; //set it to one
		}
		
	}
         }
}

void io_init(void){
	//outputs for LEDs
	DDRA = 0xFF;
	PORTA = 0x00;
	
    //500ms delay LED
	DDRB=(0xFF); //LED 13 set as output
	PORTB=(0x00); //turn off LED at initialization
}

