#include "stm32f10x.h"

/* observations :
	- l'effacement met des 11111111, classique
	- si on tente d'ecrire sur une position non effacee, l'ecriture echoue
	  ==> on ne peut pas cumuler les zeros
*/

void flashy_unlock(void)
{
if	( FLASH->CR & FLASH_CR_LOCK )
	{
	FLASH->KEYR = 0x45670123;
	FLASH->KEYR = 0xCDEF89AB;
	}
}

void flashy_relock(void)
{
FLASH->CR |= FLASH_CR_LOCK;
}

void flashy_page_erase( unsigned int adr )
{
while	( FLASH->SR & FLASH_SR_BSY )
	{}
FLASH->CR |= FLASH_CR_PER;
FLASH->AR = adr;
FLASH->CR |= FLASH_CR_STRT;
while	( FLASH->SR & FLASH_SR_BSY )
	{}
}

void flashy_write_short( unsigned int adr, unsigned short data )
{
while	( FLASH->SR & FLASH_SR_BSY )
	{}
FLASH->CR |= FLASH_CR_PG;
/* Write data in the address */
*(__IO uint16_t*)adr = data;
while	( FLASH->SR & FLASH_SR_BSY )
	{}
}
