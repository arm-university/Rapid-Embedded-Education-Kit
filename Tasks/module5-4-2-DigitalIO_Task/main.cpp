
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
DigitalIn  b1(BUTTON_1); 
DigitalIn  b2(BUTTON_2); 
DigitalIn  b3(BUTTON_3); 
DigitalIn  b4(BUTTON_4);

//Output pins
DigitalOut redLed(RED_LED);
DigitalOut greenLed(GREEN_LED);
DigitalOut blueLed(BLUE_LED);

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

}
