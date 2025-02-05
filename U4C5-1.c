#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

#define RED_LED_PIN 11
#define YELLOW_LED_PIN 12
#define GREEN_LED_PIN 13

void setup() {
    stdio_init_all();
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    gpio_init(YELLOW_LED_PIN);
    gpio_set_dir(YELLOW_LED_PIN, GPIO_OUT);
    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
}

void turn_off_all_leds() {
    gpio_put(RED_LED_PIN, 0);
    gpio_put(YELLOW_LED_PIN, 0);
    gpio_put(GREEN_LED_PIN, 0);
}

void turn_on_led(uint led_pin) {
    turn_off_all_leds();
    gpio_put(led_pin, 1);
}

bool repeating_timer_callback(struct repeating_timer *t) {
    static int state = 0;
    switch (state) {
        case 0:
            turn_on_led(RED_LED_PIN);
            state = 1;
            break;
        case 1:
            turn_on_led(YELLOW_LED_PIN);
            state = 2;
            break;
        case 2:
            turn_on_led(GREEN_LED_PIN);
            state = 0;
            break;
    }
    return true; // Keep repeating
}

int main() {
    setup();
    turn_on_led(RED_LED_PIN);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (1) {
        printf("Running...\n");
        sleep_ms(1000); // Delay de 1 segundo
    }

    return 0;
}