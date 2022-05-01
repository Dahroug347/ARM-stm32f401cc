/*
 * Sched.c
 *
 *  Created on: Apr 14, 2022
 *      Author: dahroug
 */


/****** section of includes ******/
#include "Std_types.h"

#include "Sched.h"
#include "Sched_prv.h"
#include "Sched_cfg.h"

#include "Systick.h"
/* ----------------------------- */

/***************************** Section of global variables **************************************/
static TaskCtrlBlock_t*  SCHED_tenuArrTasks [SCHED_TASKS_NUM] = {NULL};

static u8 		   SCHED_su8TasksCounter     				  = SCHED_ZERO;

u8 				   SCHED_u8StartFlag 						  = SCHED_STOP;
/* -------------------------------------------------------------------------------------------- */


/****************************************************** Optional private function if "priority" will be used according to user configuration ******************************************************/
#if SCHED_PRORITY
static void Sched_vidSwapTasks (TaskCtrlBlock_t* Add_tenuTask1, TaskCtrlBlock_t* Add_tenuTask2)
{
		TaskCtrlBlock_t Loc_tenuTaskTempHolder = *Add_tenuTask1;
		*Add_tenuTask1 = *Add_tenuTask2;
		*Add_tenuTask2 = Loc_tenuTaskTempHolder;

		Add_tenuTask1->index = Add_tenuTask1->priority;
		Add_tenuTask2->index = Add_tenuTask2->priority;
}
#endif


/****************************************************** section of User function section  ******************************************************/

Std_enuErrorStatus Sched_tenuInit(void)
{
	Std_enuErrorStatus Loc_tenuErrStatusRetVal = OK;

	SYSTICK_vidInit();

if (SYSTICK_tenuRegisterCbf(Sched_vidSetSchedRunFlag) != OK)
	{
		Loc_tenuErrStatusRetVal = NULL_PTR;
	}
	else
	{

	}
	return Loc_tenuErrStatusRetVal;
}

Std_enuErrorStatus Sched_tenuAddTask(TaskCtrlBlock_t* Add_typeTcbTask)
{

	Std_enuErrorStatus Loc_tenuErrStatusRetVal = OK;

	if (SCHED_su8TasksCounter == SCHED_TASKS_NUM)
	{
		Loc_tenuErrStatusRetVal = NOK;
	}
	else if (Add_typeTcbTask == NULL)
	{
		Loc_tenuErrStatusRetVal = NULL_PTR;
	}
	else
	{
		SCHED_tenuArrTasks[SCHED_su8TasksCounter] = Add_typeTcbTask;
		SCHED_tenuArrTasks[SCHED_su8TasksCounter]->index = SCHED_su8TasksCounter;
	}

	SCHED_su8TasksCounter ++;

	return Loc_tenuErrStatusRetVal;

}

Std_enuErrorStatus  Sched_tenuStopTask (u8 Copy_u8TaskIndex)
{
	Std_enuErrorStatus Loc_tenuErrStatusRetVal = OK;

	if (SCHED_tenuArrTasks[Copy_u8TaskIndex] == NULL)
	{
		Loc_tenuErrStatusRetVal = NULL_PTR;
	}
	else
	{
		SCHED_tenuArrTasks[Copy_u8TaskIndex]->state = PASSIVE;
	}

	return Loc_tenuErrStatusRetVal;
}

void 				Sched_vidDeleteTask(u8 Copy_u8TaskIndex)
{
	if (SCHED_tenuArrTasks[Copy_u8TaskIndex] != NULL)
	{
		while (Copy_u8TaskIndex < SCHED_su8TasksCounter)
		{
			SCHED_tenuArrTasks[Copy_u8TaskIndex] = SCHED_tenuArrTasks[Copy_u8TaskIndex + SCHED_ONE];
			if (SCHED_tenuArrTasks[Copy_u8TaskIndex + SCHED_ONE] != NULL)
			{
				SCHED_tenuArrTasks[Copy_u8TaskIndex]->index = SCHED_tenuArrTasks[Copy_u8TaskIndex]->index - SCHED_ONE;
			}
			else
			{

			}

			Copy_u8TaskIndex++;
		}
		SCHED_su8TasksCounter --;
	}
	else
	{

	}
}

Std_enuErrorStatus  Sched_tenuStartSched (void)
{
	Std_enuErrorStatus Loc_tenuErrStatusRetVal = OK;
	u8 Loc_u8BackQueueIterator = SCHED_ZERO;

		if (SYSTICK_tenuSetTickTimeMs(SCHED_TICK) != OK)
		{
			Loc_tenuErrStatusRetVal = NOK;
		}
		else if (SYSTICK_tenuStart() != OK)
		{
			Loc_tenuErrStatusRetVal = NOK;
		}
		else
		{
			while(1)
			{
				if (SCHED_u8StartFlag == SCHED_START)
				{
					SCHED_u8StartFlag = SCHED_STOP;
					Sched_vidRunSched();
				}
				else
				{
					while (SCHED_u8StartFlag != SCHED_START && Loc_u8BackQueueIterator < SCHED_TASKS_NUM)
					{
						if (SCHED_tenuArrTasks[Loc_u8BackQueueIterator]->queueType == BACK_QUEUE)
						{
							SCHED_tenuArrTasks[Loc_u8BackQueueIterator]->pCode();
						}
						else
						{

						}
						Loc_u8BackQueueIterator ++;
					}
					if (Loc_u8BackQueueIterator == SCHED_TASKS_NUM)
					{
						Loc_u8BackQueueIterator = SCHED_ZERO;
					}
					else
					{

					}

				}
			}
		}
	return Loc_tenuErrStatusRetVal;
}
/*--------------------------------------------------------------------------------------------------*/


/************************* section of private function section  ************************************/
void Sched_vidRunSched(void)
{
	u8 Loc_u8SchedIterator;

	#if SCHED_PRORITY
		u8 Loc_u8TaskIterator, Loc_u8SizeReference = SCHED_ONE;

		u8 Loc_u8TasksOrderState = SCHED_NOT_SORTED;

		while (Loc_u8TasksOrderState == SCHED_NOT_SORTED)
		{
			Loc_u8TasksOrderState = SCHED_SORTED;

			for (Loc_u8TaskIterator = SCHED_ZERO; Loc_u8TaskIterator < (SCHED_TASKS_NUM - Loc_u8SizeReference); Loc_u8TaskIterator++)
			{
				if (SCHED_tenuArrTasks[Loc_u8TaskIterator]->priority > SCHED_tenuArrTasks[Loc_u8TaskIterator + SCHED_ONE]->priority)
				{
					Sched_vidSwapTasks(SCHED_tenuArrTasks[Loc_u8TaskIterator], SCHED_tenuArrTasks[Loc_u8TaskIterator + SCHED_ONE]);
					Loc_u8TasksOrderState = SCHED_NOT_SORTED;
				}
				else
				{

				}
			}

			Loc_u8SizeReference ++;
		}
	#endif

	for (Loc_u8SchedIterator = SCHED_ZERO; Loc_u8SchedIterator < SCHED_TASKS_NUM; Loc_u8SchedIterator++)
	{
		if (SCHED_tenuArrTasks[Loc_u8SchedIterator] != NULL)
			{
			  if (SCHED_tenuArrTasks[Loc_u8SchedIterator]->queueType == SECOND_QUEUE)
			  {
					if (SCHED_tenuArrTasks[Loc_u8SchedIterator]->state == RUNNING)
						{
							if (SCHED_tenuArrTasks[Loc_u8SchedIterator]->firstDelay == SCHED_ZERO && SCHED_tenuArrTasks[Loc_u8SchedIterator]->pCode != NULL)
							{
								SCHED_tenuArrTasks[Loc_u8SchedIterator]->pCode();
								SCHED_tenuArrTasks[Loc_u8SchedIterator]->firstDelay = SCHED_tenuArrTasks[Loc_u8SchedIterator]->periodicity;
							}
							else
							{

							}
							SCHED_tenuArrTasks[Loc_u8SchedIterator]->firstDelay --;
						}
					else
					{

					}
			  }
			  else
			  {

			  }

			}
			else
			{

			}
	}

	for (Loc_u8SchedIterator = SCHED_ZERO; Loc_u8SchedIterator < SCHED_TASKS_NUM; Loc_u8SchedIterator++)
	{
		if (SCHED_tenuArrTasks[Loc_u8SchedIterator] != NULL)
			{
			  if (SCHED_tenuArrTasks[Loc_u8SchedIterator]->queueType == FIRST_QUEUE)
			  {
					if (SCHED_tenuArrTasks[Loc_u8SchedIterator]->state == RUNNING)
						{
							if (SCHED_tenuArrTasks[Loc_u8SchedIterator]->firstDelay == SCHED_ZERO && SCHED_tenuArrTasks[Loc_u8SchedIterator]->pCode != NULL)
							{
								SCHED_tenuArrTasks[Loc_u8SchedIterator]->pCode();
								SCHED_tenuArrTasks[Loc_u8SchedIterator]->firstDelay = SCHED_tenuArrTasks[Loc_u8SchedIterator]->periodicity;
							}
							else
							{

							}
							SCHED_tenuArrTasks[Loc_u8SchedIterator]->firstDelay --;
						}
					else
					{

					}
			  }
			  else
			  {

			  }

			}
			else
			{

			}
	}


}


void Sched_vidSetSchedRunFlag(void)
{
	SCHED_u8StartFlag = SCHED_START;
}
/* ------------------------------------------------------------------------------------------------ */
