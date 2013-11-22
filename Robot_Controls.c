/*
 * Robot_Controls.c
 *
 *  Created on: Nov 19, 2013
 *      Author: C15Michael.Bentley
 */

#include "Robot_Controls.h"
#include <msp430.h>

void initPins() {

	P1DIR |= BIT1;
	P1SEL |= BIT1;

	P1DIR |= BIT2;
	P1SEL |= BIT2;

	P2DIR |= BIT0;
	P2SEL |= BIT0;

	P2DIR |= BIT1;
	P2SEL |= BIT1;
}

void initTimer() {

	TA0CTL &= ~(MC1 | MC0);			// Stop timer
	TA1CTL &= ~(MC1 | MC0);

	TA0CTL |= TACLR;                // clear timer A0
	TA1CTL |= TACLR;

	TA0CTL |= TASSEL1;           // configure for SMCLK
	TA1CTL |= TASSEL1;

	TA0CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	TA1CCR0 = 100;

	TA0CCR1 = 50;
	TA1CCR1 = 50;

	TA0CCTL1 |= OUTMOD_5;
	TA1CCTL1 |= OUTMOD_5;

	TA0CCTL0 |= OUTMOD_5;
	TA1CCTL0 |= OUTMOD_5;

	TA0CTL |= MC0;				// Start timer
	TA1CTL |= MC0;

}

void stop() {

	TA0CCTL1 &= ~(OUTMOD_7);
	TA0CCTL1 |= OUTMOD_5;

	TA0CCTL0 &= ~(OUTMOD_7);
	TA0CCTL0 |= OUTMOD_5;

	TA1CCTL1 &= ~(OUTMOD_7);
	TA1CCTL1 |= OUTMOD_5;

	TA1CCTL0 &= ~(OUTMOD_7);
	TA1CCTL0 |= OUTMOD_5;

}

void moveLeftForward() {
	TA0CCTL0 &= ~(OUTMOD_7);
	TA0CCTL0 |= OUTMOD_5;

	_delay_cycles(10000);

	TA0CCTL1 &= ~(OUTMOD_7);
	TA0CCTL1 |= OUTMOD_4;

}

void moveRightForward() {
	TA1CCTL0 &= ~(OUTMOD_7);
	TA1CCTL0 |= OUTMOD_5;

	_delay_cycles(10000);

	TA1CCTL1 &= ~(OUTMOD_7);
	TA1CCTL1 |= OUTMOD_4;

}

void moveLeftReverse() {

	TA0CCTL1 &= ~(OUTMOD_7);
	TA0CCTL1 |= OUTMOD_5;

	_delay_cycles(10000);

	TA0CCTL0 &= ~(OUTMOD_7);
	TA0CCTL0 |= OUTMOD_4;
}

void moveRightReverse() {

	TA1CCTL1 &= ~(OUTMOD_7);
	TA1CCTL1 |= OUTMOD_5;

	_delay_cycles(10000);

	TA1CCTL0 &= ~(OUTMOD_7);
	TA1CCTL0 |= OUTMOD_4;

}

void moveForward() {
	moveLeftForward();
	moveRightForward();

}

void moveReverse() {
	moveLeftReverse();
	moveRightReverse();
}

void turnRight() {

	moveLeftForward();
	moveRightReverse();
}

void turnLeft() {
	moveRightForward();
	moveLeftReverse();
}
