#include "gssp72.h"
#include "g_gpio.h"
#include "audio.h"
#include "flashy.h"
#include "adc.h"

#define GREEN_CPU

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

unsigned int voltage;

// durees exprimees en periode systick (nominal 100ms)
#define DUREE_LASER 	1
#define DUREE_LOCK  	3	// duree de verrouillage mini avant prochain tir (avec ou sans son)
#define DUREE_LOCK_MAX  600	// duree de verrouillage max en cheat mode

int get_cheat_code()
{
short x = ((short int *)LAST_FLASH_PAGE)[0];
short y = ((short int *)LAST_FLASH_PAGE)[1];
if	( x == ~y )
	return ( x & 7 );
else	return 7;
}

// systick interrupt handler
void sys_callback( void )
{
++cnt10Hz;
if	( cnt10Hz == DUREE_LASER )
	{
	if	(!( ( mode == 2 ) && ( get_cheat_code() == 6 ) ) )
		gpio_laser_off();	// couper le laser apres 100ms
	if	( mode == 1 )
		{		// demarrer audio apres 100ms (delai de demarrage de l'ampli TS4990)
		switch	( freq )
			{
			case 0 : audio_init( woui_pk );  audio_start(); break;
			case 1 : audio_init( to_poing ); audio_start(); break;
			case 2 : audio_init( zip_unk );  audio_start(); break;
			case 3 : audio_init( pop );      audio_start(); break;
			case 4 : say_number( 5 );	 seq_start();   break;
			case 5 : say_number( 6 );	 seq_start();   break;
			default : audio_init( woui_pk ); audio_start();
			}
		}
	else if	( mode == 2 )
		{
		say_code( get_cheat_code() ); seq_start();
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
	// on avait mis mode sur M3, on a attendu 2s que LED verte s'allume
	case 1 :
	if	( gpio_get_mode() == 2 )
		{
		cheat_stat++;
		cheat_tt += 1;
		gpio_led( VERT, 1 );
		adc_init();
		}
	else	cheat_stat = 900;
	break;
	case 2 :
		{
		cheat_stat++;
		cheat_tt += 1;
		adc_start_cal();
		}
	break;
	case 3 :
		{
		cheat_stat++;
		cheat_tt += 1;
		adc_start_conv();
		}
	break;
	case 4 :
		{
		cheat_stat = 10;
		cheat_tt += 17;
		voltage = ( 4095 * 1200 ) / adc_get();
		}
	break;
	// mettre mode sur M2, dans 2s la LED rouge s'allume
	case 10 :
		{
		cheat_stat++;
		cheat_tt += 5;
		gpio_led( VERT, 0 ); gpio_led( ROUGE, 1 );
		if	( gpio_get_mode() == 1 )
			gpio_power_on();	// pour nous permettre de lacher la gachette, car DUREE_LOCK est passe
		else	cheat_stat = 900;
		}
	break;
	// si ok, dans 0.5s la LED verte s'allume et on peut lacher gachette
	case 11 :
		{
		cheat_stat++;
		cheat_tt += 15;
		gpio_led( ROUGE, 0 ); gpio_led( VERT, 1 );
		}
	break;
	// alors metre mode sur M1, dans 1.5s la LED rouge s'allume
	case 12 :
		{
		cheat_stat++;
		cheat_tt += 5;
		gpio_led( VERT, 0 ); gpio_led( ROUGE, 1 );
		if	( gpio_get_mode() == 0 )
			{}
		else	cheat_stat = 900;
		}
	// si ok dans 0.5s la LED verte s'allume
	case 13 :
		{
		cheat_stat = ( freq + 1 ) * 100;
		cheat_tt += 10;
		gpio_led( ROUGE, 0 ); gpio_led( VERT, 1 );
		}
	break;
	// dans 1s la LED verte s'eteint et la rouge donne un bref flash
	// F1 = 100 etc...
	case 100 : case 200 : case 300 : case 400 : case 500 : case 600 :
		{		// effacement
		cheat_stat++;
		cheat_tt += 10;
		gpio_led( VERT, 0 ); gpio_led( ROUGE, 1 );
		flashy_unlock();
		flashy_page_erase( LAST_FLASH_PAGE );	// derniere page
		short c = cheat_stat / 100;
		flashy_unlock();
		flashy_write_short( LAST_FLASH_PAGE,    c );
		flashy_unlock();
		flashy_write_short( LAST_FLASH_PAGE+2, ~c );
		gpio_led( VERT, 0 ); gpio_led( ROUGE, 0 );
		}
	break;
	case 101 : case 201 : case 301 : case 401 : case 501 : case 601 :
		{		// bye
		cheat_stat++;
		cheat_tt += 10;
		gpio_led( VERT, 1 ); gpio_led( ROUGE, 1 );
		}
	break;
	default :
		gpio_led( VERT, 0 ); gpio_led( ROUGE, 0 );	// en cas d'alim forcee
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
// gpio_init_audio();
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
etat.pos = -1;		// pour que audio_is_playing() rende 0 si on n'a pas initialise l'audio
etat.iseq = -1;		// index sequence audio (-1 = pas de sequence en cours)

while	(1)
	{
	if	( !GPIO_Read( GPIOA, 0 ) )	// bouton carre - c'est pour faciliter le debug si necesaire
		GPIO_Clear( GPIOC, 12 );	// LED verte Olimex
	#ifdef GREEN_CPU
	else	{
		SCB->SCR = 0;				// avoid deep sleep
		PWR->CR &= ~(PWR_CR_PDDS|PWR_CR_LPDS);	// avoid power down
		__WFI();				// Wait for Interrupt
		}
	#endif
	}
}
