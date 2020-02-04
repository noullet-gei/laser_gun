//________________________________________________________________________
//
//  COMPATIBLE avec "stm32f10x.h" et "Clock.h" (lors du passage KEIL4.53) 
//________________________________________________________________________
//

#include "stm32f10x.h"
#include "Clock.h"


//=======================================================================================
// 	Auteur T.R.
//  sept 2010
//  Processeur : STM32F103RB
//  Logiciel dev : µVision 4
//  
//=======================================================================================

// Modif TR :
// 18 Avril 2012
// Ajout de la fonction :
// void Active_IT_Compare_Timer( TIM_TypeDef *Timer, char Prio, void (*IT_function) (void))
// Qui va permettre de lancer une IT sur comparaison CNT, CCR. (sorte d'IT PWM)

// modif JLN 15-02-2013
// ajout variantes _ff (float free)
// 2020 : allegement pour pistolets laser
//______________________________________________________________________________________


// variante _ff, durees en CPU ticks
void Timer_1234_Init_ff(TIM_TypeDef *Timer, u32 Duree_ticks )
{
u32 N_prescaler, N_Reload, Kclk;

//  activation horloge periph :
if (Timer==TIM1)  (RCC->APB2ENR)=(RCC->APB2ENR) | RCC_APB2ENR_TIM1EN;
if (Timer==TIM2)  (RCC->APB1ENR)=(RCC->APB1ENR) | RCC_APB1ENR_TIM2EN;
if (Timer==TIM3)  (RCC->APB1ENR)=(RCC->APB1ENR) | RCC_APB1ENR_TIM3EN;
if (Timer==TIM4)  (RCC->APB1ENR)=(RCC->APB1ENR) | RCC_APB1ENR_TIM4EN;

// récupération d'horloge
Kclk = CLOCK_GetHCLK() / CLOCK_GetTIMCLK(Timer);
// typiquement _PPRE2 = 1 ==> Kclk = 1 (pas teste dans les autres cas...) 

Duree_ticks /= Kclk;

// Paramétrage du prescaler 16bit et du Reload 16 bits
// Periode totale = N_prescaler * N_Reload * T_ck

N_prescaler = Duree_ticks / 65536; // Calcul du prescaler optimal (Arr maxi)
N_prescaler += 1; // arrondi immédiatement supérieur
N_Reload = Duree_ticks / N_prescaler; // calcul du reload arr

// Affectation registres
Timer->PSC = N_prescaler - 1;
Timer->ARR = N_Reload - 1;
Timer->CNT = N_Reload - 1;

//TIMx_CR1=	|xxx... CKD[1:0] ARPE CMS DIR OPM URS UDIS CEN |
// CKD=00 (pour le filtrage de ETR mode compteur, on s'en moque )
// ARPE = 0 (autoreload direct en comparaison, pas de shadow reg
// CMS = 00 (mode edge aligned)
// OPM = 0 (compteur continue à compter même si update event)
// DIR = 1 (comptage down)
// URS (Update request source) = 0 car de toute manière, pas d'IT
// UDIS (Update disable) = 0 
// CEN=1 Counter enable
Timer->CR1=(1<<4)|(1<<0); // run, décomptage, pas de mis à jour des reg de conf sur event
}

//______________________________________________________________________________________
static void (*Ptr_TIM1)(void);	
static void (*Ptr_TIM2)(void);
static void (*Ptr_TIM3)(void);
static void (*Ptr_TIM4)(void);


//______________________________________________________________________________________
void Active_IT_Debordement_Timer( TIM_TypeDef *Timer, char Prio, void (*IT_function) (void))
{
//  activation horloge periph :
if (Timer==TIM1)  (RCC->APB2ENR)=(RCC->APB2ENR) | RCC_APB2ENR_TIM1EN;
if (Timer==TIM2)  (RCC->APB1ENR)=(RCC->APB1ENR) | RCC_APB1ENR_TIM2EN;
if (Timer==TIM3)  (RCC->APB1ENR)=(RCC->APB1ENR) | RCC_APB1ENR_TIM3EN;
if (Timer==TIM4)  (RCC->APB1ENR)=(RCC->APB1ENR) | RCC_APB1ENR_TIM4EN;
// validation locale de l'interruption, registre EGR , update event (over/underflow)
Timer->DIER=(Timer->DIER)|(1<<0);

// position (numéro d'interruption de NVIC)
// Timer 2,3,4 : 28,29,30
// Les priorités tiennent sur 4 bits. C'est jeu de registres IPRx qui permet de régler
// la prio. Chaque canal a un champ de 8 bits, mais seuls les 4 bits de pds fort
// sont considérer
if (Prio > 15)	Prio=15; // saturation prio par précaution
// un registre IPR = 4 canaux.
// Les timers 2,3,4 sont donc ds le registre 28/4 = 7, soit IPR[7]
if (Timer==TIM1)
	{
	Ptr_TIM1=IT_function;
	NVIC->IP[25]=Prio<<4;
	// validation d'IT au niveau NVIC
	NVIC->ISER[0] = (NVIC->ISER[0])|(1<<25);
	}

if (Timer==TIM2)
	{
	Ptr_TIM2=IT_function;
	NVIC->IP[28]=Prio<<4;
	// validation d'IT au niveau NVIC
	NVIC->ISER[0] = (NVIC->ISER[0])|(1<<28);
	}
if (Timer==TIM3)
	{
	Ptr_TIM3=IT_function;
	NVIC->IP[29]=Prio<<4;
	// validation d'IT au niveau NVIC
	NVIC->ISER[0] = (NVIC->ISER[0])|(1<<29);
	}
if (Timer==TIM4)
	{
	Ptr_TIM4=IT_function;
	NVIC->IP[30]=Prio<<4;
	// validation d'IT au niveau NVIC
	NVIC->ISER[0] = (NVIC->ISER[0])|(1<<30);
	}

}

//___________________________________________________________________________________
//
//    Programmation du timer en mode PWM
//___________________________________________________________________________________
//

vu16 PWM_Init_ff( TIM_TypeDef *Timer, char Voie, unsigned int Periode_ticks )
{
//  activation horloge periph  dans la ligne qui suit
Timer_1234_Init_ff(Timer, Periode_ticks);

// Réglage PWM proprement dit
//Config OCy en sortie, implicite mais bon :
if ((Voie==1) || (Voie==2)) 
{
//Config OCy en sortie, implicite mais bon :
Timer->CCMR1 = (Timer->CCMR1)& ~(0x03<<((Voie-1)*8));	//00 ds le champs CCyS
//PWM en mode Edge aligned OCyM=110
Timer->CCMR1 = (Timer->CCMR1)& ~(0x07<<((Voie-1)*8+4));
Timer->CCMR1 = (Timer->CCMR1)|(0x06<<((Voie-1)*8+4));	
}
if ((Voie==3) || (Voie==4)) 
{
//Config OCy en sortie, implicite mais bon :
Timer->CCMR2 = (Timer->CCMR2)& ~(0x03<<((Voie-3)*8));	//00 ds le champs CCyS
//PWM en mode Edge aligned OCyM=110
Timer->CCMR2 = (Timer->CCMR2)& ~(0x07<<((Voie-3)*8+4));
Timer->CCMR2 = (Timer->CCMR2)|(0x06<<((Voie-3)*8+4));	
}
// polarité positive bit CCyP = 0, reg CCER
Timer->CCER = (Timer->CCER)& ~(0x01<<((Voie-1)*4+1));
// validation du canal y, bit CCyE, reg CCER
Timer->CCER = (Timer->CCER)|(0x01<<((Voie-1)*4));

// gestion particulière du Timer 1
//bit MOE à 1 pour valider les sorties positives
if (Timer==TIM1) Timer->BDTR= (Timer->BDTR)|(1<<15);

return ((Timer->ARR)+1);
}


//______________________________________________________________________________________
void TIM1_UP_IRQHandler (void)
{
TIM1->SR &=~(0x1);
Ptr_TIM1();
}
//______________________________________________________________________________________
void TIM2_IRQHandler (void)
{
if (((TIM2->SR & 0x1) ==0x1)&& ((TIM2->DIER & 0x1) ==0x1) ) // IT par overflow	 et Enable à 1 !!
	{
	TIM2->SR &=~(0x1);
	Ptr_TIM2();
	}
}
//______________________________________________________________________________________
void TIM3_IRQHandler (void)
{
if (((TIM3->SR & 0x1) ==0x1)&& ((TIM3->DIER & 0x1) ==0x1) ) // IT par overflow	 et Enable à 1 !!
	{
	TIM3->SR &=~(0x1);
	Ptr_TIM3();
	}
}
//______________________________________________________________________________________
void TIM4_IRQHandler (void)
{
if (((TIM4->SR & 0x1) ==0x1)&& ((TIM4->DIER & 0x1) ==0x1) ) // IT par overflow	 et Enable à 1 !!
	{
	TIM4->SR &=~(0x1);
	Ptr_TIM4();
	}
}
