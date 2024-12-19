#include "button.h"




void button_init(uint pin) {
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
    gpio_pull_up(pin);
}

bool button_is_pressed(uint pin) {
    
    return !gpio_get(pin); //if the button is pressed, the value is 1
}
