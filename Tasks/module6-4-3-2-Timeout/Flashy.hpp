#include "mbed.h"
#include <iostream>
#include <chrono>
#include <ratio>
using namespace std;
using namespace chrono;

class Flashy 
{
    private:
    Ticker _tk;             // Ticker used to generate periodic interrupts
    milliseconds _t=0ms;    // Interval between LED state changes
    DigitalOut _led;        // GPIO output pin being "Flashed"

    void tickerISR() {      // ISR for Ticker
        _led = !_led;
    }

    public:
    //Constructor - sets the default flash interval to 1/2 second
    Flashy(PinName ledPin, milliseconds flashInterval = 500ms) : _led(ledPin) {
        *this=flashInterval;
    }

    //Set the flash interval
    void operator = (milliseconds newTime) {
        if (newTime == _t) return;
        if (newTime < 50ms) return;
        _t = newTime;
        _tk.detach();
        _tk.attach(callback(this, &Flashy::tickerISR), _t);
    }

    //Increment the time interval
    void operator += (milliseconds deltaT) {
        *this = _t + deltaT;
    }

    //Decrement the time interval
    void operator -= (milliseconds deltaT) {
        *this = _t = deltaT;
    }

};