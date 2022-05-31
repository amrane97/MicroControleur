#include "buzzer.h"


void buzzer_init(BUZZER_TypeDef *buzzer, GPIO_TypeDef *port, uint8_t pn)

{

	buzzer -> gpioPort = port;
	buzzer -> pin = pn;

	//Activation de l'horloge sur le port en question

	//d�terminer le num�ro du port 0--> GPIOA, 1-->GPIOB, etc.
	uint8_t nb_port;
	nb_port=(uint32_t)((uint32_t *)port - IOPPERIPH_BASE)/ (uint32_t)0x400;

	//2-activation de l'hologe
	RCC -> IOPENR|= 1 << nb_port;

	//configuration de la pin en sortie

	buzzer -> gpioPort -> MODER&=~(0b11<<2*pn);
	buzzer -> gpioPort -> MODER|=(0b01<<2*pn);
}

void buzzer_turnOn(BUZZER_TypeDef *buzzer){
	buzzer -> gpioPort -> ODR |=(1<<(buzzer -> pin)); // allume sur le pin 7
}

void buzzer_turnOff(BUZZER_TypeDef *buzzer){
	buzzer -> gpioPort -> ODR &=~(1<<(buzzer -> pin)); // eteint la led sur le pin 7
}
