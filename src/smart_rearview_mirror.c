#include "pico/stdlib.h"
#include "servo180.h"
#include "camera.h"
#include "buzzer.h"
#include "ultrasonic.h"
#include "button.h"
// #include "FreeRTOS.h"
// #include "task.h"

// Pin Definitions
#define EMERGENCY_BUTTON 18
#define BUZZER_PIN 5
#define SERVO_PIN 19
#define CAMERA_RIGHT_BUTTON 15
#define CAMERA_LEFT_BUTTON 25

#define STACK_SIZE 256  // Example, adjust as needed



// // Task Handles
// TaskHandle_t emergencyTaskHandle = NULL;
// TaskHandle_t normalOperationTaskHandle = NULL;

// Global Variables
volatile bool emergencyState = false;

// Task: Handle Emergency State
// void emergencyTask(void *pvParameters) {
//     while (true) {
//         if (button_is_pressed(EMERGENCY_BUTTON)) {
//             if (!emergencyState) {
//                 printf("ENTERING EMERGENCY STATE\n");
//                 turn_camera_off();
//                 buzzer_turn_off(BUZZER_PIN);
//                 emergencyState = true;
//                 // Suspend the normal operation task
//                 vTaskSuspend(normalOperationTaskHandle);
//             } else {
//                 printf("SYSTEM IS ON!!!!\n");
//                 emergencyState = false;
//                 // Resume the normal operation task
//                 vTaskResume(normalOperationTaskHandle);
//             }
//             vTaskDelay(pdMS_TO_TICKS(500)); // Debounce delay
//         }
//         vTaskDelay(pdMS_TO_TICKS(100)); // Task delay
//     }
// }

// Task: Handle Normal Operations
// void normalOperationTask(void *pvParameters) {
//     float angles[] = {0.0f, 180.0f};
//     int distance;

//     while (true) {
//         camera_update();

//         // Check distance using ultrasonic sensor
//         distance = get_distance_cm();
//         if (distance < 10 && distance != -1) {
//             buzzer_turn_on(BUZZER_PIN);
//             turn_camera_on();
//         } else {
//             buzzer_turn_off(BUZZER_PIN);
//         }

//         // Handle servo movement based on button press
//         if (button_is_pressed(CAMERA_LEFT_BUTTON)) {
//             set_servo_angle(SERVO_PIN, angles[0]);
//         } else if (button_is_pressed(CAMERA_RIGHT_BUTTON)) {
//             set_servo_angle(SERVO_PIN, angles[1]);
//         }

//         vTaskDelay(pdMS_TO_TICKS(50)); // Task delay to avoid busy-waiting
//     }
// }

// void led_task() {
//     gpio_init(LED_PIN);
//     gpio_set_dir(LED_PIN, GPIO_OUT);
//     while (true) {
//         gpio_put(LED_PIN, 1);
//         vTaskDelay(100);
//         gpio_put(LED_PIN, 0);
//         vTaskDelay(100);
//     }
// }

// Main Function
int main() {
    stdio_init_all(); // Initialize standard I/O for debugging
    
    init_servo(SERVO_PIN);
    init_ultrasonic();
    buzzer_init(BUZZER_PIN);
    
    button_init(CAMERA_RIGHT_BUTTON);
    button_init(CAMERA_LEFT_BUTTON);
    button_init(EMERGENCY_BUTTON);
    led_init(LED_PIN);
    camera_init(); 


    

    
    bool emergencyState = false;
    int distance;
    float angles[] = {0.0f,180.0f};
    
    while (true) {
        if(!emergencyState){  
        
            camera_update();

            distance = get_distance_cm();
            
            if(distance < 10 && distance != -1){
                
                buzzer_turn_on(BUZZER_PIN);
                turn_camera_on();
            }
            else{
                buzzer_turn_off(BUZZER_PIN);
            }

            if(button_is_pressed(CAMERA_LEFT_BUTTON)){
                set_servo_angle(SERVO_PIN, angles[0]); // Set servo to the specified angle
            } else if(button_is_pressed(CAMERA_RIGHT_BUTTON)){
                set_servo_angle(SERVO_PIN, angles[1]);
            }

            if(button_is_pressed(EMERGENCY_BUTTON)){
                printf("ENTERING EMERGENCY STATE\n");
                turn_camera_off();
                buzzer_turn_off(BUZZER_PIN);
                emergencyState = true;
                sleep_ms(500);
            }
      }
      else{
        if(button_is_pressed(EMERGENCY_BUTTON)){
            printf("SYSTEM IS ON!!!!\n");
            emergencyState = false;
            sleep_ms(500);
        }
      }

        




        
    }

    return 0;
}
