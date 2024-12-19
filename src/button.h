#ifndef BUTTON_H
#define BUTTON_H
#include "pico/stdlib.h"
#include <stdio.h>

void button_init(uint pin);
bool button_is_pressed(uint pin);

#endif // BUTTON_H
