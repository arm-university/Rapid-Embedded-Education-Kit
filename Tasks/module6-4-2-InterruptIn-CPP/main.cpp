/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <iostream>
using namespace std;

class ButtonFlash {
    private:
    InterruptIn _button1; 
    InterruptIn _button2;
    InterruptIn _button3;
    InterruptIn _button4;

    DigitalOut _ledRed;
    DigitalOut _ledGreen;
    DigitalOut _ledBlue;

    void button1ISR() {
        _ledRed = !_ledRed;
    }
    void button2ISR() {
        _ledGreen = !_ledGreen;
    }
    void button3ISR() {
        _ledBlue = !_ledBlue;
    }    
    void button4ISR() {}

    public:
    ButtonFlash(PinName btn_p1, PinName btn_p2, PinName btn_p3, PinName btn_p4, 
                PinName led_p1, PinName led_p2, PinName led_p3) : 
                _button1(btn_p1), _button2(btn_p2), _button3(btn_p3), _button4(btn_p4),
                _ledRed(led_p1), _ledGreen(led_p2), _ledBlue(led_p3) {
            

        //Set up interrupts (expect some switch bounce!)

        // THIS WILL NOT WORK
        // this->_button1.rise(&_button1ISR);
        // this->_button2.rise(&_button2ISR);
        // this->_button3.fall(&_button3ISR);
        // this->_button4.fall(&_button4ISR); 

        // You MUST wrap the member function with the `this` pointer so it knows which instance data to use
        this->_button1.rise(callback(this, &ButtonFlash::button1ISR));
        this->_button2.rise(callback(this, &ButtonFlash::button2ISR));
        this->_button3.fall(callback(this, &ButtonFlash::button3ISR));
        this->_button4.fall(callback(this, &ButtonFlash::button4ISR));      
    }

    ~ButtonFlash() {
        //Turn off all interrupts
        this->_button1.rise(NULL);
        this->_button2.rise(NULL);
        this->_button3.fall(NULL);
        this->_button4.fall(NULL);  
    }
};

//We instantiate only ONE object in this project, but you could create more if we had more switches and LEDs
ButtonFlash obj(D2,D3,D4,D5, D6,D7,D8);

int main()
{
    printf("This is Lab 6 on Mbed OS %d.%d.%d.\n\r", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
    wait_us(1000000);

    //Main loop can sleep - only an interrupt will wake it
    while (true)
    {
        cout << "Going to sleep...." << endl;
        sleep();
        cout << "Awake!" << endl;
    }
}