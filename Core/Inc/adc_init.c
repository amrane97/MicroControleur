#include "adc_init.h"

void ADC_init(ADC_TypeDef * adc, uint8_t resolution, uint8_t channel){

	RCC->APB2ENR |= RCC_APB2ENR_ADCEN; // configuration de convertisseur

	adc->CFGR2|=(0b11<<ADC_CFGR2_CKMODE_Pos); // choix de l'horloge
	adc->CFGR1|=(0b11<<13);

	// calibrage
	if((ADC1->CR & ADC_CR_ADEN) != 0) {
		ADC1->CR &= ~(uint32_t)ADC_CR_ADEN;
		}
	ADC1->CR |= ADC_CR_ADCAL; // activation de la conversion continue
	// Attente ADCAL = 0 (fin calibration)

	// choix de la resolution
	while ((ADC1->CR & ADC_CR_ADCAL) != 0);

			if(resolution==12){
				adc->CFGR1|=(0b00<<ADC_CFGR1_RES_Pos);
			}
			else if(resolution==10){
				adc->CFGR1|=(0b01<<ADC_CFGR1_RES_Pos);
			}
			else if(resolution==8){
				adc->CFGR1|=(0b10<<ADC_CFGR1_RES_Pos);
			}
			else if(resolution==6){
				adc->CFGR1|=(0b11<<ADC_CFGR1_RES_Pos);
			}

			adc->CHSELR|=(0b01<<channel); //selection du channel
			adc->CR|=(0b01<<ADC_CR_ADEN_Pos); //activation du convertisseur
			adc->CR|=(0b01<<ADC_CR_ADSTART_Pos);//lancement de conversion
}
