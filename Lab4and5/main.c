#include <avr/io.h> // Include the appropriate AVR library for your microcontroller

int main() {
	// Set OC1A (connected to PORTB.5) as an output
	DDRB = (1 << DDB5);

	// Set OC3A (connected to PORTE.5) as an output
	DDRE = (1 << DDE5);

	// Your code goes here

	return 0;
}





