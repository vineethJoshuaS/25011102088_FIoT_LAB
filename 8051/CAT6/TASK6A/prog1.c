#include <reg51.h>

void uart_init(void) {
    TMOD = 0x20; // Timer 1 Mode 2 (8-bit auto-reload)
    TH1 = 0xFD;  // 9600 baud rate at 11.0592 MHz
    SCON = 0x50; // Mode 1, 8-bit, 1 stop bit, REN enabled
    TR1 = 1;     // Start Timer 1
}

void uart_tx(char c) {
    SBUF = c;
    while (!TI);
    TI = 0;
}

void main(void) {
    uart_init();
    while (1) {
        uart_tx('A');
    }
}
