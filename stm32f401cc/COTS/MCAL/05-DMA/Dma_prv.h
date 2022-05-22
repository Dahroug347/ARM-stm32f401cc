/*
 * Dma_prv.h
 *
 *  Created on: May 16, 2022
 *      Author: dahroug
 */

#ifndef      DMA_PRV_H_
#define      DMA_PRV_H_

typedef struct
{
	volatile u32 DMA_LISR;
	volatile u32 DMA_HISR;
	volatile u32 DMA_LIFCR;
	volatile u32 DMA_HIFCR;

	volatile u32 DMA_SOCR;
	volatile u32 DMA_SONDTR;
	volatile u32 DMA_SOPAR;
	volatile u32 DMA_SOMOAR;
	volatile u32 DMA_SOM1AR;
	volatile u32 DMA_SOFCR;

	volatile u32 DMA_S1CR;
	volatile u32 DMA_S1NDTR;
	volatile u32 DMA_S1PAR;
	volatile u32 DMA_S1MOAR;
	volatile u32 DMA_S1M1AR;
	volatile u32 DMA_S1FCR;

	volatile u32 DMA_S2CR;
	volatile u32 DMA_S2NDTR;
	volatile u32 DMA_S2PAR;
	volatile u32 DMA_S2MOAR;
	volatile u32 DMA_S2M1AR;
	volatile u32 DMA_S2FCR;

	volatile u32 DMA_S3CR;
	volatile u32 DMA_S3NDTR;
	volatile u32 DMA_S3PAR;
	volatile u32 DMA_S3MOAR;
	volatile u32 DMA_S3M1AR;
	volatile u32 DMA_S3FCR;

	volatile u32 DMA_S4CR;
	volatile u32 DMA_S4NDTR;
	volatile u32 DMA_S4PAR;
	volatile u32 DMA_S4MOAR;
	volatile u32 DMA_S4M1AR;
	volatile u32 DMA_S4FCR;

	volatile u32 DMA_S5CR;
	volatile u32 DMA_S5NDTR;
	volatile u32 DMA_S5PAR;
	volatile u32 DMA_S5MOAR;
	volatile u32 DMA_S5M1AR;
	volatile u32 DMA_S5FCR;

	volatile u32 DMA_S6CR;
	volatile u32 DMA_S6NDTR;
	volatile u32 DMA_S6PAR;
	volatile u32 DMA_S6MOAR;
	volatile u32 DMA_S6M1AR;
	volatile u32 DMA_S6FCR;

	volatile u32 DMA_S7CR;
	volatile u32 DMA_S7NDTR;
	volatile u32 DMA_S7PAR;
	volatile u32 DMA_S7MOAR;
	volatile u32 DMA_S7M1AR;
	volatile u32 DMA_S7FCR;

}DmaReg_t;


#define 	DMA1		                 ((volatile DmaReg_t*)0x40026000)
#define 	DMA2		                 ((volatile DmaReg_t*)0x40026400)

#define 	DMA_FLAG_CLR_MASK			 ((u32)0x0F7D0F7D)
#define 	DMA_NO_CFG					 ((u32)0x00000000)

#define 	DMA_ZERO					 0
#define 	DMA_ONE						 1

#define 	DMA_STREAM_NUM				 8

#endif       /* DMA_PRV_H_ */
