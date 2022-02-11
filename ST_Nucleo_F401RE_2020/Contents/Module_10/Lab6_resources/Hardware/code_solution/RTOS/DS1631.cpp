/*----------------------------------------------------------------------------
 MAXIM DS1631 2-wire temperature sensor library
 *----------------------------------------------------------------------------*/

#include "mbed.h"
#include "DS1631.h"

DS1631::DS1631(PinName sda, PinName scl, int addr) : temp_sensor(sda, scl), _addr(addr){
}

char cmd[] = {0x51, 0xAA};
char read_temp[2];

float DS1631::read(){
	temp_sensor.write(_addr, &cmd[0], 1);
	wait(0.5);
	temp_sensor.write(_addr, &cmd[1], 1);
	temp_sensor.read(_addr, read_temp, 2);
		
	float temp = (float((read_temp[0] << 8) | read_temp[1]) / 256);
	
	return temp;
}
// *******************************ARM University Program Copyright (c) ARM Ltd 2019*************************************
