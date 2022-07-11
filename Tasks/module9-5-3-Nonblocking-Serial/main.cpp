#include "mbed.h"
#include <chrono>
#include <cstdio>
#include <functional>

//Inputs
DigitalIn button_1(D2);
DigitalIn blueButton(BUTTON1);

// Digital Outputs
DigitalOut redLED(D6); 
DigitalOut greenLED(D7,1);
DigitalOut onBoardLED(LED1);     

// PWM
PwmOut buzz(D9);

// Create a UnbufferedSerial object with a default baud rate.
BufferedSerial serial_port(USBTX, USBRX);

int main()
{
    // Set up the serial port to 9600,8,N,1
    serial_port.set_baud(9600);
    serial_port.set_format(
        /* bits */ 8,
        /* parity */ SerialBase::None,
        /* stop bit */ 1
    );

    // ******************** Turn OFF blocking ********************
    serial_port.set_blocking(false);
    // ***********************************************************
    
    //Write strings to the terminal
    char msg1[] = "Press 1 to turn ON the buzzer\n\r";
    char msg2[] = "Press 2 to turn OFF the buzzer\n\r";
    char msg3[] = "Press q to quit\n\r";
    serial_port.write(msg1, sizeof(msg1));
    serial_port.write(msg2, sizeof(msg2));
    serial_port.write(msg3, sizeof(msg3));

    //This will hold the single byte that we read
    char p = 0;
    int switchInput=0, previousSwitchInput = 0;

    //Wait for blue button
    char msg4[] = "Press the blue button to start\n\r";
    serial_port.write(msg4, sizeof(msg4));
    while (blueButton == 1);

    do
    {
        //READ ALL INPUTS WITHOUT BLOCKING
        switchInput = button_1.read();

        //Update if there was a change
        if (switchInput != previousSwitchInput) {
            redLED = switchInput;
            previousSwitchInput = switchInput;
        }

        // Is there a character in the buffer to read?
        if (serial_port.read(&p, 1) != -EAGAIN)             // Non-blocking read
        { 
            //Yes - there is a character -  indicate with a flash
            onBoardLED = !onBoardLED;

            //Control buzzer depending on response
            switch(p) {
                case '1':
                buzz.period_ms(1);
                buzz = 0.5f;
                break;
                case '2':
                buzz = 0.0f;
                break;
                default:
                printf("You typed ASCII %u\n\r", (unsigned int)p);
            }            
        }

        //Toggle the green LED each time the (rapid) polling loop repeats
        greenLED = !greenLED;

    } while (p != 'q');

    //Comment this out to see the change
    serial_port.enable_input(false);

    //Once finished - sleep
    while (true) {
        sleep();
        onBoardLED = !onBoardLED;
    }
 
}