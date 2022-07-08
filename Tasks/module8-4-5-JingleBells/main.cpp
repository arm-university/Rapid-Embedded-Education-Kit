/*----------------------------------------------------------------------------
LAB EXERCISE  - TIMER AND PWM
 ----------------------------------------
Make an audio player to play music

Input: 2x potentiometers, one for tuning the music speed, and one for the volume
Output: PWM Speaker (play the music), and RGB LED (reflect the melody)

	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"
#include <chrono>
#include <ratio>
#include <math.h>

#define BUTTON_1 D2
#define BUTTON_2 D3
#define BUTTON_3 D4
#define BUTTON_4 D5
#define RED_LED D6
#define GREEN_LED D7
#define BLUE_LED D8
#define SPEAKER D9

// Frequency of middle C (Hz)
#define MIDDLEC 261.63

// Calculate frequency for each semi-tone in the chromatic scale
double noteFreq[12];    //C,C#,D,D#,E,F,F#,G,G#,A,A#,B
double notePeriod[12];
void preCalculateNotes()
{
    for (unsigned n=0; n<12; n++) {
        noteFreq[n] = MIDDLEC*pow(2.0, (double)n/12.0); // f_n = root * 2^(n/12)
        notePeriod[n] = (1.0 / noteFreq[n]);              // T_n = 1/T_n
    }
}

//MACROS to define the frequency of basic music notes (no accidentals)
#define Do(octave)  ((double)octave*noteFreq[0])      //C
#define Re(octave)  ((double)octave*noteFreq[2])      //D        
#define Mi(octave)  ((double)octave*noteFreq[4])      //E
#define Fa(octave)  ((double)octave*noteFreq[5])      //F
#define So(octave)  ((double)octave*noteFreq[7])      //G
#define La(octave)  ((double)octave*noteFreq[9])      //A
#define Si(octave)  ((double)octave*noteFreq[11])     //B
#define No          0.0                         //PAUSE - never set the PWM period to 0

//Define the beat length (e.g. whole note, half note) 
#define b1     0.5
#define b2     0.25
#define b3     0.125
#define b4     0.075

//Blue button to start
DigitalIn blueButton(BUTTON1);

//Define the PWM output for the speaker
PwmOut Speaker(SPEAKER);

/*---------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
    //Initialise the arrays
    preCalculateNotes();

    //Define the musical piece
    double note[] = { Mi(1),No,Mi(1),No,Mi(1),No, 
                      Mi(1),No,Mi(1),No,Mi(1),No,
                      Mi(1),No,So(1),No,Do(1),No,Re(1),No,Mi(1),No, 
                      Fa(1),No,Fa(1),No,Fa(1),No,Fa(1),No,Fa(1),No,Mi(1),No,Mi(1),No,Mi(1),No,Mi(1),No,Mi(1),Re(1),No,Re(1),Mi(1), Re(1),No,So(1),No};

    double beat[] = { b3,b3, b3,b3, b2,b2, 
                      b3,b3, b3,b3, b2,b2, 
                      b3,b3, b3,b3, b3,b3, b3,b3, b2,b1, b3,b3, b3,b3, b3,b3, b3,b3, b3,b3, b3,b3, b3,b3, b4,b4, b4,b4, b2,b3, b3,b2, b2, b2,b2, b2,b2};

    //Wait for button press
    while (blueButton == 1);

    //Play tune
    for (unsigned int n=0; n< sizeof(note)/sizeof(double); n++) {
        double nextNote     = note[n];   // This is the *frequency* of the note, or a zero (for a rest)
        double nextDuration = beat[n];   // This is the duration

        //Note or rest?
        if (nextNote == No) {
            Speaker = 0.0;           // Rest - sound off
        } else {
            double T = 1.0/nextNote; // Period of the next note
            Speaker.period(T);       // Set PWM period
            Speaker = 0.5;           // Volume to on
        }
        
        // Sets the duration of the note or rest
        wait_us(beat[n]*1000000);
    }

    // All done - sleep
    while(1){ 
		sleep();
    }
	
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2022*************************************
