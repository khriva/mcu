#define DEVICE_NAME "my-pico-device"
#define DEVICE_VRSN "v0.0.1"
#include "pico/stdlib.h"
#include "stdio.h"
#include "stdlib.h"
#include "hardware/gpio.h"
uint32_t global_variable = 0;
const uint LED_PIN = 25;

const uint32_t constant_variable = 42;
int main(){
stdio_init_all();
gpio_init(LED_PIN);
gpio_set_dir(LED_PIN, GPIO_OUT);

while (1)
{

gpio_put(LED_PIN, 1);
sleep_ms(250);
gpio_put(LED_PIN, 0);
sleep_ms(1000);

printf("Hello World!\n");
char symbol = getchar();
printf(char)
print("\n")

sleep_ms(1000);
}
}
