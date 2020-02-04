//________________________________________________________________________
//
//  COMPATIBLE avec "stm32f10x.h" et "Clock.h" (lors du passage KEIL4.53) 
//________________________________________________________________________
//

//=======================================================================================
// 	Auteur T.R.
//  12 Mai 2010, 
//  Processeur : STM32F103RB
//  Logiciel dev : µVision 4.53 
//  Module qui configure les I/O, plus d'info ds le Port_IO.h
//  Release : Juin 2011 conf des ports D et E pour le STM32 107
//  modif Jan 2013 pour compatibilité 4_53 : stm32f10x.h et Clock.c
//  Clé compil : Pas besoin, configurée pour le 107, donc GPIOD et E accessibles
//=======================================================================================


/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "gpio.h"




char GPIO_Configure(GPIO_TypeDef * Port, int Broche, int Sens, int Techno)


// Doc tech : STM32F103RM.pdf
// Port : GPIOA à GPIOC
// Broche : de 0 à 15 pour GPIOA, GPIOB, 

// Sens   : I pour entree, O pour sortie

// Techno : 0 Analog						  / Output push-pull
//			1 Input floating				  / Output open-drain
//			2 Input-pull-down / up			  / Alternate function push-pull
//			3 reserved						  / Alternate function open-drain
// 
// Retourne 0 si tout est OK, 1 sinon
{
		
	
char BrocheH;
char Erreur;
char Sens_1_0;

	// Activer horloges A, B et C
	if (Port==GPIOA) (RCC->APB2ENR)=(RCC->APB2ENR)|RCC_APB2ENR_IOPAEN;
	if (Port==GPIOB) (RCC->APB2ENR)=(RCC->APB2ENR)|RCC_APB2ENR_IOPBEN;
	if (Port==GPIOC) (RCC->APB2ENR)=(RCC->APB2ENR)|RCC_APB2ENR_IOPCEN;

	if (Port==GPIOD) (RCC->APB2ENR)=(RCC->APB2ENR)|RCC_APB2ENR_IOPDEN;
	if (Port==GPIOE) (RCC->APB2ENR)=(RCC->APB2ENR)|RCC_APB2ENR_IOPEEN;

	
	// Verifications	 générales
	// vérification  nbre de broche
	Erreur=0; //pas de pb à priori
	if (Broche>15)	Erreur = 1;
	
	//verification que la "combinaison reservée" n'est pas demandée
	if ((Sens == 'i' || Sens =='I') && Techno == 3) Erreur=1;
	
	// vérification depassement valeur de techno de 0 à 3
	if (Techno>3) Erreur=1;
	
	// verification valeur de Sens
	
	if (Sens != 'i' && Sens != 'I' && Sens != 'o' && Sens != 'O' ) Erreur=1;
	
	//------------------------------------------
	// Configuration proprement dite :
	//------------------------------------------
	// Techno, pull up, pushpull, analog...
	
	// Sens de la broche (Input ou Output 10MHz, on se prive de la sortie 50MHz...)
	if (Sens == 'i' || Sens == 'I') Sens_1_0=0;
	if (Sens == 'o' || Sens == 'O') Sens_1_0=1;
	
	// But: fixer la techno de la broche en question 
	if (Broche <8)
	{
		// Exemple Broche = 5, Techno = 2
		// il faut arriver à CRL = xxxx xxxx | 10xx xxxx | xxxx xxxx | xxxx xxxx
		// mise à 0 du champ
		Port->CRL=(Port->CRL)&~(0x3<<(4*Broche+2));
		// ecriture de la valeur
		Port->CRL=(Port->CRL) | Techno<<(4*Broche+2); // les bits à 1 sont en place
	
	    // Mise à 0 de la zone de 2 bits
		Port->CRL=(Port->CRL) & ~(0x3<<(4*Broche)); 
		// Ecriture du sens par un OU
		Port->CRL=(Port->CRL) | Sens_1_0<<(4*Broche);  
 	}
	else
    // idem mais sur le registre CRH
 	{
		BrocheH=Broche-8;
		// mise à 0 du champ
		Port->CRH=(Port->CRH)&~(0x3<<(4*BrocheH+2));
		// ecriture de la valeur
		Port->CRH=(Port->CRH) | Techno<<(4*BrocheH+2); // les bits à 1 sont en place
		// Mise à 0 de la zone de 2 bits
		Port->CRH=(Port->CRH) & ~(0x3<<(4*BrocheH)); 
		// Ecriture du sens par un OU
		Port->CRH=(Port->CRH) | Sens_1_0<<(4*BrocheH); 
   	}

	return Erreur;
}




