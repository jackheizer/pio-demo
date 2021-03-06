/*
 Copyright (c) 2014-present PlatformIO <contact@platformio.org>
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
**/

#include <calculator.h>
#include <unity.h>

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

void test_function_calculator_addition(void) {
    Calculator calc;
    TEST_ASSERT_EQUAL(32, calc.add(25, 7));
}

void test_function_calculator_subtraction(void) {
    Calculator calc;
    TEST_ASSERT_EQUAL(20, calc.sub(23, 3));
}

void test_function_calculator_multiplication(void) {
    Calculator calc;
    TEST_ASSERT_EQUAL(50, calc.mul(25, 2));
}

void test_function_calculator_division(void) {
    Calculator calc;
    TEST_ASSERT_EQUAL(32, calc.div(96, 3));
}

void process() {
    UNITY_BEGIN();
    RUN_TEST(test_function_calculator_addition);
    RUN_TEST(test_function_calculator_subtraction);
    RUN_TEST(test_function_calculator_multiplication);
    RUN_TEST(test_function_calculator_division);
    UNITY_END();
}

#ifdef MBED
#include <mbed.h>

int main(int argc, char **argv) {
    DigitalOut led(LED2);
    ThisThread::sleep_for(2000);
    process();
    
    while(1) {
    led = 1;
      ThisThread::sleep_for(100);
      led = 0;
      ThisThread::sleep_for(500);
    }
    return 0;
}

#else

int main(int argc, char **argv) {
    process();
    return 0;
}

#endif
