#include <reg51.h>

sbit RS = P3^2;
sbit EN = P3^3;
sbit D4 = P3^4;
sbit D5 = P3^5;
sbit D6 = P3^6;
sbit D7 = P3^7;

sbit R1 = P2^4; sbit R2 = P2^5; sbit R3 = P2^6; sbit R4 = P2^7;
sbit C1 = P2^0; sbit C2 = P2^1; sbit C3 = P2^2; sbit C4 = P2^3;

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 112; j++);
}

void lcd_pulse(void) { EN = 1; delay_ms(1); EN = 0; delay_ms(1); }
void lcd_nibble(unsigned char n) {
    D4 = (n & 0x01) ? 1 : 0; D5 = (n & 0x02) ? 1 : 0;
    D6 = (n & 0x04) ? 1 : 0; D7 = (n & 0x08) ? 1 : 0;
    lcd_pulse();
}
void lcd_cmd(unsigned char c) { RS = 0; lcd_nibble(c >> 4); lcd_nibble(c & 0x0F); delay_ms(2); }
void lcd_data(unsigned char d) { RS = 1; lcd_nibble(d >> 4); lcd_nibble(d & 0x0F); delay_ms(2); }

char scan_keypad(void) {
    R1 = 0; R2 = 1; R3 = 1; R4 = 1;
    if (C1 == 0) { while(!C1); return '1'; }
    if (C2 == 0) { while(!C2); return '2'; }
    if (C3 == 0) { while(!C3); return '3'; }
    if (C4 == 0) { while(!C4); return 'A'; }
    R1 = 1; R2 = 0; R3 = 1; R4 = 1;
    if (C1 == 0) { while(!C1); return '4'; }
    if (C2 == 0) { while(!C2); return '5'; }
    if (C3 == 0) { while(!C3); return '6'; }
    if (C4 == 0) { while(!C4); return 'B'; }
    return 0;
}

void main(void) {
    char k;
    delay_ms(20);
    lcd_cmd(0x02); lcd_cmd(0x28); lcd_cmd(0x0C); lcd_cmd(0x01);
    while (1) {
        k = scan_keypad();
        if (k != 0) {
            lcd_data(k);
        }
    }
}
