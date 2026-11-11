#include <reg51.h>

// Common Cathode 7-Segment lookup table (0-9)
unsigned char code seg_lut[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 112; j++);
}

void main(void) {
    unsigned char count = 0;
    while (1) {
        P2 = seg_lut[count];
        count = (count + 1) % 10;
        delay_ms(1000);
    }
}
