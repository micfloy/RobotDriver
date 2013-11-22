#include "Robot_Controls.h"
#include <msp430.h> 

/*
 * example.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	initPins();
	initTimer();
	while (1) {

		moveForward();
		_delay_cycles(1000000);
		stop();
		_delay_cycles(500000);

		moveReverse();
		_delay_cycles(1000000);
		stop();
		_delay_cycles(500000);

		turnRight();
		_delay_cycles(500000);
		stop();
		_delay_cycles(500000);

		turnLeft();
		_delay_cycles(500000);
		stop();
		_delay_cycles(500000);

		turnRight();
		_delay_cycles(800000);
		stop();
		_delay_cycles(500000);

		turnLeft();
		_delay_cycles(800000);
		stop();
		_delay_cycles(500000);

	}

}
