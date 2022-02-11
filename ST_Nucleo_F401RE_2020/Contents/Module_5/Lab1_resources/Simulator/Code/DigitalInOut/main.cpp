
#include "mbed.h"

#define BUTTON_1 p5
#define BUTTON_2 p6
#define BUTTON_3 p7
#define BUTTON_4 p8

#define RED_LED p9
#define YELLOW_LED p10
#define BLUE_LED p11


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
