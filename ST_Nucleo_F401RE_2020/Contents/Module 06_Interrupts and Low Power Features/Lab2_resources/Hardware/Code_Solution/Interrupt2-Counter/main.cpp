/*----------------------------------------------------------------------------
LAB EXERCISE 2.2 - INTERRUPT IN/OUT - Counters
PROGRAMMING USING MBED API
 ----------------------------------------
In this exercise you will need to write some code so that it counts the number of times a button has been pressed and 
lights up the RGB LED. This will correspond to the button which has been pressed the most.
    •	Button 1 corresponds to the Red LED
    •	Button 2 corresponds to the Green LED
    •	Button 3 corresponds to the Blue LED
    •	Button 4 is used to reset all the counters and turn off all the LEDs.
Also, if several buttons have been pressed the same number of times their respective LEDs should all be ON simultaneously. 

 *----------------------------------------------------------------------------*/

#include "mbed.h"


#define BUTTON_1 D2 
#define BUTTON_2 D3 
#define BUTTON_3 D4 
#define BUTTON_4 D5 

#define RED_LED D6
#define GREEN_LED D7
#define BLUE_LED D8

//Define output
DigitalOut led1(RED_LED);
DigitalOut led2(GREEN_LED);
DigitalOut led3(BLUE_LED);

//Define Interrupt Inputs
InterruptIn button_1(BUTTON_1);
InterruptIn button_2(BUTTON_2);
InterruptIn button_3(BUTTON_3);
InterruptIn button_4(BUTTON_4);

//Define counters
volatile unsigned int count1;
volatile unsigned int count2;
volatile unsigned int count3;
volatile unsigned int countmax;


void updateLEDs(){
    led1 = 0;
	led2 = 0;
	led3 = 0;
    
    if(count1==countmax)led1=1;
    if(count2==countmax)led2=1;
    if(count3==countmax)led3=1;

}

//Define ISRs for interrupts
void button_1_handler(){
	count1++;
    if(count1>countmax) countmax=count1;
    updateLEDs();
}

void button_2_handler(){
    count2++;
    if(count2>countmax) countmax=count2;    
    updateLEDs();
    }

void button_3_handler(){
    count3++;
    if(count3>countmax) countmax=count3;
    updateLEDs();
    }

void button_4_handler(){
    led1 = 0;
	led2 = 0;
	led3 = 0;

	count1=0; 
    count2=0;
    count3=0;
    countmax=0;
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	
	__enable_irq();
	
	//initially turn off all LEDs and  set all the counters to 0
    button_4_handler();

	//Interrupt handlers
	button_1.rise(&button_1_handler);
	button_2.rise(&button_2_handler);
	button_3.rise(&button_3_handler);
	button_4.rise(&button_4_handler);
	
	//Sleep on exit
	while(1)
		__WFI();
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2019*************************************
