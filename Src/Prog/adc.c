#include "stm32f10x.h"
#include "adc.h"


void adc_init(void)
{
// perif clock
RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

// clock prescaler X8 --> 9 MHz
RCC->CFGR |= RCC_CFGR_ADCPRE;	// 0x0000C000

// software trigger
ADC1->CR2 |= ADC_CR2_EXTSEL;	// 0x000E0000

// no continuous mode
ADC1->CR2 &= (~ADC_CR2_CONT);

// no scan (= 1 conversion)
ADC1->SQR1 &= (~ADC_SQR1_L);	// with mask 0x00F00000 set 0 (lol)

// temp sensor + vref enable
ADC1->CR2 |= ADC_CR2_TSVREFE;

// sampling time CH 17 au max
ADC1->SMPR1 |= ( 7 << 21 );	// 0x00E00000,  shift = 3 * 7 car les LSB c'est canal 10 

// numero de channel = 17 en 1ere position de la sequence
ADC1->SQR3 = 17;

// enable
ADC1->CR2 |= ADC_CR2_ADON;
}

void adc_start_cal(void)
{
ADC1->CR2 |= ADC_CR2_CAL;
}

void adc_start_conv(void)
{
ADC1->CR2 |= ( ADC_CR2_SWSTART | ADC_CR2_EXTTRIG );
}

unsigned int adc_get(void)
{
return ( ADC1->DR & 0x0FFF );	// default = right align
}
