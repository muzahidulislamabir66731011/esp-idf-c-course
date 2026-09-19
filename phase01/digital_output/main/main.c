#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

static const char *TAG = "digital_output";

#define LED_PIN GPIO_NUM_5 

void app_main(void)
{
    gpio_config_t io_conf = {};

    io_conf.pin_bit_mask = (1ULL << LED_PIN);
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.intr_type = GPIO_INTR_DISABLE;

    gpio_config(&io_conf);

    ESP_LOGI(TAG, "GPIO%d configured as output", LED_PIN);

    bool led_on = false;

    while (1)
    {
        led_on = !led_on;
        gpio_set_level(LED_PIN, led_on ? 1 : 0);
        ESP_LOGI(TAG, "LED %s", led_on ? "ON" : "OFF");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}