#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

static const char *TAG = "loop_timing";

#define LED_PIN       GPIO_NUM_5
#define TIME_BASE_MS  100        /* the metronome of this loop */

/*
 * A DELIBERATELY BAD delay.
 * It burns CPU cycles doing nothing and NEVER yields.
 * We keep it here only for the watchdog experiment below.
 */
static void busy_wait_ms(uint32_t ms)
{
    volatile uint32_t loops = ms * 10000;   /* rough, do not rely on accuracy */
    while (loops--)
    {
        __asm__ volatile ("nop");
    }
}

void app_main(void)
{
    /* Same pin configuration as Project 2 */
    gpio_config_t io_conf = {};
    io_conf.pin_bit_mask = (1ULL << LED_PIN);
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&io_conf);

    /* Show the clock we are dancing to */
    ESP_LOGI(TAG, "Tick rate = %d Hz, so 1 tick = %d ms",
             (int)configTICK_RATE_HZ, (int)portTICK_PERIOD_MS);

    /*
     * EXPERIMENT 1 (leave commented for now):
     * Block the CPU for 10 seconds without yielding.
     * Expect a task-watchdog panic and a reboot.
     */
    // busy_wait_ms(10000);

    uint32_t beats = 0;      /* how many time-base delays have passed */
    bool led_on = false;

    while (1)
    {
        /*
         * The ONLY blocking call in the loop.
         * vTaskDelay() does two jobs:
         *   1. sleeps this task for ~TIME_BASE_MS
         *   2. YIELDS the CPU so other tasks can run
         */
        vTaskDelay(pdMS_TO_TICKS(TIME_BASE_MS));
        beats++;

        /* Every 5 beats = 500 ms: flip the LED */
        if (beats % 5 == 0)
        {
            led_on = !led_on;
            gpio_set_level(LED_PIN, led_on ? 1 : 0);
        }

        /* Every 20 beats = 2000 ms: heartbeat report */
        if (beats % 20 == 0)
        {
            TickType_t now = xTaskGetTickCount();
            ESP_LOGI(TAG, "beats=%lu  ticks=%lu  uptime=%lu ms",
                     (unsigned long)beats,
                     (unsigned long)now,
                     (unsigned long)(now * portTICK_PERIOD_MS));
        }
    }
}