#include "gassp72.h"
#include "etat.h"
#include "audio.h"

void sample_callbak( void );

extern int LongueurSon;
extern int PeriodeSonMicroSec;
extern short Son;

type_etat etat;

void audio_init()
{
etat.taille = LongueurSon;
etat.position = etat.taille;
etat.son = &Son;
// 1 tick (periode d'horloge) = 1/72 microseconde
etat.periode_ticks = PeriodeSonMicroSec * 72;

int periode_PWM_ticks;

// le timer pour la source PWM (ch. 3 pour TIM3-CH3)
// la frequence PWM doit
//	1) etre egale ou multiple de la frequence d'echantillonnage du son
//	2) assez elevee pour ne pas etre audible ( > 20 kHz )
//	3) pas trop elevee pour ne pas degrader la resolution 
// on tente successivement les multiples 1, 2 et 3
periode_PWM_ticks = etat.periode_ticks;
if	( periode_PWM_ticks > (72000000/20000) )
	periode_PWM_ticks = PeriodeSonMicroSec * (72/2);
if	( periode_PWM_ticks > (72000000/20000) )
	periode_PWM_ticks = PeriodeSonMicroSec * (72/3);
etat.resolution = PWM_Init_ff( TIM3, 3, periode_PWM_ticks );

// la sortie PB0 pour la PWM (TIM3-CH3)
GPIO_Configure(GPIOB, 0, OUTPUT, ALT_PPULL);

// le timer pour l'interruption audio
Timer_1234_Init_ff( TIM4, etat.periode_ticks );
Active_IT_Debordement_Timer( TIM4, 2, sample_callbak );
Run_Timer( TIM4 );
}

void audio_start()
{
etat.position = 0;
}

int audio_is_playing()
{
return ( etat.position < etat.taille );
}