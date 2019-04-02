#include "gassp72.h"
#include "g_gpio.h"
#include "audio.h"

#define GREEN_CPU

unsigned int cnt10Hz = 0;

// durees exprimees en periode systick
#define DUREE_LASER 1
#define DUREE_LOCK  3	// prolongee eventuellement par le son

// systick interrupt handler
void sys_callback( void )
{
++cnt10Hz;
if	( cnt10Hz == DUREE_LASER )
	gpio_laser_off();	// couper le laser apres 100ms
if	( ( cnt10Hz >= DUREE_LOCK ) && ( !audio_is_playing() ) )
	{
	gpio_power_off();
	}
}

// arrondi optimal de N/D : ((2N/D)+1)/2
// calcule a la compilation
const static unsigned int periode_modu[] = {
	((2*72000000/85000)+1)/2,
	((2*72000000/90000)+1)/2,
	((2*72000000/95000)+1)/2,
	((2*72000000/100000)+1)/2,
	((2*72000000/115000)+1)/2,
	((2*72000000/120000)+1)/2 };

int main(void)
{
// couper le laser au plus tôt
gpio_init_gate();

// activer de la PLL qui multiplie la fréquence du quartz par 9
CLOCK_Configure();

// Timer 2 CH3 en PWM
gpio_init_modu();
int freq = gpio_get_freq();
int resolution = PWM_Init_ff( TIM2, 3, periode_modu[freq] );
TIM2->CCR3 = resolution / 2;	// a peu pres carre
GPIO_Set( GPIOA, 9 );		// allumer le laser
		
// Config System Timer, période exprimée en périodes horloge CPU (72 MHz)
Systick_Period_ff( 72000000 / 10 );
// enregistrement de la fonction de traitement de l'interruption timer
// ici le 3 est la priorité, sys_callback est l'adresse de cette fonction, a créér en C
Systick_Prio_IT( 3, sys_callback );
SysTick_On;
SysTick_Enable_IT;

gpio_init_aux();

int mode = gpio_get_mode();
if	( mode >= 1 )
	{
	audio_init();
	audio_start();
	gpio_init_audio();
	}

while	(1)
	{
	if	( !GPIO_Read( GPIOA, 0 ) )
		GPIO_Clear( GPIOC, 12 );
	#ifdef GREEN_CPU
	else	{
		SCB->SCR = 0;				// avoid deep sleep
		PWR->CR &= ~(PWR_CR_PDDS|PWR_CR_LPDS);	// avoid power down
		__WFI();				// Wait for Interrupt
		}
	#endif
	}
}
