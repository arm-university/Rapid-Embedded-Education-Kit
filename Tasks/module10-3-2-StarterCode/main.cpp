/* LCD demo for Lab 1. Sends character strings to LCD
 * LCD is operated in 4-bit mode.  */

#include "mbed.h"
#include "temp_sensor.h"
#include "lcd.h"


#define BUTTON_1 D2
#define BUTTON_2 D3
#define BUTTON_3 D4
#define BUTTON_4 D5
#define RED_LED D6
#define GREEN_LED D7
#define BLUE_LED D8
#define SPEAKER D9

DigitalOut redLED(RED_LED);

//----------- MAIN function ---------------//
int main() 
{
    //Temperature
    float temp = readtemperature();
    char tStr[20];
    snprintf(tStr, 20, "%4.1f", temp);

    // LCD
    CS_LCD=1;
    init_lcd();  //initialise the LCD
    clr_lcd();   //Clear the LCD

    print_lcd("Temperature:");
    write_cmd(0xc0);   //set cursor to second line
    wait_us(40);
    print_lcd(tStr);
    print_lcd(" C");

    //idle in permanent loop
    while (true) {       
        //Main thread heart-beat 
        ThisThread::sleep_for(500ms);
        redLED = !redLED;
    }
}   //end of Main


