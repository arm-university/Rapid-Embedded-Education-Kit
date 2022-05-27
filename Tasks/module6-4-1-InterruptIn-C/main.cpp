/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <iostream>
using namespace std;

//Digital Inputs (PULL-DOWN Push Switches)
InterruptIn button1(D2);    //Supports edge detection
InterruptIn button2(D3);
InterruptIn button3(D4);
InterruptIn button4(D5);    

//Digital Outputs (LEDs - PUSH-PULL Mode)
DigitalOut ledRed(D6);
DigitalOut ledGreen(D7);
DigitalOut ledBlue(D8);

//MACRO to create a literal string based on the state of an input  
#define PRESSED(u) ((u.read() == 1) ? "RELEASED" : "PRESSED")

// Interrupt Service Routines (ISR)
void button1ISR() {
    ledRed = !ledRed;
}
void button2ISR() {
    ledGreen = !ledGreen;
}
void button3ISR() {
    ledBlue = !ledBlue;
}
void button4ISR() {}

int main()
{
    printf("This is Lab 6 on Mbed OS %d.%d.%d.\n\r", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
    wait_us(1000000);

    //Set up interrupts (expect some switch bounce!)
    button1.rise(&button1ISR);
    button2.rise(&button2ISR);
    button3.fall(&button3ISR);
    button4.fall(&button4ISR);

    //Main loop can sleep - only an interrupt will wake it
    while (true)
    {
        cout << "Going to sleep...." << endl;
        sleep();
        cout << "Awake!" << endl;
    }
}