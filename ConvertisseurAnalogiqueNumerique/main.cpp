#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);
AnalogIn pot(A0);

int main() {
    while(1) {
        led1 = (pot < 0.00) ? 1 : 0;
        led2 = (pot < 0.25) ? 1 : 0;
        led3 = (pot < 0.50) ? 1 : 0;
        led4 = (pot < 0.75) ? 1 : 0;
        wait(0.05);
    }
}