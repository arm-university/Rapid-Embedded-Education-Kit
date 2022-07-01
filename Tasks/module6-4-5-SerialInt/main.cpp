#include "mbed.h"
#include <chrono>
#include <ratio>
using namespace chrono;

// Create a DigitalOutput object to toggle an LED whenever data is received.
DigitalOut ledRed(D6);
DigitalOut ledGreen(D7);
DigitalOut led1(LED1);

// Create a UnbufferedSerial object with a default baud rate.
UnbufferedSerial serial_port(USBTX, USBRX);

//Ticker
Ticker ledTicker;

//Reason why MCU left sleep
volatile bool isT_updated = false;

//Flash rate (us)
volatile long long T = 500000;

//ISR for flashing green LED
void onTick() {
    ledRed = !ledRed;
    ledRed.write(1);
}

void on_rx_interrupt()
{
    CriticalSectionLock lock;
    char p;

    // NON blocking - Read the data to clear the receive interrupt.
    if (serial_port.read(&p, 1)) {

        //Check the character input
        switch (p) {
        case '1':
            //Switch on Green LED
            ledGreen = 1;
            break;
        case '2':
            //Switch off Green LED
            ledGreen = 0;
            break;
        case '+':
            T += 100000;
            isT_updated = true;
            ledTicker.detach();
            ledTicker.attach(&onTick, microseconds(T));
            break;
        case '-':
            if (T >= 200000) {
                T -= 100000;
                ledTicker.detach();
                ledTicker.attach(&onTick, microseconds(T));
                isT_updated = true;
            }
            break;            
        default:
            //Echo typed character to the terminal
            serial_port.write(&p,1);
            serial_port.write("\n\r",2);
            break;
        };
    }

    // Toggle the onboard LED with each press
    led1 = !led1;
}


int main(void)
{
    // Set desired properties (115200-8-N-1).
    serial_port.baud(115200);
    serial_port.format(
        /* bits */ 8,
        /* parity */ SerialBase::None,
        /* stop bit */ 1
    );

    //ISR to flash led
    ledTicker.attach(&onTick, microseconds(T));

    // Register a callback to process a Rx (receive) interrupt.
    serial_port.attach(&on_rx_interrupt, SerialBase::RxIrq);

    while (true) {

        //Enter low power state until an ISR wakes the CPU
        sleep(); 

        // Safely access shared mutable state
        CriticalSectionLock::enable();

        if (isT_updated) {
            // printf would use the same serial interface, so we do things manually
            char strBuff[32];
            snprintf(strBuff, 32, "T=%Ldms\n\r", T/1000L);
            //sprintf(strBuff, "T = %Ld ms", T/1000L); //Not safe
            serial_port.write(strBuff, strlen(strBuff));
            serial_port.write("\n\r",2);
            isT_updated = false;
        }
 
        //Release lock
        CriticalSectionLock::disable();
    }
    
}