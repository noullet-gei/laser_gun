/** compression predictive avec perte */
#include <math.h>
#include <stdio.h>
#include "codec.h"


// parametres derives

// les limites de plages cote diff source, t.q. ( bnd[n-1] <= x < bnd[n] ) ==> y = QLIN + n  
// cas limite inferieur				( QLIN-0.5 <= x < bnd[0] ) ==> y = QLIN
// cas limite superieur : bnd[QLOG-1] n'est pas applique vu qu'il n'y a rien apres
float bnd[QLOG-1];
// les valeurs de restitution, qui tombent "au milieu" des plages, t.q. y --> ddi[y-QLIN]
int ddi[QLOG];
// la table de dequantification
int dequant[1<<QBIT];

// tmp static storage
int oldsig_d;	// predicteur du decodeur
float oldsig_e;	// predicteur de l'encodeur 

//int dequant( unsigned short code );
unsigned short quant( float diff );

// initialisation
void codec_init()
{
oldsig_d = 0;
oldsig_e = 0.0;
// calcul des plages en progression exponentielle soit une serie constituee de :
// QLIN-0.5, ddi[0], bnd[0], ddi[1], bnd[1], ... ddi[QLOG-1] soit 2*QLOG elements,
// ddi[QLOG-1] etant le plafond, determine par kplaf.
// le facteur de progression est donc :
double kexp = pow( ( ((double)target_p) * kplaf ) / ((double)(QLIN-0.5)), 1.0 / ((double)((2*QLOG)-1)) );
double _ddi, _bnd = ((double)(QLIN-0.5));
int i;
for	( i = 0; i < ( QLOG - 1 ); ++i )
	{
	_ddi = _bnd * kexp;
	_bnd = _ddi * kexp;
	ddi[i] = (int)round(_ddi);
	bnd[i] = _bnd;
	}
_ddi = _bnd * kexp;
ddi[QLOG-1] = (int)round(_ddi);
// table de dequantification
unsigned int mag, sgn, code;
for	( code = 0; code < ( 1 << QBIT ); ++code )
	{
	mag = code & codemagmask;
	sgn = code & codesgnmask;
	if	( mag >= QLIN )
		mag = ddi[mag-QLIN];
	dequant[code] = (sgn?(-((int)mag)):((int)mag));
	}
}

void codec_dump()
{
printf("target_p = %u, kplaf = %g, QLIN = %u, QLOG = %u\n", target_p, kplaf, QLIN, QLOG );
printf("serie exponentielle :\n");
printf("\t%g\n", ((double)(QLIN-0.5)) );
int i;
for	( i = 0; i < ( QLOG - 1 ); ++i )
	{
	printf("\t%u\n", ddi[i] ); 
	printf("\t%g\n", bnd[i] );
	}
printf("\t%u\n", ddi[QLOG-1] );
float v; unsigned short u;
printf("test :\n");
v = 2.0; u = quant( v );
printf("\t%g -> %u -> %d\n", v, u, dequant[u] );
v = -2.0; u = quant( v );
printf("\t%g -> %u -> %d\n", v, u, dequant[u] );
v = 100.0; u = quant( v );
printf("\t%g -> %u -> %d\n", v, u, dequant[u] );
v = -200.0; u = quant( v );
printf("\t%g -> %u -> %d\n", v, u, dequant[u] );
v = 666.0; u = quant( v );
printf("\t%g -> %u -> %d\n", v, u, dequant[u] );
v = 1111.0; u = quant( v );
printf("\t%g -> %u -> %d\n", v, u, dequant[u] );
v = 0.0; u = quant( v );
printf("\t%g -> %u -> %d\n", v, u, dequant[u] );
v = 2700.0; u = quant( v );
printf("\t%g -> %u -> %d\n", v, u, dequant[u] );
v = -7000.0; u = quant( v );
printf("\t%g -> %u -> %d\n", v, u, dequant[u] );
}

// decodeur

/*
int dequant( unsigned short code )
{
unsigned int mag = code & codemagmask;
unsigned int sgn = code & codesgnmask;
if	( mag >= QLIN )
	mag = ddi[mag-QLIN];
return (sgn?(-((int)mag)):((int)mag));
}
*/

int decode( unsigned short code )
{
int retval = oldsig_d + dequant[code];
oldsig_d = retval;
return retval;
}

// encodeur

// quantificateur 1, prend diff a l'echelle target
unsigned short quant( float diff )
{
int sgn = (diff >= 0.0)?(0):(1);
float mag = fabs( diff );
// zone lin : simple round
unsigned short retval = (unsigned short)round(mag);
if	( retval >= QLIN )
	{			// zone LOG : comparer a chaque bnd[]
	int i = 0;
	do	{
		if	( mag < bnd[i] )
			break;
		++i;
		} while ( i < (QLOG-1) );
	retval = QLIN + i;
	}
// on quantifie
retval &= codemagmask;	// precaution
if	( sgn )
	retval |= codesgnmask;
return retval;
}

// encodeur : prend signal a l'echelle target
unsigned short encode( float signal )
{
unsigned short retval = quant( signal - oldsig_e );
oldsig_e = (float)decode( retval );
return retval;
}


