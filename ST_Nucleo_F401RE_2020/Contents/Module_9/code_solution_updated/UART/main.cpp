#include "mbed.h"

// Serial tx, rx connected to the PC via an USB cable
static BufferedSerial device(D1, D0);
char buf[]="Hello to the World of mbed!\n\r";
/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	//Set baudrate to 9600 bps
  device.set_baud(9600);
  device.write(buf,sizeof(buf));		// \n is for new line, \r is to return the cursor to starting position
}