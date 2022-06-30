#include "mbed.h"

//Constants
#define N 1000000
#define RELEASED 1
#define PRESSED  0
#define BTN_STATE_STR(x) ((x==PRESSED) ? "RELEASED" : "PRESSED")

DigitalOut red_led(D6);     //CountUp is in its critical section
DigitalOut yellow_led(D8);  //CountDown is in its critical section
DigitalOut green_led(D7);   //counter != 0

DigitalIn button(BUTTON1);

//Shared mutable state
volatile long long counter = 0; //Volatile means it must be stored in memory

//Increment the shared variable 
void countUp()
{
    //RED MEANS THE COUNT UP FUNCTION IS IN ITS CRITICAL SECTION
    green_led = 1;
    for (unsigned int n=0; n<N; n++) {
        CriticalSectionLock::enable();
        counter++; 
        counter++;
        counter++;
        counter++;
        counter++;
        counter++;
        counter++;
        counter++;
        counter++;
        counter++; 
        CriticalSectionLock::disable();
    }  
    green_led = 0; 
    
    //Last to finish turns out the red light
    if (counter == 0) {
        red_led = 0;   
    }
}

//Decrement the shared variable
void countDown()
{
    //YELLOW MEANS THE COUNT DOWN FUNCTION IS IN ITS CRITICAL SECTION
    yellow_led = 1;
    for (unsigned int n=0; n<N; n++) {
        CriticalSectionLock::enable();
        counter--;
        counter--;
        counter--;
        counter--;
        counter--;
        counter--;
        counter--;
        counter--;
        counter--;
        counter--;  
        CriticalSectionLock::disable();
    }
    yellow_led = 0;
      
    //Last to finish turns out the red light  
    if (counter == 0) {
        red_led = 0;   
    }     
}
int main() {

    printf(BTN_STATE_STR(button.read()));
    red_led = 1;
    Timeout t1;
    
    // TRY EACH OF THESE LINES IN TURN.
    // ALL IT DOES IS CHANGE THE TIMING OF THE ISR, NOT THE FUNCTION
    
    if (button == PRESSED) {
        //VERSION 2: short delay allowing main to be preempted - you might want to tweak this value
        t1.attach(&countDown, 15us);
    } else {
        //VERSION 1: 2s - ENOUGH TIME FOR COUNTUP TO FINISH
        t1.attach(&countDown, 2s);                   
    }
    
    //Run count up on the main thread
    countUp();
    
   
    //Now spin for ever
    while(1) { 
        wait_us(500000);
    };
}

