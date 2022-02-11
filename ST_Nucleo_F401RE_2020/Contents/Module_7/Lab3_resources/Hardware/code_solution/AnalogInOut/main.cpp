/*----------------------------------------------------------------------------
LAB EXERCISE 3 - Analog input and PWM
 ----------------------------------------
	Use two potentiometers to adjust the volume and pitch of the output sound wave.
	
	Inputs: potentiometers 1 and 2
	Output: speaker, PC

	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"

//Define the PWM speaker output
PwmOut speaker(D6);

//Define analog inputs
AnalogIn pot1(A0);
AnalogIn pot2(A1);


//Define variables
float val1;
float val2;
float i;

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	while(1){
		val1 = pot1.read();
		val2 = pot2.read();
				
		//Create a saw-tooth sound wave
		for(i=0; i<1; i+=0.05){
			speaker.period(0.003125-(0.004*val1));
			speaker = i*0.05*val2;
		}
	}
}

// *******************************ARM University Program Copyright © ARM Ltd 2019*************************************
