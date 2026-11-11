#include <reg51.h>

sbit OUT_PIN = P1^0;

void timer0_isr(void) interrupt 1 {
    OUT_PIN = ~OUT_PIN; // Toggle square wave
    TH0 = 0xFF;         // High-frequency reload
    TL0 = 0x00;
}

void main(void) {
    TMOD = 0x01; // Timer 0 Mode 1
    TH0 = 0xFF;
    TL0 = 0x00;
    IE = 0x82;   // Enable EA and ET0
    TR0 = 1;     // Start Timer 0
    while (1);
}
