#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char *TAG = "hello_esp32";

void app_main(void)
{
    printf("Hello ESP32!\n");
    ESP_LOGI(TAG, "Project 01 is running");

    int count = 0;

    while (1)
    {
        ESP_LOGI(TAG, "Count = %d", count);
        count++;

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
