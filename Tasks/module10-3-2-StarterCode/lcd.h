#pragma once

#include "mbed.h"

#define ENABLE 0x08         //Will be ORed in to data value to strobe E bit
#define COMMAND_MODE 0x00   //used to clear RS line to 0, for command transfer
#define DATA_MODE 0x04      //used to set RS line to 1, for data transfer

//Function Prototypes
extern void clr_lcd(void);
extern void init_lcd(void);
extern void print_lcd(const char *string);

extern void write_cmd(int cmd);
extern void write_data(char c); 

extern DigitalOut CS_LCD;

