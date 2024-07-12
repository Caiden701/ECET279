/*
 * LCD.c
 *
 * Created: 11/14/2023 7:17:04 PM
 * Author : moren
 */ 

//checkoff1

#include <avr/io.h>
#include "LCD.h"

void Init_PORTs (void)
{
	DDRL = 0xFF;	// PORTL all outputs 
	PORTL = 0x00;	// Set all outputs to 0 initially 
	DDRD = 0x07;	// Set D.0 through A.2 to outputs for LCD control 
}


void Init_LCD (void)
{
	_delay_ms(35);				// wait for more than 30mS after VDD rises to 4.5V 
	LCD_write(INSTR_WR,0x38); 	// function set 8bits, 2line, display off 
	_delay_us(50);				// wait for more than 39microS 
	LCD_write(INSTR_WR,0x0C);	// display on, cursor off, blink off 
	_delay_us(50);				// wait for more than 39microS 
	LCD_write(INSTR_WR,0x01);	// display clear 
	_delay_ms(2);				// wait for more than 1.53mS 
	LCD_write(INSTR_WR,0x06);	// entry mode set, increment mode 
}


void LCD_write (unsigned char RS, unsigned char data)
{
	if(RS==DATA_WR) PORTD = 0b00000001;	// write data: E = 0 R/!W=0, (write)RS = 1 ,   
	else			PORTD = 0b00000000;	// Write instruction: RS = 0 E = 0, R/!W=0 (write) 


	PORTD = PORTD | 0x04;	// Take E HIGH (logic 1) 
	PORTL = data;
	_delay_us(50);			// needs to be at least 30uS or no display - use 50 
	PORTD = PORTD & 0x01;	// Take E LOW (logic 0) 
	_delay_us(50);			// Delay REQUIRED 
}

void Print_string(char *str_ptr)
{
	PORTD = 0b00000001;	// write data: RS = 1 E = 0, R/!W=0 (write) 

	while(*str_ptr != '\0')
	{
		PORTD = PORTD | 0x04;	// Take E HIGH (logic 1) 
		PORTL = *str_ptr++;
		_delay_us(50);			// needs to be at least 30uS or no display - use 50 
		PORTD = PORTD & 0x01;	// Take E LOW (logic 0) 
		_delay_us(50);			// Delay REQUIRED 
	}
}

//checkoff 3 
/*
#include <avr/io.h>
#include "LCD.h"

void init_PORTs (void)
{
	DDRL = 0xFF;	// PORTL all outputs
	PORTL = 0x00;	// Set all outputs to 0 initially
	DDRD = 0x07;	// Set D.0 through A.2 to outputs for LCD control
}


void init_LCD (void)
{
	_delay_ms(35);				// wait for more than 30mS after VDD rises to 4.5V
	LCD_write(INSTR_WR,0x38); 	// function set 8bits, 2line, display off
	_delay_us(50);				// wait for more than 39microS
	LCD_write(INSTR_WR,0x0C);	// display on, cursor off, blink off
	_delay_us(50);				// wait for more than 39microS
	LCD_write(INSTR_WR,0x01);	// display clear
	_delay_ms(2);				// wait for more than 1.53mS
	LCD_write(INSTR_WR,0x06);	// entry mode set, increment mode
}


void LCD_write (unsigned char RS, unsigned char data)
{
	if(RS==DATA_WR) PORTD = 0b00000001;	// write data: E = 0 R/!W=0, (write)RS = 1 ,
	else			PORTD = 0b00000000;	// Write instruction: RS = 0 E = 0, R/!W=0 (write)


	PORTD = PORTD | 0x04;	// Take E HIGH (logic 1)
	PORTL = data;
	_delay_us(50);			// needs to be at least 30uS or no display - use 50
	PORTD = PORTD & 0x01;	// Take E LOW (logic 0)
	_delay_us(50);			// Delay REQUIRED
}

void Print_string(char *str_ptr)
{
	PORTD = 0b00000001;	// write data: RS = 1 E = 0, R/!W=0 (write)

	while(*str_ptr != '\0')
	{
		PORTD = PORTD | 0x04;	// Take E HIGH (logic 1)
		PORTL = *str_ptr++;
		_delay_us(50);			// needs to be at least 30uS or no display - use 50
		PORTD = PORTD & 0x01;	// Take E LOW (logic 0)
		_delay_us(50);			// Delay REQUIRED
	}
}

*/