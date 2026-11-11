#include <reg51.h>

sbit WAVE = P2^0;

void timer0_delay_50ms(void) {
    TMOD = 0x01; // Timer 0, Mode 1 (16-bit)
    TL0 = 0xFD;  // Load count for 50ms (at 11.0592 MHz)
    TH0 = 0x4B;
    TR0 = 1;     // Start Timer 0
    while (TF0 == 0); // Wait for overflow
    TR0 = 0;     // Stop Timer 0
    TF0 = 0;     // Clear flag
}

void main(void) {
    while (1) {
        WAVE = ~WAVE;
        timer0_delay_50ms();
    }
}
