#include <reg51.h>

sbit LED = P2^0;

void delay_t0_mode1(void) {
    TMOD &= 0xF0;
    TMOD |= 0x01; // Timer 0, Mode 1 (16-bit)
    TH0 = 0xB8;   // 20ms delay count
    TL0 = 0x00;
    TR0 = 1;
    while (!TF0);
    TR0 = 0;
    TF0 = 0;
}

void main(void) {
    while (1) {
        LED = ~LED;
        delay_t0_mode1();
    }
}
