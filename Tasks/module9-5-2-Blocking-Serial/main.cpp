#include "mbed.h"
#include <chrono>

//Inputs
DigitalIn button_1(D2);

// Digital Outputs
DigitalOut redLED(D6);      

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

    //Turn ON blocking (happens to be the default)
    serial_port.set_blocking(true);
    
    //Write strings to the terminal
    char msg1[] = "Press 1 to turn ON the buzzer\n\r";
    char msg2[] = "Press 2 to turn OFF the buzzer\n\r";
    char msg3[] = "Press q to quit\n\r";
    serial_port.write(msg1, sizeof(msg1));
    serial_port.write(msg2, sizeof(msg2));
    serial_port.write(msg3, sizeof(msg3));

    //This will hold the single byte that we read
    char p = 0;

    // Read and process
    do {
        //Read serial terminal
        serial_port.read(&p, 1);

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

        // LED control
        if (button_1 == 1) redLED = 1;   else redLED = 0;

        // Small 250ms wait to demonstrate buffering behaviour
        wait_us(250000);

    } while (p != 'q');

    sleep();
}
