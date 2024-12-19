#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/pwm.h"

// Define pins for motor
#define MOTOR_PIN 7  // Motor connected to GP26
#define top 20000
void initMotor();
uint16_t angle_to_pulse(int angle);
void rotateMotor(int angle, bool isClockwise);
#endif
