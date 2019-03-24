#include "gassp72.h"
#include "g_gpio.h"

#define GREEN_CPU

unsigned int cnt10Hz = 0;

// systick interrupt handler
void sys_callback( void )
{
++cnt10Hz;
if	( cnt10Hz == 1 )
	GPIO_Clear( GPIOA, 9 );		// couper le laser apres 100ms
switch	( cnt10Hz % 10 )
	{
	case 0 :
		GPIO_Clear( GPIOC, 12 );
		break;
	case 1 :
		GPIO_Set( GPIOC, 12 );
		break;
	}
if	( cnt10Hz >= 31 )
	{
	GPIO_Configure( GPIOB, 14, INPUT, INPUT_FLOATING ); 
	GPIO_Set( GPIOB, 14 );		// power unlock
	}
}

int main(void)
{
// couper le laser au plus tôt
gpio_init_gate();

// activer de la PLL qui multiplie la fréquence du quartz par 9
CLOCK_Configure();

// Timer 2 CH3 en PWM
gpio_init_modu();
int resolution = PWM_Init_ff( TIM2, 3, 72000000/85000 );
TIM2->CCR3 = resolution / 2;	// a peu pres carre
GPIO_Set( GPIOA, 9 );		// allumer le laser
		
// Config System Timer, période exprimée en périodes horloge CPU (72 MHz)
Systick_Period_ff( 72000000 / 10 );
// enregistrement de la fonction de traitement de l'interruption timer
// ici le 3 est la priorité, sys_callback est l'adresse de cette fonction, a créér en C
Systick_Prio_IT( 3, sys_callback );
SysTick_On;
SysTick_Enable_IT;

gpio_init_aux();

while	(1)
	{
	if	( !GPIO_Read( GPIOA, 0 ) )
		GPIO_Clear( GPIOC, 12 );
	#ifdef GREEN_CPU
	else	{
		SCB->SCR = 0;				// avoid deep sleep
		PWR->CR &= ~(PWR_CR_PDDS|PWR_CR_LPDS);	// avoid power down
		__WFI();				// Wait for Interrupt
		}
	#endif
	}
}
