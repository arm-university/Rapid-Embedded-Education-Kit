#include "mbed.h"

#define SPEAKER p21
#define RED_LED p22
#define YELLOW_LED p23
#define BLUE_LED p24
#define AIN1 p15
#define AIN2 p16

// Define the frequency of basic music notes
# define Do     0.5
# define Re     0.45
# define Mi     0.4
# define Fa     0.36
# define So     0.33
# define La     0.31
# define Si     0.3
# define No     0 

// Define the beat length (e.g. whole note, half note) 
# define b1     0.5
# define b2     0.25
# define b3     0.125
# define b4     0.075

// Define the musical piece
float note[] = {Mi,No,Mi,No,Mi,No, Mi,No,Mi,No,Mi,No, Mi,No,So,No,Do,No,Re,No,Mi,No, Fa,No,Fa,No,Fa,No,Fa,No, Fa,No,Mi,No,Mi,No,Mi,No,Mi,No,  Mi,No,Re,No,Re,No,Mi,No, Re,No,So,No};
float beat[] = {b3,b3,b3,b3,b2,b2, b3,b3,b3,b3,b2,b2, b3,b3,b3,b3,b3,b3,b3,b3,b2,b1, b3,b3,b3,b3,b3,b3,b3,b3, b3,b3,b3,b3,b3,b3,b3,b3,b3,b3,  b3,b3,b3,b3,b3,b3,b3,b3, b2,b2,b2,b2};

// Define the analog inputs
AnalogIn Volume(AIN1);
AnalogIn Speed(AIN2);

// Define the PWM output for the speaker
PwmOut Speaker(SPEAKER);

// Define the PWM output for the RGB LED
PwmOut RedLed(RED_LED);
PwmOut YellowLed(YELLOW_LED);
PwmOut BlueLed(BLUE_LED);

// Define the time ticker
Ticker timer; 

// Static variable
static int k;
static float volume;
static float speed;

/*----------------------------------------------------------------------------
 Interrupt Service Routine
 *----------------------------------------------------------------------------*/

// Define the ticker ISR
void timer_ISR(){ 
	if (k<(sizeof(note)/sizeof(int))){

		if(note[k] == No) {                       	//If there is a sound pause
			
			Speaker = 0;                          	//Set the PWM duty cycle to zero
		
		} else {

			Speaker.period(0.02*note[k]);   		//Set the PWM period, which determines the note of the sound
			Speaker = volume;          				//Set the PWM duty cycle that determines the volume of the sound (controlled by one potentiometer)
		
		}

		k++;
			
		//Set the time for the next ticker interrupt, this is determined by the default music beat and the potentiometer
		timer.attach(&timer_ISR, ((beat[k]/2)+(speed/2)));
			
		//RGB LED indicator
    	RedLed = note[k];
		YellowLed = Speaker;
		BlueLed = beat[k];
    
	} else {
		k = 0;                                 	//If the musical piece is finished, start again
		Speaker = 0;
	}
} 

/*----------------------------------------------------------------------------
0V5V

Potentiometer (p16)X


 MAIN function
 *----------------------------------------------------------------------------*/

int main() {

	//Initialize the time ticker
  	timer.attach(&timer_ISR, 0.1); 

    k=0;

    while (1) {
        volume = Volume.read();
        speed = Speed.read();
        wait_ms(10);
    }
}
