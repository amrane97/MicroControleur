#include "stm32l053xx.h"


typedef struct {
	GPIO_TypeDef * gpioPort;
	uint8_t pin5;
	uint8_t pin6;
	uint8_t pin7;
	uint8_t pin8;


}AFF_TypeDef;

void afficher_distance(AFF_TypeDef *aff, int a);
void init_entree (AFF_TypeDef *aff, GPIO_TypeDef * port, uint8_t pn1, uint8_t pn2, uint8_t pn3, uint8_t pn4);
