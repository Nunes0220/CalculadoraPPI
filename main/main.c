#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"


void app_main(void)
{
    gpio_set_direction(2 output);


    while(1){
        gpio_set_level(2, 1);
        vTaskDelay(vTaskDelay/portTICK_PERIOD_MS);
        gpio_set_level(2, 0);
        vTaskDelay(vTaskDelay/portTICK_PERIOD_MS);        
    }


}
