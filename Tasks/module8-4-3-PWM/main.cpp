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
#include "nonblocking_read.h"

// Digital Outputs
// See https://os.mbed.com/platforms/ST-Nucleo-F401RE/ to see which pins also support PWM
DigitalOut redLED(D5);      
DigitalOut greenLED(D6);

//Create instance of a timer
Timer tmr;
 
//Create instance of a PWM
PwmOut blueLED(D7);
 
int main() {
    tmr.start();
    printf("Hello World!\n");
    tmr.stop();
    printf("The time taken was %Ld uSeconds\n", tmr.elapsed_time().count()); 

    //Start the hardware PWM to produce 50% duty cycle
    blueLED.period_ms(10);      //Fast enought to avoid flicker
    blueLED.pulsewidth_ms(5);   //Start with half power   
    int pwBlue = 5;

    while (true) {

        //LED ON
        redLED = 1;     //Duty: 25%
        greenLED = 1;   //Duty: 50%

        //Blocking delay of 25ms
        tmr.reset();
        while (tmr.elapsed_time() < 25ms);

        //LED OFF
        redLED = 0;

        //Blocking delay of 25ms
        tmr.reset();
        while (tmr.elapsed_time() < 25ms);
        greenLED = 0;

        //Blocking delay of 50ms
        tmr.reset();
        while (tmr.elapsed_time() < 50ms);

        //Read keyboard and update duty of blue
        char key = getCharNonblocking();
        switch (key) {
            case '1':
            //Make darker
            if (pwBlue>=1) {
                pwBlue--;
                blueLED.pulsewidth_ms(pwBlue);
            }
            break;
            case '2':
            //Make lighter
            if (pwBlue <= 9) {
                pwBlue++;
                blueLED.pulsewidth_ms(pwBlue);
            }
            break;
            default:
            break;
        }
    }
}