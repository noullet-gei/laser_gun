#include "gssp72.h"
#include "g_gpio.h"

// Configuration des E/S
//
// PA2  TIM2-CH3 PWM (carre) modulation laser 
// PA3  (ex gachette)
// PA9  laser gate
// PB0  TIM3-CH3 PWM audio
// PB14 power switch act. lo opendrain FT (5 volts tolerant)	
//
// Entree choix freq
// PC7 F1 85k
// PC8 F2 90k
// PC9 F3 95k
// PA4 F4 100k
// PA5 F5 115k
// PA6 F6 120k
//
// Entree mode
// PC0 M1
// PC1 M2
// PC2 M3
//
// LEDs boitier
// PC3 Rouge
// PC4 Verte

void gpio_init_gate( void )
{
// PA9 pour gate laser
GPIO_Configure( GPIOA, 9, OUTPUT, OUTPUT_PPULL );
GPIO_Clear( GPIOA, 9 );		// couper le laser pendant la suite du demarrage
// PB14 pour power lock
GPIO_Configure( GPIOB, 14, OUTPUT, OUTPUT_OPDRAIN );	// FT out must be open-drain
GPIO_Clear( GPIOB, 14 );		// power lock
}

void gpio_power_off( void )
{
GPIO_Configure( GPIOB, 14, INPUT, INPUT_FLOATING ); 
GPIO_Set( GPIOB, 14 );		// power unlock
}

void gpio_laser_on( void )
{
GPIO_Set( GPIOA, 9 );
}

void gpio_laser_off( void )
{
GPIO_Clear( GPIOA, 9 );
}

void gpio_init_modu( void )
{
// config port PA2 (TIM2-CH3) pour modulation laser
GPIO_Configure( GPIOA, 2, OUTPUT, ALT_PPULL );
}

void gpio_init_audio(void)
{
// la sortie PB0 pour la PWM (TIM3-CH3)
GPIO_Configure(GPIOB, 0, OUTPUT, ALT_PPULL);
}

void gpio_init_aux( void )
{
// commutateur frequences (act. Lo)
GPIO_Configure(GPIOC, 7, INPUT, INPUT_PULL_DOWN_UP); 
GPIO_Configure(GPIOC, 8, INPUT, INPUT_PULL_DOWN_UP); 
GPIO_Configure(GPIOC, 9, INPUT, INPUT_PULL_DOWN_UP); 
GPIO_Configure(GPIOA, 4, INPUT, INPUT_PULL_DOWN_UP); 
GPIO_Configure(GPIOA, 5, INPUT, INPUT_PULL_DOWN_UP); 
GPIO_Configure(GPIOA, 6, INPUT, INPUT_PULL_DOWN_UP); 
GPIO_Set(GPIOC,7);  // pullup via ODR
GPIO_Set(GPIOC,8);  // pullup via ODR
GPIO_Set(GPIOC,9);  // pullup via ODR
GPIO_Set(GPIOA,4);  // pullup via ODR
GPIO_Set(GPIOA,5);  // pullup via ODR
GPIO_Set(GPIOA,6);  // pullup via ODR
// commutateur mode (act. Lo)
GPIO_Configure(GPIOC, 0, INPUT, INPUT_PULL_DOWN_UP); 
GPIO_Configure(GPIOC, 1, INPUT, INPUT_PULL_DOWN_UP); 
GPIO_Configure(GPIOC, 2, INPUT, INPUT_PULL_DOWN_UP); 
GPIO_Set(GPIOC,0);  // pullup via ODR
GPIO_Set(GPIOC,1);  // pullup via ODR
GPIO_Set(GPIOC,2);  // pullup via ODR
// LEDs boitier (act.Hi)
GPIO_Configure(GPIOC, 3, OUTPUT, OUTPUT_PPULL);
GPIO_Configure(GPIOC, 4, OUTPUT, OUTPUT_PPULL);
GPIO_Clear( GPIOC, 3 );
GPIO_Clear( GPIOC, 4 );
// config port PC12 pour LED verte Olimex
GPIO_Configure( GPIOC, 12, OUTPUT, OUTPUT_PPULL );
GPIO_Set( GPIOC, 12 );
// config port PA0 pour bouton carre
GPIO_Configure( GPIOA, 0, INPUT, INPUT_FLOATING );
}

int gpio_get_freq(void)
{
if	( !GPIO_Read(GPIOC, 7) ) return 0;
if	( !GPIO_Read(GPIOC, 8) ) return 1;
if	( !GPIO_Read(GPIOC, 9) ) return 2;
if	( !GPIO_Read(GPIOA, 4) ) return 3;
if	( !GPIO_Read(GPIOA, 5) ) return 4;
// if	( !GPIO_Read(GPIOA, 6) ) return 5;
return 5;
}

int gpio_get_mode(void)
{
if	( !GPIO_Read(GPIOC, 0) ) return 0;
if	( !GPIO_Read(GPIOC, 1) ) return 1;
// if	( !GPIO_Read(GPIOC, 2) ) return 2;
return 2;
}

// led = ROUGE ou VERT (3 ou 4)
void gpio_led( int led, int val )
{
if	( val )
	GPIO_Set( GPIOC, led );
else	GPIO_Clear( GPIOC, led );
}
