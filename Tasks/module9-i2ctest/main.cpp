/*Reads temp from DS1631 and displays on PC screen
*/

#include "mbed.h"

I2C temp_sensor(D14, D15); //Configure I2C interface
BufferedSerial pc(USBTX, USBRX, 9600); 

const int temp_addr = 0x90; //I2C address of temperature sensor DS1631
char commands[] = {0x51, 0xAA};
char read_temp[2];

int main(){
    
while(1){
  //Write 0x51 to 0x90 to start temperature conversion
  temp_sensor.write(temp_addr, &commands[0], 1, false);
  thread_sleep_for (500);    //wait for the conversion to complete
  //Write 0xAA to 0x90 to read the last converted temperature
  temp_sensor.write(temp_addr, &commands[1], 1, false);
  //Read the temperature into the read_temp array
  temp_sensor.read(temp_addr, read_temp, 2);
  //Convert temperature to Celsius
  float temp = (float((read_temp[0] << 8) | read_temp[1]) / 256);
  //Print temperature to the serial monitor
  printf("Temp = %d.%d\r\n", int(temp), int((temp-int(temp))*10));
  }
}
