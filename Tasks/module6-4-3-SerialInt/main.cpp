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

//Flash rate (us)
volatile long long T = 500000;

//ISR for flashing blue LED
void onTick() {
    ledRed = !ledRed;
}

void on_rx_interrupt()
{
    CriticalSectionLock lock;
    char p;

    // NON blocking - Read the data to clear the receive interrupt.
    if (serial_port.read(&p, 1)) {

        //Check the character input
        switch (p) {
        case 13:
            //User pressed return
            serial_port.write("\n\r",2); //Echo a newline
            break;
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
            ledTicker.detach();
            ledTicker.attach(&onTick, microseconds(T));
            break;
        case '-':
            if (T >= 200000) {
                T -= 100000;
                ledTicker.detach();
                ledTicker.attach(&onTick, microseconds(T));
            }
            break;            
        default:
            //Echo typed character to the terminal
            serial_port.write(&p,1);
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

    // Register a callback to process a Rx (receive) interrupt.
    serial_port.attach(&on_rx_interrupt, SerialBase::RxIrq);

    //ISR to flash led
    CriticalSectionLock::enable();
    ledTicker.attach(&onTick, microseconds(T));
    CriticalSectionLock::disable();

    while (true) {
        sleep(); 

        //Safely get copy of T
        CriticalSectionLock::enable();
        long long currentT = T;
        CriticalSectionLock::disable();

        //printf cannot be performed in an ISR
        printf("T=%Ldms\n\r", currentT/1000L);    
    }
    
}