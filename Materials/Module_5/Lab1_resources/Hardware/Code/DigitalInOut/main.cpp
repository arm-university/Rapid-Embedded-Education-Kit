
#include "mbed.h"

#define BUTTON_1 D2 
#define BUTTON_2 D3 
#define BUTTON_3 D4 
#define BUTTON_4 D5 

#define RED_LED D6
#define GREEN_LED D7
#define BLUE_LED D8


// Define the Input pins 
	//Write your code here

//Define the Output pins
	//Write your code here

//Define Input/Output buses
	//Write your code here

void ControlLED_DigitalIO ();
void ControlLED_BusIO ();


int main()
{
    while(1) {
        ControlLED_DigitalIO ();
        // ControlLED_BusIO ();
        wait(0.25);
    }
}

void ControlLED_DigitalIO (){
          //Write your code here
}

void ControlLED_BusIO (){
    //Write your code here
}
