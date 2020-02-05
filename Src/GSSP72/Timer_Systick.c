//________________________________________________________________________
//
//  COMPATIBLE avec "stm32f10x.h" et "Clock.h" (lors du passage KEIL4.53) 
//________________________________________________________________________
//


#include "stm32f10x.h"
#include "clock.h"

//=======================================================================================
// 	Auteur T.R.
//  02 Oct 2010, revu 18 Jan 2013
//  Processeur : STM32F103RB
//  Logiciel dev : µVision 4.53
//  Module qui configure le timer système Systick

// modif JLN 15-02-2013
// ajout variantes _ff (float free)

//=======================================================================================

static void (*Ptr_Systick)(void);	

//========================================================================================
// Fixer la priorité de l'IT coeur Systick
//=======================================================================================

void Systick_Prio_IT(char Prio,void (*Systick_function) (void))
{
Ptr_Systick=Systick_function;
SCB->SHP[11]=Prio<<4;
}


//========================================================================================
// Fixe la periode du Systick et renvoie de la valeur effective
//=======================================================================================

// variante _ff, periode en CPU ticks, sans detection de debordement
void Systick_Period_ff( unsigned int Periode_ticks )
{
// Pas de prescaler :
SysTick->CTRL |= (1 << 2);

if	( Periode_ticks >= 16777215 ) // 2^24-1 maxi
	{
	// fixer le prescaler spécifique au systick à 8
	SysTick->CTRL &= ~(1<<2);
	Periode_ticks /= 8;
	}

SysTick->LOAD = Periode_ticks;
}


void SysTick_Handler (void) 

{
Ptr_Systick();	
}
