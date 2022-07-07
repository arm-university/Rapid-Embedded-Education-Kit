#include "nonblocking_read.h"

// Create a UnbufferedSerial object for keyboard input.
static BufferedSerial serial_port(USBTX, USBRX);
static bool isInitialised = false;

//Initialise the serial interface
static void initSerial()
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
}    

char getCharNonblocking()
{
    //Lazy initialisation
    if (!isInitialised) initSerial();

    //Read byte non-blocking
    char p;
    // Is there a character in the buffer to read?
    if (serial_port.read(&p, 1) != -EAGAIN) { 
        // - Note: EAGAIN is a standard error message that means "no data available, try again later". 
        // - Only meaningful for non-blocking reads
        return p;
    } else {
        return 0;
    }
}
