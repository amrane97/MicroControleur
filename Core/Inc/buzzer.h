#include "stm32l053xx.h"

typedef struct
{
GPIO_TypeDef * gpioPort;
uint8_t pin;

}BUZZER_TypeDef;

void buzzer_turnOn(BUZZER_TypeDef *buzzer);

void buzzer_turnOff(BUZZER_TypeDef *buzzer);

void buzzer_init(BUZZER_TypeDef *buzzer, GPIO_TypeDef *port, uint8_t pn);
