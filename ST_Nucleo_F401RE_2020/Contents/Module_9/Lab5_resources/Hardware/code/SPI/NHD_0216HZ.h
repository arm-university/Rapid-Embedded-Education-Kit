/*----------------------------------------------------------------------------
 Definitions header file for Newhaven NHD0216HZ LCD
 *----------------------------------------------------------------------------*/

#ifndef NHD_0216HZ_H
#define NHD_0216HZ_H

//Define constants
#define ENABLE 0x08
#define DATA_MODE 0x04
#define COMMAND_MODE 0x00

#define LINE_LENGTH 0x40
#define TOT_LENGTH 0x80
		
	//Function prototypes
	void write_cmd(int data);
	void write_data(char c);
	void write_4bit(int nibble, int mode);
	void init_spi(void);
	void init_lcd(void);
	void set_cursor(int column, int row);
	void print_lcd(const char *string);

#endif

// *******************************ARM University Program Copyright (c) ARM Ltd 2019*************************************
