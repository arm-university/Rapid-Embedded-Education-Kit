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
<figcaption>Figure 2: (Upper) Buttons Pulling GPIO inputs HIGH; (Lower) LED Outputs</figcaption>
</figure>

On a breadboard, connect all four buttons according to the diagram on the left.  For the purpose of this lab, your buttons should pull the GPIO pin HIGH. Then connect the buttons and the LED to their respective pin on the board as defined in the table below.

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
| 1. | Set `module6-3-1-hwtest` as the active project |
| 2. | Build and run |
| 3. | Check all the LEDs are lighting up |
| 4. | Press each button in turn and check the output in the serial monitor |

Note from figure 2 that the switches are configured as PULL-UP. 

* With the switch open, the 10k&Omega; resistor will pull the level down to 0V (LOW). Almost no current flows out of the microcontroller pin.
* Pressing a switch will pull the respective input to 3.3V (HIGH), and conduct 0.1mA of current to ground via the resistor.

If the hardware is not working, proceed no further and check the wiring carefully.

# 4 Software Interfaces

## 4.1 InterruptIn in C

The InterruptIn interface is used to trigger an event when a digital input pin (GPIO) changes. 

| Task 4.1 | InterruptIn |
| - | - |
| 1. | Set task-4-1 as your active project. Build and run |
| 2. | Press and release each of the buttons |
| - | Observe the console output and LED states |

Let's now look at some key points in this code. First, we declare 4 instances of `InterruptIn`.

```C++
InterruptIn button1(D2);
InterruptIn button2(D3);
InterruptIn button3(D4);
InterruptIn button4(D5);
```

 This is similar to `DigitalIn` except we can now enable interrupts as follows:

 ```C++
button1.rise(&button1ISR);
button2.rise(&button2ISR);
button3.fall(&button3ISR);
button4.fall(&button4ISR);
  ```

Not that the only parameter is the address of a function (otherwise known as a **function pointer**). This function takes no parameters and returns nothing. This function is known as an **Interrupt Service Routine (ISR)**

One of these is shown below:

```C++
void button1ISR() {
    ledRed = !ledRed;
}
```

Note also how a particular type of event triggers an interrupt. For `InterruptIn`, this is either a rising or falling edge.

There are a few key points to note about an ISR:

* They are usually kept very short and execute quickly.
* Once these functions are configured as ISRs, they are ONLY called by the hardware using the on-chip Nested Interrupt Vector Controller (NVIC). 
   * You do not normally call an ISR in your code.
* All code inside the ISR must be **interrupt safe** and **re-entrant**. Many functions (such as `printf`) do not qualify.
   * Calling functions that are not interrupt safe will result in unpredictable behaviour!


> **WARNING** *There are many hazzards when using interrupts. You should first learn about how to write them safely before considering using them*

The remaining code in main spends most of it's time in a low-power sleep state:

```C++
while (true)
{
    cout << "Going to sleep...." << endl;
    sleep();
    cout << "Awake!" << endl;
}
```

Once in the sleep state, the MCU will only wake upon an interrupt. This is a power-efficient way to write software. 

`InterruptIn` has other functions are listed below:

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


## 4.2 InterruptIn and C++ (Optional)

This section is for readers who are experienced in *writing* C++ and prefer to write their code in an Object Orientated way. If you are not familiar with C++, you may want to skip this section.

`InterruptIn` is of course a C++ class, but the code in the previous section used ISRs written as C-functions. This is the simplest approach, as each function has a unique address in memory, and has access to local and global state, such as variables and IO.

With C++, the situation gets a bit more complex (and is a source of confusion) due to the way class member functions are called.

> Identical C++ class member functions are shared across all instances of a class, and there is only one copy of the function code. *However*, each instance has exclusive access to it's member variables via the *this* pointer.
>
>> Therefore, each instance of a class (object) shares the same identical member function code. This makes sense as the code is read-only.
>
>> Conversely, each instance of a class (object) contains it's own independent set of member variables. 
>
> When you invoke a member function on an object (instance of a class), it needs to know where it's member variables are in memory. Under the hood, the address for each object is passed as a hidden parameter, which becomes the *this* pointer.

Therefore, to use a member function as an ISR, we need two pieces of information:

* Address of the function (which has access to member variables)
* The *this* pointer (so it can locate the member variables)

Let's look at an example to illustrate how this is achieved:

| Task 4.2 | InterruptIn in C++ |
| - | - |
| 1. | Set task-4-2 as your active project. Build and run |
| 2. | Note how it performs the same as the previous task |
| 3. | Look closely at the constructor of the `ButtonFlash` class |
| - | The initialiser list ensure the members are initialised correctly BEFORE the constructor runs |
| - | The constructor initialises the interrupts |

The following would NOT work:

```C++
this->_button1.rise(&_button1ISR);
```

As explained above, all instances of the class share the same member function `_button1ISR`. This function would have no way to know the value of *this*.

Luckily, the Mbed OS framework handles this for you via the `callback` function:

```C++
this->_button1.rise(callback(this, &ButtonFlash::button1ISR));
```

To instantiate an object for this set of buttons and LEDs, the following line is used:

```C++
ButtonFlash obj(D2,D3,D4,D5, D6,D7,D8);
```

| Task 4.2 | continued... |
| - | - |
| 4. | Simplify the class to simply control one LED with one switch |
| - | The constructor only needs two pin names - one for the switch and one for the LED |
| - | Add a parameter (`bool`) to control whether a rising or falling edge should be used |
| 5. | Create 3 instances, one for each LED and test |
| - | A example solution is provided |

If you really like C++ templates, then by all means look at the sources to see how this works! For this course, it is enough to simply *use* `callback` whenever we involve C++.

## 4.3 Timer Interrupts

Nearly every Microcontroller has a number of hardware **timers**. These on-chip devices can be programmed to count independently of the CPU, even when the CPU is in sleep mode. 

> It should be noted that all timers are driven from the same clock tree, so are fully synchronous. 

* The programmer can read (poll) these timers. 
* Timers can generate one or more interrupts.

There are three timer classes of interest:

* `Timer` - this is used to start and stop a hardware timer. The developer is able read it's value at any time. This class does not support interrupts.
* `Timeout` - this is used to generate a **single** interrupt after a designated period of time.
* `Ticker` - generates periodic interrupts that fire at regular intervals.

For this section, we are concerned with interrupts so we will look more closely at `Timeout` and `Ticker`. It is important to note the following examples do not use the RTOS, and is in "bare metal" mode.

### 4.3.1 - Ticker Class (periodic)
In this task, we will look at the `Ticker` class to generate periodic interrupts. The basic usage of `Ticker` is to execute a C function every `T` seconds, where T>0.0.

For example, if we wish to call the C function `funcRed` every 0.25s, we could do the following:

1. Write the Interrupt Service Routine (ISR) function:

```C++
void funcRed() {
    ledRed = !ledRed;
}
```

2. Instantiate an instance of `Ticker`

```C++
Ticker tickRed;
```

3. Initialise the Ticker object

```C++
tickRed.attach(&funcRed, 250ms);
```

Note the first parameter is the **address** of the function `funcRed` (a function pointer). The second parameter is the duration between interrupts. 

> The second parameter is of type `std::chrono::microseconds`. This is an 8-byte integer (under the hood, it is type `long long`). Thanks to the standard C++ `chrono` class,  literal values can be written in a human readable way, with both values and units. The unit suffix ensures the actual value is scaled to the correct value.

| TASK 4.3.1 | `Ticker` |
| - | - |
| 1. | Make the project `module6-4-3-1-Ticker` the active project. Build and run. |
| 2. | Try pressing 1 or 2 to slow down or speed up the flash rate of the LED |
| 3. | Study the code and read the comments to try and understand how this code works. A copy is provided below for your convenience |
| 4. | Note the loop in the function `main`. There is a line that read `char c = getchar();`. This is a BLOCKING read, therefore no code in main will run until a key is pressed. |
| -  | Can you explain how the LEDs continue to flash even through the code stops on this line? |
| 5. |  Modify the code so that the flash rate of the green LED can be changed. Use keys 3 and 4 |

```c++
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
```

**Key points**

* Note how the ISR functions `funcRed` and `funcGreen` are never called directly. They are invoked by the Nested Vectored Interrupt Controller (NVIC) inside the microcontroller. 

* The interrupts are generated by hardware Timers. These fire periodically.

* To change the period of the `Ticker`, you must first `detach` and then `attach` with the new parameters.

If you want to use C++ and encapsulate a `Ticker` inside a class, this is also possible. This is illustrated in the next part of this task.

| TASK 4.3.1 | continued |
| - | - |
| 6. | The C++ class in `Flashy.hpp` is designed to make it easier to scale to multiple flashing LEDs. First study this code. Then change the code in `main.cpp` to use this class to make the code both shorter and more expressive |
| - | A solution is provided |

**Key points**

Again, to obtain the address (function pointer) for a C++ member function, you need to use `callback`.

```C++
_tk.attach(callback(this, &Flashy::tickerISR), _t);
```

where `this` is the address of the object and `&Flashy::tickerISR` specifies which member function to invoke.

### 4.3.2 - Timeout Class (one-shot)
In this task, we will look at the `Timeout` class. Unlike `Ticker` which periodically generates an interrupt (until it is detached), `Timeout` generates a single "one-shot" interrupt after a given interval.

| TASK 4.3.2 | `Timeout` |
| - | - |
| 1. | Make the project `module6-4-3-2-Timeout` the active project. Build and run. |
| 2. | Press and release the button. Observe the serial terminal and wait one second. You should see the LED go out. |

The relevant sections of code are shown below. First the `Timeout` object is instantiated:

```C++
Timeout oneshot;
``` 

The Interrupt Service Routine (ISR) is also defined:

```C++
void ledOFF() {
    ledRed = 0;
}
```

To call `ledOFF()` 1 second into the future, you would invoke the following:

```C++
//Trigger ISR in 1s
oneshot.attach(&ledOFF, 1s);  
```

 Switches are noisy. At the point switch contacts are made or released, it is common for there to be a short burst of multiple contact and release events. This is known as *switch bounce* and can last hundreds of ms. The result of this is registering multiple fake press and release events.

One way to address switch bounce is to ignore the switch signal for a period of time `T` after each first press (or release) is detected. This allows the mechanics (and hence signal) to acquire a steady state. We also want to do this in a power efficient way.

Consider the following sequence:

a) Wait for a switch press

b) Toggle the red LED and wait for 250ms (allows time for bounce noise to stop)

c) Wait for a switch release

d) Wait for 250ms - then goto (a)


| TASK 4.3.2 | continued |
| - | - |
| 3. | Starting with the project `module6-4-3-2-Timeout`, implement the above algorithm. |
| - | Use the `InterruptIn` class to detect the switch events and `Timeout` to wait for bounce noise to clear |
| hint | The sequence above spends most of it's time *waiting*, which in this context means putting the MCU into the sleep state. The transition between each of the states (a)-(d) is always caused by an interrupt. |
| - | A solution is provided. |

## Race Conditions

We simply cannot talk about interrupts without discussing race conditions.

In previous sections, all code was running *in-sequence*. From a logical standpoint, statements execute in the order they are written and there is no notion of parallel processing.

However, interrupts leverage hardware that runs *concurrently* with the CPU. We saw this with the hardware timer. The CPU can even sleep while the timer continues to count. 

Very often, the CPU will not be in a sleep state when an interrupt event occurs. When an interrupt occurs, the CPU will preempt (interrupt) whatever is taking place at that moment by:

* completing the current machine-code instructions
* pushing a set of registers onto the stack memory
* branching to the interrupt service routine
* executing the interrupt service routine
* popping the registers back off the stack memory
* resuming execution, *as if nothing had happened....*

*Except... something did happen*. The code in the ISR will have had some effect on the state of the system (otherwise it does nothing!). This might be to modify the hardware or a variable (still hardware, SRAM).

With the exception of trivial examples, we do NOT know when the ISR will run and interrupts are asynchronous events (consider the press of a button...your code cannot read the users mind!). Our code now contains *out-of-sequence operations*, and **this is potentially hazardous**.

You compiler knows nothing of interrupts. It's job is to check the syntax and if correct, efficiently convert C/C++ language statements into sequences of machine code. What we mean by efficient is also influenced by our optimisation settings. Compilers can employ all manner of techniques to improve the speed of your code (or reduce it's size), such as:

* cache variables in CPU registers
* change the order of code
* even remove code (that has no impact on code logic)

For example, consider the following code:
 
```C++
uint32_t dat[10];
uint32_t y = 0;
for (uint32_t n=0; n<10; n++) {
    dat[n] = 0;
    //Flash LED
    led = !led;

    y++;

    //Small delay (I think)
    for (uint32_t m=0; m<0x8000; m++);

    y++;
}
```

It is likely that:

* The index `n` is never created as a variable, and instead is cached in a 32-bit register. It cannot be used beyond the context of the loop and it is much faster to modify and read a CPU register.
* The inner delay loop is removed. Logically it does nothing, so gets optimised to nothing. The compiler does not know this is supposed to be a delay
* The two `y++` are combined into a single `y+=2`, or even removed from the loop, and replaced with a single `y+=20`.

Note that **optimisation does not change the logic** of your code, so this is not something we usually concern ourselves with. But we are using interrupts, with code that runs out-of-sequence.

> **Terminology** 
>
> *Mutable state* - anything that persists that can be modified, including memory (e.g. variables and hardware registers)
>
> *Shared Mutable State* - any mutable state that can be accessed from more than one one execution context, such as an interrupt service routine or thread. 

As you will soon learn, it is critical that we know **where** in our code mutable state is accessed. However we now we have some sources of uncertainty:

* We do not know where we will be in the code when an interrupt fires
* We not not really know the precise sequence of the compiled code
* We do not know when/if variables will be stored in memory

None of this is a problem, until you introduce out-of-sequence code, such as interrupts or threads (see later section on RTOS).

> **Terminology** 
>
> A *Race condition* (also called race hazard) is a problem with the design of a system. With a race condition, the result of a calculation or the behaviour of the system as a whole is dependent on how long a certain calculation takes, or when it is started. Race conditions occur in logic circuits and computer software, especially with multi-threaded or distributed systems.
> [Wikipedia, access July 2022](https://simple.wikipedia.org/wiki/Race_condition#:~:text=A%20Race%20condition%20%28also%20called%20race%20hazard%29%20is,certain%20calculation%20takes%2C%20or%20when%20it%20is%20started.)


The greatest concern with interrupts is the inadvertent introduction of race conditions. 

Let's now look at a **very** contrived example that somewhat forces the phenomena known as a **race condition** to occur.

// TODO Add example

It should be noted that *race conditions* are usually much more subtle and may take many hours, days or even years to detect. This is what makes them so *sinister*.

### The `CritcalSectionLock` class

### Example - Serial Interface Interrupts

## Non-reentrant functions

## Interaction with the RTOS?


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