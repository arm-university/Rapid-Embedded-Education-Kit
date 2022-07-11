#include "uop_msb.h"
#include <chrono>
using namespace uop_msb;

#define WAIT_TIME_MS 100 
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalIn blueButton(USER_BUTTON);

// Create a UnbufferedSerial object with a default baud rate.
static BufferedSerial serial_port(USBTX, USBRX);

int main()
{
    // Set up the serial port to 9600,8,N,1
    serial_port.set_baud(9600);
    serial_port.set_format(
        /* bits */ 8,
        /* parity */ SerialBase::None,
        /* stop bit */ 1
    );

    //This is critical - turn off blocking
    serial_port.set_blocking(false);
    
    //Write strings to the terminal
    char msg1[] = "Press a key to toggle the green LED\n\r";
    char msg2[] = "Press 1 to turn ON the buzzer\n\r";
    char msg3[] = "Press 2 to turn OFF the buzzer\n\r";
    serial_port.write(msg1, sizeof(msg1));
    serial_port.write(msg2, sizeof(msg2));
    serial_port.write(msg3, sizeof(msg3));

    //This will hold the single byte that we read
    char p;

    //Timer used to flash blue LED
    Timer tmr;
    tmr.start();

    //Buzzer
    Buzzer buzz;

    while (true)
    {
        // Is there a character in the buffer to read?
        if (serial_port.read(&p, 1) != -EAGAIN) { 
            // - Note: EAGAIN is a standard error message that means "no data available, try again later". 
            // - Only meaningful for non-blocking reads
            
            //Toggle LED
            led1 = !led1;

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
            default:
                //Echo typed character to the terminal
                serial_port.write(&p,1);
                break;
            };
        }
        
        //Flash second LED
        if (tmr.elapsed_time() >= 250ms) {
            tmr.reset();
            led2 = !led2;
        }
    
        //Experiment -  uncommend the following line. Are any characters missed?
        //wait_us(1000000);   //Delay 1 seconds

    }
}
