include "mbed.h"

DigitalOut myled(LED1);

int main() {
    while(1) {
        myled = !myled;
        wait(0.2);
    }
}