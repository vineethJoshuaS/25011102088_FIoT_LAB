/**
 ******************************************************************************
 * @file    prog1.c
 * @brief   CAT 6 Task 6A: 8051 Full-Duplex UART Serial Transmitter
 * @details Transmits formatted ASCII telemetry data at 9600 baud (8-N-1)
 *          using Timer 1 Mode 2 auto-reload at 11.0592 MHz crystal frequency.
 ******************************************************************************
 */

#include <reg51.h>

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 112; j++);
}

void uart_init(void) {
    TMOD = 0x20; // Timer 1 Mode 2 (8-bit auto-reload)
    TH1  = 0xFD; // 9600 baud rate at 11.0592 MHz
    SCON = 0x50; // Mode 1, 8-bit UART, 1 stop bit, REN enabled
    TR1  = 1;    // Start Timer 1
}

void uart_tx_char(char c) {
    SBUF = c;
    while (!TI); // Wait until transmit complete
    TI = 0;      // Clear transmit interrupt flag
}

void uart_tx_string(char *str) {
    while (*str) {
        uart_tx_char(*str++);
    }
}

void main(void) {
    uart_init();
    delay_ms(100);
    uart_tx_string("=== 8051 UART Transmitter (9600 Baud) ===\r\n");

    while (1) {
        uart_tx_string("Telemetry Packet: Status OK, MCU Active.\r\n");
        delay_ms(1000);
    }
}
