/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

PwmOut led1(D5);        //Define the PWM output using a PWM compatible pin

int main()
{
    led1.period(0.02f);  //Define the PWM period (20ms, 50Hz)
    led1 = 0.1f;         //Set the duty cycle to 10%

    while (true)
    {
        sleep();
    }
}
