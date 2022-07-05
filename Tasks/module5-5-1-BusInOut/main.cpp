
#include "mbed.h"

//Button Pin Names
#define BUTTON_1 D2 
#define BUTTON_2 D3 
#define BUTTON_3 D4 
#define BUTTON_4 D5 

// LED Pin Names
#define RED_LED D6
#define GREEN_LED D7
#define BLUE_LED D8

// Define the Input pins 
BusIn  buttons(BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4);
BusOut rgbLED(RED_LED, GREEN_LED, BLUE_LED);

//Function prototypes
void ControlLED_DigitalIO ();


int main()
{

    while(1) {
        ControlLED_DigitalIO ();
        ThisThread::sleep_for(250ms);
    }
}

void ControlLED_DigitalIO ()
{

    //TO BE DONE
    switch (buttons.read())
    {
        case 0 ... 2:
        break;

        default:
        break;
    }

}
