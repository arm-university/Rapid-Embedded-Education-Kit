#include "mbed.h"
# include "headers/song_def.h"
# include "headers/song.h"
# include "C12832.h"
# include <string>
using namespace std;

# define BUTTON_1   p22 
# define BUTTON_2   p23 
# define BUTTON_3   p24 
# define BUTTON_4   p25 

# define RED_LED    p26
# define YELLOW_LED p27
# define BLUE_LED   p28
# define SPEAKER    p21
# define UART_TX    p13
# define UART_RX    p14


Song allsongs [] ={
    FUR_ELISE,
    CANNON_IN_D,
    MINUET_IN_G_MAJOR,
    TURKISH_MARCH,
    NOCTRUNE_IN_E_FLAT,
    WALTZ_NO2,
    SYMPHONY_NO5,
    EINE_KLEINE_NACHTAMUSIK
};

volatile int song_index = 0;
volatile bool is_playing = false;
volatile bool wait_for_new_song = false;
string lcd_text[2];
volatile int k;
volatile int temp_index;
volatile float Volume;





// Define ticker and timeout
Ticker timer; 
Timeout delay;

//Define the LCD display and the Serial
C12832 lcd(SPI_COTI, SPI_SCK, SPI_CITO, p8, p11);
Serial pc(UART_TX, UART_RX);


//Define other inputs and outputs
AnalogIn    volume(p15);
InterruptIn   pause_button(BUTTON1);
InterruptIn   get_input(BUTTON_1);
BusIn       song_number (BUTTON_2,BUTTON_3,BUTTON_4);
DigitalOut  red(RED_LED);
DigitalOut  yellow (YELLOW_LED);
DigitalOut  blue(BLUE_LED);
PwmOut      speaker(SPEAKER);


//Display the song name on the LCD and the RGB LEDs
void update_lcd_leds_thread(){
    lcd.cls();
    lcd.locate(3, 3);
    lcd.printf(lcd_text[0].c_str());
    lcd.locate(3, 13);  
    lcd.printf(lcd_text[1].c_str());
  

    red = !is_playing;
    blue = is_playing;
    yellow = wait_for_new_song;
}

//Adjust the volume of the speaker 
void adjust_volume(){
    if (is_playing == true ) Volume = volume.read();
    else speaker = 0;
}




//Define the ticker ISR
void timer_ISR(){ 
    if (is_playing == true){
        if (k<allsongs[song_index].length){

            //Set the PWM duty cycle to zero, if there is a sound pause
            if(*(allsongs[song_index].note +k) == No) speaker = 0;            
            //Set the PWM period, which determines the note of the sound
            else {
                speaker.period(0.001*(*(allsongs[song_index].note + k)));   
                speaker = Volume;
            }    			
            
            k++;

            //Set the time for the next ticker interrupt
            timer.attach(&timer_ISR, ((*(allsongs[song_index].beat + k)/3)+(allsongs[song_index].tempo/2)));
        }
        else{
            //If the musical piece is finished, start again
            k = 0;                                                                 	
            speaker = 0;
        }
    }
}

//Define pause button handler
void pause_button_handler() { 
    if(wait_for_new_song == false ) is_playing = !is_playing; 
}

void no_response () {
    lcd_text[0] = allsongs[song_index].name1;
    lcd_text[1] = allsongs[song_index].name2;
    wait_for_new_song = false;
}


//Define get input handler
void get_input_handler() { 
    if(wait_for_new_song == false ) {
        wait_for_new_song = true;
        temp_index = song_number.read();
        lcd_text[0] = "Do you want to ";
        lcd_text[1] = "play song " + to_string(temp_index);
        delay.attach(&no_response, 5);
    }
    else {
        wait_for_new_song = false;
        song_index = temp_index;
        k=0;
        lcd_text[0] = allsongs[song_index].name1;
        lcd_text[1] = allsongs[song_index].name2;
        is_playing = true;
        timer.attach(&timer_ISR, 0.1);    					//Initialize the time ticker
    }
}




/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	// Clear the LCD display
    lcd.cls();

    // initalize pc 9600 bd //////////////////////////////////////////////////
  
	bool pressed_get_input=false;
    bool pressed_pause=false;

    //Initialize the interrupt handler 
	pause_button.rise(&pause_button_handler);
	get_input.rise(&get_input_handler);

    pc.printf("Choose a song:\r\n");
    for (int i=0; i<8; i++){
        pc.printf("     %d %s %s %s %s\r\n", i, " - ", allsongs[i].name1.c_str(), " ", allsongs[i].name2.c_str());
    }
    pc.printf("Using the Buttons 2 to 4, insert the song number in binary form\r\n");
    pc.printf("Then press on Button 1 and release all the buttons\r\n");
	
	// Wait for timer interrupt
  while(1){
		update_lcd_leds_thread();
        adjust_volume();
        wait_ms (100);
	}
}
