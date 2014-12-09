//-----------------------------------------------------------------
// Name:
// File:	main.c
// Date:	Fall 2014
// Purp:
//-----------------------------------------------------------------
#include "msp430g2553.h"
#include "ADC10.h"

void initMSP430();

//----------------------------------------------------------------------
//----------------------------------------------------------------------
int main(void) {

	unsigned short LeftSample, CenterSample, RightSample;

	IFG1=0; 													// clear interrupt flag1
	WDTCTL = WDTPW + WDTHOLD;

	BCSCTL1 = CALBC1_8MHZ;										// 8MHz clock
	DCOCTL = CALDCO_8MHZ;

	P1DIR |= BIT0;
	P1DIR |= BIT6;

	while(1) {

		LeftSample = readvalue(2);
		CenterSample = readvalue(3);
		RightSample = readvalue(4);

		if (LeftSample > 0x200) {
			P1OUT |= BIT6;
			P1OUT &= ~BIT0;
		}

		else if (CenterSample > 0x200) {
			P1OUT |= BIT0;
			P1OUT |= BIT6;
		}

		else if (RightSample > 0x200) {
			P1OUT |= BIT0;
			P1OUT &= ~BIT6;
		}

		else {
			P1OUT &= ~BIT0;
			P1OUT &= ~BIT6;
		}


/*		ADC10CTL0 = 0;											//P1.4
		ADC10CTL1 = INCH_4 | ADC10DIV_3 ;
		ADC10AE0 = BIT4;
		ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;

		ADC10CTL0 |= ADC10SC;									// Start a conversion
		while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
		RightSample = ADC10MEM;

		ADC10CTL0 = 0;											//P1.2
		ADC10CTL1 = INCH_2 | ADC10DIV_3 ;
		ADC10AE0 = BIT2;
		ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;

		ADC10CTL0 |= ADC10SC;									// Start a conversion
		while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
		LeftSample = ADC10MEM;									// collect that 10-bit value

		ADC10CTL0 = 0;											//P1.3
		ADC10CTL1 = INCH_3 | ADC10DIV_3 ;
		ADC10AE0 = BIT3;
		ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;

		ADC10CTL0 |= ADC10SC;									// Start a conversion
		while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
		CenterSample = ADC10MEM;									// collect that 10-bit value



		if (LeftSample > 0x200) {
			P1OUT |= BIT6;
			P1OUT &= ~BIT0;
		}

		else if (CenterSample > 0x200) {
			P1OUT |= BIT0;
			P1OUT |= BIT6;
		}

		else if (RightSample > 0x200) {
			P1OUT |= BIT0;
			P1OUT &= ~BIT6;
		}

		else {
			P1OUT &= ~BIT0;
			P1OUT &= ~BIT6;
		}
*/
	} // end infinite loop

} // end main

