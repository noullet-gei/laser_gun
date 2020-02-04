//________________________________________________________________________
//
//  COMPATIBLE avec "stm32f10x.h" et "Clock.h" (lors du passage KEIL4.53) 
//________________________________________________________________________
//


#include "stm32f10x.h"
  
/******************************************************************************
* File Name          : TIMER_1234.h
* Author             : T Rocacher
* Version            : revu 7/09/2011, ALLEGEMENT pour pisto laser 2020
* Date               : 01/03/2011
* Description        : Module qui configure les TIMER 1,2,3 et 4
*                     
*******************************************************************************/



#ifndef _TIMER_1234_H__
#define _TIMER_1234_H__


//=======================================================================================
// Rappel sur les ressources 
//
//
//  3 Timer "general Purpose", TIM2, TIM3 et TIM4 + TIM1
//  Chacun d'entre eux dispose de 4 voies de sorties num�rot�es de 1 � 4
//  Mapping des IO:
//  	TIM1_CH1 - PA08       TM2_CH1_ETR - PA0 TM3_CH1 - PA6		TIM4_CH1 - PB6	
//    	TIM1_CH1 - PA09       TM2_CH2 - PA1		TM3_CH2 - PA7		TIM4_CH2 - PB7
// 		TIM1_CH1 - PA10       TM2_CH3 - PA2		TM3_CH3 - PB0		TIM4_CH3 - PB8
// 		TIM1_CH4 - PA11		  TM2_CH4 - PA3		TM3_CH4 - PB1		TIM4_CH4 - PB9
//
//=======================================================================================



//=======================================================================================
// Fonctions basiques des timers : de TIM1 � TIM4
//=======================================================================================

//______________________________________________________________________________

// la duree entre deux debordements successifs doit etre donnnee en periodes
// d'horloge CPU (typiquement 72 MHz)
void Timer_1234_Init_ff(TIM_TypeDef *Timer, u32 Duree_ticks );
//______________________________________________________________________________

//______________________________________________________________________________

void Active_IT_Debordement_Timer( TIM_TypeDef *Timer, char Prio, void (*IT_function) (void));
//______________________________________________________________________________

/*
La fonction initialise le p�riph�rique et le NVIC de mani�re � g�n�rer une interruption 
� chaque d�bordement du timer pr�cis�.
Le handler est �crit dans la lib (non accessible). Il op�re un test sur les flags 
(sauf pour TIM1, vectorisation multiple) pour identifier la source d'IT (d�b, capure...),
 puis lance la fonction pr�cis�e en param�tre (pointeur de fonction).
Avant de lancer la fonction, le handler rabaisse le flag d'IT pour ne pas 
rerentrer immediatement. Aucune gestion de ce type n'est � faire dans la 
fonction �IT_function�

Exemple :
Active_IT_Debordement_Timer( TIM2, 1, IT_Timer2); // La fonction active une interruption 
lors du d�bordement du Timer 2. La fonction appel�e est IT_Timer2. La priorit� associ�e est	1 
*/

//=======================================================================================
// Timers en PWM
//=======================================================================================

vu16 PWM_Init_ff( TIM_TypeDef *Timer, char Voie, unsigned int Periode_ticks );


#define PWM_Valeur(Timer,Voie) Timer->CCR##Voie
/*
Permet de fixer  la dur�e � l'�tat haut de la PWM, dont indirectement son rapport 
cyclique. La grandeur doit �tre comprise entre 0 et ARR. Ex:
Reso = PWM_Init (TIM3,2,25.0);
PWM_Valeur(TIM3,2) = Reso /4; // arrondi � gerer
*/

// bloque le timer
#define Bloque_Timer(Timer) Timer->CR1=(Timer->CR1)&~(1<<0)

// Lance timer
#define Run_Timer(Timer) Timer->CR1=(Timer->CR1)|(1<<0)


/*
Permet un acc�s direct au compteur du Timer sp�cifi� sans avoir � conna�tre 
les registres du STM32
*/
#define CNT(Timer) Timer->CNT

/*
Permet un acc�s direct � l'autoreload du Timer (modulo du timer) sp�cifi� sans 
avoir � conna�tre les registres du STM32
*/
#define ARR(Timer) Timer->ARR

#define Clear_Flag_Overflow(Timer) 	Timer->SR = ((Timer->SR)&~0x01)

//============== MODIF TR 18 Avril 2012==================
#define CptUp(Timer) Timer->CR1=Timer->CR1&~(1<<4)
#define CptDown(Timer) Timer->CR1=Timer->CR1|(1<<4)
//============== FIN MODIF TR 18 Avril 2012==================



#endif
