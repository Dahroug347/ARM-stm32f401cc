/*
 * Timer_prv.h
 *
 *  Created on: Jun 28, 2022
 *      Author: dahroug
 */

#ifndef         TIMER_PRV_H_
#define         TIMER_PRV_H_

typedef struct
{
	volatile u32 TIMx_CR1;
	volatile u32 TIMx_SMCR;
	volatile u32 TIMx_DIER;
	volatile u32 TIMx_SR;
	volatile u32 TIMx_EGR;
	volatile u32 TIMx_CCMR1;
	volatile u32 TIMx_RESERVED;
	volatile u32 TIMx_CCER;
	volatile u32 TIMx_CNT;
	volatile u32 TIMx_PSC;
	volatile u32 TIMx_ARR;
	volatile u32 TIMx_RESERVED0;
	volatile u32 TIMx_CCR1;
	volatile u32 TIMx_RESERVED1;
	volatile u32 TIMx_OR;

}TimerReg_10_11;

typedef struct
{
	TimerReg_10_11* TIM10;
	TimerReg_10_11* TIM11;
}TIMER;

#define 	TIMER_BASE		        ((volatile TIMER*)0x40014400)

#define 	TIMx_CLR_VALUE			0x0000
#define 	TIMx_ONE_VALUE			0x0001



#endif         /* TIMER_PRV_H_ */
