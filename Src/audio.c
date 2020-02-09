#include "gssp72.h"
#include "audio.h"
#include "g_gpio.h"
#include <stdio.h>

type_etat etat;


static void next_seqel(void)
{
etat.pos = -1; etat.silcnt = 0;
if	( etat.iseq >= 0 )
	{
	int seqel = etat.seqbuf[etat.iseq++];
	if	( seqel > 0 )
		{
		audio_init( (const unsigned int *)seqel );
		audio_start();
		}
	else if	( seqel < 0 )
		etat.silcnt = -seqel;
	else	etat.iseq = -1;
	}
}

// interrupt audio
void sample_callbak( void )
{
int pos = etat.pos;
if	( pos < 0 )
	{				// pas de son en cours
	TIM3->CCR3 = PWM_SILENCE;
	if	( etat.iseq >= 0 )
		{			// sequence en cours ?
		if	( etat.silcnt > 0 )
			--etat.silcnt;	// silence en cours
		else	{		// silence fini
			next_seqel();
			}
		}
	// else	;	// disable audio interrupt
	}
else if	( pos >= etat.tai )
	{				// son fini
	etat.pos = -1;
	if	( etat.iseq >= 0 )
		next_seqel();
	// else	;	// disable audio interrupt
	}
else	{
	// extraire le code du buffer
	unsigned int pb0 = etat.pb0;
	unsigned int zecode = ( etat.zew >> pb0 );
	pb0 += QBIT;
	if	( pb0 >= 32 )
		{			// passer au word suivant
		etat.zew = etat.wbuf1[etat.iw++];
		pb0 -= 32;
		if	( pb0 > 0 )	// traiter residu
			zecode |= ( etat.zew << ( QBIT - pb0 ) ); 
		}
	etat.pb0 = pb0;
	zecode &= ( ( 1 << QBIT ) - 1 );
	// decoder le sample
	short sig = etat.oldsig;
	sig += dequant[zecode];
	etat.oldsig = sig;
	TIM3->CCR3 = sig;
	// avancer le compteur
	pos++;
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
etat.iw = 1;			// indice du word (32 bits) N.B. 1 parceque le premier word est lu ci-dessous
etat.pb0 = 0;			// position du lsb du code courant dans le word courant	
etat.zew = etat.wbuf1[0];	// word courant
etat.oldsig = PWM_SILENCE;	// predicteur N.B. cette valeur initiale determine la composante continue

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
etat.pos = 0; gpio_init_audio();
}

int audio_is_playing()
{
return ( ( etat.pos >= 0 ) || ( etat.iseq >= 0 ) );
}

// a appeler apres avoir renseigne etat.seqbuf[] 
void seq_start( void )
{
etat.iseq = 0;
next_seqel();
}

// const unsigned int * const digits[] = { zero, one, two, three, four, five, six, seven, eight, nine };
const unsigned int * const digits[] = {    one,  one, one, one,   one,  five, six, seven, one,   one };

// preparer une sequence audio epelant un nombre
int say_number( unsigned int n )
{
char tbuf[8];
snprintf( tbuf, sizeof(tbuf), "%u", n );
int i = 0, is = 0, c = tbuf[i++];
while	( c )
	{
	c -= '0';
	if	( ( c >= 0 ) && ( c <= 9 ) && ( is < ( QSEQ - 2 ) ) )
		{
		etat.seqbuf[is++] = (int)digits[c];
		etat.seqbuf[is++] = -1000;
		}
	c = tbuf[i++];
	};
etat.seqbuf[is++] = 0;
return is;
}

// preparer une sequence audio disant "code" suivi d'un chiffre
int say_code( unsigned int c )
{
int is = 0;
etat.seqbuf[is++] = (int)code;
etat.seqbuf[is++] = -3000;
if	( ( c <= 9 ) && ( is < ( QSEQ - 2 ) ) )
	{
	etat.seqbuf[is++] = (int)digits[c];
	}
etat.seqbuf[is++] = 0;
return is;
}

