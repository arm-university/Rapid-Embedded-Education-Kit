/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

AnalogIn   ain(A0);
DigitalOut led_2(D5);

int main(void) {
    while (1) {
        float v = ain;  //Read ADC
        if(v > 0.3f) {  // is the voltage greater than 0.3 * VCC?
            led_2 = 1;   //Turn on LED_2
        } else {
            led_2 = 0;   //Turn off LED_2
        }
        wait_us(200000); // 200ms delay
    }
}
