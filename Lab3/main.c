/*
 * Lab3_Stepper_Motor.c
 *
 * Created: 9/3/2023 4:50:36 PM
 * Author: Caiden Moreno
 
 Project name: Three_Modes_stepper
 Description: Control stepper motor using three different modes: 
 Wave step mode
 Full step mode 
 Half step mode
 
 Three arrays were created to associate the bit patter necessary to move
 the pattern required for each mode. The code also has at least two for loops 
 for each mode to help drive the stepper functions. The program also utilizes
 the delay function in between each step to see more clearly the motors movement 
 and functionality.
 
 HardWare: 
 Outputs Active high/low
 IN1 = PINC.0
 IN2 = PINC.1
 IN3 = PINC.2
 IN4 = PINC.3
 
 Inputs (pushbuttons used to select which mode) 
 SW0 = PINA.0 WaveStep mode
 SW1 = PINA.1 FullStep mode
 SW2 = PINA.2 HalfStep mode
 
 *////////////////////////////////////////////////////////////////////////
  

#define F_CPU 16000000UL
#define PushButton PINA //used for checkoff 2&3 defines "PushButton" as PINA
#include <avr/io.h>
#include "Debugger.h" //includes Debugger.h 
//#include "stepper_motor.h" //includes stepper_motor.h file

//checkoff1
/*
void io_init(void) //initialize io ports
{
	//inputs
	DDRA=(0x00); 
	PORTA=(0xFF);
	//outputs
	DDRC = 0xFF;
	PORTC = 0x00; 
	
}

int main(void)
{
	io_init(); //call initialized io ports function
    initDebug(); //call debug function 
    PORTC=0x55; //PORTC follows 01010101 output to make LED pattern on driver board
    while (1) 
    { 
    }
	
}
*/

//checkoff2

void io_init(void); //initialize io ports

int main(void)
{
	io_init(); //call initialized io ports function
	while (1)
	{
		uint16_t n = 2;  // declares an unsigned 16 bit integer variable "n" to 2
		switch (PushButton) //switch case for Wave, Full, and half step mode depending on which Pushbutton is pressed from PINA
		{
			case Wave_step:   //if SW0 is pressed, start Wave Step mode
			{
				Stepper_Drive('W',n); //call stepper_drive function for 2 revolutions in wave step mode
				break; //break out of case
			}
			case Full_step:  //if SW1 is pressed, Full Step mode
			{
				Stepper_Drive('F',n); //call stepper_drive function for 2 revolutions in full step mode
				break; //break out of case
			}
			case Half_step: //if SW1 is pressed, Half Step mode
			{
				Stepper_Drive('H',n); //call stepper_drive function for 2 revolutions in half step mode
				break; //break out of case
			}
		}
		stepper_output = 0x00;  //clear output when done
	}
}



void io_init(void) //initialize io ports
{
	//inputs
	DDRA=(0x00); //set all 8 pins on PORTA as i/p
	PORTA=(0xFF); //All pull-ups set
	//outputs
	DDRC = 0xFF; //All PORTC set to o/p to drive Stepper Motor
	PORTC = 0x00; //All output initially off 
	
}



//checkoff 3
/*
int main(void)
{
	io_init();
	while (1)
	{
		switch (PushButton)
		{
			case clockwise:   //if SW0 is pressed, start Wave Step mode clockwise
			{
				stepper_movement('W',2); //call stepper_movement function clockwise in wave step mode
				break; //break out of case
			}
			case counterclockwise: //if SW1 is pressed, start Wave Step mode counterclockwise
			{
				stepper_movement('C',2); //call stepper_movement function counterclockwise in wave step mode
				break; //break out of case
			}
			
		}
		stepper_output = 0x00;  //clear output when done
	}
}



void io_init(void) //initialize io ports
{
	//inputs
	DDRA=(0x00); //set all 8 pins on PORTA as i/p
	PORTA=(0xFF); //All pull-ups set
	//outputs
	DDRC = 0xFF; //All PORTC set to o/p to drive Stepper Motor
	PORTC = 0x00; //All output initially off
	
}
*/