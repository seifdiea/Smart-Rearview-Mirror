#include "buzzer.h"

void buzzer_init(uint pin) {
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
    gpio_put(pin, false); // Ensure the buzzer is off initially
}

void buzzer_turn_on(uint pin) {
    gpio_put(pin, true); // Turn the buzzer on
}

void buzzer_turn_off(uint pin) {
    gpio_put(pin, false); // Turn the buzzer off
}

void buzzer_toggle(uint pin) {
    gpio_put(pin, !gpio_get(pin)); // Toggle the buzzer state
}
