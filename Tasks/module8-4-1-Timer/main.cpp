#include "mbed.h"
#include "nonblocking_read.h"
#include <chrono>

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
 
int main() 
{
    tmr.start();
    printf("Hello World!\n");
    tmr.stop();

    printf("The time taken was %Ld uSeconds\n", tmr.elapsed_time().count()); 

    //Wait for 0.5s
    tmr.start();
    tmr.reset();
    while (tmr.elapsed_time() < 500ms);
    printf("Starting....\n");

    //Rapid polling loop
    tmr.reset();    //Reset to 0 and continue to run
    while (true) {

        // 1. POLL the Timer (non-blocking read)
        std::chrono::microseconds T = tmr.elapsed_time();

        // 2. UPDATE STATE

        // red LED has a duty of ?%
        if (T < 250us) {
            redLED = 1;
        } else {
            redLED = 0;
        }

        // green LED has a duty of ?%
        if (T < 5ms) {
            greenLED = 1;
        } else {
            greenLED = 0;
        }
        
        // Reset timer every 10ms
        if (T >= 10ms) {
            tmr.reset();
        }

    }
}