#include "stdio.h"
#include "stdlib.h"
#include "pico/stdlib.h"
#include "stdio-task/stdio-task.h"
#include "protocol-task/protocol-task.h"
#include "led-task/led-task.h"	
#define DEVICE_NAME "my-pico-device"
#define DEVICE_VRSN "v0.0.1"

void version_callback(const char* args)
{
	printf("device name: '%s', firmware version: %s\n", DEVICE_NAME, DEVICE_VRSN);
}
void led_on_callback(const char* args)
{
    led_task_set_state(LED_STATE_ON);
}

void led_off_callback(const char* args)
{
    led_task_set_state(LED_STATE_OFF);
}  

void led_blink_callback(const char* args)
{
    led_task_set_state(LED_STATE_BLINK);
}

void led_blink_set_period_ms_callback(const char* args)
{
    uint32_t period_ms = 0;
    sscanf(args, "%u", &period_ms);
    if (period_ms == 0)
    {
        printf("invalid period_ms value: '%s'\n", args);
        return;
    }
    led_task_set_blink_period(period_ms);
}
api_t device_api[] =
{
	{"version", version_callback, "get device name and firmware version"},
    {"on", led_on_callback, "turn on the LED"},
    {"off", led_off_callback, "turn off the LED"},
    {"blink", led_blink_callback, "set the LED to blink"},
    {"setp", led_blink_set_period_ms_callback, "set the LED blink period in milliseconds"},
	{NULL, NULL, NULL},
};


int main(){
	stdio_init_all();
	stdio_task_init();
	protocol_task_init(device_api);
	led_task_init();


	while (1) {
		protocol_task_handle(stdio_task_handle());
		led_task_handle();
	}
}