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


#define BUTTON_1 p5
#define BUTTON_2 p6 
#define BUTTON_3 p7 
#define BUTTON_4 p8 

#define RED_LED p9
#define GREEN_LED p10
#define BLUE_LED p11

//Define outputs

	//Write your code here


//Define interrupt inputs

	//Write your code here


//Define ISRs for the interrupts
void button_1_handler(){
	
	//Write your code here
	
}

void button_2_handler(){
	
	//Write your code here
	
}

void button_3_handler(){
	
	//Write your code here
	
}

void button_4_handler(){
	
	//Write your code here
	
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
		
	//initially turn off all LEDs
	//Write your code here
	
	//Interrupt handlers
	//Attach the address of the ISR to the rising edge
	
		//Write your code here
	//wait 100 ms
	while(1)
		wait_ms(100);
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2019*************************************
