/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

PwmOut led1(D5);        //Define the PWM output using a PWM compatible pin

int main()
{
    led1.period_us(100);  //Define the PWM period (100us)

    while (true) {
        for (uint32_t i=0; i<100; i++) {    //
            led1.pulsewidth_us(i);          // Pulse width ranges from 0..100us
            wait_us(10000);                 // 10ms*100 = 1s per cycle
        }
    }
}

