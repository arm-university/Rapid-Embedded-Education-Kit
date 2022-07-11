#include "lcd.h"
void write_4bit(int data);
void shift_out(int data);

DigitalOut CS_LCD(D10);
static SPI ser_port(D11, D12, D13); // Initialise SPI, using default settings

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
static void write_4bit(int data, int mode) {  //mode is RS line, ie 0 for cmd, 1 for data
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
    CS_LCD = 0;
    ser_port.write(data);  
    CS_LCD = 1;
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