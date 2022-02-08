/*----------------------------------------------------------------------------
LAB EXERCISE 6 - Real-Time Operating System
 ----------------------------------------
	Integrate functions developed in previous modules and run then concurrently
	in the Mbed RTOS. The following four threads have to be implemented:
	
	1. Display the temperature on the LCD
	2. Adjust the brightness of the RGB LED using a potentiometer
	3. Display an incrementing counter on the LCD
	4. Blink an LED

	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"
#include "DS1631.h"
#include "NHD_0216HZ.h"

# define LED D4
# define RED_LED D3
# define GREEN_LED D5
# define BLUE_LED D6
# define SPI_CS D10
# define SPI_MOSI D11
# define SPI_SCLK D13
# define I2C_SDA D14
# define I2C_SCL D15

/*
Define the mutex
Define the LCD display and the temperature sensor
Define other inputs and outputs
*/

//Write your code here


//Display temperature on the LCD
void temp_thread(){

	//Write your code here

}

//Adjust the brightness of the RGB LED
void adjust_brightness(){
	
    //Write your code here

}

//Blink an LED
void led1_thread(){
	
    //Write your code here

}

//Display a counter on the LCD
void count_thread(){

	 //Write your code here

}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	/*
    Initialise and clear the LCD display
	Start all threads
	Wait for timer interrupt
	*/
	
	//Write your code here
	
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2019*************************************
