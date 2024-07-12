
/*
 * main.c
 *
 * Created: 11/14/2023 7:17:04 PM
 * Author : moren
 */ 



//checkoff 1

#include <avr/io.h>
#include <util/delay.h>
//#include "Debugger.h"
#include "LCD.h"

int main(void)
{
	char T_mess[] = {" O            O "};
	char B_mess[] = {"   __________  "};
	
	Init_PORTs();
	Init_LCD();

	LCD_write(INSTR_WR, 0x01);
	_delay_ms(20);	//can remove if use Busy Flag check

	LCD_write(INSTR_WR, 0x02);
	_delay_ms(20);  //can remove if use Busy Flag check

	LCD_write(INSTR_WR, 0x80);//sets to top middle of LCD
	Print_string (T_mess);


	LCD_write(INSTR_WR, 0xC0);
	_delay_us(50);	//can remove if use Busy Flag check


	while(1) 
	{

		LCD_write(INSTR_WR, 0xC0);// Sets to bottom middle of LCD
		_delay_us(50);	//can remove if use Busy Flag check
		Print_string (B_mess);
		_delay_ms(50);
	}  
		return(0);
	}

//checkoff 2
/*
	#include <avr/io.h>
	//#include <util/delay.h>
	#include <avr/interrupt.h>
//	#include "Debugger.h"
	#include "USART0.h"

	int main(void)
	{
		//initDebug();
		init_UART0();
		init_PORTs();
        sei(); 
		
	    while (1) {
		    uint8_t switchValue = read_switches(); //send switch value to readswitch function 
		    UART_out(switchValue);
			PORTA=rx_char; // Display the received character on LEDs 
		}
		
	}
		
void init_PORTs (void) 
{
	//inputs
	DDRL = 0x00;	// PORTL all inputs
	PORTL = 0x00;	// Set all outputs to 0 initially
	
	//outputs
	DDRA = 0xFF;//Set PORTA as LED output
	PORTA = 0x00; //Turn LEDS off at initialization
}
	*/

//checkoff 3
/*
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "main.h"

volatile uint8_t LCD_update;


int main(void) {
	init_PORTs();
	init_LCD();
 LCD_write(INSTR_WR, 0x01);  // Clear display
 _delay_ms(2);               // Delay for LCD to complete the operation
 LCD_write(INSTR_WR, 0x02);  // Set cursor to home
 _delay_ms(2);               // Delay for LCD to complete the operation
	init_UART0(); //initialize USART
		sei(); //enable global interrupts
	
	while (1) {
		if(LCD_update){
		LCD_update=0;
		LCD_write(INSTR_WR, 0x86); // Set to top middle of LCD
		Print_string(rx_buffer); //write text in array to LCD
		LCD_write(INSTR_WR, 0xC6);// Sets to bottom middle of LCD
		_delay_us(50);	//can remove if use Busy Flag check
		Print_string (rx_buffer);
		_delay_ms(50);
		}
		}
	}
*/
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
