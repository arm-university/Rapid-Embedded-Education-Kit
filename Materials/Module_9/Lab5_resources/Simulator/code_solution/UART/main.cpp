#include "mbed.h"

// Serial tx, rx connected to the PC via an USB cable
Serial device(p13, p14);

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	//Set baudrate to 9600 bps
  device.baud(9600);
  device.printf("Hello to the World of mbed!\n\r");		// \n is for new line, \r is to return the cursor to starting position
}