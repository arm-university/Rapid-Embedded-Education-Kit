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

// Digital Outputs
DigitalOut redLED(D5);      
DigitalOut greenLED(D6);
DigitalOut blueLED(D7);

//Inputs
DigitalIn button_1(D4);


//Create instance of a timer
Timer tmr;
 
 
int main() {
    tmr.start();
    printf("Hello World!\n");
    tmr.stop();
    printf("The time taken was %Ld uSeconds\n", tmr.elapsed_time().count()); 


    //Rapid polling loop
    while (true) {

        // Read Timer (non-blocking)
        std::chrono::microseconds T = tmr.elapsed_time();

        // red LED has a duty of 25%
        if (T < 25ms) {
            redLED = 1;
        } else {
            redLED = 0;
        }

        // green LED has a duty of 60%
        if (T < 60ms) {
            greenLED = 1;
        } else {
            greenLED = 0;
        }

        // Reset timer
        if (T >= 100ms) {
            tmr.reset();
            tmr.start();
        }

    }
}