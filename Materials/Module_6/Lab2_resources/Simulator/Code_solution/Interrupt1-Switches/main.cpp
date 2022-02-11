/*----------------------------------------------------------------------------
LAB EXERCISE 6.1 - INTERRUPT IN/OUT
PROGRAMMING USING MBED API
 ----------------------------------------
 In this exercise you need to use the Mbed API functions to:
 
	1) Define InterruptIn and ISR for each button press
	2) In the interrupt service routine, the RGB LED is used to indicate when a
	button was pressed:
			+ Button 1 - light RED
			+ Button 2 - light BLUE
			+ Button 3 - light GREEN
			+ Button 4 - light WHITE (RED, GREEN and BLUE at the same time)
			
	3) Put the processor into sleep mode upon exiting from the ISR
			
	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"


#define BUTTON_1 p5
#define BUTTON_2 p6 
#define BUTTON_3 p7 
#define BUTTON_4 p8 

#define RED_LED p9
#define GREEN_LED p10
#define BLUE_LED p11

//Define output
DigitalOut led1(RED_LED);
DigitalOut led2(GREEN_LED);
DigitalOut led3(BLUE_LED);

//Define Interrupt Inputs
InterruptIn button_1(BUTTON_1);
InterruptIn button_2(BUTTON_2);
InterruptIn button_3(BUTTON_3);
InterruptIn button_4(BUTTON_4);

//define ISRs for interrupts
void button_1_handler(){
	led1 = !led1;
}

void button_2_handler(){
	led2 = !led2;
}

void button_3_handler(){
	led3 = !led3;
}

void button_4_handler(){
	led1 = 1;
	led2 = 1;
	led3 = 1;
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
		
	//initially turn off all LEDs
	led1 = 0;
	led2 = 0;
	led3 = 0;
	
	//Interrupt handlers
	button_1.rise(&button_1_handler);
	button_2.rise(&button_2_handler);
	button_3.rise(&button_3_handler);
	button_4.rise(&button_4_handler);
	
	//wait 100 ms
	while(1)
		wait_ms(100);
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2019*************************************
