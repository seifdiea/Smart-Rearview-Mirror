#include "camera.h"
#include <stdio.h>
#include "led.h"

// Internal state variables
static bool last_button_state = false;
static bool camera_on = false;

// Initialize the camera module
void camera_init(void) {
    gpio_init(CAMERA_BUTTON_PIN);
    gpio_set_dir(CAMERA_BUTTON_PIN, GPIO_IN);
    gpio_pull_up(CAMERA_BUTTON_PIN);

    led_init(LED_PIN);
}

// Update the camera state based on button press
void camera_update(void) {
    bool button_state = !gpio_get(CAMERA_BUTTON_PIN);  // Read button (inverted logic)

    if (button_state && !last_button_state) {
        // Toggle camera state
        camera_on = !camera_on;
        printf("%s\n", camera_on ? "ON" : "OFF");
        if(camera_on){
            led_turn_on(LED_PIN);
        }
        else{
            led_turn_off(LED_PIN);
        }
    }

    last_button_state = button_state;
}

void turn_camera_on(void){
    camera_on = true;
    led_turn_on(LED_PIN);
    printf("ON\n");
}

void turn_camera_off(void){
    camera_on = false;
    led_turn_off(LED_PIN);
    printf("OFF\n");
}


