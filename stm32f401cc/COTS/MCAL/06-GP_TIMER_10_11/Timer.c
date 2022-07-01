/*
 * Timer.c
 *
 *  Created on: Jun 28, 2022
 *      Author: dahroug
 */

#include "Std_types.h"
#include "Bit_utils.h"

#include "Timer.h"
#include "Timer_prv.h"
#include "Timer_cfg.h"

pfunc Add_GlbOvfOfTim11 = NULL;
pfunc Add_GlbIcuOfTim11 = NULL;
pfunc Add_GlbOcuOfTim10 = NULL;


u16  Glb_u16PreloadValue        = TIM_DEFAULT_PRELOAD_VALUE;

u16  Glb_u16SegmentTimeCountsOC = 496;

u8 	 Glb_u16OvfCounter = 0;

u16  Glb_u16FullrevolutionTicks = 0;



void TIMER_vidInitTimers (void)
{
	TIMER_BASE->TIM10->TIMx_CR1  |= (1<<TIM_CR1_ARPE);
	TIMER_BASE->TIM11->TIMx_CR1  |= (1<<TIM_CR1_ARPE);

	TIMER_BASE->TIM11->TIMx_DIER |= (TIM_DIER_UIE      | TIM_DIER_CC1IE);
	TIMER_BASE->TIM10->TIMx_DIER |=  TIM_DIER_CC1IE;

	TIMER_BASE->TIM10->TIMx_CCMR1 =  TIMx_CLR_VALUE;
	TIMER_BASE->TIM11->TIMx_CCMR1 = (TIM_CCMR1_CC1S_IC | TIM_CCMR1_IC1F_SAMPLE_INT_4);

	TIMER_BASE->TIM10->TIMx_CCER  =  TIMx_CLR_VALUE;
	TIMER_BASE->TIM11->TIMx_CCER |= (TIM_CCER_CC1E_ON  | TIM_CCER_CC1P_FALLING_EDGE);

	TIMER_BASE->TIM10->TIMx_PSC   = TIMx_CLR_VALUE;
	TIMER_BASE->TIM11->TIMx_PSC   = TIMx_CLR_VALUE;

	TIMER_BASE->TIM10->TIMx_ARR   = (Glb_u16SegmentTimeCountsOC+1);
	TIMER_BASE->TIM11->TIMx_ARR   =  Glb_u16PreloadValue;

	TIMER_BASE->TIM10->TIMx_CCR1  =  Glb_u16SegmentTimeCountsOC;

}

void TIMER_vidStartTimers (void)
{
	TIMER_BASE->TIM11->TIMx_CR1 |= TIM_CR1_CEN_EN;
	TIMER_BASE->TIM10->TIMx_CR1 |= TIM_CR1_CEN_EN;
}

void TIMER_vidStopTimers  (void)
{
	TIMER_BASE->TIM11->TIMx_CR1 &= ~(1<<TIM_CR1_CEN);
	TIMER_BASE->TIM10->TIMx_CR1 &= ~(1<<TIM_CR1_CEN);
}

void TIMER_vidSetCallBackOvfTim11 (pfunc Add_Tim11OvfFunc)
{
	if (Add_Tim11OvfFunc)
	{
		Add_GlbOvfOfTim11 = Add_Tim11OvfFunc;
	}
}

void TIMER_vidSetCallBackIcuTim11 (pfunc Add_Tim11ICUFunc)
{
	if (Add_Tim11ICUFunc)
	{
		Add_GlbOvfOfTim11 = Add_GlbIcuOfTim11;
	}
}

void TIMER_vidSetCallBackOcuTim10 (pfunc Add_Tim10OcuFunc)
{
	if (Add_Tim10OcuFunc)
	{
		Add_GlbOcuOfTim10 = Add_Tim10OcuFunc;
	}
}

void __attribute__ ((weak, alias ("Default_Handler")))
TIM1_UP_TIM10_IRQHandler(void)
{
	static u8 counter = 0;
	counter ++;
	if (counter % 100 == 0)
	{
		trace_printf("Hello from timer 10 output compare\n");
	}
	if (Add_GlbOcuOfTim10)
	{
		Add_GlbOcuOfTim10();
	}
	TIMER_BASE->TIM10->TIMx_CCR1  =  Glb_u16SegmentTimeCountsOC;
	TIMER_BASE->TIM10->TIMx_CNT   =  TIMx_CLR_VALUE;
}

void __attribute__ ((weak, alias ("Default_Handler")))
TIM1_TRG_COM_TIM11_IRQHandler(void)
{
	if (GET_BIT(TIMER_BASE->TIM11->TIMx_SR,0))
	{
		if (Glb_u16OvfCounter% 10 == 0)
		{
			trace_printf("Hello from timer 11 overflow\n");
		}

		if (Add_GlbOvfOfTim11)
		{
			Add_GlbOvfOfTim11();
		}

		CLR_BIT(TIMER_BASE->TIM11->TIMx_SR,0);
		CLR_BIT(TIMER_BASE->TIM11->TIMx_SR,9);

		Glb_u16OvfCounter++;
	}
	else
	{
		trace_printf("Hello from timer 11 Input Capture\n");

		if (Add_GlbIcuOfTim11)
		{
			Add_GlbIcuOfTim11();
		}
		CLR_BIT(TIMER_BASE->TIM11->TIMx_SR,1);
		CLR_BIT(TIMER_BASE->TIM11->TIMx_SR,9);
		TIMER_BASE->TIM11->TIMx_CNT   =  TIMx_CLR_VALUE;
	}
}
