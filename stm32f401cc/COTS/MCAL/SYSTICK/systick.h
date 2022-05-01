/*
 * systick.h
 *
 *  Created on: Apr 6, 2022
 *      Author: dahroug
 */

#ifndef     SYSTICK_H_
#define     SYSTICK_H_

/* New type for the SYSTICK timer for operation state */
typedef enum
{
	TIMER_READY,
	TIMER_NOT_INITIALIZED,
	TIMER_LOAD_NOT_SET

}SystickTimerState_t;

/* Macros for the SYSTICK register-reset values*/
#define 	STK_CTRL_RESET_VAL 				((u32)0x00000004)
#define 	STK_LOAD_RESET_VAL 				((u32)0x00000000)
#define 	STK_VAL_RESET_VAL 				((u32)0x00000000)
#define 	STK_CALIB_RESET_VAL 			((u32)0x00000000)

/* Macros for the CTRL register bits*/
#define 	STK_CTRL_ENABLE_EN		        ((u32)0x00000001)
#define 	STK_CTRL_ENABLE_DIS		        ((u32)0x00000000)

#define 	STK_CTRL_TICKINT_EN		        ((u32)0x00000002)
#define 	STK_CTRL_TICKINT_DIS	        ((u32)0x00000000)

#define 	STK_CTRL_CLKSOURCE_AHB	        (0x00000004)
#define 	STK_CTRL_CLKSOURCE_AHB_DIV_8    (0x00000000)

#define 	STK_CTRL_COUNTFLAG_SET	        ((u32)0x00010000)
#define 	STK_CTRL_CLKSOURCE_CLR	        ((u32)0x00000000)
/* Macros for operating system clock options*/
#define 	STK_TICK_SYSTEM_CLK				0
#define 	STK_REAL_SYSTEM_CLK				1

/* Macros for operating system clock options*/
#define 	STK_SINGLE_SHOT_MODE			0
#define 	STK_MULTI_SHOT_MODE				1

/*CONFIGURATION SECTION*/
#define 	STK_FCPU						((u32)25000000)
#define		STK_LOAD_INIT_VAL				STK_LOAD_RESET_VAL
#define		STK_CLK_SRC						STK_CTRL_CLKSOURCE_AHB
#define 	STK_CLK_SYSTEM_SELECT			STK_TICK_SYSTEM_CLK
#define 	STK_INTERRUPT_STATE				STK_CTRL_TICKINT_EN
#define 	STK_SYSTICK_MODE				STK_MULTI_SHOT_MODE

extern void	   		      SYSTICK_vidInit (void);
extern Std_enuErrorStatus SYSTICK_tenuSetTickTimeMs (u32 timeMs);
extern Std_enuErrorStatus SYSTICK_tenuStart(void);
extern Std_enuErrorStatus SYSTICK_tenuRegisterCbf (pfunc Cbf);

#endif /* MCAL_SYSTICK_SYSTICK_H_ */
