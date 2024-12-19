#include "ultrasonic.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include <stdio.h>

// Pins for the ultrasonic sensor
#define TRIG_PIN 21 //D9
#define ECHO_PIN 20 //D8

// Speed of sound in cm/us
#define SOUND_SPEED 0.0343
#define TIMEOUT_US 30000 // 30 ms timeout for no echo

void init_ultrasonic() {
    gpio_init(TRIG_PIN);
    gpio_init(ECHO_PIN);

    gpio_set_dir(TRIG_PIN, GPIO_OUT);
    gpio_put(TRIG_PIN,0);
    gpio_set_dir(ECHO_PIN, GPIO_IN);
}

unsigned get_distance_cm() {
    // Send a 10 microsecond pulse to TRIG
    gpio_put(TRIG_PIN, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN, 0);

    // Wait for ECHO to go HIGH
    uint32_t start_time = time_us_32();
    while (gpio_get(ECHO_PIN) == 0) {
        if (time_us_32() - start_time > TIMEOUT_US) {
            return -1; // Timeout
        }
    }

    // Measure the time ECHO stays HIGH
    uint32_t echo_start = time_us_32();
    while (gpio_get(ECHO_PIN) == 1) {
        if (time_us_32() - echo_start > TIMEOUT_US) {
            return -1; // Timeout
        }
    }
    uint32_t echo_end = time_us_32();

    // Calculate the duration of the HIGH pulse
    float duration_us = echo_end - echo_start;

    // Calculate distance in cm
    return (duration_us * SOUND_SPEED) / 2;
}

