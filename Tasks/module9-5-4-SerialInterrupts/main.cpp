#include "uop_msb.h"
#include <chrono>
#include <ratio>
using namespace uop_msb;
using namespace chrono;

//Buzzer
Buzzer buzz;

// Create a DigitalOutput object to toggle an LED whenever data is received.
static DigitalOut led1(LED1);
static DigitalOut led2(LED2);

// Create a UnbufferedSerial object with a default baud rate.
static UnbufferedSerial serial_port(USBTX, USBRX);

//Ticker
Ticker ledTicker;

//Flash rate (us)
volatile long long T = 500000;

//ISR for flashing blue LED
void onTick()
{
    led2 = !led2;
}

void on_rx_interrupt()
{
    CriticalSectionLock lock;
    char p;

    // Read the data to clear the receive interrupt.
    if (serial_port.read(&p, 1)) {

        //Check the character input
        switch (p) {
        case 13:
            //User pressed return
            serial_port.write("\n\r",2); //Echo a newline
            break;
        case '1':
            //Switch on buzzer
            buzz.playTone("A");
            break;
        case '2':
            //Switch off buzzer
            buzz.rest();
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

    // Toggle the LED.
    led1 = !led1; 
}

LCD_16X2_DISPLAY disp;

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
        disp.cls();
        disp.printf("T=%Ldms", T/1000);    
    }
    
}