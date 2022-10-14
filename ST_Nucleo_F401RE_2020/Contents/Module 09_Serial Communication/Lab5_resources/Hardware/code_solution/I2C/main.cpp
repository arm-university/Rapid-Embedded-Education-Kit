#include "mbed.h"

# define UART_TX D1
# define UART_RX D0
# define I2C_SCL D15
# define I2C_SDA D14


//I2C interface
I2C temp_sensor(I2C_SDA, I2C_SCL);
Serial pc(UART_TX, UART_RX);

//I2C address of temperature sensor DS1631
const int temp_addr = 0x90;

char commands[] = {0x51, 0xAA};
char read_temp[2];

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	while(1){
		//Write 0x51 to 0x90 to start temperature conversion
		temp_sensor.write(temp_addr, &commands[0], 1, false);
		
		wait(0.5);
		
		//Write 0xAA to 0x90 to read the last converted temperature
		temp_sensor.write(temp_addr, &commands[1], 1, false);
		//Read the temperature into the read_temp array
		temp_sensor.read(temp_addr, read_temp, 2);
		
		//Convert temperature to Celsius
		float temp = (float((read_temp[0] << 8) | read_temp[1]) / 256);
		
		//Print temperature to the serial monitor
		pc.printf("Temp = %.2f\r\n", temp);
	}
}
