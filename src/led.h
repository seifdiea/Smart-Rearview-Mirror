#ifndef LED_H
#define LED_H
#include <stdio.h>
#include "pico/stdlib.h"


void led_init(uint pin);
void led_turn_on(uint pin);
void led_turn_off(uint pin);
void led_toggle(uint pin);

#endif // LED_H
