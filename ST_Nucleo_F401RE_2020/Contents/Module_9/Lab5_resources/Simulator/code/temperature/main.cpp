#include "mbed.h"
#include "C12832.h"
#include "Sht31.h"

C12832 lcd(SPI_MOSI, SPI_SCK, SPI_MISO, p8, p11);
Sht31 sht31(I2C_SDA, I2C_SCL);

int main() {

    while (1) {
        /* 
        Clear the lcd screen 
        Read the temperature and Humidity 
        print the the temperature and Humidity on the LCD
        wait
        */
       
            //Write your code
    }
}