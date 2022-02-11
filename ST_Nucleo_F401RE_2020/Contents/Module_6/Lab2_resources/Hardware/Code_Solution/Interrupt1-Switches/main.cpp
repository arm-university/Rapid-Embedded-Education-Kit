/*----------------------------------------------------------------------------
LAB EXERCISE 2.1 - INTERRUPT IN/OUT
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
	
	__enable_irq();
	
	//initially turn off all LEDs
	led1 = 0;
	led2 = 0;
	led3 = 0;
	
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
