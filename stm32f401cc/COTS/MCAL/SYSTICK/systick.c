/*
 * systick.c
 *
 *  Created on: Apr 6, 2022
 *      Author: dahroug
 */


#include <SERVICES/Std_types.h>

#include <MCAL/SYSTICK/Systick.h>

typedef struct
{
	volatile u32 STK_CTRL;
	volatile u32 STK_LOAD;
	volatile u32 STK_VAL;
	volatile u32 STK_CALIB;

}Systick_reg_t;

/* private functions or handlers prototypes */
void 		SysTick_Handler (void);
#if STK_SYSTICK_MODE == STK_SINGLE_SHOT_MODE
static void SYSTICK_vidStop (void);
#endif

#define 	SYSTICK_BASE_ADD		((volatile Systick_reg_t*)0xE000E010)

/* private Macros for needed values in calculations */
#define 	STK_LOAD_COUNT			((u32)16777216)
#define 	STK_LOAD_TOPVAL			((u32)16777215)
#define 	MAX_TIME_MSEC			((u32)4294967296)
#define 	DIV_8					((u8)8)
#define 	DIV_1					((u8)1)
#define 	SEC_IN_MILLI 			((u16)1000)
#define 	STK_CLR_VAL				0
#define 	STK_ONE_VAL				1
#define 	STK_FXD_PNT				10000


#if 	STK_CLK_SRC == STK_CTRL_CLKSOURCE_AHB_DIV_8

#define 	PRESCALER  	DIV_8

#elif 	STK_CLK_SRC == STK_CTRL_CLKSOURCE_AHB

#define 	PRESCALER  	DIV_1

#endif

/* Global Variables Section*/
#if STK_CLK_SYSTEM_SELECT == STK_REAL_SYSTEM_CLK

static f32 SYSTICK_noOfOvfs       	  				   = STK_CLR_VAL;
static u32 SYSTICK_counter	 	  	  				   = STK_CLR_VAL;

#endif

static SystickTimerState_t SYSTICK_timerOperationState = TIMER_NOT_INITIALIZED;
static pfunc SYSTICK_TimerLoadRegisterOvf 		   = NULL;

#if STK_SYSTICK_MODE == STK_SINGLE_SHOT_MODE
void SYSTICK_vidStop (void)
{
	SYSTICK_BASE_ADD->STK_CTRL &= ~(STK_CTRL_ENABLE_EN);
}
#endif


void  		   SYSTICK_vidInit (void)
{
	SYSTICK_BASE_ADD->STK_LOAD = STK_LOAD_INIT_VAL;  										/*Program reload value*/
	SYSTICK_BASE_ADD->STK_VAL  = STK_VAL_RESET_VAL;											/*Clear current value*/
	SYSTICK_BASE_ADD->STK_CTRL = (STK_CTRL_ENABLE_DIS | STK_INTERRUPT_STATE | STK_CLK_SRC);
	SYSTICK_timerOperationState = TIMER_LOAD_NOT_SET;
}

Std_enuErrorStatus   SYSTICK_tenuSetTickTimeMs (u32 timeMs)
{

	Std_enuErrorStatus StdRetVal   = OK;
	u32 		tempLoadVal = STK_CLR_VAL;
	u32 		loadValue   = STK_CLR_VAL;

#if STK_CLK_SYSTEM_SELECT == STK_REAL_SYSTEM_CLK

	#if 	STK_SYSTICK_MODE == STK_MULTI_SHOT_MODE
	#warning  "The needed time will probably never be reached !!!"
	#endif

	u32 noOfOvfsRemainder = STK_CLR_VAL;
	u32 equTimeMs  = timeMs*STK_FXD_PNT;
	static u32 milliTov   = PRESCALER*STK_LOAD_COUNT*SEC_IN_MILLI*STK_FXD_PNT / STK_FCPU;

	if (timeMs > MAX_TIME_MSEC)
	{
		StdRetVal = INVALID_ARGUMENT;
	}
	else
	{

		if (equTimeMs > milliTov)
		{
			SYSTICK_noOfOvfs = (f32)equTimeMs /milliTov;
			noOfOvfsRemainder = (SYSTICK_noOfOvfs - (u32)SYSTICK_noOfOvfs)*STK_FXD_PNT;

			if (noOfOvfsRemainder > STK_FXD_PNT)
			{
				SYSTICK_noOfOvfs ++;
				SYSTICK_counter            = (u32)SYSTICK_noOfOvfs;
				loadValue = (STK_LOAD_COUNT*(noOfOvfsRemainder/STK_FXD_PNT));
				#if 	STK_SYSTICK_MODE == STK_MULTI_SHOT_MODE
								tempLoadVal = loadValue - STK_ONE_VAL;
				#else
								tempLoadVal = loadValue;
				#endif
				SYSTICK_BASE_ADD->STK_LOAD = tempLoadVal;
			}
			else
			{
				SYSTICK_counter            = (u32)SYSTICK_noOfOvfs;
				loadValue = STK_LOAD_TOPVAL;
				#if 	STK_SYSTICK_MODE == STK_MULTI_SHOT_MODE
								tempLoadVal = loadValue - STK_ONE_VAL;
				#else
								tempLoadVal = loadValue;
				#endif
				SYSTICK_BASE_ADD->STK_LOAD = tempLoadVal;
			}
		}

		else if (equTimeMs < milliTov)
		{
			SYSTICK_noOfOvfs 		   = STK_ONE_VAL;
			SYSTICK_counter  		   = STK_ONE_VAL;
			loadValue = STK_LOAD_COUNT * (equTimeMs/milliTov);
			#if 	STK_SYSTICK_MODE == STK_MULTI_SHOT_MODE
							tempLoadVal = loadValue - STK_ONE_VAL;
			#else
							tempLoadVal = loadValue;
			#endif
			SYSTICK_BASE_ADD->STK_LOAD = tempLoadVal;
		}

		else
		{
			SYSTICK_noOfOvfs 		   = STK_ONE_VAL;
			SYSTICK_counter  		   = STK_ONE_VAL;
			loadValue = STK_LOAD_TOPVAL;
			#if 	STK_SYSTICK_MODE == STK_MULTI_SHOT_MODE
							tempLoadVal = loadValue - STK_ONE_VAL;
			#else
							tempLoadVal = loadValue;
			#endif
			SYSTICK_BASE_ADD->STK_LOAD = tempLoadVal;
		}

	}
#else
	static u32 oneMsecTicksCount = STK_FCPU/PRESCALER*SEC_IN_MILLI;
		   loadValue = timeMs*oneMsecTicksCount;

		   if (SYSTICK_timerOperationState == TIMER_NOT_INITIALIZED)
		   	{
			   StdRetVal  = NOK;
		   	}
		   else if (loadValue > STK_LOAD_TOPVAL)
		    {
			   StdRetVal = INVALID_ARG;
		    }
		   	else
		   	{
				#if 	STK_SYSTICK_MODE == STK_MULTI_SHOT_MODE
								tempLoadVal = loadValue - STK_ONE_VAL;
				#else
								tempLoadVal = loadValue;
				#endif
		   		SYSTICK_BASE_ADD->STK_LOAD = tempLoadVal;
		   	}
#endif

	if (SYSTICK_BASE_ADD->STK_LOAD == STK_CLR_VAL)
	{
		SYSTICK_timerOperationState = TIMER_LOAD_NOT_SET;
	}
	else
	{
		SYSTICK_timerOperationState = TIMER_READY;
	}

	return StdRetVal;
}

Std_enuErrorStatus	SYSTICK_tenuStart(void)
{
	Std_enuErrorStatus StdRetVal = OK;

	if (SYSTICK_timerOperationState != TIMER_READY)
	{
		StdRetVal = NOK;
	}

	else
	{
		SYSTICK_BASE_ADD->STK_CTRL |= STK_CTRL_ENABLE_EN;
	}

	return StdRetVal;
}

Std_enuErrorStatus	   SYSTICK_tenuRegisterCbf (pfunc Cbf)
{
	Std_enuErrorStatus StdRetVal = OK;

	if (Cbf == NULL)
	{
		StdRetVal = NULL_PTR;
	}
	else
	{
		SYSTICK_TimerLoadRegisterOvf = Cbf;
	}

	return StdRetVal;
}



void __attribute__ ((section(".after_vectors"),weak))
SysTick_Handler (void)
{
	if (SYSTICK_TimerLoadRegisterOvf != NULL)
	{
		#if STK_CLK_SYSTEM_SELECT == STK_REAL_SYSTEM_CLK

			SYSTICK_counter --;
			if (SYSTICK_counter == STK_CLR_VAL)
			{
				SYSTICK_TimerLoadRegisterOvf();
				SYSTICK_counter = (u32)SYSTICK_noOfOvfs;
			}

		#else

			SYSTICK_TimerLoadRegisterOvf();

			#if STK_SYSTICK_MODE == STK_SINGLE_SHOT_MODE
				SYSTICK_vidStop();
			#endif

		#endif
	}

}
