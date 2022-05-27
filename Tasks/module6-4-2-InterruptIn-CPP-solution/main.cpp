/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <iostream>
using namespace std;

class ButtonFlash {
    private:
    InterruptIn _button; 
    DigitalOut _led;

    void buttonISR() {
        _led = !_led;
    }

    public:
    ButtonFlash(PinName btn_pin, PinName led_pin, bool rising = true) : 
                _button(btn_pin), _led(led_pin)
            
    {
        //Set up interrupts (expect some switch bounce!)
        if (rising) {
            this->_button.rise(callback(this, &ButtonFlash::buttonISR));
        } else {
            this->_button.fall(callback(this, &ButtonFlash::buttonISR));
        }
    }

    ~ButtonFlash() {
        //Turn off all interrupts
        this->_button.rise(NULL);
    }
};

//Each instance manages a single switch-led pair
ButtonFlash red(D2, D6);
ButtonFlash grn(D3, D7);
ButtonFlash yel(D4, D8, false);

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