/*----------------------------------------------------------------------------
LAB EXERCISE 4 - TIMER AND PWM
 ----------------------------------------
Make an audio player to play a music

Input: 2x potentiometers, one for tuning the music speed, and one for the volume
Output: PWM Speaker (play the music), and RGB LED (reflect the melody)

	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"
#include <chrono>
#include <ratio>
#include "nonblocking_read.h"

//Inputs
DigitalIn button_1(D2);
DigitalIn button_2(D3);
DigitalIn button_3(D4);
DigitalIn button_4(D5);

// Digital Outputs
DigitalOut redLED(D6,0);      
DigitalOut greenLED(D7,0);
DigitalOut blueLED(D8,1);   //Initial state ON


//Create instance of a timer
Timer tmr;
 
int main() {
    tmr.start();
    printf("Hello World!\n");
    long long t = tmr.elapsed_time().count();
    printf("The time taken was %Ld uSeconds\n", t); 

    //Wait for 0.25s
    tmr.reset();
    while (tmr.elapsed_time() < 250ms);
    printf("Starting....\n");

    //Rapid polling loop
    tmr.reset();    //Reset to 0 and continue to run
    while (true) {

        // Read Timer (non-blocking)
        std::chrono::microseconds T = tmr.elapsed_time();

        // red LED has a duty of 2.5%
        if (T < 250us) {
            redLED = 1;
        } else {
            redLED = 0;
        }

        // green LED has a duty of 50%
        if (T < 5000us) {
            greenLED = 1;
        } else {
            greenLED = 0;
        }
        
        // Reset timer
        if (T >= 10000us) {
            tmr.reset();
        }

    }
}