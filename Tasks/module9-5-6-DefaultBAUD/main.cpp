
#include "mbed.h"

// See mbed_app.json
// The following key-value pair was added
//    "platform.stdio-baud-rate": 115200
//
// See https://os.mbed.com/docs/mbed-os/latest/apis/platform-options-and-config.html

/* Alterantive - uncomment this
FileHandle* mbed::mbed_override_console(int)
{
    static BufferedSerial   myConsole(USBTX, USBRX, 115200);
    return &myConsole;
}
*/

BufferedSerial serial(USBTX, USBRX);

int main()
{
    printf("Hello World\n\r");
    sleep();
}
