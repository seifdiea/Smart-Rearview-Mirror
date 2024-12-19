#ifndef BUZZER_H
#define BUZZER_H
#include <stdio.h>
#include "pico/stdlib.h"

void buzzer_init(uint pin);
void buzzer_turn_on(uint pin);
void buzzer_turn_off(uint pin);
void buzzer_toggle(uint pin);

#endif // BUZZER_H
