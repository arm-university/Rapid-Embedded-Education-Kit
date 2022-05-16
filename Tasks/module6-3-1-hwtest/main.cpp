/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <iostream>
using namespace std;

//Digital Inputs (PULL-DOWN Push Switches)
DigitalIn button1(D2);
DigitalIn button2(D3);
DigitalIn button3(D4);
DigitalIn button4(D5);

//Digital Outputs (LEDs - PUSH-PULL Mode)
DigitalOut ledRed(D6);
DigitalOut ledGreen(D7);
DigitalOut ledBlue(D8);

//MACRO to create a literal string based on the state of an input  
#define PRESSED(u) ((u.read() == 1) ? "RELEASED" : "PRESSED")

int main()
{
    printf("This is Lab 6 on Mbed OS %d.%d.%d.\n\r", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
    wait_us(1000000);

    uint8_t sel = 1;
    while (true)
    {
        //Echo back which switch(s) is/are being pressed
        cout << "Button1: " << PRESSED(button1) << endl;
        cout << "Button2: " << PRESSED(button2) << endl;
        cout << "Button3: " << PRESSED(button3) << endl;
        cout << "Button4: " << PRESSED(button4) << endl << endl;

        //Update LEDs
        switch (sel) {
            case 1:
            ledRed   = !ledRed;
            break;

            case 2:
            ledGreen = !ledGreen;
            break;

            case 4:
            ledBlue  = !ledBlue;
            break;

            default:
            cout << "ERROR" << endl;
            sel = 1;
            break;
        }
        
        //Update
        sel = (sel == 4) ? 1 : (sel << 1);
        
        //0.5s delay
        wait_us(500000);
    }
}
