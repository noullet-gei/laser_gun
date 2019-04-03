/* programme pour experimenter le decoupage en bandes sur fichier WAVE */
/*   */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <math.h>

#include "wav_head.h"


void usage()
{
fprintf( stderr, "\nUsage : wav2asm source.wav dest.s\n\n");
exit(1);
}

// lecture WAV entier en memoire, fichier doit etre ouvert et header lu dans un wavpars
// donnees mono 32 bits stock�es dans un buffers de float alloue par cette fonction
void wave_read_body_mono( wavpars * s, float ** pbuf )
{
unsigned int rambytes;

// allocation RAM pour le son entier
rambytes = s->wavsize * sizeof(float);
*pbuf = (float *)malloc( rambytes );

if	( *pbuf == NULL )
	gasp("echec malloc %d bytes", rambytes );
// printf("malloc Ok %d bytes = %d samples\n", rambytes, rambytes/sizeof(float) );

// lecture bufferisee pour pouvoir traiter stereo ou pouvoir convertir en float ou les deux
unsigned int rdbytes;			// retour de read()
unsigned int remsamples;		// samples restant a lire
unsigned int rdsamples;			// samples juste lus
unsigned int rdframes;			// frames juste lues (1 frame = 2 samples si on est en stereo)
unsigned int totalframes;		// total des frames lues
unsigned int sizeofsamp=1;		// taille d'un sample en bytes
#define QRAW 4096			// taille du buffer en bytes

char rawsamples[QRAW];	// buffer pour read()
#define rawsamples16 ((short int *)rawsamples)
#define rawsamples32 ((float *)rawsamples)

if	( ( s->type == 1 ) && ( s->resol == 16 ) )
	sizeofsamp = 2;
else if	( ( s->type == 3 ) && ( s->resol == 32 ) )
	sizeofsamp = 4;
else	gasp("type %d with resolution %d unsupported", s->type, s->resol );

unsigned int i, j;
j = 0; totalframes = 0;
while	( totalframes < s->wavsize )
	{
	remsamples = ( s->wavsize - totalframes ) * s->chan;
	if	( remsamples > ( QRAW / sizeofsamp ) )
		remsamples = ( QRAW / sizeofsamp );
	rdbytes = read( s->hand, rawsamples, ( remsamples * sizeofsamp ) );
	rdsamples = rdbytes / sizeofsamp;
	if	( rdsamples != remsamples )
		gasp("truncated WAV data");
	rdframes = rdsamples / s->chan;
	totalframes += rdframes;
	if	( s->chan == 2 )
		{
		if	( s->type == 3 )
			for	( i = 0; i < rdsamples; i += 2 )
				(*pbuf)[j++] = 0.5 * ( rawsamples32[i] + rawsamples32[i+1] );
		else	for	( i = 0; i < rdsamples; i += 2 )
				(*pbuf)[j++] = (0.5/32768.0) * (float)( rawsamples16[i] + rawsamples16[i+1] );
		}
	else if	( s->chan == 1 )
		{
		if	( s->type == 3 )
			for	( i = 0; i < rdsamples; ++i )
				(*pbuf)[j++] = rawsamples32[i];
		else	for	( i = 0; i < rdsamples; ++i )
				(*pbuf)[j++] = (1.0/32768.0) * (float)rawsamples16[i];
		}
	}
if	( totalframes != s->wavsize )	// cela ne peut pas arriver, cette verif serait parano
	gasp("WAV size error %u vs %d", totalframes , (int)s->wavsize );
close( s->hand );
// printf("lu %d samples Ok\n", totalframes );
}

int main( int argc, char ** argv )
{
wavpars s;
char snam[256];
char dnam[256];
FILE * dfil;
float * mbuf;

if ( argc != 3 ) usage();

sprintf( snam, "%s", argv[1] );
sprintf( dnam, "%s", argv[2] );

printf("ouverture %s en lecture\n", snam );
s.hand = open( snam, O_RDONLY | O_BINARY );
if ( s.hand == -1 ) gasp("not found");

WAVreadHeader( &s );

printf("%d echantillons par canal, duree %gs\n", (int)s.wavsize, (double)s.wavsize / (double)s.freq );

printf("ouverture %s en ecriture\n", dnam );
dfil = fopen( dnam, "w" );
if ( dfil == NULL ) gasp("pb ouverture pour ecrire");

// Keil style ASM source code
fprintf( dfil, "\tAREA DonneeSon, DATA, READONLY\n");
fprintf( dfil, "\texport LongueurSon\n");
fprintf( dfil, "\texport PeriodeSonMicroSec\n");
fprintf( dfil, "\texport Son\n");

fprintf( dfil, "LongueurSon\tDCD\t%u\n", s.wavsize );
fprintf( dfil, "PeriodeSonMicroSec\tDCD\t%d\n", (int)( round( 1000000.0/(double)s.freq ) ) );

fprintf( dfil, "Son "); 

wave_read_body_mono( &s, &mbuf );

// on a le son entier en mono dans fbuf[], convertissons le en ASM "Keil"
for	( int i = 0; i < s.wavsize; ++i )
	{
	fprintf( dfil, "\tdcw\t%d\n", (int)floor(32768.0*mbuf[i]) );
	}

fprintf( dfil, "\tend\n"); 
fclose( dfil );
close( s.hand );
return 0;
}
