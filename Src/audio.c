#include "gssp72.h"
#include "audio.h"

type_etat etat;

// interrupt audio
void sample_callbak( void )
{
int pos = etat.pos;
if	( pos < 0 )
	TIM3->CCR3 = PWM_SILENCE;
else	{
	// extraire le code du buffer
	unsigned short pb0 = etat.pb0;
	unsigned short zecode = ( etat.zew >> pb0 );
	pb0 += QBIT;
	if	( pb0 >= 32 )
		{			// passer au word suivant
		etat.zew = etat.wbuf1[etat.iw++];
		pb0 -= 32; etat.pb0 = pb0;
		if	( pb0 > 0 )	// traiter residu
			zecode |= ( etat.zew << ( QBIT - pb0 ) ); 
		}
	zecode &= ( ( 1 << QBIT ) - 1 );
	// decoder le sample
	short sig = etat.oldsig + dequant[zecode];
	etat.oldsig = sig;
	TIM3->CCR3 = sig;
	// avancer le compteur
	pos++;
	if	( pos >= etat.tai )
		pos = -1;
	etat.pos = pos;
	}
}

// leson est l'adresse d'un tableau dont le premier element est la taille du son
// la suite contient les codes entasses dans des mots de 32 bits
void audio_init( const unsigned int * leson )
{
etat.tai = leson[0];		// nombre de samples du son
etat.wbuf1 = leson + 1;		// pack de codes
etat.pos = -1;			// position en samples (-1 = stop)
etat.iw = 0;			// indice du word (32 bits)
etat.pb0 = 0;			// position du lsb du code courant dans le word courant	
etat.zew = etat.wbuf1[0];	// word courant
etat.oldsig = 0;		// predicteur

// le timer pour la source PWM (ch. 3 pour TIM3-CH3)
// la frequence PWM doit
//	1) etre egale ou multiple de la frequence d'echantillonnage du son
//	2) assez elevee pour ne pas etre audible ( > 20 kHz )
//	3) pas trop elevee pour ne pas degrader la resolution 
PWM_Init_ff( TIM3, 3, PWM_PERIOD );

// le timer pour l'interruption audio
Timer_1234_Init_ff( TIM4, SAMP_PERIOD );
Active_IT_Debordement_Timer( TIM4, 2, sample_callbak );
Run_Timer( TIM4 );
}

void audio_start()
{
etat.pos = 0;
}

int audio_is_playing()
{
return ( etat.pos >= 0 );
}
