
#include "mbed.h"

#define BUTTON_1 D2 
#define BUTTON_2 D3 
#define BUTTON_3 D4 
#define BUTTON_4 D5 

#define RED_LED D6
#define GREEN_LED D7
#define BLUE_LED D8


DigitalIn  b1(BUTTON_1); 
DigitalIn  b2(BUTTON_2); 
DigitalIn  b3(BUTTON_3); 
DigitalIn  b4(BUTTON_4);
// Define the Input pins 

DigitalOut rled(RED_LED);
DigitalOut gled(GREEN_LED);
DigitalOut bled(BLUE_LED);
//Define the Output pins

BusIn buttonsbus (BUTTON_1,BUTTON_2,BUTTON_3,BUTTON_4);
BusOut ledsbus(BLUE_LED, GREEN_LED, RED_LED);
//Define Input/Output buses

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
    rled = (!b4&&(!b3||b2)) || (b4&&b3&&b2&&b1);
    gled= (b4^b3) || (b4&&b3&&b2&&b1);
    bled = b4;
}

void ControlLED_BusIO (){
    switch (buttonsbus){
        case 0 ... 3: 
            ledsbus=0b0100;
            break;
        case 4 ... 5: 
            ledsbus=0b0010;
            break;
        case 6 ... 7: 
            ledsbus=0b0110;
            break;
        case 8 ... 11: 
            ledsbus=0b0011;
            break;
        case 12 ... 14: 
            ledsbus=0b0001;
            break;
        case 15: 
            ledsbus=0b0111;
            break;
        default: ;
    }
}
