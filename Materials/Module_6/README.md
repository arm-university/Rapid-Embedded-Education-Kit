Rapid Embedded Systems - Design and Programming Course - Rev 1.0

[Table of Contents](/README.md#syllabus)

---

![header](../../Materials/img/ARM_University_horizontal_blue_LG.png)

---

# Module 6 - Interrupts

## Lecture Slides

The lecture slides relevant to this section are listed below. It is suggested you follow these first before attempting the lab materials.

| Lecture | Description |
| - | - |
| 6 | [Interrupts](./Module_6.pptx) |
| |

If you clone this repository, lecture slides are available in PowerPoint format in the folder `Materials/Module_6`

# 1 Introduction

## 1.1 Lab Overview
In this lab, we will implement two functions. For the first function, the RGB LEDs are controlled by the status of the buttons. For the second, the number of times each button has been pressed controls the LEDs. By the end of this lab you will get some insight and practical experience with the Mbed API for Interrupts.

# 2 Requirements

## 2.1	Software and Hardware

In this lab, we will be using the following software and hardware: 

* SOFTWARE - one of the following:

   * **Mbed Studio**, an IDE designed to streamline development and prototyping using Mbed enabled microcontrollers and development boards: https://os.mbed.com/studio/
    
   * **Mbed online compiler**, which can be found here: https://ide.mbed.com/compiler

* **NUCLEO-F401RE**, or another suitable Mbed OS 6 compatible development board. A full list of compatible devices can be found here: https://os.mbed.com/platforms, note that outputs may have to be reconfigured for devices following a different standard.

* A breadboard, 4 x 330Ω resistors, 4 x buttons, 1 red LED, 1 blue LED, 1 green LED.

Two code skeletons, which includes some support for implementing the task in section [5.1](#51) and [5.2](), should be found in the same folder as this manual.

# 3 Hardware Setup

## 3.1 Pin Layout

In this experiment, we are going to use the Nucleo F401RE board. The pin descriptions for the board can be found below:

<figure>
<img src="../../Materials/img/nucleo_f401re_pin_descriptions.png" width="600px">
<figcaption>Figure 1: The NUCLEO F401RE board pin descriptions</figcaption>
</figure>

On 2 breadboards, build the circuits in Figure 2, using the hardware components listed in 2. [“2. Requirements”](#2-Requirements):

<figure>
<img src="../../img/lab6-switch-circuit.png" width="400px" >
<img src="../../img/lab6-led-circuit.png" width="400px" >
<figcaption>Figure 2: (Upper) Buttons Pulling GPIO inputs low; (lower) LED Outputs</figcaption>
</figure>

On a breadboard, connect all four buttons according to the diagram on the left.  Your buttons should pull the GPIO pin low. Then connect the buttons and the LED to their respective pin on the board as defined in the table below.

| Pin | Pin name in Mbed API |
| - | - |
| `BUTTON 1` | D2 |
| `BUTTON 2` | D3 |
| `BUTTON 3` | D4 |
| `BUTTON 4` | D5 |
| `RED LED` | D6 |
| `GREEN LED` | D7 |
| `BLUE LED` | D8 |
| - | - |

| TASK 6-3-1 | Hardware Test |
| - | - |
| 1. | Set module6-3-1-hwtest as the active project |
| 2. | Build and run |
| 3. | Check all the LEDs are flashing |
| 4. | Press each button in turn and check the output in the serial monitor |

Note from figure 2 that the switches are configured as PULL-DOWN. 

* With the switch open, the 10k&Omega; resistor will pull the level up to 3.3V (HIGH). Virtual no current flows into the microcontroller.
* Pressing a switch will pull the respective input to 0V (LOW), and draw 0.1mA of current to ground.

If the hardware is not working, proceed no further and check the wiring carefully.

# 4 Software Interfaces

## 4.1 InterruptIn/InterruptOut Interfaces

The InterruptIn interface is used to trigger an event when a digital input pin changes. For example:
InterruptIn button_press(Input Pin);

```C++
void button_ISR(){
    Led_out = !Led_out;
}
 
int main(){
button_press.rise(&button_ISR);
while(1);					  // waiting for interrupts
}
```

Other functions are listed below:

| Function Name | Description |
| - | - |
| `void  rise (void(*fptr)(void))` | Attach a function to call when a rising edge occurs on the input |
| `template<typename T> void rise (T *tptr, void (T : :*mptr)(void))` | Attach a member function to call when a rising edge occurs on the input |
| `void  fall (void(*fptr)(void))` | Attach a function to call when a falling edge occurs on the input |
| `template<typename T > void  fall (T *tptr, void(T::*mptr)(void))` | Attach a member function to call when a falling edge occurs on the input |
| `void mode (PinMode pull)` | Set the input pin mode |
| `void  enable_irq ()` | Enable IRQ |
| `void  disable_irq ()` | Disable IRQ |
| - | - |

## 4.2 Low Power Mode

Use the sleep mode to reduce the power consumption of your application. For example, to use the Sleep-on-Exit feature you can use the wait-for-interrupt operation:

```C++
__wfi() ; 		//go to sleep.
```

# 5 Your Application Code
In this lab task, you will use the Mbed API for Interrupts in order to complete two exercises.

## 5.1 Toggle the Lights
In the first exercise, you need to use the Mbed API functions to:
* Define an InterruptIn and ISR for each bit from input
* Setup the interrupt service routine, so that the RGB LED is used to indicate when a button is pressed.
  * Button 1: toggles RED
  * Button 2: toggles GREEN
  * Button 3: toggles BLUE
  * Button 4: lights up WHITE (RED, GREEN and BLUE)
* Put the processor into sleep mode upon exiting from the ISR
Try to issue an interrupt on different signal edges (rising edge or falling edge). What changes?

## 5.2 Counter

In the second exercise, you will need to complete the skeleton code so that it counts the number of times a button has been pressed and lights up the RGB LED, which corresponds to the button which has been pressed the most.
* Button 1 corresponds to the Red LED
* Button 2 corresponds to the Green LED
* Button 3 corresponds to the Blue LED
* Button 4 is used to reset all the counters and turn off all the LEDs.
Also, if several buttons have been pressed the same number of times, their respective LEDs should all be ON simultaneously.

> **If you are stuck you can look at the code solution provided with the lab for some help.**

# 6 Additional References

**Documentation for Mbed API for Interrupts**

https://os.mbed.com/docs/mbed-os/v5.13/apis/interruptin.html#related-content 


[Table of Contents](/README.md#syllabus)

Copyright © 2021 Arm Limited (or its affiliates). All rights reserved. 