/*----------------------------------------------------------------------------
LAB EXERCISE 4 - TIMER AND PWM
 ----------------------------------------
Make an audio player to play a music

Input: 2x potentiometers, one for tuning the music speed, and one for the volume
Output: PWM Speaker (play the music), and RGB LED (reflect the melody)

	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"

#define SPEAKER p21
#define RED_LED p22
#define YELLOW_LED p23
#define BLUE_LED p24
#define AIN1 p15
#define AIN2 p16



//Define the frequency of basic music notes
# define Do     0.5
# define Re     0.45
# define Mi     0.4
# define Fa     0.36
# define So     0.33
# define La     0.31
# define Si     0.3
# define No     0 

//Define the beat length (e.g. whole note, half note) 
# define b1     0.5
# define b2     0.25
# define b3     0.125
# define b4     0.075

//Define the musical piece
float note[] = {Mi,No,Mi,No,Mi,No, Mi,No,Mi,No,Mi,No, Mi,No,So,No,Do,No,Re,No,Mi,No, Fa,No,Fa,No,Fa,No,Fa,No, Fa,No,Mi,No,Mi,No,Mi,No,Mi,No, Mi,Re,No,Re,Mi, Re,No,So,No};
float beat[] = {b3,b3,b3,b3,b2,b2, b3,b3,b3,b3,b2,b2, b3,b3,b3,b3,b3,b3,b3,b3,b2,b1, b3,b3,b3,b3,b3,b3,b3,b3, b3,b3,b3,b3,b3,b3,b4,b4,b4,b4, b2,b3,b3,b2,b2, b2,b2,b2,b2};

//Define the analog inputs

	//Write your code

//Define the PWM output for the speaker

	//Write your code

//Define the PWM output for the LED

	//Write your code

//Define the time ticker

	//Write your code

//Static variable
static int k;
static float volume;
static float speed;


/*----------------------------------------------------------------------------
 Interrupt Service Routine
 *----------------------------------------------------------------------------*/

//Define the ticker ISR
void timer_ISR(){
	/*
	The time ticker ISR will be periodically triggered after every single note
		+ Update the PWM frequency to the next music note
		+ Update beat length for the next music note (reconfigure the tick interrupt time)
		+ Update the colour of the RGB LEDs to reflect the melody changing
		+ The inputs from the two potentiometers will be used to adjust the volume and the speed
	*/
	
		//Write your code here
}

int main() {
 	/*
	Initialize the time ticker
	*/
	
	//Write your code here

    while (1) {
        //update the value of the volume and the speed 
			
			//Write your code here
    
	}
}
