#include "stm32f10x.h"
#include "audio.h"

extern type_etat etat;

// traduction en C de l'ASM Keil ci-dessous
// verifier que le code desassemble n'est pas plus gros...
// Keil : Ok avec -O2 et -O3
void sample_callbak( void )
{
unsigned int pos = etat.position;
unsigned int tai = etat.taille;
int sample;
if	( pos >= tai )
	sample = 0;
else	sample = (int)((short *)(etat.son))[pos++];
etat.position = pos;
// il reste a convertir sample au format PWM
sample += 0x8000; // il devient positif
sample *= etat.resolution;
sample >>= 16;
TIM3->CCR3 = sample;
}

/*
	thumb
	area	moncode, code, readonly
TIM3_CCR3	equ	0x4000043C	; PWM
	include etat.inc
	import	etat
	export	sample_callbak

sample_callbak proc

	ldr	r1, =etat
	ldr	r2, [r1, #E_POS]	; lire position
	ldr	r3, [r1, #E_TAI]	; lire taille
	cmp	r2, r3		; pos - taille
	bhs	silence

	ldr	r3, [r1, #E_SON]	; lire adresse data
	ldrsh	r0, [r3, r2, lsl #1]	; lire son
	add	r2, #1
	str	r2, [r1]	; ecrire position

reso	add	r0, #0x00008000	; passer sample en positif
	ldr	r2, [r1, #E_RES]	; lire resolution
	mul	r0, r0, r2	; appliquer resolution
	lsr	r0, #16
;				; action pwm
	ldr	r3, =TIM3_CCR3
	str	r0, [r3]	; voila c'est fait
	bx	lr
;
silence	mov	r0, #0		; silence (signe)
	b	reso
	endp
	end
*/
