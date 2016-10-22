// Project name : WALL_FOLLOWER_for_ATmega8_iBOT_mini_V3
// Compile Date : 28/03/2013 Time : (13:10)
// Complied by 	: Pradeep Kumar Sharma (Pradeep.elcom@gmail.com)
// Designed By 	: ROBOSAPIENS TECHNOLOGIES PVT. LTD 
//                http://www.robosapiensindia.com

/* Program for "WALL_FOLLOWER/Fabricated to follow wall using a single sensor connected on PC0" 
_______________________________________________________________________________________________

Connection Settings of the Kit

LEDs---@------------->PB1
LEDs---@------------->PB2
LEDs---@------------->PB3
LEDs---@------------->PB4
Left Sensor---------->PC3
Right Sensor--------->PC0
Buzzer--------------->PD4
SOUND SENSOR--------->PB0
RIGHT MOTOR(+)------->PB1
RIGHT MOTOR(-)------->PB2
LEFT MOTOR(-)-------->PB3
LEFT MOTOR(+)-------->PB4
BOOTLoader Condition Check----->PC5(If 0 bootloader section else program execution
							  section of Flash memory)
RESET-------------------------->PC6
Crystal Oscillator------------->PB6 and PB7
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)
*/

#define F_CPU 12000000UL
#include<avr/io.h>

int main(void)
{
	DDRD=0b11111111;	       // set PD4 as output bit
	DDRC=0b0000000;            // set PORTC as input port
	DDRB=0b00011110;           // PB1, PB2, PB3, PB4 as output port
    int rs=0;  		  	       // define & initialize  rs integer as 0 to acquire the right sensor status in rs
					  					  
	while(1)          		   // create infinite loop
	{
	
	rs=(PINC&0b0000001);       //acquire only right sensor status connected at PC0
	PORTD &= ~(1<<4);		

		if((rs==0b0000000))    //check  right sensor status for OFF 
		{

			PORTD=(1<<4);
			PORTB=0b00010000;  //right turn
			rs=0;              //set sensor status off
		
		}
		
		else
			
			PORTB=0b00000010;  //left turn
		
		}

}
