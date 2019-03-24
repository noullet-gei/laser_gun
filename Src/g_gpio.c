#include "gassp72.h"
#include "g_gpio.h"

void gpio_init_gate( void )
{
// PA9 pour gate laser
GPIO_Configure( GPIOA, 9, OUTPUT, OUTPUT_PPULL );
GPIO_Clear( GPIOA, 9 );		// couper le laser pendant la suite du demarrage
// PB14 pour power lock
GPIO_Configure( GPIOB, 14, OUTPUT, OUTPUT_OPDRAIN );	// FT out must be open-drain
GPIO_Clear( GPIOB, 14 );		// power lock
}

void gpio_init_modu( void )
{
// config port PA2 (TIM2-CH3) pour modulation laser
GPIO_Configure( GPIOA, 2, OUTPUT, ALT_PPULL );
}

void gpio_init_aux( void )
{
// config port PC12 pour LED verte
GPIO_Configure( GPIOC, 12, OUTPUT, OUTPUT_PPULL );
GPIO_Set( GPIOC, 12 );
//config port PA0 pour bouton carre
GPIO_Configure( GPIOA, 0, INPUT, INPUT_FLOATING );
}
