
void gpio_init_gate( void );

void gpio_power_on( void );

void gpio_power_off( void );

void gpio_laser_on( void );

void gpio_laser_off( void );

void gpio_init_modu( void );

void gpio_init_audio( void );

void gpio_init_aux( void );

int gpio_get_freq(void);

int gpio_get_mode(void);

#define ROUGE 3
#define VERT 4
void gpio_led( int led, int val );
