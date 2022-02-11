/*----------------------------------------------------------------------------
 Header file for Newhaven NHD0216HZ LCD
 *----------------------------------------------------------------------------*/

#ifndef NHD_0216HZ_H
#define NHD_0216HZ_H

#include "mbed.h"

//Define constants
#define ENABLE 0x08
#define DATA_MODE 0x04
#define COMMAND_MODE 0x00

#define LINE_LENGTH 0x40
#define TOT_LENGTH 0x80

class NHD_0216HZ{
	public:
		NHD_0216HZ(PinName SPI_CS, PinName SPI_MOSI, PinName SPI_SCLK);
	
		//Function prototypes
		void shift_out(int data);
		void init_lcd(void);
		void write_4bit(int data, int mode);
		void write_cmd(int data);
		void write_data(char c);
	    void printf(const char *format, ...);
		void set_cursor(int column, int row);
		void clr_lcd(void);

	private:
		DigitalOut _SPI_CS;
		DigitalOut _SPI_MOSI;
		DigitalOut _SPI_SCLK;
};
#endif

// *******************************ARM University Program Copyright (c) ARM Ltd 2014*************************************
