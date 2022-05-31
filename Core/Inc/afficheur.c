#include "afficheur.h"
#include "stm32l0xx_ll_exti.h"
#include "buzzer.h"

void init_entree (AFF_TypeDef *aff, GPIO_TypeDef * port, uint8_t pn1, uint8_t pn2, uint8_t pn3, uint8_t pn4)
{

	aff -> gpioPort = port;
	aff -> pin5 = pn1;
	aff -> pin6 = pn2;
	aff -> pin7 = pn3;
	aff -> pin8 = pn4;

	//1-déterminer le numéro du port 0--> GPIOA, 1-->GPIOB, etc.
	uint8_t nb_port;
	nb_port = ((uint32_t) port - IOPPERIPH_BASE) / 0x400;

	//2-activation de l'horloge
	RCC->IOPENR |= 1 << nb_port;

	//3-configuration des pin d'entree

	aff -> gpioPort -> MODER &=~(0b11<<2*pn1);
	aff -> gpioPort -> MODER |= (0b01<<2*pn1);

	aff -> gpioPort -> MODER &=~(0b11<<2*pn2);
	aff -> gpioPort -> MODER |= (0b01<<2*pn2);

	aff -> gpioPort -> MODER &=~(0b11<<2*pn3);
	aff -> gpioPort -> MODER |= (0b01<<2*pn3);

	aff -> gpioPort -> MODER &=~(0b11<<2*pn4);
	aff -> gpioPort -> MODER |= (0b01<<2*pn4);

	//allumer l'afficheur 7segments
	aff -> gpioPort -> ODR |= (1 << aff->pin5);
	aff -> gpioPort -> ODR |= (1 << aff->pin6);
	aff -> gpioPort -> ODR |= (1 << aff->pin7);
	aff -> gpioPort -> ODR |= (1 << aff->pin8);
}


void afficher_distance(AFF_TypeDef *aff, int a)
{

	if (a > 240) {
		aff->gpioPort->ODR &=~(1 << aff->pin5);
		aff->gpioPort->ODR &=~(1 << aff->pin6);
		aff->gpioPort->ODR &=~(1 << aff->pin7);
		aff->gpioPort->ODR &=~(1 << aff->pin8);

		//GPIOA->ODR |= (1<<5);//0 poids le plus faible
		//GPIOA->ODR |= (1<<6);//0
		//GPIOA->ODR |= (1<<7);//0
		//GPIOA->ODR |= (1<<8);//0 poids le plus fort
	}
	else if (a > 220 && a <= 240){
		aff->gpioPort->ODR |= (1 << aff->pin5);
		aff->gpioPort->ODR &=~(1 << aff->pin6);
		aff->gpioPort->ODR &=~(1 << aff->pin7);
		aff->gpioPort->ODR &=~(1 << aff->pin8);

		//GPIOA->ODR &=~(1<<5);//1
		//GPIOA->ODR |= (1<<6);//0
		//GPIOA->ODR |= (1<<7);//0
		//GPIOA->ODR |= (1<<8);//0
	}
	else if (a > 195 && a <= 220){
		aff->gpioPort->ODR &=~(1 << aff->pin5);
		aff->gpioPort->ODR |= (1 << aff->pin6);
		aff->gpioPort->ODR &=~(1 << aff->pin7);
		aff->gpioPort->ODR &=~(1 << aff->pin8);

		//GPIOA->ODR |= (1<<5);//0
		//GPIOA->ODR &=~(1<<6);//1
		//GPIOA->ODR |= (1<<7);//0
		//GPIOA->ODR |= (1<<8);//0
	}
	else if ( a > 170 && a <= 195) {
		aff->gpioPort->ODR |= (1 << aff->pin5);
		aff->gpioPort->ODR |= (1 << aff->pin6);
		aff->gpioPort->ODR &=~(1 << aff->pin7);
		aff->gpioPort->ODR &=~(1 << aff->pin8);

		//GPIOA->ODR &=~(1<<5);//1
		//GPIOA->ODR &=~(1<<6);//1
		//GPIOA->ODR |= (1<<7);//0
		//GPIOA->ODR |= (1<<8);//0
	}
	else if (a > 145 && a <= 170){
		aff->gpioPort->ODR &=~(1 << aff->pin5);
		aff->gpioPort->ODR &=~(1 << aff->pin6);
		aff->gpioPort->ODR |= (1 << aff->pin7);
		aff->gpioPort->ODR &=~(1 << aff->pin8);

		//GPIOA->ODR |= (1<<5);//0
		//GPIOA->ODR |= (1<<6);//0
		//GPIOA->ODR &=~(1<<7);//1
		//GPIOA->ODR |= (1<<8);//0
	}
	else if (a > 120 && a <= 145){
		aff->gpioPort->ODR |= (1 << aff->pin5);
		aff->gpioPort->ODR &=~(1 << aff->pin6);
		aff->gpioPort->ODR |= (1 << aff->pin7);
		aff->gpioPort->ODR &=~(1 << aff->pin8);

		//GPIOA->ODR &=~(1<<5);//1
		//GPIOA->ODR |= (1<<6);//0
		//GPIOA->ODR &=~(1<<7);//1
		//GPIOA->ODR |= (1<<8);//0
	}
	else if(a > 95 && a <= 120){
		aff->gpioPort->ODR &=~(1 << aff->pin5);
		aff->gpioPort->ODR |= (1 << aff->pin6);
		aff->gpioPort->ODR |= (1 << aff->pin7);
		aff->gpioPort->ODR &=~(1 << aff->pin8);

		//GPIOA->ODR |= (1<<5);//0
		//GPIOA->ODR &=~(1<<6);//1
		//GPIOA->ODR &=~(1<<7);//1
		//GPIOA->ODR |= (1<<8);//0
	}
	else if ( a > 70 && a <= 95){
		aff->gpioPort->ODR |= (1 << aff->pin5);
		aff->gpioPort->ODR |= (1 << aff->pin6);
		aff->gpioPort->ODR |= (1 << aff->pin7);
		aff->gpioPort->ODR &=~(1 << aff->pin8);

		//GPIOA->ODR &=~(1<<5);//1
		//GPIOA->ODR &=~(1<<6);//1
		//GPIOA->ODR &=~(1<<7);//1
		//GPIOA->ODR |= (1<<8);//0
	}
	else if (a > 55 && a <= 70) {
		aff->gpioPort->ODR &=~(1 << aff->pin5);
		aff->gpioPort->ODR &=~(1 << aff->pin6);
		aff->gpioPort->ODR &=~(1 << aff->pin7);
		aff->gpioPort->ODR |= (1 << aff->pin8);

		//GPIOA->ODR |= (1<<5);//0
		//GPIOA->ODR |= (1<<6);//0
		//GPIOA->ODR |= (1<<7);//0
		//GPIOA->ODR &=~(1<<8);//1
	}
	else if (a <= 55) {
		aff->gpioPort->ODR |= (1 << aff->pin5);
		aff->gpioPort->ODR &=~(1 << aff->pin6);
		aff->gpioPort->ODR &=~(1 << aff->pin7);
		aff->gpioPort->ODR |= (1 << aff->pin8);


		//GPIOA->ODR &=~(1<<5);//1
		//GPIOA->ODR |= (1<<6);//0
		//GPIOA->ODR |= (1<<7);//0
		//GPIOA->ODR &=~(1<<8);//1
	}
}


