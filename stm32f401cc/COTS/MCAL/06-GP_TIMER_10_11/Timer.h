/*
 * Timer.h
 *
 *  Created on: Jun 28, 2022
 *      Author: dahroug
 */

#ifndef         TIMER_H_
#define         TIMER_H_

#define 	TIM_10			                0
#define 	TIM_11			                11

#define 	TIM_CR1_CEN 	                0
#define 	TIM_CR1_UDIS 	                1
#define 	TIM_CR1_URS 	                2
#define 	TIM_CR1_OPM 	                3
#define 	TIM_CR1_ARPE	                7

#define 	TIM_CR1_CEN_EN					0x0001


#define 	TIM_DIER_UIE	                0x0001
#define 	TIM_DIER_CC1IE	                0x0002

#define 	TIM_CCMR1_CC1S_OC	            0x0000
#define 	TIM_CCMR1_CC1S_IC	            0x0001
#define 	TIM_CCMR1_IC1F_SAMPLE_INT_4		0x0020

#define 	TIM_CCER_CC1E_OFF 	            0x0000
#define 	TIM_CCER_CC1E_ON 	            0x0001
#define 	TIM_CCER_CC1P_FALLING_EDGE		0x0002

#define 	TIM_DEFAULT_PRELOAD_VALUE		0xFFFF
#define 	TIM_DEFAULT_PRESCALER_VALUE		1

extern void TIMER_vidInitTimers(void);

extern void TIMER_vidStartTimers (void);
extern void TIMER_vidStopTimers  (void);

extern void TIMER_vidSetCallBackOvfTim11 (pfunc Add_Tim11OvfFunc);
extern void TIMER_vidSetCallBackIcuTim11 (pfunc Add_Tim11ICUFunc);
extern void TIMER_vidSetCallBackOcuTim10 (pfunc Add_Tim10OcuFunc);

#endif          /* TIMER_H_ */
