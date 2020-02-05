#include "gssp72.h"
#include "g_gpio.h"
#include "audio.h"

#define GREEN_CPU

/* gamme temperee en Q15
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
*/

// arrondi optimal de N/D : ((2N/D)+1)/2
// calcule a la compilation
const static unsigned int periode_modu[] = {
	((2*72000000/85000)+1)/2,
	((2*72000000/90000)+1)/2,
	((2*72000000/95000)+1)/2,
	((2*72000000/100000)+1)/2,
	((2*72000000/115000)+1)/2,
	((2*72000000/120000)+1)/2,
	((2*72000000/110000)+1)/2 };	// frequence hors-jeu

unsigned int cnt10Hz = 0;
int mode = 0;
int freq = 0;		// index dans periode_modu
int cheat_stat = 0;	// state machine state
int cheat_tt = 0;	// target time : instant du prochain changement d'etat, en periodes systick 

// durees exprimees en periode systick (nominal 100ms)
#define DUREE_LASER 	1
#define DUREE_LOCK  	3	// duree de verrouillage mini avant prochain tir (avec ou sans son)
#define DUREE_LOCK_MAX  600	// duree de verrouillage max en cheat mode

// systick interrupt handler
void sys_callback( void )
{
++cnt10Hz;
if	( cnt10Hz == DUREE_LASER )
	{
	gpio_laser_off();	// couper le laser apres 100ms
	if	( mode == 1 )
		{		// demarrer audio apres 100ms (delai de demarrage de l'ampli TS4990)
		switch	( freq )
			{
			case 0 : audio_init( &woui_pk ); break;
			case 1 : audio_init( &to_poing ); break;
			case 2 : audio_init( &zip_unk ); break;
			case 3 : audio_init( &zip_unk ); break;
			default : audio_init( &woui_pk );
			}
		audio_start();
		gpio_init_audio();
		}
	return;
	}
if	( ( cnt10Hz >= DUREE_LOCK ) && ( !audio_is_playing() ) && ( cheat_stat == 0 ) )
	{
	if	( gpio_get_mode() == 2 )	// il faut deja etre en M3 pour aller plus loin
		{
		cheat_stat = 1;
		cheat_tt = cnt10Hz + 20;
		}
	gpio_power_off();
	return;
	}
// fin de la zone de tir simple, on entre dans la cheat code state machine
// tant que cnt10Hz < cheat_tt on ne fait rien
if	( cnt10Hz != cheat_tt )
	{
	if	( cnt10Hz >= DUREE_LOCK_MAX )	// error catch
		{ cheat_stat = 0; gpio_power_off(); }
	return;
	}
// on est ici parceque cnt10Hz == cheat_tt
switch	( cheat_stat )
	{
	// on avait mis mode sur M3, on a attendu 2s que LED verte s'allume, alors on peut lacher gachette
	case 1 :
	if	( gpio_get_mode() == 2 )
		{
		cheat_stat = ( freq + 1 ) * 100;
		cheat_tt += 20;
		gpio_init_gate();	// pour nous permettre de lacher la gachette, car DUREE_LOCK est passe
		gpio_led( VERT, 1 );
		}
	break;
	// le niveau de la frequence 1 : les 100
	// mettre mode sur M2, dans 2s la LED rouge s'allume
	case 100 :
		{
		cheat_stat++;
		cheat_tt += 10;
		gpio_led( VERT, 0 ); gpio_led( ROUGE, 1 );
		}
	break;
	// dans 1s la LED verte s'allume
	case 101 :
		{
		cheat_stat++;
		cheat_tt += 10;
		gpio_led( ROUGE, 0 );
		if	( gpio_get_mode() == 1 )
			gpio_led( VERT, 1 );
		else	{
			cheat_stat = 0; gpio_power_off();
			}
		}
	break;
	// alors metre mode sur M1, dans 1s la LED rouge s'allume
	case 102 :
		{
		cheat_stat++;
		cheat_tt += 10;
		gpio_led( VERT, 0 ); gpio_led( ROUGE, 1 );
		}
	break;
	// dans 1s la LED rouge s'eteint et laser s'allume pour 29s
	case 103 :
		{
		cheat_stat++;
		cheat_tt += 100;	// le temps de faire tests analog
		gpio_led( ROUGE, 0 );
		if	( gpio_get_mode() == 0 )
			{
			int resolution = PWM_Init_ff( TIM2, 3, periode_modu[6] );	// hors-jeu
			TIM2->CCR3 = resolution / 2;		// a peu pres carre
			gpio_laser_on();			// allumer le laser
			}
		else	gpio_power_off();
		}
	break;
	default :
		cheat_stat = 0; gpio_power_off();
	}
}


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
