add_executable(${ProjectName}
    main.c
    buzzer.c
    button.c
    servomotor.c
    ultrasonic.c   
    camera.c    
    servo180.c
    led.c

)

target_include_directories(${ProjectName} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${ProjectName} 
    pico_stdlib
    hardware_pwm
    hardware_adc 
    FreeRTOS-Kernel-Heap4 
    )

target_sources(${PROJECT_NAME} PRIVATE main.c)   # Ensure main.c is included
pico_enable_stdio_usb(${PROJECT_NAME} 1)         # Enable USB serial
pico_enable_stdio_uart(${PROJECT_NAME} 0)        # Disable UART (optional)

pico_add_extra_outputs(${ProjectName})