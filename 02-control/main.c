#include "stdio-task/stdio-task.h"
#define DEVICE_NAME "my-pico-device"
#define DEVICE_VRSN "v0.0.1"
#include "pico/stdlib.h"
#include "stdio.h"
#include "stdlib.h"
#include "hardware/gpio.h"
#include "stdio-task/stdio-task.c"
int main(){
	stdio_init_all();
	stdio_task_init();
	while (1) {
		stdio_task_handle();

	}
}