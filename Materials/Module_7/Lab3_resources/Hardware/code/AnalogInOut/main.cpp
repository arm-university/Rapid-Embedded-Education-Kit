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
#define HW_PLATFORM SIMULATOR //Comment this line out if using physical hardware
//#define HW_PLATFORM NUCLEO_F401RE
//#define HW_PLATFORM NUCLEO_F428ZI
// *****************************************************************

#if HW_PLATFORM == SIMULATOR
#define SPEAKER_PIN p21     
#define AN_POT1_PIN p15
#define AN_POT2_PIN p16
#elif HW_PLATFORM == NUCLEO_F401RE
//Tutors can adapt this for their own hardware
#define SPEAKER_PIN D6
#define AN_POT1_PIN A0
#define AN_POT2_PIN A1
#else

#endif
/*
Define the PWM speaker output
Define analog inputs

Use the pin definitions at the top of this file

*/

	//Write your code here


//Define variables
float i;

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	while(1){
		/*
		Print values of the potentiometers to the PC serial terminal
		Create a saw-tooth sound wave
		Make the period and volume adjustable using the potentiometers
		*/
	}
}

// *******************************ARM University Program Copyright © ARM Ltd 2019*************************************
