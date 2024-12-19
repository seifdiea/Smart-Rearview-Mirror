#ifndef CAMERA_H
#define CAMERA_H

#include <stdbool.h>
#include "pico/stdlib.h"

// Define GPIO pin for the camera button
#define CAMERA_BUTTON_PIN 16
#define LED_PIN 17


void turn_camera_off(void);

// Initialize the camera module
void camera_init(void);

// Update the camera state based on button press
void camera_update(void);

void turn_camera_on(void);

#endif // CAMERA_H