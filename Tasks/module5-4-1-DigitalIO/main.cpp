#include "DigitalInOut.h"
#include "mbed.h"

DigitalIn BUTTON_1(D2);
DigitalOut RED_LED(D6);

int main()
{

    if (BUTTON_1 == 1) {
        RED_LED = 1; 
    } else {
        RED_LED = 0; 
    }	

    //Spin forever
    while(true);
}
