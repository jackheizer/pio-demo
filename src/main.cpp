#include <mbed.h>
#include <USBSerial.h>
#include <calculator.h>

Calculator calc;
DigitalOut led(LED2);
Serial serial(USBTX, USBRX);

void blink_once(unsigned int delay_ms)
{
    led = 1;
    ThisThread::sleep_for(delay_ms);
    led = 0;
    ThisThread::sleep_for(delay_ms);
}

int main() {
    while(1) {
        serial.printf("Addition: ");
        serial.printf(calc.add(25, 17));
        blink_once(200);
        serial.printf("Subtraction: ");
        serial.printf(calc.sub(10, 3));
        blink_once(200);
        serial.printf("Multiplication: ");
        serial.printf(calc.mul(3, 3));
        blink_once(200);
        serial.printf("Division: ");
        serial.printf(calc.div(100, 3));
        blink_once(200);
    }
}
