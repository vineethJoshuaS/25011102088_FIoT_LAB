#include <reg51.h>

sbit LED = P2^1;

void delay_t1_mode1(void) {
    TMOD &= 0x0F;
    TMOD |= 0x10; // Timer 1, Mode 1 (16-bit)
    TH1 = 0x4B;   // 50ms delay count
    TL1 = 0xFD;
    TR1 = 1;
    while (!TF1);
    TR1 = 0;
    TF1 = 0;
}

void main(void) {
    while (1) {
        LED = ~LED;
        delay_t1_mode1();
    }
}
