#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

#define BLUE_LED_PIN 11
#define RED_LED_PIN 12
#define GREEN_LED_PIN 13

void setup() {
    stdio_init_all();
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
    gpio_init(BLUE_LED_PIN);
    gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);
}

void turn_off_all_leds() {
    gpio_put(RED_LED_PIN, 0);
    gpio_put(GREEN_LED_PIN, 0);
    gpio_put(BLUE_LED_PIN, 0);
}

void set_led_color(bool red, bool green, bool blue) {
    gpio_put(RED_LED_PIN, red);
    gpio_put(GREEN_LED_PIN, green);
    gpio_put(BLUE_LED_PIN, blue);
}

bool repeating_timer_callback(struct repeating_timer *t) {
    static int state = 0;
    switch (state) {
        case 0:
            set_led_color(false, true, false); // Vermelho
            state = 1;
            break;
        case 1:
            set_led_color(false, true, true); // Amarelo (vermelho + verde)
            state = 2;
            break;
        case 2:
            set_led_color(false, false, true); // Verde
            state = 0;
            break;
    }
    return true; // Keep repeating
}

int main() {
    setup();
    set_led_color(true, false, false); // Inicia com vermelho

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (1) {
        printf("Running...\n");
        sleep_ms(1000); // Delay de 1 segundo
    }

    return 0;
}