#include <reg51.h>

sbit LED1 = P2^0;
sbit LED2 = P2^1;
sbit SW   = P3^2; // INT0 pin

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 112; j++);
}

void main(void) {
    SW = 1; // Configure as input
    while (1) {
        if (SW == 0) {
            LED1 = 0;
            LED2 = 1;
        } else {
            LED1 = 1;
            LED2 = 0;
        }
        delay_ms(20);
    }
}
