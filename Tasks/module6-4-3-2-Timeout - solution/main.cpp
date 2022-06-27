#include "mbed.h"
#include <iostream>
#include <chrono>
#include <ratio>
using namespace std;
using namespace chrono;

//Digital Inputs (PULL-DOWN Push Switches)
InterruptIn button1(D2);    //Supports edge detection
InterruptIn button2(D3);

//Digital Outputs (LEDs - PUSH-PULL Mode)
DigitalOut ledRed(D6);
DigitalOut ledGreen(D7);
DigitalOut ledBlue(D8);

//Timeout
Timeout btn1Timeout;

//ISR prototypes
void waitForPress();
void waitForBounce1();
void waitforRelease();
void waitForBounce2();

//Classed when the button is pressed
void waitForPress() {
    //Turn off button1 ISR
    button1.rise(NULL);

    //Toggle LED
    ledRed = !ledRed;

    //Start one-shot
    btn1Timeout.attach(&waitForBounce1, 250ms);
}

//Called 250ms after a button press
void waitForBounce1() {
    //Wait for button release
    button1.fall(&waitforRelease);
}

//Called when button is released
void waitforRelease() {
    //Turn off interrupt
    button1.fall(NULL);

    //start one-shot
    btn1Timeout.attach(&waitForBounce2, 250ms);
}

//Called 250ms after a button release
void waitForBounce2() {
    //Wait for button press again
    button1.rise(&waitForPress);
}

int main()
{
    //Wait for initial button press
    button1.rise(&waitForPress);   

    //Main loop 
    while (true) {
        sleep();
        cout << "Woken by ISR" << endl;
    }
}