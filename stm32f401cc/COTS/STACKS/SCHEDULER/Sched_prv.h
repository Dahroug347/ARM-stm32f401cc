/*
 * Sched_Prv.h
 *
 *  Created on: Apr 25, 2022
 *      Author: dahroug
 */

#ifndef         SCHED_PRV_H_
#define         SCHED_PRV_H_

/* private defined macros section */
#define 	    SCHED_ZERO			    0
#define 	    SCHED_ONE			    1

#define 	    SCHED_SORTED		    1
#define 	    SCHED_NOT_SORTED	    0

#define 		SCHED_START			    1
#define			SCHED_STOP			    0

/* Macros for modes selection section */
#define 	    SCHED_PRIORITY_ON	 	1
#define 	    SCHED_PRIORITY_OFF	 	0

/* Macros Targets' options */
#define 	    ATMEGA_32	 			0
#define 	    STM_32_M4				1

/* private function prototypes section */
static void Sched_vidRunSched(void);
static void Sched_vidSetSchedRunFlag(void);
#endif         /* SCHED_PRV_H_ */
