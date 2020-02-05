typedef struct {
unsigned int longson;
unsigned int periodus;
const short * son;
} type_son;

// liste des sons a compiler
#define USE_woui_pk
extern const type_son woui_pk;
#define USE_to_poing
extern const type_son to_poing;
#define USE_zip_unk
extern const type_son zip_unk;



typedef struct {
int position;		// 0
int taille;		// 4
void * son;		// 8
int resolution;		// 12
int periode_ticks;	// 16
} type_etat;

void audio_init( const type_son * zesound );

void audio_start(void);

int audio_is_playing(void);
