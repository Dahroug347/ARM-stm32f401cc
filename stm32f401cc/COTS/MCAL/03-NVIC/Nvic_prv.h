/*
 * Nvic_prv.h
 *
 *  Created on: May 15, 2022
 *      Author: dahroug
 */

#ifndef      NVIC_PRV_H_
#define      NVIC_PRV_H_

typedef struct
{
	u32 NVIC_ISERx[8];		//Interrupt set-enable register x
	u32 Reserved  [24];
	u32 NVIC_ICERx[8];		//Interrupt clear-enable register x
	u32 Reserved1 [24];
	u32 NVIC_ISPRx[8];		//Interrupt set-pending register x
	u32 Reserved2 [24];
	u32 NVIC_ICPRx[8];
	u32 Reserved3 [24];
	u32 NVIC_IABRx[8];
	u32 Reserved4 [56];
	u32 NVIC_IPRx [60];
	u32 Reserved5 [580];     ///////////// Error in data sheet 643 or 580 ?//////////////
	u32 NVIC_STIR;
}NVIC_Reg_t;

#define     NVIC_BASE  			((volatile  NVIC_Reg_t*) 0xE000E100)
#define     IRQN_NUM			240
#define 	INTRQ_CFG		    ((PriorityCfg_t)GRP4_SUB4)

#define     AIRCR               (*(volatile  u32*) 0xE000ED0C)
#define     AIRCR_KEY           0xFA050000

#define 	NVIC_ZERO			0
#define 	NVIC_ONE			1
#define 	NVIC_TWO			2
#define 	NVIC_THREE			3
#define 	NVIC_FOUR			4

#define 	NVIC_MAX_PRI_CFGS	7

#define 	NVIC_BYTE_BITS		8

#endif      /* NVIC_PRV_H_ */
