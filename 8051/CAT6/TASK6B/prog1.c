#include <reg51.h>

void uart_init(void) {
    TMOD = 0x20; // Timer 1 Mode 2
    TH1 = 0xFD;  // 9600 baud
    SCON = 0x50; // Mode 1, 8-bit UART
    TR1 = 1;
}

char uart_rx(void) {
    while (!RI);
    RI = 0;
    return SBUF;
}

void uart_tx(char c) {
    SBUF = c;
    while (!TI);
    TI = 0;
}

void main(void) {
    char ch;
    uart_init();
    while (1) {
        ch = uart_rx();
        uart_tx(ch); // Echo back
    }
}
