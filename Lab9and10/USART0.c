/*
 * USART0.c
 *
 * Created: 11/16/2023 2:07:22 PM
 * Author : moren
 */ 
//checkoff 2 
/*
#include <avr/io.h>
#include "USART0.h"

void init_UART0(void) 
{
	UCSR0A=0x00; //clear USCR0A
	// Enable receiver and transmitter, enable RX complete interrupt
	UCSR0B = (1 << RXCIE0) | (1 << RXEN0) | (1 << TXEN0);
	UCSR0C=(1<<UCSZ01) | (1<<UCSZ00); //8 bit data 
	uint16_t myubr = (F_CPU)/(16UL*BAUD)-1; //9600 baud rate no parity 1 stop bit
	UBRR0L= myubr; //load UBBR low
	UBRR0H=(myubr>>8) & 0x0F; //load UBBR high 
}

void UART_out (uint8_t ch) //transmit byte of data
{
  while((UCSR0A & (1<<UDRE0))==0)	
  {
	  //wait for UDRE0 flag to indicate UDR0 ready for new data to start new transmission
  }
  UDR0=ch;//store charcter in UDR0
}

ISR(USART0_RX_vect)
{
	rx_char=UDR0;  // Read the received character from UART
	
}

uint8_t read_switches(void) {
	return PINL;
}
*/

//checkoff 3
/*
#include <avr/io.h>
#include "USART0.h"

void init_UART0(void)
{
	UCSR0A=0x00; //clear USCR0A
	// Enable transmit, receive, and receive interrupt
	UCSR0B = (1 << RXCIE0) | (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data
	
	uint16_t myubr = (F_CPU)/(16UL*BAUD)-1; //9600 baud rate no parity 1 stop bit
	UBRR0L= myubr; //load UBBR low
	UBRR0H=(myubr>>8) & 0x0F; //load UBBR high
}

uint8_t UART_in (void) //transmit byte of data
{
	while((UCSR0A & (1<<RXC0))==0)
	{
		//wait for data to arrive
	}
	return (UDR0);//store charcter in UDR0
}


ISR(USART0_RX_vect) {
	// Read the received character from UART
	    rx_char = UDR0;
		if(rx_char!=0x0D){
		rx_buffer[array_index]=rx_char;
		array_index++;
		}
		else{
			rx_buffer[array_index] = '\0';
			array_index=0;
			LCD_update=1; 
		}
	
}
*/