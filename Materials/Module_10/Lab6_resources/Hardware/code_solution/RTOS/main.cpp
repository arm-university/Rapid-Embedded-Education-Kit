/*----------------------------------------------------------------------------
LAB EXERCISE 6 - Real-Time Operating System
 ----------------------------------------
	Integrate functions developed in previous modules and run then concurrently
	in the mbed RTOS. The following four threads have to be implemented:
	
	1. Display the temperature on the LCD
	2. Adjust the brightness of the RGB LED using a potentiometer
	3. Display an incrementing counter on the LCD
	4. Blink an LED

	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"
#include "DS1631.h"
#include "NHD_0216HZ.h"
#include "pindef.h"

//Define the mutex
Mutex lcd_mutex;

//Define the LCD display and the temperature sensor
NHD_0216HZ lcd(SPI_CS, SPI_MOSI, SPI_SCLK);
DS1631 temp_sensor(I2C_SDA, I2C_SCL, 0x90);

//Define other inputs and outputs
AnalogIn    pot1(Ain0);
PwmOut      red(LED_r);
PwmOut      green(LED_g);
PwmOut      blue(LED_b);
DigitalOut  led(Dout0);

//Display temperature on the LCD
void temp_thread(void const *args){
	while(1){
		lcd_mutex.lock();
		lcd.set_cursor(0, 0);
		lcd.printf("Temp: %.2f", temp_sensor.read());
		lcd_mutex.unlock();
		ThisThread::sleep_for(100ms);
	}
}

//Adjust the brightness of the RGB LED
void adjust_brightness(void const *args){
	float v;
	while(1){
		v = pot1.read();
		red = 1-v;
		green = 1-v;
		blue = 1-v;
		ThisThread::sleep_for(500ms);
	}
}

//Blink an LED
void led1_thread(void const *args){
	led = 0;
	while(1){
		led = !led;
		ThisThread::sleep_for(500ms);
	}
}

//Display a counter on the LCD
void count_thread(void const *args){
	float k = 0.0;
	while(1){
		lcd_mutex.lock();
		lcd.set_cursor(0, 1);
		lcd.printf("Counting: %.2f", k);
		lcd_mutex.unlock();
		k += 0.25f;
		ThisThread::sleep_for(1000ms);
	}
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	//Initialise and clear the LCD display
  lcd.init_lcd();
  lcd.clr_lcd();
  Thread thread1;
  Thread thread2;
  Thread thread3;
  Thread thread4;
  //Start all threads
  thread1.start(&led1_thread);
  thread2.start(&count_thread);
  thread3.start(&temp_thread);
  thread4.start(&adjust_brightness);
	
	//Wait for timer interrupt
  while(1){
		__wfi();
	}
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2019*************************************
