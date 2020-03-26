#include <mbed.h>
#include <USBSerial.h>
#include <calculator.h>

const Calculator calc;
const DigitalOut led(LED2);
const Serial serial(USBTX, USBRX);

void blink_once(unsigned int delay_ms)
{
    led = 1;
    ThisThread::sleep_for(delay_ms);
    led = 0;
    ThisThread::sleep_for(delay_ms);
}

int main() {
    while(1) {
        serial.printf("Addition: %d\n",calc.add(25, 17));
        blink_once(200);
        serial.printf("Subtraction: %d\n",calc.sub(10, 3));
        blink_once(200);
        serial.printf("Multiplication: %d\n",calc.mul(3, 3));
        blink_once(200);
        serial.printf("Division: %d\n",calc.div(100, 3));
        blink_once(200);
    }
}
