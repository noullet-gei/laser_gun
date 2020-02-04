/**
 * Bibliotheque GSSP derivee de GASSP 2013-02-15
 *
 * GPIO - System Timer - Timers 1234 - PWM - 72 MHz
 * Cette version lite pour pistolets laser n'a ni ADC ni DMA
 * et n'est pas destinee a etre precompilee, pour simplifier la migration hors-Keil
 */

#include "GSSP72/GPIO.h"
#include "GSSP72/Timer_Systick.h"
#include "GSSP72/TIMER_1234.h"
#include "GSSP72/clock.h"
