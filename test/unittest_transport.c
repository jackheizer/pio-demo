#include <mbed.h>
#include "unittest_transport.h"

static Serial serial(USBTX, USBRX);

void unittest_uart_begin() {}

void unittest_uart_putchar(char c) {
    serial.printf("%c", c);
}

void unittest_uart_flush() {}

void unittest_uart_end() {}
