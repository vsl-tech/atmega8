// Project name : OBSTACE_AVOIDER_for_ATmega8_iBOT_mini_V3
// Compile Date : 28/03/2013 Time : (14:02)
// Complied by 	: Pradeep Kumar Sharma (Pradeep.elcom@gmail.com)
// Designed By 	: ROBOSAPIENS TECHNOLOGIES PVT. LTD 
//                http://www.robosapiensindia.com

/* Program for "OBSTACLE AVOIDER/Fabricated for avoiding obstacle" 
__________________________________________________________________

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
#include<util/delay.h>
#include"robosapiens.c"

int main(void)
{
	DDRD=0b11111111;	//set PD4 as output bit
	DDRC=0b0000000;   	//set PORTC as input port
	DDRB=0b00011110;  	//PB1, PB2, PB3, PB4 as output port
    int ls=0, rs=0;   	// define & initialize ls, rs integer as 0 to 
					  	// acquire the left sensor status in ls and right sensor
					  	// status in rs 
	
	while(1)          	// create infinite loop
	{
	rs=(PINC&0b0000001);   //acquire only left sensor status connected at PC0
	ls=(PINC&0b0001000);   // acquire only right sensor status connected at PC3
	PORTD = ~PORTD;		
		
		if((rs==0b0000001)||(ls==0b0001000)) 
		{
		PORTD=(1<<4);
		}		

		if((rs==0b0000000)&&(ls==0b0000000)) //check sensor status for both sensor OFF 
		{

			PORTB=0b00010010;  //forward
			ls=0;              //set sensor status off
			rs=0;              //set sensor status off
		
		}

		if((rs==0b0000001)&&(ls==0b0000000))  //check sensor status for left sensor=ON and
		                                      // right sensor=OFF
		{
			
			PORTD = (1<<4);
			PORTB=0b00001100;    //backward
			wait(0.5);
			PORTB=0b00000010;    //turn left to avoid the obstacle
			wait(1);
			ls=0;                //set sensor status off
			rs=0; 				 //set sensor status off	
			            
		}
	
	
		if((rs==0b0000000)&&(ls==0b0001000))  //check sensor status for left sensor=OFF and
		                                     // right sensor=ON
		{
			 
			PORTD = (1<<4);
			PORTB=0b00001100;    //backward
			wait(0.5);
			PORTB=0b00010000;    //turn right to avoid the obstacle
			wait(1);
			ls=0;                //set sensor status off
			rs=0; 				 //set sensor status off
			 
		}
	
		

        if((rs==0b0000001)&&(ls==0b0001000)) //check sensor status for both sensor ON 
		{
			PORTB=0b00000000;  //stop
			ls=0;              //set sensor status off
			rs=0;              //set sensor status off
		}
		
		
		
	}
}
