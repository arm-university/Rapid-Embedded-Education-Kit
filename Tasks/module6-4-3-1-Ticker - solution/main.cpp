#include "mbed.h"
#include <iostream>
#include <chrono>
#include <ratio>
using namespace std;
using namespace chrono;

#include "Flashy.hpp"

int main()
{
    Flashy led1(D6, 150ms);
    Flashy led2(D7, 1s);

    //Main loop 
    while (true) {

        // Write status and instructions to user
        cout << "For RED   - press\n1: to slow down\n2: speed up\n";
        cout << "For GREEN - press\n3: to slow down\n4: speed up\n";

        // BLOCK waiting for key-press (via serial interface)
        char c = getchar();

        // Decode user input 
        switch (c) {
            case '1': 
            led1 += 50ms;
            break;
            case '2':
            led1 -= 50ms;
            break;
            case '3':
            led2 +=50ms;
            break;
            case '4':
            led2 -= 50ms;
            break;
            default:
            break;
        }

    }
}