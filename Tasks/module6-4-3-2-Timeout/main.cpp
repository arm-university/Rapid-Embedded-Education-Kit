#include "mbed.h"
#include <iostream>
#include <chrono>
#include <ratio>
using namespace std;
using namespace chrono;

//Digital Inputs (PULL-DOWN Push Switches)
DigitalIn button1(D2);    //Supports edge detection
InterruptIn button2(D3);

//Digital Outputs (LEDs - PUSH-PULL Mode)
DigitalOut ledRed(D6);
DigitalOut ledGreen(D7);
DigitalOut ledBlue(D8);

//Timeout
Timeout oneshot;

//Called when the button is pressed
void ledOFF() {
    //Turm OFF LED
    ledRed = 0;
}

int main()
{
    //Main loop 
    while (true) {

        //Wait for initial button press (spinning)
        while (button1 == 0);
        
        //Turn on red LED
        ledRed = 1;

        //Trigger ISR in 1s
        oneshot.attach(&ledOFF, 1s);  

        //Sleep until ISR has run
        sleep();

        cout << "Woken by ISR" << endl;
    }
}