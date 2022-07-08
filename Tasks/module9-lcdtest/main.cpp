/* LCD demo for Lab 1. Sends character strings to LCD
 * LCD is operated in 4-bit mode.  */

#include "mbed.h"

#define ENABLE 0x08         //Will be ORed in to data value to strobe E bit
#define COMMAND_MODE 0x00   //used to clear RS line to 0, for command transfer
#define DATA_MODE 0x04      //used to set RS line to 1, for data transfer

DigitalOut CS(D10);
SPI ser_port(D11, D12, D13); // Initialise SPI, using default settings

//Function Prototypes
void clr_lcd(void);
void init_lcd(void);
void print_lcd(const char *string);
void shift_out(int data);
void write_cmd(int cmd);
void write_data(char c); 
void write_4bit(int data);

//----------- MAIN function ---------------//
int main() 
{
    // LCD

    CS=1;
    init_lcd();  //initialise the LCD
    clr_lcd();   //Clear the LCD

    print_lcd("  Hello world!");
    write_cmd(0xc0);   //set cursor to second line
    wait_us(40);
    print_lcd("      Testing");



    while (1) {        //idle in permanent loop
        thread_sleep_for (100);
    }
}   //end of Main

//----------- Other functions --------------//
void init_lcd(void) {   //follow designated procedure in data sheet
    thread_sleep_for (40);
    shift_out(0x30);    //function set 8-bit
    wait_us(37);
    write_cmd(0x20);    //function set
    wait_us(37);
    write_cmd(0x20);    //function set
    wait_us(37);
    write_cmd(0x0C);    //display ON/OFF
    wait_us(37);
    write_cmd(0x01);    //display clear
    wait_us(1520);
    write_cmd(0x06);    //entry-mode set
    wait_us(37);
    write_cmd(0x28);    //function set
    wait_us(37);
}
void write_4bit(int data, int mode) {  //mode is RS line, ie 0 for cmd, 1 for data
    int hi_n;
    int lo_n;
    hi_n = (data & 0xF0);           //form the two 4-bit nibbles that will be sent
    lo_n = ((data << 4) &0xF0);
    shift_out(hi_n | ENABLE | mode); //send each word twice, strobing the Enable line
    wait_us(1);
    shift_out(hi_n & ~ENABLE);
    shift_out(lo_n | ENABLE | mode);
    wait_us(1);
    shift_out(lo_n & ~ENABLE);
}
void shift_out(int data) {     //Invokes SPI
    CS = 0;
    ser_port.write(data);  
    CS = 1;
}
void write_cmd(int cmd) {
    write_4bit(cmd, COMMAND_MODE);  
}
void write_data(char c) {
    write_4bit(c, DATA_MODE);    //1 for data mode
}
void clr_lcd(void) {
    write_cmd(0x01);    //display clear
    wait_us(1520);
}
void print_lcd(const char *string) {
    while(*string){
        write_data(*string++);
            wait_us(40);
    }
}
