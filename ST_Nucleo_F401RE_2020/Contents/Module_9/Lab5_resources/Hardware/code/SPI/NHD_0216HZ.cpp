/*----------------------------------------------------------------------------
 Newhaven NHD0216HZ LCD C/C++ file
 *----------------------------------------------------------------------------*/

#include "mbed.h"
#include "NHD_0216HZ.h"


#define SPI_MOSI D11
#define SPI_SCLK D13
#define SPI_CS D10

DigitalOut SS(SPI_CS);     //slave select a.k.a. cs or latch for shift reg
SPI spi(SPI_MOSI, NC, SPI_SCLK);

//Initialise SPI
void init_spi(void) {
    SS = 1;
    
    spi.format(8, 3);         //8bit spi mode 2
    spi.frequency(100000);    //100 kHz spi clock
}

//Initialise LCD
void init_lcd(void) {
    /*
	Implement the LCD initialisation using the information 
	from the ST7066U LCD driver datasheet (pages 25-26)
	*/
	
	//Write your code here
}

//Write 4bits to the LCD
void write_4bit(int nibble, int mode) {
    SS = 0;
    spi.write(nibble | ENABLE | mode);
    SS = 1;
    wait_us(1);
    SS = 0;
    spi.write(nibble & ~ENABLE);
    SS = 1;
}

//Write a command to the LCD
void write_cmd(int data) {
    int hi_n;
    int lo_n;
    
    hi_n = hi_n = (data & 0xF0);
    lo_n = ((data << 4) &0xF0);
    
    write_4bit(hi_n, COMMAND_MODE);
    write_4bit(lo_n, COMMAND_MODE);
}

//Write data to the LCD
void write_data(char c) {
    int hi_n;
    int lo_n;
    
    hi_n = hi_n = (c & 0xF0);
    lo_n = ((c << 4) &0xF0);
    
    write_4bit(hi_n, DATA_MODE);
    write_4bit(lo_n, DATA_MODE);
}

//Set cursor position
void set_cursor(int column, int row) {
    int addr;
    
    addr = (row * LINE_LENGTH) + column;
    addr |= TOT_LENGTH;
    write_cmd(addr);
}

//Print strings to the LCD
void print_lcd(const char *string) {
    while(*string){
        write_data(*string++);
    }
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2014*************************************
