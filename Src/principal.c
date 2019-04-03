#include "gassp72.h"
#include "g_gpio.h"
#include "audio.h"

#define GREEN_CPU

extern int LongueurSon;
extern int PeriodeSonMicroSec;
extern short Son;

// gamme temperee en Q15
const static int coeff_detune[] = {
//	52016,
//	49096,
//	46340,
	43740,
//	41285,
	38967,
//	36780,
	34716,
	32768,	// orig
//	30929,
	29193,
//	27554,
	26008 };

unsigned int cnt10Hz = 0;
int mode = 0;
int freq = 0;
int cheat_flag = 0;

// durees exprimees en periode systick
#define DUREE_LASER 1
#define DUREE_LOCK  3	// prolongee eventuellement par le son

// systick interrupt handler
void sys_callback( void )
{
++cnt10Hz;
if	( cnt10Hz == DUREE_LASER )
	{
	gpio_laser_off();	// couper le laser apres 100ms
	if	( mode == 1 )
		{		// demarrer audio apres 100ms (delai de demarrage de l'ampli TS4990)
		audio_init( &Son, LongueurSon, ( PeriodeSonMicroSec * coeff_detune[freq] ) >> 15 );
		audio_start();
		gpio_init_audio();
		}
	}
if	( ( cnt10Hz >= DUREE_LOCK ) && ( !audio_is_playing() ) && ( !cheat_flag ) )
	{
	gpio_power_off();
	}
if	( ( cnt10Hz == 20 ) && ( gpio_get_mode() == 2 ) )		// commencer en mode 2
	{
	cheat_flag = 1; gpio_init_gate();
	gpio_led( VERT, 1 );
	}
if	( ( cnt10Hz == 40 ) && ( cheat_flag ) )
	{
	gpio_led( VERT, 0 ); gpio_led( ROUGE, 1 );	// passer en mode 1
	}
if	( ( cnt10Hz == 50 ) && ( cheat_flag ) )
	{
	gpio_led( ROUGE, 0 );
	if	( gpio_get_mode() == 1 )
		gpio_led( VERT, 1 );
	else	{
		cheat_flag = 0; gpio_power_off();
		}
	}
if	( ( cnt10Hz == 60 ) && ( cheat_flag ) )
	{
	gpio_led( VERT, 0 ); gpio_led( ROUGE, 1 );	// passer en mode 0
	}
if	( ( cnt10Hz == 70 ) && ( cheat_flag ) )
	{
	gpio_led( ROUGE, 0 );
	if	( gpio_get_mode() == 0 )
		gpio_laser_on();			// allumer le laser
	else	gpio_power_off();
	}
if	( cnt10Hz == 360 )
	gpio_power_off();
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
gpio_init_aux();
freq = gpio_get_freq();
int resolution = PWM_Init_ff( TIM2, 3, periode_modu[freq] );
TIM2->CCR3 = resolution / 2;	// a peu pres carre
gpio_laser_on();		// allumer le laser
		
// Config System Timer, période exprimée en périodes horloge CPU (72 MHz)
Systick_Period_ff( 72000000 / 10 );
// enregistrement de la fonction de traitement de l'interruption timer
// ici le 3 est la priorité, sys_callback est l'adresse de cette fonction, a créér en C
Systick_Prio_IT( 3, sys_callback );
SysTick_On;
SysTick_Enable_IT;

mode = gpio_get_mode();

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
