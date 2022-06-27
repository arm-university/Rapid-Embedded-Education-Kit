#include "mbed.h"
#include <iostream>
#include <chrono>
#include <ratio>
using namespace std;
using namespace chrono;

//Digital Inputs (PULL-DOWN Push Switches)
InterruptIn button1(D2);    //Supports edge detection
InterruptIn button2(D3);
InterruptIn button3(D4);
InterruptIn button4(D5);    

//Digital Outputs (LEDs - PUSH-PULL Mode)
DigitalOut ledRed(D6);
DigitalOut ledGreen(D7);
DigitalOut ledBlue(D8);

//Ticker (Timer with Interrupt)
Ticker tickRed;
Ticker tickGreen;

void funcRed() {
    ledRed = !ledRed;
}
void funcGreen() {
    ledGreen = !ledGreen;
}

int main()
{
    //Note this useful data type in C++
    chrono::milliseconds Tred_current, Tred_new;
    Tred_current = Tred_new = 150ms;

    //Initialise interrupts
    tickRed.attach(&funcRed, Tred_current);
    tickGreen.attach(&funcGreen, 1s);

    //Main loop 
    while (true) {

        // Write status and instructions to user
        cout << endl << endl << "T=" << Tred_current.count() << endl;
        cout << "Press\n1: to slow down\n2: speed up\n";

        // BLOCK waiting for key-press (via serial interface)
        char c = getchar();

        // Decode user input 
        switch (c) {
            case '1': 
            Tred_new += 50ms;
            break;
            case '2':
            //Do not allow to go below 50ms
            Tred_new = (Tred_current > 50ms) ? (Tred_current - 50ms) : Tred_current;
            break;
            default:
            break;
        }

        //Update ONLY if there was a change
        if (Tred_new != Tred_current) {
            //Turn off the current interrupt
            tickRed.detach();
            //Reattach with new time interval
            tickRed.attach(&funcRed, Tred_new);
            //Update state
            Tred_current = Tred_new;
        }
    }
}