#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "pico/stdlib.h"

// Initializes the ultrasonic sensor on the specified ADC pin
void init_ultrasonic();

// Reads the analog value from the ultrasonic sensor and converts it to distance in cm
unsigned get_distance_cm();

#endif // ULTRASONIC_H
