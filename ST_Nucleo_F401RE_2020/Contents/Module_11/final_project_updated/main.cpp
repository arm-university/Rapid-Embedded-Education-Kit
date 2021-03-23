#include "mbed.h"
# include "headers/song_def.h"
# include "headers/song.h"
#include "headers/NHD_0216HZ.h"
# include <string>
using namespace std;

# define BUTTON_1 D2 
# define BUTTON_2 D3 
# define BUTTON_3 D4 
# define BUTTON_4 D5 

# define RED_LED D6
# define GREEN_LED D7
# define BLUE_LED D8
# define SPEAKER D9
# define SPI_CS D10
# define SPI_MOSI D11
# define SPI_SCLK D13
# define UART_TX D1
# define UART_RX D0


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



//Define the mutex
Mutex lcd_mutex;

//Define the threads
Thread t1;
Thread t2;
Thread t3;


// Define ticker and timeout
Ticker timer; 
Timeout delay;

//Define the LCD display and the Serial
NHD_0216HZ lcd(SPI_CS, SPI_MOSI, SPI_SCLK);
//Serial pc(UART_TX, UART_RX);


//Define other inputs and outputs
AnalogIn    volume(A0);
DigitalIn pause(USER_BUTTON);
DigitalIn get_input(BUTTON_1);
BusIn       song_number (BUTTON_2,BUTTON_3,BUTTON_4);
DigitalOut  red(RED_LED);
DigitalOut  green(GREEN_LED);
DigitalOut  blue(BLUE_LED);
PwmOut      speaker(SPEAKER);


//Display the song name on the LCD and the RGB LEDs
void update_lcd_leds_thread(){
	while(1){
        lcd_mutex.lock();
        lcd.clr_lcd();
        lcd.set_cursor(0, 0);
        lcd.printf(lcd_text[0].c_str());
        lcd.set_cursor(0, 1);  
        lcd.printf(lcd_text[1].c_str());  
        lcd_mutex.unlock();

        red = !is_playing;
        blue = is_playing;
        green = wait_for_new_song;

       ThisThread::sleep_for(500ms);
	}
}

//Adjust the volume of the speaker 
void adjust_volume(){
	while(1){
		if (is_playing == true ) Volume = 0.1 * volume.read();
        else speaker = 0;
		 ThisThread::sleep_for(500ms);
	}
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
        delay.attach(&no_response, 5s);
    }
    else {
        wait_for_new_song = false;
        song_index = temp_index;
        k=0;
        lcd_text[0] = allsongs[song_index].name1;
        lcd_text[1] = allsongs[song_index].name2;
        is_playing = true;
        timer.attach(&timer_ISR, 100ms);    					//Initialize the time ticker
    }
}
void polling_loop(){
    bool pressed_get_input=false;
    bool pressed_pause=false;
	while(1){
		if(!pause && !pressed_pause) {
            pause_button_handler();
            pressed_pause = true;
        }
        if(pause) pressed_pause =false;
		if(get_input && !pressed_get_input) 
        { 
        pressed_get_input = true;
        get_input_handler();
        }
        if(!get_input) pressed_get_input=false;
         ThisThread::sleep_for(500ms);
	}
}



/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	// Initialise and clear the LCD display
	lcd.init_lcd();
    lcd.clr_lcd();

    // initalize pc 9600 bd //////////////////////////////////////////////////
  
	//Start all threads
    t1.start(update_lcd_leds_thread);
    t2.start(adjust_volume);
    t3.start(polling_loop);

	// __enable_irq();
    //Initialize the interrupt handler 
	// pause.rise(&pause_button_handler);
	// pause.rise(&get_input_handler);

    printf("Choose a song:\r\n");
    for (int i=0; i<8; i++){
        printf("     %d %s %s %s %s\r\n", i, " - ", allsongs[i].name1.c_str(), " ", allsongs[i].name2.c_str());
    }
    printf("Using the Buttons 2 to 4, insert the song number in binary form\r\n");
    printf("Then press on Button 1 and release all the buttons\r\n");
	
	// Wait for timer interrupt
  while(1){
		__WFI();
	}
}