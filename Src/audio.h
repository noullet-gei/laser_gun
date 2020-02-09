// 72000000 / 6532 = 11022.7 Hz
#define QBIT 5
#define SAMP_PERIOD  6532
#define PWM_PERIOD   (SAMP_PERIOD/2)
#define PWM_SILENCE  (PWM_PERIOD/2)

// liste des sons a compiler
#define USE_woui_pk
extern const unsigned int woui_pk[];
#define USE_to_poing
extern const unsigned int to_poing[];
#define USE_zip_unk
extern const unsigned int zip_unk[];
#define USE_pop
extern const unsigned int pop[];

#define USE_one
extern const unsigned int one[];
#define USE_two
extern const unsigned int two[];
#define USE_three
extern const unsigned int three[];
#define USE_four
extern const unsigned int four[];
#define USE_five
extern const unsigned int five[];
#define USE_six
extern const unsigned int six[];
#define USE_seven
extern const unsigned int seven[];
#define USE_eight
extern const unsigned int eight[];
#define USE_nine
extern const unsigned int nine[];
#define USE_zero
extern const unsigned int zero[];
#define USE_point
extern const unsigned int point[];
#define USE_code
extern const unsigned int code[];
#define USE_bat
extern const unsigned int bat[];
#define USE_roca
extern const unsigned int roca[];

#define QSEQ 20		// nombre de seqel dans la sequence audio (sons ou silences)

// etat du systeme audio
typedef struct {
int seqbuf[QSEQ];		// sequence audio : code > 0 = audio, < 0 = silence, 0 = fin de sequence
int iseq;			// index sequence (-1 = pas de sequence en cours)
int silcnt;			// decompteur de silence (0 = pas de silence)
int tai;			// nombre de samples du son
const unsigned int * wbuf1;	// pack de codes
int pos;			// position en samples (-1 = stop)
unsigned int iw;		// indice du word (32 bits)
unsigned int pb0;		// position du lsb du code courant dans le word courant	
unsigned int zew;		// word courant
short oldsig;			// predicteur
} type_etat;

extern const short dequant[];
extern type_etat etat;

// methodes
void audio_init( const unsigned int * leson );

void audio_start(void);

int audio_is_playing(void);

// a appeler apres avoir renseigne etat.seqbuf[] 
void seq_start( void );

// preparer une sequence audio epelant un nombre
int say_number( unsigned int n );

// preparer une sequence audio disant "code" suivi d'un chiffre
int say_code( unsigned int c );
