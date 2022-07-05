#include "mbed.h"

// Direct access MCU registers
DigitalOut led1(LED1); // Let Mbed OS initialise PA_5

int main(){

    //Let's have a look at the address of the BSRR register for PORTA
    uint32_t *p = (uint32_t*)0x40020018;
    printf("BSRR Address= %p\n", p);

    while(true){
 
        //Set PA_5 HIGH
        *p = 1<<5;
        wait_us(500000);

        //Reset PA_5 
        *p = 1<<21; 
        wait_us(500000);
    }
}

