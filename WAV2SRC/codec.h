/** compression predictive avec perte */

// parametres de design
#define target_p 	(((72000000/11025)+1)/2)	// amplitude peak sur target (i.e. 1/2 resolution PWM)
#define QBIT		5				// nombre de bits du code
#define QCODE		(1<<(QBIT-1))			// nombre de valeurs de la magnitude du code
#define QLIN		4				// nombre de valeurs de la partie lineaire du code
#define kplaf		0.4				// coeff de limitation de la mag de la diff, 2.0 <==> no limit

// parametres derives
#define QLOG		(QCODE-QLIN)			// nombre de bits de la partie "log" du code
#define codemagmask	(QCODE-1)			// mask pour la magnitude du code
#define codesgnmask	QCODE				// mask pour le bit de signe du code

// initialisation
void codec_init();
void codec_dump();

// decodeur
int decode( unsigned short code );

// encodeur
unsigned short encode( float signal );
