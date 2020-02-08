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

// etat du systeme audio
typedef struct {
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
