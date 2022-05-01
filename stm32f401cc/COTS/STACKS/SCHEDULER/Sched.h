/*
 * Sched.h
 *
 *  Created on: Apr 14, 2022
 *      Author: dahroug
 */

#ifndef 	SCHED_H_
#define 	SCHED_H_

/* New types (enums) section */
typedef enum
{
	PASSIVE,
	RUNNING

}TaskState_t;

typedef enum
{
	SECOND_QUEUE,
	FIRST_QUEUE,
	BACK_QUEUE

}TaskQueueType_t;

typedef struct
{

	u16   		    firstDelay;				//dont ever change first delay in runTime without changing periodicity
	u16   		    periodicity;
	TaskState_t     state;
	TaskQueueType_t queueType;
	pfunc 		    pCode;
	u8 			    priority;
	u8 			    index;

}TaskCtrlBlock_t;

/* Function prototypes section */
extern Std_enuErrorStatus Sched_tenuInit(void);
extern Std_enuErrorStatus Sched_tenuStopTask  (u8 Copy_u8TaskIndex);
extern Std_enuErrorStatus Sched_tenuAddTask   (TaskCtrlBlock_t* Add_typeTcbTask);
extern void 			  Sched_vidDeleteTask (u8 Copy_u8TaskIndex);
extern Std_enuErrorStatus Sched_tenuStartSched (void);

#endif 		/* SCHED_H_ */
