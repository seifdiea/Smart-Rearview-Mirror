#include "servomotor.h"


void initMotor() {
    // Initialize the GPIO pin for Motor
    gpio_set_function(MOTOR_PIN,GPIO_FUNC_PWM);
    // Set the direction of the pin to output
    uint slice_num = pwm_gpio_to_slice_num(MOTOR_PIN);
    float clkdiv=125.0/(top/20.0);
    pwm_set_clkdiv(slice_num, clkdiv); // Set the clock divider
    pwm_set_wrap(slice_num, top-1); // Set the PWM wrap value for 50Hz frequency
    //pwm_set_chan_level(slice_num, PWM_CHAN_A, 250); // Set the duty cycle for 90 degrees CW
    pwm_set_enabled(slice_num, true); // Enable the PWM output

}

uint16_t angle_to_pulse(int angle){
    if (angle<0){
        angle=0;
    }
    if (angle>180){
        angle=180;
    }
    return (uint16_t)(1000+(angle*1000)/180);
}
void rotateMotor(int angle, bool isClockwise) {
    // Set the PWM frequency and duty cycle for 90 degrees CW rotation
    
    uint slice_num=pwm_gpio_to_slice_num(MOTOR_PIN);
    int adjusted_angle = isClockwise ? angle : (180 - angle);
    uint16_t pulse=angle_to_pulse(angle);
    //uint16_t duty=(uint32_t)pulse *(pwm_get_wrap(slice_num)+1)/top;

    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(MOTOR_PIN), pulse); // Set the duty cycle for 90 degrees CW
}

