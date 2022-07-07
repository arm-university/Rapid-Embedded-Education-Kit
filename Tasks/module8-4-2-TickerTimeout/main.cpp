#include "mbed.h"

Ticker t1;
Ticker t2;
Timeout oneShot;

DigitalOut led1(D6);
DigitalOut led2(D7);
DigitalOut led3(D8);
 
void flip1() {
    led1 = !led1;
}

void flip2() {
    led2 = !led2;
}
 
int main() {
    // Passing a function pointer
    t1.attach(&flip1, 500ms); 
    t2.attach(&flip2, 700ms);

    //Using a C++ lambda function
    oneShot.attach( []() { led3 = 1; }, 5s);

    // Sleep in the main loop
    while(1) {
        sleep();
        printf("I'm awake\n\r");
    }
}