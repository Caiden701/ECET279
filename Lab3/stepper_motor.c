/*
 * stepper_motor.c
 *
 * Created: 9/6/2023 3:44:50 PM
 *  Author: Caiden Moreno
 */ 
#include "stepper_motor.h" //calls stepper_motor.h file
//checkoff2

uint8_t Wave[4] = {1,2,4,8}; //array for Wave step mode
uint8_t Full[4] = {3,6,0x0C,9}; //array for full step mode
uint8_t Half[8] = {9,1,3,2,6,4,0x0C,8};//array for half step mode
	
void Stepper_Drive(char mode, uint8_t revolutions) //stepper drive function 
{
	uint16_t steps = 512; //declares an unsigned 16 bit integer variable "steps" to 512
	 
	switch (mode)
	{
		case 'W': //wave step mode
			steps=512*revolutions;  //calculate the steps needed for each revolution
			for(uint16_t i=0; i<steps; i++) //loop through the array based on the calculated steps needed for each revolution
			{
				for(uint16_t j=0; j<4; j++)//loop through the whole array
				{
					stepper_output = Wave[j]; //use array
					_delay_ms(3); //3 ms delay
				}
			}
		break; //break from case
		case 'F': //full step mode
		steps=512*revolutions;//calculated steps needed for each revolution.
		for(uint16_t i=0; i< steps; i++)//loop through the array based on the calculated steps needed for each revolution
		{
			for(uint16_t j=0; j<4; j++) //loop through the whole array
			{
				stepper_output = Full[j]; //use the array
				_delay_ms(3); //3 ms delay
			}
		}
	break; //break from case
	case 'H': //half step mode
	steps=512*revolutions; //calculated steps needed for each revolution.
	for(uint16_t i=0; i<steps; i++) //loop through the array based on the calculated steps needed for each revolution
	{
		for(uint16_t j=0; j<8; j++)//loop through the whole array
		{
		stepper_output = Half[j]; //use the array
			_delay_ms(3); //3 ms delay
		}
	}
break; //break from case
	}
}


//checkoff3
/*
uint8_t Wave[4] = {1,2,4,8}; //clockwise wavestep array 
uint8_t Wavey[4]= {8,4,2,1};   //counterclockwise wavestep array 

void stepper_movement(char mode, uint8_t revolutions) //stepper movement function 
{
	switch (mode)
	{
		uint16_t steps = 512; //declares an unsigned 16 bit integer variable "steps" to 512
		case 'W': //clockwise wave step
		steps=512*revolutions;  //calculate the steps needed for each revolution
		for(uint16_t i=0; i<steps; i++) //loop through the array based on the calculated steps needed for each revolution
		{
			for(uint16_t j=0; j<4; j++)//loop through the whole array
			{
				stepper_output = Wave[j];  //use array
				_delay_ms(3); //3ms delay
			}
		}
		break;
		
		case 'C': //counterclockwise wave step
		steps=512*revolutions;//calculated the steps needed for each revolution.
		for(uint16_t i=0; i< steps; i++)//loop through the array based on the calculated steps needed for each revolution
		{
			for(uint16_t j=0; j<4; j++)//loop through the whole array
			{
				stepper_output = Wavey[j]; //use the array
				_delay_ms(3); //3 ms delay
			}
		}
		break;//break from case
   }
}
*/