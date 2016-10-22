/* Project name		: SAND_GLASS_for_ATmega8_iBOT_mini_V3
// Compiled Date 	: 08/04/2013 Time : (13:30)
// Complied by 		: Pradeep Kumar Sharma (Pradeep.elcom@gmail.com)
// Designed By 		: ROBOSAPIENS TECHNOLOGIES PVT. LTD 
//                	  http://www.robosapiensindia.com

/* Program for "SAND GLASS/filling up led in sequence with PB1, PB2, PB3, PB4" 
______________________________________________________________________________

Connection Settings of the Kit

LEDs---@--------------------->PB1
LEDs---@--------------------->PB2
LEDs---@--------------------->PB3
LEDs---@--------------------->PB4
RIGHT MOTOR(+)--------------->PB1
RIGHT MOTOR(-)--------------->PB2
LEFT MOTOR(-)---------------->PB3
LEFT MOTOR(+)---------------->PB4
Buzzer----------------------->PD4
BOOTLoader Condition Check--->PC5(If 0 bootloader section else program execution section of Flash memory)
RESET------------------------>PC6
Crystal Oscillator(12MHz)----->PB6 and PB7(hence PB6 & PB7 are not available for user)
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)
*/

#define F_CPU 12000000UL        // defining the frequency of the controller
#include<avr/io.h>
#include<util/delay.h>
#include<math.h>			    // including <math.h> from the root directory
#include "robosapiens.c"		// including wait function from the local folder

int powe(int x);				// power function

void main()
{
DDRB=0xFF;						// making port B as output port
int i,j,k,p=0;
j=1;

while(1)						// starting while loop
	{
	for(i=4;i>=0;i--)			// for loop for power function
		{
		for(k=0;k<=i;k++)		// for loop for changing bit value
			{

			PORTB=p+(1<<k);		// giving values to port B according to bit shift
			wait(.5);

			}
		
		p=p+powe(i);			// assigning powered value + p to variable p
		
		}
	
	p=0;

	}

}


int powe(int x)					// return value as int
{
int d=1;
	for (int i=0;i<x;i++)		// for loop for calculating powered value of x argument
	{
	d=d*2;
 	}
 
return d;						// returning int data type

}
