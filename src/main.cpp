#include <mbed.h>
#include <USBSerial.h>
#include <calculator.h>

void blink_once(DigitalOut& led, unsigned int delay_ms)
{
    led = 1;
    ThisThread::sleep_for(delay_ms);
    led = 0;
    ThisThread::sleep_for(delay_ms);
}

int main() {
    Calculator calc;
    DigitalOut led(LED2);
    Serial serial(USBTX, USBRX);
    
    while(1) {
        serial.printf("Addition: %d\n",calc.add(25, 17));
        blink_once(led, 200);
        serial.printf("Subtraction: %d\n",calc.sub(10, 3));
        blink_once(led, 200);
        serial.printf("Multiplication: %d\n",calc.mul(3, 3));
        blink_once(led, 200);
        serial.printf("Division: %d\n",calc.div(100, 3));
        blink_once(led, 200);
    }
}
