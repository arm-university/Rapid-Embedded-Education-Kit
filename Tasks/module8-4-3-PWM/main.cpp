#include "mbed.h"
#include "nonblocking_read.h"
#include "math.h"
#include <chrono>
#include <cmath>

//Inputs
DigitalIn startButton(BUTTON1);
BusIn volControl(D2, D3);      //Button_1 and Button_2
BusIn freqControl(D4, D5);     //Button_3 and Button_4

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

int main() 
{
    uint16_t vol  = 1;
    uint16_t note = 0;  // Musical A

    //Press blue button to start (and press the black button to silence)
    while (startButton == 1);

    //Initial tone - 440Hz A
    buzz.period_us(notePeriod(note));
    buzz = calcVolume(vol);

    while (true) {

        // Update volume
        switch (volControl.read())
        {
            case 1:
            vol = vol - ( (vol >= 2) ? 1 : 0);
            buzz = calcVolume(vol);
            break;
            
            case 2:
            vol = vol + ( (vol <= 8) ? 1 : 0);
            buzz =calcVolume(vol);
            break;
        }

        // Update frequency
        switch (freqControl.read())
        {
            case 1:
            note = note + 1;
            buzz.period_us(notePeriod(note));
            break;

            case 2:
            note = note - ((note >= 1) ? 1 : 0);
            buzz.period_us(notePeriod(note));
            break; 
        }

        ThisThread::sleep_for(250ms);
    }
}