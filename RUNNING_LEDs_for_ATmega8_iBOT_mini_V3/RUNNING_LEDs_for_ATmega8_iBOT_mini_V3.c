/* Project name		: Running_LEDs_for_ATmega8_iBOT_mini_V3
// Compiled Date 	: 08/04/2013 Time : (12:30)
// Complied by 		: Pradeep Kumar Sharma (Pradeep.elcom@gmail.com)
// Designed By 		: ROBOSAPIENS TECHNOLOGIES PVT. LTD 
//                	  http://www.robosapiensindia.com


/* Program for "Running LED/Toggeling LEDs one by one connected with PB1, PB2, PB3, PB4" 
________________________________________________________________________________________

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
BOOTLooder Condition Check--->PC5(If 0 bootler section else program execution section of Flash memory)
RESET------------------------>PC6
Crystal Ossilator(12MHz)----->PB6 and PB7(hence PB6 & PB7 are not available for user)
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)
*/

#define F_CPU 120000000UL
#include<avr/io.h>
#include<util/delay.h>
#include "robosapiens.c"

int main(void)
{
DDRD=0b00010000;
DDRB=0b00011110;  // PB1,PB2,PB3 and PB4 of PORTB are set as output.  

while(1)         // infinite while loop
    {
		for(int i=1; i<=4; i++)
		{
    	PORTB = (1<<i);    // bitwise operation to glow leds after every 0.5 secs one by one     
		PORTD=(1<<4);
		wait(0.5);         // wait function defined in robosapiens.c file function argument: time in seconds
    	PORTD = ~PORTD;
		wait(0.5);
   	    }
	}
}



