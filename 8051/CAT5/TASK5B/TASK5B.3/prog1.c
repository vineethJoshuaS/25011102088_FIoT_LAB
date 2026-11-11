#include <reg51.h>

sbit PULSE = P2^2;

void delay_t0_mode2(void) {
    TMOD &= 0xF0;
    TMOD |= 0x02; // Timer 0, Mode 2 (8-bit auto-reload)
    TH0 = 0xA6;   // Auto-reload value
    TL0 = 0xA6;
    TR0 = 1;
    while (!TF0);
    TR0 = 0;
    TF0 = 0;
}

void main(void) {
    while (1) {
        PULSE = ~PULSE;
        delay_t0_mode2();
    }
}
