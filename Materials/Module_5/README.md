[Table of Contents](/README.md#syllabus)

---

![header](../../Materials/img/ARM_University_horizontal_blue_LG.png)

---

# Module 5 - Digital Input and Output

## Lecture Slides

The lecture slides relevant to this section are listed below. It is suggested you follow these first before attempting the lab materials.

| Lecture | Description |
| - | - |
| 5 | [Digital IO](./Module_5.pptx) |
| |

If you clone this repository, lecture slides are available in PowerPoint format in the folder `Materials/Module_5`

# 1 Introduction

## 1.1 Lab Overview

In this lab, we will implement two functions in which the RGB LEDs are controlled by the status of the buttons. We will use the `DigitalIn`/`DigitalOut` and the `BusIn`/`BusOut` interfaces to assist with this. 

By the end of this lab you will get some insight and practical experience with the Mbed API for Digital I/O.

# 2 Requirements

## 2.1 Software and Hardware

In this lab, we will be using the following software and hardware:

- **Mbed Studio**, an IDE designed to streamline development and prototyping using Mbed enabled microcontrollers and development boards: https://os.mbed.com/studio/

    **OR**

    **Keil Studio**, which can be found here: https://studio.keil.arm.com/auth/login/
  

- **NUCLEO-F401RE**, or another suitable Mbed OS 6 compatible development board. A full list of compatible devices can be found here: https://os.mbed.com/platforms, note that outputs may have to be reconfigured for devices following a different standard.

- A breadboard, 4 x 330 Ω resistors, 4 x buttons, 1 red LED, 1 green LED, 1 blue LED.

The code skeleton, which includes some support for implementing the task at the end of this lab should be found in the same folder as this manual.

# 3 Hardware Setup

## 3.1 Pin Layout

In this experiment, we are going to use the NUCLEO F401RE board. The pin descriptions for the board can be found below:

![F401RE Pinout Diagram](../../Materials/img/nucleo_f401re_pin_descriptions.png)

*F401RE Pinout Diagram*


On a breadboard:

* Connect all 4 buttons according to the figure below. Your buttons should pull the GPIO pin HIGH. 
* Connect the LEDs as shown in the lower figure.

<figure>
<img src="../../img/lab6-switch-circuit.png" width="400px" >
<img src="../../img/lab6-led-circuit.png" width="400px" >
<figcaption>Figure 2: (Upper) Buttons Pulling GPIO inputs HIGH; (Lower) LED Outputs</figcaption>
</figure>

# 4 DigitalIn/DigitalOut Interfaces

In this section, you will be controling RGB LEDs using the status of the buttons. This will be achieved using the `DigitalIn` and `DigitalOut` interfaces.


## 4.1 Introduction to DigitalIn/DigitalOut Interfaces

The `DigitalIn` interface is used to read the value of a digital input pin. The logic level is either 1 or 0. The `DigitalOut` interface is used to configure and control a digital output pin by setting the pin to a logic level 0 or 1.

You can use any of the numbered Arm Mbed pins as a `DigitalIn` or `DigitalOut`, for example:

```C++
#include "mbed.h"

DigitalIn BUTTON_1(D2);
DigitalOut RED_LED(D6);

int main()
{

    if (BUTTON_1 == 1) {
        RED_LED = 1; 
    } else {
        RED_LED = 0; 
    }	

    //Spin forever
    while(true);
}
```

| Task 4-1 | DigitalIO |
| - | - |
| 1. | Make module5-4-1-DigitalIO the active project |
| 2. | Build and run the code |
| 3. | Holding down BUTTON_1, press the black RESET button on your Nucleo board to restart the code |

The `DigitalIn` and `DigitalOut` interfaces have a set of member functions which can be found in figure 2.
<table>
<tbody>
  <tr>
    <td>Function Name</td>
    <td>Description</td>
  </tr>
  <tr>
    <td>int <blue>read</blue>()</td>
    <td>Read the input, represented as a 0 or 1 (int) for DigitalIn.<br>Return the output setting, represented as 0 or 1 (int) for DigitalOut.</td>
  </tr>
  <tr>
    <td><blue>Operator int</blue>()</td>
    <td>Shorthand for <blue>read()</blue></td>
  </tr>
  <tr>
    <td>void <blue>mode</blue>(PinMode pull)</td>
    <td>Set the input pin mode. Parameters: PullUp, PullDown, PullNone, OpenDrain.</td>
  </tr>
  <tr>
    <td>int <blue>is_connected</blue>()</td>
    <td>Return the output setting, represented as 0 or 1 (int)</td>
  </tr>
  <tr>
    <td>void <blue>write</blue>(int)</td>
    <td>Seet the output, specified as 0 or 1 (int)</td>
  </tr>
  <tr>
    <td><blue>DigitalOut</blue>&amp; <blue>operator =</blue>(int value)</td>
    <td>Shorthand for <blue>write</blue>()</td>
  </tr>
</tbody>
</table>

| Task 4-1 | DigitalIO |
| - | - |
| 4. | Change the code to use the `write()` function instead of the `=` operator |
| 5. | Change the code to use the `read()` function when reading the intput (implicity used the `int()` operator) |


## Variant: `DigitalInOut`

The `DigitalInOut` interface is a bidirectional digital pin. 

* When set as an input (via the `input()` API), we can use this interface to read the value of a digital pin
* When set as an output (via the `output()` API), we can assert the value of a digital pin
* In input mode, the pin is also in a high-impedance state

This is typically used for bidirectional communications or bus systems. Great care is needed to avoid short-circuiting the power lines when working with shared data lines in this way!

> Consider what happens where two pins are connected together and accidentaly configured as outputs - If on is asserted HIGH and the other LOW, in effect you short circuit the power supply. Protection resistors would normally be used, but this impacts on speed.

## 4.2 Application Code

In this next exercise you are required to write the function a ,moore complex function to controll all 3 LEDs using the 4 switches.

| Task 4-2 | DigitalIO Task |
| - | - |
| 1. | Make `module5-4-2-DigitalIO_Task` the active project |
| 2. | Complete `ControlLED_DigitalIO` to implement the logic in the table below |
| - | The four buttons represent an unsigned binary number N with button 1 being the Least Significant Bit (LSB) and button 4 the Most Significant Bit (MSB).|
| - | Your function should turn on the right combination of RGB LEDs for all ranges of N as specified below:|
| |

| N | 0-2 | 3-7 | 8-12 | 13-15 | 
| - | - | - | - | - |
| RED | ON | ON | OFF | OFF |
| GREEN | OFF | ON | ON | OFF |
| BLUE | OFF | OFF | ON | ON |

|  |  |
| - | - |
| *Hint* | As each input represents a single (weighted) bit of a 4-bit number, you might want to calculate the decimal equivalent first. |

# 5 BusIn/BusOut Interfaces

In this task, you will be implementing the same function as in section 4-2, but using the `BusIn` and `BusOut` interfaces instead of the `DigitalIn` and `DigitalOut` interfaces. 

## 5.1 Introduction to BusIn/BusOut Interfaces
The `BusIn` interface is used to combine `DigitalIn` pins to read them together as an integer scalar. Similarly, `BusOut` is used to combine `DigitalOut` pins so that we can easily write to multiple pins. For example:


```C++
// Define the Input pins 
BusIn  buttons(BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4);
BusOut rgbLED(RED_LED, GREEN_LED, BLUE_LED);

int main()
{
    //If button1 and button3 are pressed, turn on the RED and BLUE
    if (buttons == 0b0101) {
        rgbLED = 0b101;
    } else {  //Otherwise it is GREEN only
        rgbLED = 0b010;
    }
}
```

Note that the order of the pins in the constructor is least significant bit first, and you can have up to 16 pins. 

For example, if you have `BusOut(a,b,c,d,e,f,g,h)`, then the order of bits in the byte would be `hgfedcba` with `a` being bit `0`, `b` being bit `1`, `c` being bit 2 etc.

Note that you can also combine pins from across multiple ports.  This is because under the hood, both `BusIn` and `BusOut` encapsulate an *array* of `DigitalIn` and `DigitalOut` objects respectively.

> The convenience of `BusOut` is traded for performance. When you write to `BusOut`, you can expect a small timing skew. It will also be slower than writing to a single port address (the sameapplies to `BusIn`).
>
> If you want to see for yourself, from within Mbed Studio, right-click `BusOut` in your source code, and click `Go to Definition`. Read the header file. Now locate the accompanying source (`BusOut.cpp`) and see how `write` is implemented.

If you really wish to write to multiple bits at very high speed or with zero timing skew, then consider `PortIn` and `PortOut`. See the [documentation](#6-additional-references) for more details. Of course, all bits must be on the same hardware port.

| Task 5-1 | `BusIn` and `BusOut` |
| - | - |
| 1. | Make `module5-5-1-BusInOut` the active project |
| 2. | Repeat the challenge set in Task 4-2 |
| *Hint* | Did you know case-statements in C++ can work with ranges? See the code snippet below |

```C++
void ControlLED_BusIO (){
    switch (buttons){
        case 0 ... 2: 
            rgbLED=0b001;
            break;
       // continue...
    }
}
```

For your reference, here is the table again

| N | 0-2 | 3-7 | 8-12 | 13-15 | 
| - | - | - | - | - |
| RED | ON | ON | OFF | OFF |
| GREEN | OFF | ON | ON | OFF |
| BLUE | OFF | OFF | ON | ON |

# Reflection

Read and writing GPIO ports is a very fundamental activity in embedded systems and IoT. In this section, we have seen how Mbed OS abstracts many of the platform specific details, and allows us to access GPIO pins without any significant overhead.

* `DigitalIn` and `DigitalOut` - Push/Pull mode GPIO drivers
* `BusIn` and `BusOut` - encapsulate arrays of `DigitalIn` and `DigitalOut` so we can groups a collection of pins (from different ports) as scalars
* `DigitalInOut` - flexible driver that enables maximum configuration, include the pin mode, but to be used with care.
* `PortIn` and `PortOut` - high performance access to specific digital ports

If you explore the documentation, you will discover there is more you can do, including:

* Changing the mode (e.g. open drain)
* Enabling internal pull up/down resistors
* Setting initial values

We also saw how both Mbed OS drivers and less abstracted code can be combined (if we are careful) to access features that may not be supported on all hardware.

# 6	Additional references
Documentation Mbed API for Digital I/O can be found in the *drivers* section of the API documentation:

https://os.mbed.com/docs/mbed-os/v6.15/apis/drivers.html


---

[Table of Contents](/README.md#syllabus)

Copyright © 2021 Arm Limited (or its affiliates). All rights reserved. 
