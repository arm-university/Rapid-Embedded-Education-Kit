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


//Define outputs

	//Write your code here


//Define interrupt inputs

	//Write your code here

//Define counters

    //Write your code here

void updateLEDs(){
    //Write your code here
}


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
	
	__enable_irq();
	
	//initially turn off all LEDs and  set all the counters to 0
	    //Write your code here

	//Interrupt handlers
	    //Write your code here

	//Sleep on exit
	while(1){
	    //Write your code here
    }
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2019*************************************
