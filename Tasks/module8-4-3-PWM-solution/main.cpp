#include "mbed.h"
#include "nonblocking_read.h"
#include "math.h"
#include <chrono>
#include <cmath>

//Inputs
InterruptIn startButton(BUTTON1);
InterruptIn volDownButton(D2);
InterruptIn volUpButton(D3);
InterruptIn toneDownButton(D4);
InterruptIn toneUpButton(D5);

// Digital Outputs
DigitalOut redLED(D6,0);      
DigitalOut greenLED(D7,0);
DigitalOut blueLED(D8,1);   //Initial state ON

// PWM
PwmOut buzz(D9);

// Calculate the period for a given note
// note = 0, freq = 440Hz (middle A)
// note = +1, frequency is one tone above middle A
// note = -1, frequency is one tone below middle A
// Result is in uSeconds
uint32_t notePeriod(uint16_t note)
{
    double T = (10000.0/4.4) * pow(2.0, -(double)note/12.0);
    return round(T);
}

// Human ear is logarithmic - perceived loudness is proportional to log(power)
// Caluclate the pulse width for a volume vol
// where 1 <= vol <= 9
float calcVolume(uint16_t vol)
{
    return (1.0f/1024.0f) * (1 << vol);
}

//Shared mutable state
uint16_t vol  = 1;
uint16_t note = 0;  // Musical A

// ISRs for buttons
// These do not perform any debounce so may be a bit erratic
void increaseVolume() {
    CriticalSectionLock lock;
    vol = vol + ( (vol <= 8) ? 1 : 0);
    buzz =calcVolume(vol);
}
void decreaseVolume() {
    CriticalSectionLock lock;
    vol = vol - ( (vol >= 2) ? 1 : 0);
    buzz = calcVolume(vol);
}
void increaseTone() {
    CriticalSectionLock lock;
    note = note + 1;
    buzz.period_us(notePeriod(note));
}
void decreaseTone() {
    CriticalSectionLock lock;
    note = note - ((note >= 1) ? 1 : 0);
    buzz.period_us(notePeriod(note));
}

void init()
{
    //Turn off this interrupt as we're finished with it
    startButton.rise(NULL);

    //Initial tone - 440Hz
    buzz.period_us(notePeriod(note));
    buzz = calcVolume(vol);

    //Setup ISRs for volume and tone
    volDownButton.rise(decreaseVolume);
    volUpButton.rise(increaseVolume);
    toneDownButton.rise(decreaseTone);
    toneUpButton.rise(increaseTone);
}

int main() 
{
    //Press blue button to start (and press the black button to silence)
    startButton.rise(init);

    //Sleep until interrupted... then sleep again!
    while (true) {
        sleep();
    }
}