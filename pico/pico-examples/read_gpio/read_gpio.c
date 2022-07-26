#include "pico/stdlib.h"

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning read_gpio example requires a board with a regular LED
#else
    /* Sets pin numbering */
    const uint READ_PIN = 19;
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;

    /* Inits READ_PIN and sets it as an input */
    gpio_init(READ_PIN);
    gpio_set_dir(READ_PIN, GPIO_IN);

    /* Inits LED_PIN and sets it as an output */
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    /* The expected binary value to see when the READ_PIN is connected to 3.3V (HIGH) */
    const uint expectedPinReadValue = 1;

    while (true) {
        /* Reads the READ_PIN and stores its value */
        int pinReadValue = gpio_get(READ_PIN);

        /* Compares the READ_PIN value to the expected value and if it matches turn the LED_PIN on */
        if (pinReadValue == expectedPinReadValue) {
            gpio_put(LED_PIN, 1);
        } else {
            gpio_put(LED_PIN, 0);
        }
    }
#endif
}
