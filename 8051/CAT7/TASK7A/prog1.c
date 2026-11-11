#include <reg51.h>

sbit RS = P3^2;
sbit EN = P3^3;
sbit D4 = P3^4;
sbit D5 = P3^5;
sbit D6 = P3^6;
sbit D7 = P3^7;

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 112; j++);
}

void lcd_pulse(void) {
    EN = 1;
    delay_ms(1);
    EN = 0;
    delay_ms(1);
}

void lcd_nibble(unsigned char n) {
    D4 = (n & 0x01) ? 1 : 0;
    D5 = (n & 0x02) ? 1 : 0;
    D6 = (n & 0x04) ? 1 : 0;
    D7 = (n & 0x08) ? 1 : 0;
    lcd_pulse();
}

void lcd_cmd(unsigned char c) {
    RS = 0;
    lcd_nibble(c >> 4);
    lcd_nibble(c & 0x0F);
    delay_ms(2);
}

void lcd_data(unsigned char d) {
    RS = 1;
    lcd_nibble(d >> 4);
    lcd_nibble(d & 0x0F);
    delay_ms(2);
}

void lcd_str(char *s) {
    while (*s) lcd_data(*s++);
}

void main(void) {
    delay_ms(20);
    lcd_cmd(0x02); // 4-bit mode
    lcd_cmd(0x28); // 2 lines, 5x7 matrix
    lcd_cmd(0x0C); // Display ON, Cursor OFF
    lcd_cmd(0x06); // Auto increment
    lcd_cmd(0x01); // Clear display

    lcd_str("Hello SNUC!");
    while (1);
}
