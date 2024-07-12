/*
 * FileName: Lab1_IO.c
 * version: 1
 * Created: 8/15/2023 9:23:56 PM
 * Author : Caiden Moreno
 
 Operations: 
This is a multi-module program, where the on-board LED
is turned on every second. 

Hardware connection:  
Atmega2560          Hardware:
//checkoff 1-3
PortB PIN7       LED13 Active high 

//checkoff 4
PORTA            8 LED outputs 

//checkoff 5     
PORTA            8 LED outputs
PORTC            3 Pushbutton inputs
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

//Checkoff 1-3
void io_init(void) //initialize io ports
{
	DDRB=(0xFF); //LED 13 set as output
	PORTB=(0x80); //turn off LED at initialization 
}

int main(void)
{
    io_init(); //initialize io and call function
    while (1) 
    {
		PORTB ^=(0x80); //toggle pin 7 LED13 on and off
		_delay_ms(500); //time delay of 500ms
    }
}



//checkoff4
void io_init(void) //initialize io ports
{
	DDRA=(0xFF); //set PORTA as output
	PORTA=(0x00); // initial LEDs states are off
}

void LED_Sweep(); //function prototype for LED_Sweep 

int main(void)
{
	io_init(); //initialize io
	while (1)
	{
		PORTA=(0x00); //turn off all LEDS at power up
		LED_Sweep(); //call LED_Sweep function
		if (PORTA & 0x01) //check if rightmost LED is on 
		{
			//repeat sequence when the right most LED is turned on.
			PORTA=(0xFF);
			LED_Sweep();
	}
	}
	
}

void LED_Sweep()
{
	// Turns on LEDs one at a time from right to left
	for (int i = 0; i < 8; i++) {
		PORTA |= (1 << i);    // Turn off LED at i
	//	_delay_ms(500);
	}
    
	//_delay_ms(500); //delay for when all LEDs turn on 
	
	// Turns off LEDs one at a time
	for (int i = 7; i >= 0; i--) {
		PORTA &= ~ (1 << i);     // Turn on LED at i
		//_delay_ms(500);
	}
}



//checkoff 5 
#define Start 01   
#define Pause 02 
#define Reset 04 

void LED_Sweep(); //function prototype for LED_Sweep

void io_init(void) //initialize io ports

{
	DDRA=(0xFF); //set PORTA as output
	PORTA=(0x00); // initial LEDs states are off
	
	DDRC = 0x00; //set PORTC as input
	PORTC = 0xFF; //enable push buttons
}

int main(void)
{
	io_init(); //initialize io  
	uint8_t input_sw; //stores input switch status
	
	while (1)
	{
		input_sw = PINC & ( (1<<PC0) | (1<<PC1) | (1<<PC2)); //bit masking PORTC for the pushbuttons
		
		if (input_sw & Start){ //starts LED sequence
			LED_Sweep(); //call LED_Sweep function
		}
	}
}


void LED_Sweep(void)
{
	// Turns on LEDs one at a time from right to left
	for (int i = 0; i < 8; i++) {

		{
			while (PINC&Pause) //pauses the LEDs sequence
			{
				//waits for pushbutton to be released after being paused 
			}
		if (PINC&Reset) //resets LEDs
		{
			PORTA=0x00; //turns off LEDs
			break; //breaks out of loop
		}	
		PORTA=(PORTA^(1<<i)); //moves Leds to the left 
		_delay_ms(500); 
		}
		PORTA |= (1 << i);    // Turn off LED at i
	_delay_ms(500);
	}
    
	_delay_ms(500); //delay for when all LEDs turn on 
	
	// Turns off LEDs one at a time
	for (int8_t i = 0; i >= 8; i++) {

			while (PINC&Pause) //pauses the LEDs sequence
			{
				//waits for push button to be released after being paused 
			}
			
		if (PINC&Reset)// resets the LEDs 
		{
			PORTA=0x00; //turns off all LEDs
			break; //breaks out of loop after restart
			}
		}
		PORTA = (PORTA >> 1); // Turn on LED at i
		_delay_ms(500);
}



