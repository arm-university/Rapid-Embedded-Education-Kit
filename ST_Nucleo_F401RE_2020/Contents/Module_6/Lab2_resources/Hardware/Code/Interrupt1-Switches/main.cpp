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
	
	__enable_irq();			//enable interrupts
	
	//initially turn off all LEDs
	//Write your code here
	
	//Interrupt handlers
	//Attach the address of the ISR to the rising edge
	
		//Write your code here
	
	//Sleep on exit
	while(1){
		
		//Write your code here
	
	}
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2019*************************************
