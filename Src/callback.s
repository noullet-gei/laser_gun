	thumb
	area	moncode, code, readonly

TIM3_CCR3	equ	0x4000043C	; PWM

	include etat.inc
	import	etat

; typedef struct {
; int position;		// 0
; int taille;		// 4
; void * son		// 8
; int resolution;	// 12
; int periode_ticks;	// 16
; } type_etat;


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
