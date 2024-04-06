#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define BUTTON_GPIO 32
#define LED_GPIO GPIO_NUM_2

void app_main(void) {
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUTTON_GPIO, GPIO_MODE_INPUT);

    gpio_set_level(LED_GPIO, 0);
    int ledState = 0;

    while(1) {
        if (gpio_get_level(BUTTON_GPIO) == 1) {
            while (gpio_get_level(BUTTON_GPIO) == 1) {
                vTaskDelay(100 / portTICK_PERIOD_MS);
            }
            // Alternar o estado do LED
            ledState = !ledState;
            // Definir o estado do LED
            gpio_set_level(LED_GPIO, ledState);
            printf("Botao Pressionado!!!\n");
        }
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}
