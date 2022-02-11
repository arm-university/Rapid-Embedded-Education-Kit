/*----------------------------------------------------------------------------
LAB EXERCISE 3 - Analog input and PWM
 ----------------------------------------
	Use two potentiometers to adjust the volume and pitch of the output sound wave.
	
	Inputs: potentiometers 1 and 2
	Output: speaker, PC

	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"

// **************************** NOTE *******************************
//#define TARGET_SIMULATOR //Comment this line out if using physical hardware
//#define TARGET_NUCLEO_F401RE
#define TARGET_NUCLEO_F429ZI_MSB
// *****************************************************************

#if defined TARGET_SIMULATOR
#define SPEAKER_PIN p21     
#define AN_POT1_PIN p15
#define AN_POT2_PIN p16
#elif defined TARGET_NUCLEO_F401RE
//Tutors can adapt this for their own hardware
#define SPEAKER_PIN D6
#define AN_POT1_PIN A0
#define AN_POT2_PIN A1
#elif defined TARGET_NUCLEO_F429ZI_MSB
#define SPEAKER_PIN PB_13
#define AN_POT1_PIN PC_0
#define AN_POT2_PIN PA_0
#endif
/*
Define the PWM speaker output
Define analog inputs

Use the pin definitions at the top of this file

*/

//Define the PWM speaker output
PwmOut speaker(SPEAKER_PIN);

//Define analog inputs
AnalogIn pot1(AN_POT1_PIN);
AnalogIn pot2(AN_POT2_PIN);


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
		for(i=0.0f; i<1.0f; i+=0.05f){
			speaker.period(0.003125f-(0.004f*val1));
			speaker = i*0.05f*val2;
		}
	}
}

// *******************************ARM University Program Copyright © ARM Ltd 2021*************************************
