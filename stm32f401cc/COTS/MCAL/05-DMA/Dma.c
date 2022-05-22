/*
 * Dma.c
 *
 *  Created on: May 12, 2022
 *      Author: dahroug
 */

#include "Std_types.h"
#include "Bit_utils.h"

#include "Dma.h"
#include "Dma_prv.h"



static pfunc 	DMA1_pfGlbDmaTransferCompleteCbfHandler[DMA_STREAM_NUM] = {NULL};
static pfunc 	DMA2_pfGlbDmaTransferCompleteCbfHandler[DMA_STREAM_NUM] = {NULL};


Std_enuErrorStatus DMA_tenuConfig(DMA_strCfg* Add_pStrDmaCfg)
{
	Std_enuErrorStatus Loc_enuErrStatRetVal = OK;

	if (Add_pStrDmaCfg == NULL || Add_pStrDmaCfg->MemoryAddress == NULL || Add_pStrDmaCfg->PeripheralMemory2Address == NULL)
	{
		Loc_enuErrStatRetVal = NULL_PTR;
	}

	else
	{
		if (Add_pStrDmaCfg->DMA == DMA_1)
		{

			DMA1->DMA_LIFCR |= DMA_FLAG_CLR_MASK;
			DMA1->DMA_HIFCR |= DMA_FLAG_CLR_MASK;

		  		 switch (Add_pStrDmaCfg->Stream)
		  		 {
		  		 	 case stream_0:

		  		 		while (DMA1->DMA_SOCR & DMA_SxCR_EN);                                /* waiting for DMA to finish previous operation*/

		  		 		 DMA1->DMA_SOPAR 	= (u32)Add_pStrDmaCfg->PeripheralMemory2Address;

		  		 		 if (Add_pStrDmaCfg->DmaDoubleBufferMode)
		  		 		 {

		  		 			 DMA1->DMA_SOMOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 			 DMA1->DMA_SOM1AR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 		 }
		  		 		 else
		  		 		 {
		  		 			 DMA1->DMA_SOMOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 		 }

		  		 		 DMA1->DMA_SONDTR = Add_pStrDmaCfg->DmaDataBlockItemsToTransfer;

		  		 		 DMA1->DMA_SOCR   = Add_pStrDmaCfg->DmaChannel;
		  		 		 DMA1->DMA_SOCR   = Add_pStrDmaCfg->DmaPeripheralControl;
		  		 		 DMA1->DMA_SOCR	  = Add_pStrDmaCfg->DmaStreamPriority;
		  		 		 DMA1->DMA_SOCR	  = Add_pStrDmaCfg->Data_Transfer_Dir;
		  		 		 DMA1->DMA_SOCR	  = Add_pStrDmaCfg->DmaPincMemMode;
		  		 		 DMA1->DMA_SOCR	  = Add_pStrDmaCfg->DmaMincMode;
		  		 		 DMA1->DMA_SOCR	  = Add_pStrDmaCfg->DmaSingleBurstTransactions;
		  		 		 DMA1->DMA_SOCR   = Add_pStrDmaCfg->DmaPeriMemPtrSize;
		  		 		 DMA1->DMA_SOCR   = Add_pStrDmaCfg->DmaCircularMode;
		  		 		 DMA1->DMA_SOCR   = Add_pStrDmaCfg->DmaInterruptsModes;
		  		 	break;

		  		 	 case stream_1:

		  		 		 while (DMA1->DMA_S1CR & DMA_SxCR_EN);                                /* waiting for DMA to finish previous operation*/

		  		 		 DMA1->DMA_S1PAR 	= (u32)Add_pStrDmaCfg->PeripheralMemory2Address;

		  		 		 if (Add_pStrDmaCfg->DmaDoubleBufferMode)
		  		 		 {

		  		 			 DMA1->DMA_S1MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 			 DMA1->DMA_S1M1AR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 		 }
		  		 		 else
		  		 		 {
		  		 			 DMA1->DMA_S1MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 		 }

		  		 		 DMA1->DMA_S1NDTR = Add_pStrDmaCfg->DmaDataBlockItemsToTransfer;

		  		 		 DMA1->DMA_S1CR   = Add_pStrDmaCfg->DmaChannel;
		  		 		 DMA1->DMA_S1CR   = Add_pStrDmaCfg->DmaPeripheralControl;
		  		 		 DMA1->DMA_S1CR	  = Add_pStrDmaCfg->DmaStreamPriority;
		  		 		 DMA1->DMA_S1CR	  = Add_pStrDmaCfg->Data_Transfer_Dir;
		  		 		 DMA1->DMA_S1CR	  = Add_pStrDmaCfg->DmaPincMemMode;
		  		 		 DMA1->DMA_S1CR	  = Add_pStrDmaCfg->DmaMincMode;
		  		 		 DMA1->DMA_S1CR	  = Add_pStrDmaCfg->DmaSingleBurstTransactions;
		  		 		 DMA1->DMA_S1CR   = Add_pStrDmaCfg->DmaPeriMemPtrSize;
		  		 		 DMA1->DMA_S1CR   = Add_pStrDmaCfg->DmaCircularMode;
		  		 		 DMA1->DMA_S1CR   = Add_pStrDmaCfg->DmaInterruptsModes;
		  		 	break;
		  		 	 case stream_2:

		  		 		while (DMA1->DMA_S2CR & DMA_SxCR_EN);

		  		 		 DMA1->DMA_S2PAR 	= (u32)Add_pStrDmaCfg->PeripheralMemory2Address;

		  		 		 if (Add_pStrDmaCfg->DmaDoubleBufferMode)
		  		 		 {

		  		 			 DMA1->DMA_S2MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 			 DMA1->DMA_S2M1AR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 		 }
		  		 		 else
		  		 		 {
		  		 			 DMA1->DMA_S2MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 		 }

		  		 		 DMA1->DMA_S1NDTR = Add_pStrDmaCfg->DmaDataBlockItemsToTransfer;

		  		 		 DMA1->DMA_S2CR   = Add_pStrDmaCfg->DmaChannel;
		  		 		 DMA1->DMA_S2CR   = Add_pStrDmaCfg->DmaPeripheralControl;
		  		 		 DMA1->DMA_S2CR	  = Add_pStrDmaCfg->DmaStreamPriority;
		  		 		 DMA1->DMA_S2CR	  = Add_pStrDmaCfg->Data_Transfer_Dir;
		  		 		 DMA1->DMA_S2CR	  = Add_pStrDmaCfg->DmaPincMemMode;
		  		 		 DMA1->DMA_S2CR	  = Add_pStrDmaCfg->DmaMincMode;
		  		 		 DMA1->DMA_S2CR	  = Add_pStrDmaCfg->DmaSingleBurstTransactions;
		  		 		 DMA1->DMA_S2CR   = Add_pStrDmaCfg->DmaPeriMemPtrSize;
		  		 		 DMA1->DMA_S2CR   = Add_pStrDmaCfg->DmaCircularMode;
		  		 		 DMA1->DMA_S2CR   = Add_pStrDmaCfg->DmaInterruptsModes;
		  		 	break;
		  		 	 case stream_3:

		  		 		while (DMA1->DMA_S3CR & DMA_SxCR_EN);

		  		 		 DMA1->DMA_S3PAR 	= (u32)Add_pStrDmaCfg->PeripheralMemory2Address;

		  		 		 if (Add_pStrDmaCfg->DmaDoubleBufferMode)
		  		 		 {

		  		 			 DMA1->DMA_S3MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 			 DMA1->DMA_S3M1AR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 		 }
		  		 		 else
		  		 		 {
		  		 			 DMA1->DMA_S3MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 		 }

		  		 		 DMA1->DMA_S3NDTR = Add_pStrDmaCfg->DmaDataBlockItemsToTransfer;

		  		 		 DMA1->DMA_S3CR   = Add_pStrDmaCfg->DmaChannel;
		  		 		 DMA1->DMA_S3CR   = Add_pStrDmaCfg->DmaPeripheralControl;
		  		 		 DMA1->DMA_S3CR	  = Add_pStrDmaCfg->DmaStreamPriority;
		  		 		 DMA1->DMA_S3CR	  = Add_pStrDmaCfg->Data_Transfer_Dir;
		  		 		 DMA1->DMA_S3CR	  = Add_pStrDmaCfg->DmaPincMemMode;
		  		 		 DMA1->DMA_S3CR	  = Add_pStrDmaCfg->DmaMincMode;
		  		 		 DMA1->DMA_S3CR	  = Add_pStrDmaCfg->DmaSingleBurstTransactions;
		  		 		 DMA1->DMA_S3CR   = Add_pStrDmaCfg->DmaPeriMemPtrSize;
		  		 		 DMA1->DMA_S3CR   = Add_pStrDmaCfg->DmaCircularMode;
		  		 		 DMA1->DMA_S3CR   = Add_pStrDmaCfg->DmaInterruptsModes;
		  		 	break;
		  		 	 case stream_4:

		  		 		while (DMA1->DMA_S4CR & DMA_SxCR_EN);

		  		 		 DMA1->DMA_S4PAR 	= (u32)Add_pStrDmaCfg->PeripheralMemory2Address;

		  		 		 if (Add_pStrDmaCfg->DmaDoubleBufferMode)
		  		 		 {

		  		 			 DMA1->DMA_S4MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 			 DMA1->DMA_S4M1AR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 		 }
		  		 		 else
		  		 		 {
		  		 			 DMA1->DMA_S4MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 		 }

		  		 		 DMA1->DMA_S4NDTR = Add_pStrDmaCfg->DmaDataBlockItemsToTransfer;

		  		 		 DMA1->DMA_S4CR   = Add_pStrDmaCfg->DmaChannel;
		  		 		 DMA1->DMA_S4CR   = Add_pStrDmaCfg->DmaPeripheralControl;
		  		 		 DMA1->DMA_S4CR	  = Add_pStrDmaCfg->DmaStreamPriority;
		  		 		 DMA1->DMA_S4CR	  = Add_pStrDmaCfg->Data_Transfer_Dir;
		  		 		 DMA1->DMA_S4CR	  = Add_pStrDmaCfg->DmaPincMemMode;
		  		 		 DMA1->DMA_S4CR	  = Add_pStrDmaCfg->DmaMincMode;
		  		 		 DMA1->DMA_S4CR	  = Add_pStrDmaCfg->DmaSingleBurstTransactions;
		  		 		 DMA1->DMA_S4CR   = Add_pStrDmaCfg->DmaPeriMemPtrSize;
		  		 		 DMA1->DMA_S4CR   = Add_pStrDmaCfg->DmaCircularMode;
		  		 		 DMA1->DMA_S4CR   = Add_pStrDmaCfg->DmaInterruptsModes;
		  		 	break;
		  		 	 case stream_5:

		  		 		while (DMA1->DMA_S5CR & DMA_SxCR_EN);

		  		 		 DMA1->DMA_S5PAR 	= (u32)Add_pStrDmaCfg->PeripheralMemory2Address;

		  		 		 if (Add_pStrDmaCfg->DmaDoubleBufferMode)
		  		 		 {

		  		 			 DMA1->DMA_S5MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 			 DMA1->DMA_S5M1AR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 		 }
		  		 		 else
		  		 		 {
		  		 			 DMA1->DMA_S5MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 		 }

		  		 		 DMA1->DMA_S5NDTR = Add_pStrDmaCfg->DmaDataBlockItemsToTransfer;

		  		 		 DMA1->DMA_S5CR   = Add_pStrDmaCfg->DmaChannel;
		  		 		 DMA1->DMA_S5CR   = Add_pStrDmaCfg->DmaPeripheralControl;
		  		 		 DMA1->DMA_S5CR	  = Add_pStrDmaCfg->DmaStreamPriority;
		  		 		 DMA1->DMA_S5CR	  = Add_pStrDmaCfg->Data_Transfer_Dir;
		  		 		 DMA1->DMA_S5CR	  = Add_pStrDmaCfg->DmaPincMemMode;
		  		 		 DMA1->DMA_S5CR	  = Add_pStrDmaCfg->DmaMincMode;
		  		 		 DMA1->DMA_S5CR	  = Add_pStrDmaCfg->DmaSingleBurstTransactions;
		  		 		 DMA1->DMA_S5CR   = Add_pStrDmaCfg->DmaPeriMemPtrSize;
		  		 		 DMA1->DMA_S5CR   = Add_pStrDmaCfg->DmaCircularMode;
		  		 		 DMA1->DMA_S5CR   = Add_pStrDmaCfg->DmaInterruptsModes;
		  		 	break;
		  		 	 case stream_6:

		  		 		while (DMA1->DMA_S6CR & DMA_SxCR_EN);

		  		 		 DMA1->DMA_S6PAR 	= (u32)Add_pStrDmaCfg->PeripheralMemory2Address;

		  		 		 if (Add_pStrDmaCfg->DmaDoubleBufferMode)
		  		 		 {

		  		 			 DMA1->DMA_S6MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 			 DMA1->DMA_S6M1AR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 		 }
		  		 		 else
		  		 		 {
		  		 			 DMA1->DMA_S6MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 		 }

		  		 		 DMA1->DMA_S6NDTR = Add_pStrDmaCfg->DmaDataBlockItemsToTransfer;

		  		 		 DMA1->DMA_S6CR   = Add_pStrDmaCfg->DmaChannel;
		  		 		 DMA1->DMA_S6CR   = Add_pStrDmaCfg->DmaPeripheralControl;
		  		 		 DMA1->DMA_S6CR	  = Add_pStrDmaCfg->DmaStreamPriority;
		  		 		 DMA1->DMA_S6CR	  = Add_pStrDmaCfg->Data_Transfer_Dir;
		  		 		 DMA1->DMA_S6CR	  = Add_pStrDmaCfg->DmaPincMemMode;
		  		 		 DMA1->DMA_S6CR	  = Add_pStrDmaCfg->DmaMincMode;
		  		 		 DMA1->DMA_S6CR	  = Add_pStrDmaCfg->DmaSingleBurstTransactions;
		  		 		 DMA1->DMA_S6CR   = Add_pStrDmaCfg->DmaPeriMemPtrSize;
		  		 		 DMA1->DMA_S6CR   = Add_pStrDmaCfg->DmaCircularMode;
		  		 		 DMA1->DMA_S6CR   = Add_pStrDmaCfg->DmaInterruptsModes;
		  		 	break;
		  		 	 case stream_7:

		  		 		while (DMA1->DMA_S7CR & DMA_SxCR_EN);

		  		 		 DMA1->DMA_S7PAR 	= (u32)Add_pStrDmaCfg->PeripheralMemory2Address;

		  		 		 if (Add_pStrDmaCfg->DmaDoubleBufferMode)
		  		 		 {

		  		 			 DMA1->DMA_S7MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 			 DMA1->DMA_S7M1AR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 		 }
		  		 		 else
		  		 		 {
		  		 			 DMA1->DMA_S7MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
		  		 		 }

		  		 		 DMA1->DMA_S7NDTR = Add_pStrDmaCfg->DmaDataBlockItemsToTransfer;

		  		 		 DMA1->DMA_S7CR   = Add_pStrDmaCfg->DmaChannel;
		  		 		 DMA1->DMA_S7CR   = Add_pStrDmaCfg->DmaPeripheralControl;
		  		 		 DMA1->DMA_S7CR	  = Add_pStrDmaCfg->DmaStreamPriority;
		  		 		 DMA1->DMA_S7CR	  = Add_pStrDmaCfg->Data_Transfer_Dir;
		  		 		 DMA1->DMA_S7CR	  = Add_pStrDmaCfg->DmaPincMemMode;
		  		 		 DMA1->DMA_S7CR	  = Add_pStrDmaCfg->DmaMincMode;
		  		 		 DMA1->DMA_S7CR	  = Add_pStrDmaCfg->DmaSingleBurstTransactions;
		  		 		 DMA1->DMA_S7CR   = Add_pStrDmaCfg->DmaPeriMemPtrSize;
		  		 		 DMA1->DMA_S7CR   = Add_pStrDmaCfg->DmaCircularMode;
		  		 		 DMA1->DMA_S7CR   = Add_pStrDmaCfg->DmaInterruptsModes;
		  		 	break;

		  		 	 default:
		  		 		 Loc_enuErrStatRetVal = INVALID_ARG;
		  		 }

		}

		else if (Add_pStrDmaCfg->DMA == DMA_2)
		{
			DMA2->DMA_LIFCR |= DMA_FLAG_CLR_MASK;
			DMA2->DMA_HIFCR |= DMA_FLAG_CLR_MASK;

	  		 switch (Add_pStrDmaCfg->Stream)
	  		 {
	  		 	 case stream_0:

	  		 		while (DMA2->DMA_SOCR & DMA_SxCR_EN);

	  		 		 DMA2->DMA_SOPAR 	= (u32)Add_pStrDmaCfg->PeripheralMemory2Address;

	  		 		 if (Add_pStrDmaCfg->DmaDoubleBufferMode)
	  		 		 {

	  		 			 DMA2->DMA_SOMOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 			 DMA2->DMA_SOM1AR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 		 }
	  		 		 else
	  		 		 {
	  		 			 DMA2->DMA_SOMOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 		 }

	  		 		 DMA2->DMA_SONDTR = Add_pStrDmaCfg->DmaDataBlockItemsToTransfer;

	  		 		 DMA2->DMA_SOCR   = Add_pStrDmaCfg->DmaChannel;
	  		 		 DMA2->DMA_SOCR   = Add_pStrDmaCfg->DmaPeripheralControl;
	  		 		 DMA2->DMA_SOCR	  = Add_pStrDmaCfg->DmaStreamPriority;
	  		 		 DMA2->DMA_SOCR	  = Add_pStrDmaCfg->Data_Transfer_Dir;
	  		 		 DMA2->DMA_SOCR	  = Add_pStrDmaCfg->DmaPincMemMode;
	  		 		 DMA2->DMA_SOCR	  = Add_pStrDmaCfg->DmaMincMode;
	  		 		 DMA2->DMA_SOCR	  = Add_pStrDmaCfg->DmaSingleBurstTransactions;
	  		 		 DMA2->DMA_SOCR   = Add_pStrDmaCfg->DmaPeriMemPtrSize;
	  		 		 DMA2->DMA_SOCR   = Add_pStrDmaCfg->DmaCircularMode;
	  		 		 DMA2->DMA_SOCR   = Add_pStrDmaCfg->DmaInterruptsModes;
	  		 	break;

	  		 	 case stream_1:

	  		 		while (DMA2->DMA_S1CR & DMA_SxCR_EN);

	  		 		 DMA2->DMA_S1PAR 	= (u32)Add_pStrDmaCfg->PeripheralMemory2Address;

	  		 		 if (Add_pStrDmaCfg->DmaDoubleBufferMode)
	  		 		 {

	  		 			 DMA2->DMA_S1MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 			 DMA2->DMA_S1M1AR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 		 }
	  		 		 else
	  		 		 {
	  		 			 DMA2->DMA_S1MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 		 }

	  		 		 DMA2->DMA_S1NDTR = Add_pStrDmaCfg->DmaDataBlockItemsToTransfer;

	  		 		 DMA2->DMA_S1CR   = Add_pStrDmaCfg->DmaChannel;
	  		 		 DMA2->DMA_S1CR   = Add_pStrDmaCfg->DmaPeripheralControl;
	  		 		 DMA2->DMA_S1CR	  = Add_pStrDmaCfg->DmaStreamPriority;
	  		 		 DMA2->DMA_S1CR	  = Add_pStrDmaCfg->Data_Transfer_Dir;
	  		 		 DMA2->DMA_S1CR	  = Add_pStrDmaCfg->DmaPincMemMode;
	  		 		 DMA2->DMA_S1CR	  = Add_pStrDmaCfg->DmaMincMode;
	  		 		 DMA2->DMA_S1CR	  = Add_pStrDmaCfg->DmaSingleBurstTransactions;
	  		 		 DMA2->DMA_S1CR   = Add_pStrDmaCfg->DmaPeriMemPtrSize;
	  		 		 DMA2->DMA_S1CR   = Add_pStrDmaCfg->DmaCircularMode;
	  		 		 DMA2->DMA_S1CR   = Add_pStrDmaCfg->DmaInterruptsModes;
	  		 	break;
	  		 	 case stream_2:

	  		 		while (DMA2->DMA_S2CR & DMA_SxCR_EN);

	  		 		DMA2->DMA_S2PAR 	= (u32)Add_pStrDmaCfg->PeripheralMemory2Address;

	  		 		 if (Add_pStrDmaCfg->DmaDoubleBufferMode)
	  		 		 {

	  		 			 DMA2->DMA_S2MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 			 DMA2->DMA_S2M1AR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 		 }
	  		 		 else
	  		 		 {
	  		 			 DMA2->DMA_S2MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 		 }

	  		 		 DMA2->DMA_S1NDTR = Add_pStrDmaCfg->DmaDataBlockItemsToTransfer;

	  		 		 DMA2->DMA_S2CR   = Add_pStrDmaCfg->DmaChannel;
	  		 		 DMA2->DMA_S2CR   = Add_pStrDmaCfg->DmaPeripheralControl;
	  		 		 DMA2->DMA_S2CR	  = Add_pStrDmaCfg->DmaStreamPriority;
	  		 		 DMA2->DMA_S2CR	  = Add_pStrDmaCfg->Data_Transfer_Dir;
	  		 		 DMA2->DMA_S2CR	  = Add_pStrDmaCfg->DmaPincMemMode;
	  		 		 DMA2->DMA_S2CR	  = Add_pStrDmaCfg->DmaMincMode;
	  		 		 DMA2->DMA_S2CR	  = Add_pStrDmaCfg->DmaSingleBurstTransactions;
	  		 		 DMA2->DMA_S2CR   = Add_pStrDmaCfg->DmaPeriMemPtrSize;
	  		 		 DMA2->DMA_S2CR   = Add_pStrDmaCfg->DmaCircularMode;
	  		 		 DMA2->DMA_S2CR   = Add_pStrDmaCfg->DmaInterruptsModes;
	  		 	break;
	  		 	 case stream_3:

	  		 		while (DMA2->DMA_S3CR & DMA_SxCR_EN);

	  		 		 DMA2->DMA_S3PAR 	= (u32)Add_pStrDmaCfg->PeripheralMemory2Address;

	  		 		 if (Add_pStrDmaCfg->DmaDoubleBufferMode)
	  		 		 {

	  		 			 DMA2->DMA_S3MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 			 DMA2->DMA_S3M1AR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 		 }
	  		 		 else
	  		 		 {
	  		 			 DMA2->DMA_S3MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 		 }

	  		 		 DMA2->DMA_S3NDTR = Add_pStrDmaCfg->DmaDataBlockItemsToTransfer;

	  		 		 DMA2->DMA_S3CR   = Add_pStrDmaCfg->DmaChannel;
	  		 		 DMA2->DMA_S3CR   = Add_pStrDmaCfg->DmaPeripheralControl;
	  		 		 DMA2->DMA_S3CR	  = Add_pStrDmaCfg->DmaStreamPriority;
	  		 		 DMA2->DMA_S3CR	  = Add_pStrDmaCfg->Data_Transfer_Dir;
	  		 		 DMA2->DMA_S3CR	  = Add_pStrDmaCfg->DmaPincMemMode;
	  		 		 DMA2->DMA_S3CR	  = Add_pStrDmaCfg->DmaMincMode;
	  		 		 DMA2->DMA_S3CR	  = Add_pStrDmaCfg->DmaSingleBurstTransactions;
	  		 		 DMA2->DMA_S3CR   = Add_pStrDmaCfg->DmaPeriMemPtrSize;
	  		 		 DMA2->DMA_S3CR   = Add_pStrDmaCfg->DmaCircularMode;
	  		 		 DMA2->DMA_S3CR   = Add_pStrDmaCfg->DmaInterruptsModes;
	  		 	break;
	  		 	 case stream_4:

	  		 		while (DMA2->DMA_S4CR & DMA_SxCR_EN);

	  		 		 DMA2->DMA_S4PAR 	= (u32)Add_pStrDmaCfg->PeripheralMemory2Address;

	  		 		 if (Add_pStrDmaCfg->DmaDoubleBufferMode)
	  		 		 {

	  		 			 DMA2->DMA_S4MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 			 DMA2->DMA_S4M1AR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 		 }
	  		 		 else
	  		 		 {
	  		 			 DMA2->DMA_S4MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 		 }

	  		 		 DMA2->DMA_S4NDTR = Add_pStrDmaCfg->DmaDataBlockItemsToTransfer;

	  		 		 DMA2->DMA_S4CR   = Add_pStrDmaCfg->DmaChannel;
	  		 		 DMA2->DMA_S4CR   = Add_pStrDmaCfg->DmaPeripheralControl;
	  		 		 DMA2->DMA_S4CR	  = Add_pStrDmaCfg->DmaStreamPriority;
	  		 		 DMA2->DMA_S4CR	  = Add_pStrDmaCfg->Data_Transfer_Dir;
	  		 		 DMA2->DMA_S4CR	  = Add_pStrDmaCfg->DmaPincMemMode;
	  		 		 DMA2->DMA_S4CR	  = Add_pStrDmaCfg->DmaMincMode;
	  		 		 DMA2->DMA_S4CR	  = Add_pStrDmaCfg->DmaSingleBurstTransactions;
	  		 		 DMA2->DMA_S4CR   = Add_pStrDmaCfg->DmaPeriMemPtrSize;
	  		 		 DMA2->DMA_S4CR   = Add_pStrDmaCfg->DmaCircularMode;
	  		 		 DMA2->DMA_S4CR   = Add_pStrDmaCfg->DmaInterruptsModes;
	  		 	break;
	  		 	 case stream_5:

	  		 		while (DMA2->DMA_S5CR & DMA_SxCR_EN);

	  		 		 DMA2->DMA_S5PAR 	= (u32)Add_pStrDmaCfg->PeripheralMemory2Address;

	  		 		 if (Add_pStrDmaCfg->DmaDoubleBufferMode)
	  		 		 {

	  		 			 DMA2->DMA_S5MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 			 DMA2->DMA_S5M1AR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 		 }
	  		 		 else
	  		 		 {
	  		 			 DMA2->DMA_S5MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 		 }

	  		 		 DMA2->DMA_S5NDTR = Add_pStrDmaCfg->DmaDataBlockItemsToTransfer;

	  		 		 DMA2->DMA_S5CR   = Add_pStrDmaCfg->DmaChannel;
	  		 		 DMA2->DMA_S5CR   = Add_pStrDmaCfg->DmaPeripheralControl;
	  		 		 DMA2->DMA_S5CR	  = Add_pStrDmaCfg->DmaStreamPriority;
	  		 		 DMA2->DMA_S5CR	  = Add_pStrDmaCfg->Data_Transfer_Dir;
	  		 		 DMA2->DMA_S5CR	  = Add_pStrDmaCfg->DmaPincMemMode;
	  		 		 DMA2->DMA_S5CR	  = Add_pStrDmaCfg->DmaMincMode;
	  		 		 DMA2->DMA_S5CR	  = Add_pStrDmaCfg->DmaSingleBurstTransactions;
	  		 		 DMA2->DMA_S5CR   = Add_pStrDmaCfg->DmaPeriMemPtrSize;
	  		 		 DMA2->DMA_S5CR   = Add_pStrDmaCfg->DmaCircularMode;
	  		 		 DMA2->DMA_S5CR   = Add_pStrDmaCfg->DmaInterruptsModes;
	  		 	break;
	  		 	 case stream_6:

	  		 		while (DMA2->DMA_S6CR & DMA_SxCR_EN);

	  		 		 DMA2->DMA_S6PAR 	= (u32)Add_pStrDmaCfg->PeripheralMemory2Address;

	  		 		 if (Add_pStrDmaCfg->DmaDoubleBufferMode)
	  		 		 {

	  		 			 DMA2->DMA_S6MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 			 DMA2->DMA_S6M1AR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 		 }
	  		 		 else
	  		 		 {
	  		 			 DMA2->DMA_S6MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 		 }

	  		 		 DMA2->DMA_S6NDTR = Add_pStrDmaCfg->DmaDataBlockItemsToTransfer;

	  		 		 DMA2->DMA_S6CR   = Add_pStrDmaCfg->DmaChannel;
	  		 		 DMA2->DMA_S6CR   = Add_pStrDmaCfg->DmaPeripheralControl;
	  		 		 DMA2->DMA_S6CR	  = Add_pStrDmaCfg->DmaStreamPriority;
	  		 		 DMA2->DMA_S6CR	  = Add_pStrDmaCfg->Data_Transfer_Dir;
	  		 		 DMA2->DMA_S6CR	  = Add_pStrDmaCfg->DmaPincMemMode;
	  		 		 DMA2->DMA_S6CR	  = Add_pStrDmaCfg->DmaMincMode;
	  		 		 DMA2->DMA_S6CR	  = Add_pStrDmaCfg->DmaSingleBurstTransactions;
	  		 		 DMA2->DMA_S6CR   = Add_pStrDmaCfg->DmaPeriMemPtrSize;
	  		 		 DMA2->DMA_S6CR   = Add_pStrDmaCfg->DmaCircularMode;
	  		 		 DMA2->DMA_S6CR   = Add_pStrDmaCfg->DmaInterruptsModes;
	  		 	break;
	  		 	 case stream_7:

	  		 		while (DMA2->DMA_S7CR & DMA_SxCR_EN);

	  		 		 DMA2->DMA_S7PAR 	= (u32)Add_pStrDmaCfg->PeripheralMemory2Address;

	  		 		 if (Add_pStrDmaCfg->DmaDoubleBufferMode)
	  		 		 {

	  		 			 DMA2->DMA_S6MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 			 DMA2->DMA_S6M1AR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 		 }
	  		 		 else
	  		 		 {
	  		 			 DMA2->DMA_S6MOAR	= (u32)Add_pStrDmaCfg->MemoryAddress;
	  		 		 }

	  		 		 DMA2->DMA_S6NDTR = Add_pStrDmaCfg->DmaDataBlockItemsToTransfer;

	  		 		 DMA2->DMA_S6CR   = Add_pStrDmaCfg->DmaChannel;
	  		 		 DMA2->DMA_S6CR   = Add_pStrDmaCfg->DmaPeripheralControl;
	  		 		 DMA2->DMA_S6CR	  = Add_pStrDmaCfg->DmaStreamPriority;
	  		 		 DMA2->DMA_S6CR	  = Add_pStrDmaCfg->Data_Transfer_Dir;
	  		 		 DMA2->DMA_S6CR	  = Add_pStrDmaCfg->DmaPincMemMode;
	  		 		 DMA2->DMA_S6CR	  = Add_pStrDmaCfg->DmaMincMode;
	  		 		 DMA2->DMA_S6CR	  = Add_pStrDmaCfg->DmaSingleBurstTransactions;
	  		 		 DMA2->DMA_S6CR   = Add_pStrDmaCfg->DmaPeriMemPtrSize;
	  		 		 DMA2->DMA_S6CR   = Add_pStrDmaCfg->DmaCircularMode;
	  		 		 DMA2->DMA_S6CR   = Add_pStrDmaCfg->DmaInterruptsModes;
	  		 	break;

	  		 	 default:
	  		 		 Loc_enuErrStatRetVal = INVALID_ARG;
	  		 }
		}
		else
		{
			Loc_enuErrStatRetVal = INVALID_ARG;
		}
	}

	return Loc_enuErrStatRetVal;
}


Std_enuErrorStatus DMA_vidStart (DMA_Id_t Copy_tenuDmaChannel ,streams_t   Copy_tenuStream)
{
	Std_enuErrorStatus Loc_enuErrStatRetVal = OK;

	if(Copy_tenuDmaChannel == DMA_1)
	{
		switch (Copy_tenuStream)
		{
			case stream_0:

				DMA1->DMA_SOCR |= DMA_SxCR_EN;

			break;
			case stream_1:

				DMA1->DMA_S1CR |= DMA_SxCR_EN;

			break;
			case stream_2:

				DMA1->DMA_S2CR |= DMA_SxCR_EN;

			break;
			case stream_3:

				DMA1->DMA_S3CR |= DMA_SxCR_EN;

			break;
			case stream_4:

				DMA1->DMA_S4CR |= DMA_SxCR_EN;

			break;
			case stream_5:

				DMA1->DMA_S5CR |= DMA_SxCR_EN;

			break;
			case stream_6:

				DMA1->DMA_S6CR |= DMA_SxCR_EN;

			break;
			case stream_7:

				DMA1->DMA_S7CR |= DMA_SxCR_EN;

			break;

			default:
				Loc_enuErrStatRetVal = INVALID_ARG;
			break;
		}

	}

	else if (Copy_tenuDmaChannel == DMA_2)
	{
		switch (Copy_tenuStream)
		{
			case stream_0:

				DMA2->DMA_SOCR |= DMA_SxCR_EN;

			break;
			case stream_1:

				DMA2->DMA_S1CR |= DMA_SxCR_EN;

			break;
			case stream_2:

				DMA2->DMA_S2CR |= DMA_SxCR_EN;

			break;
			case stream_3:

				DMA2->DMA_S3CR |= DMA_SxCR_EN;

			break;
			case stream_4:

				DMA2->DMA_S4CR |= DMA_SxCR_EN;

			break;
			case stream_5:

				DMA2->DMA_S5CR |= DMA_SxCR_EN;

			break;
			case stream_6:

				DMA2->DMA_S6CR |= DMA_SxCR_EN;

			break;
			case stream_7:

				DMA2->DMA_S7CR |= DMA_SxCR_EN;

			break;

			default:
				Loc_enuErrStatRetVal = INVALID_ARG;
			break;
		}
	}
	else
	{
		Loc_enuErrStatRetVal = INVALID_ARG;
	}
	return Loc_enuErrStatRetVal;
}


Std_enuErrorStatus  DMA_vidStop (DMA_Id_t Copy_tenuDmaChannel ,streams_t Copy_tenuStream)
{
	Std_enuErrorStatus Loc_enuErrStatRetVal = OK;

	if(Copy_tenuDmaChannel == DMA_1)
	{
		switch (Copy_tenuStream)
		{
			case stream_0:

				DMA1->DMA_SOCR &= ~(DMA_SxCR_EN);

			break;
			case stream_1:

				DMA1->DMA_S1CR &= ~(DMA_SxCR_EN);

			break;
			case stream_2:

				DMA1->DMA_S2CR &= ~(DMA_SxCR_EN);

			break;
			case stream_3:

				DMA1->DMA_S3CR &= ~(DMA_SxCR_EN);

			break;
			case stream_4:

				DMA1->DMA_S4CR &= ~(DMA_SxCR_EN);

			break;
			case stream_5:

				DMA1->DMA_S5CR &= ~(DMA_SxCR_EN);

			break;
			case stream_6:

				DMA1->DMA_S6CR &= ~(DMA_SxCR_EN);

			break;
			case stream_7:

				DMA1->DMA_S7CR &= ~(DMA_SxCR_EN);

			break;

			default:
				Loc_enuErrStatRetVal = INVALID_ARG;
			break;
		}

	}

	else if (Copy_tenuDmaChannel == DMA_2)
	{
		switch (Copy_tenuStream)
		{
			case stream_0:

				DMA2->DMA_SOCR &= ~(DMA_SxCR_EN);

			break;
			case stream_1:

				DMA2->DMA_S1CR &= ~(DMA_SxCR_EN);

			break;
			case stream_2:

				DMA2->DMA_S2CR &= ~(DMA_SxCR_EN);

			break;
			case stream_3:

				DMA2->DMA_S3CR &= ~(DMA_SxCR_EN);

			break;
			case stream_4:

				DMA2->DMA_S4CR &= ~(DMA_SxCR_EN);

			break;
			case stream_5:

				DMA2->DMA_S5CR &= ~(DMA_SxCR_EN);

			break;
			case stream_6:

				DMA2->DMA_S6CR &= ~(DMA_SxCR_EN);

			break;
			case stream_7:

				DMA2->DMA_S7CR &= ~(DMA_SxCR_EN);

			break;

			default:
				Loc_enuErrStatRetVal = INVALID_ARG;
			break;
		}
	}

	else
	{
		Loc_enuErrStatRetVal = INVALID_ARG;
	}
	return Loc_enuErrStatRetVal;
}

Std_enuErrorStatus 	DMA1_tenuRegisterCallBackTransferComplete ( streams_t Copy_tenuDmaStream , pfunc Add_UserTransferCompleteFunc)
{
	Std_enuErrorStatus Loc_enuErrStatusVal = OK;

	if (Copy_tenuDmaStream >stream_7)
	{
		Loc_enuErrStatusVal = INVALID_ARG;
	}
	else if (Add_UserTransferCompleteFunc == NULL)
	{
		Loc_enuErrStatusVal = NULL_PTR;
	}
	else
	{
		DMA1_pfGlbDmaTransferCompleteCbfHandler[Copy_tenuDmaStream] = Add_UserTransferCompleteFunc;
	}

	return Loc_enuErrStatusVal;
}

Std_enuErrorStatus 	DMA2_tenuRegisterCallBackTransferComplete ( streams_t Copy_tenuDmaStream , pfunc Add_UserTransferCompleteFunc)
{
	Std_enuErrorStatus Loc_enuErrStatusVal = OK;

	if (Copy_tenuDmaStream >stream_7)
	{
		Loc_enuErrStatusVal = INVALID_ARG;
	}
	else if (Add_UserTransferCompleteFunc == NULL)
	{
		Loc_enuErrStatusVal = NULL_PTR;
	}
	else
	{
		DMA2_pfGlbDmaTransferCompleteCbfHandler[Copy_tenuDmaStream] = Add_UserTransferCompleteFunc;
	}

	return Loc_enuErrStatusVal;
}

void DMA1_Stream0_IRQHandler(void)
{
	if (DMA1_pfGlbDmaTransferCompleteCbfHandler[stream_0])
	{
		DMA1_pfGlbDmaTransferCompleteCbfHandler[stream_0]();
	}
}
void DMA1_Stream1_IRQHandler(void)
{
	if (DMA1_pfGlbDmaTransferCompleteCbfHandler[stream_1])
	{
		DMA1_pfGlbDmaTransferCompleteCbfHandler[stream_1]();
	}
}
void DMA1_Stream2_IRQHandler(void)
{
	if (DMA1_pfGlbDmaTransferCompleteCbfHandler[stream_2])
	{
		DMA1_pfGlbDmaTransferCompleteCbfHandler[stream_2]();
	}
}
void DMA1_Stream3_IRQHandler(void)
{
	if (DMA1_pfGlbDmaTransferCompleteCbfHandler[stream_3])
	{
		DMA1_pfGlbDmaTransferCompleteCbfHandler[stream_3]();
	}
}
void DMA1_Stream4_IRQHandler(void)
{
	if (DMA1_pfGlbDmaTransferCompleteCbfHandler[stream_4])
	{
		DMA1_pfGlbDmaTransferCompleteCbfHandler[stream_4]();
	}
}
void DMA1_Stream5_IRQHandler(void)
{
	if (DMA1_pfGlbDmaTransferCompleteCbfHandler[stream_5])
	{
		DMA1_pfGlbDmaTransferCompleteCbfHandler[stream_5]();
	}
}
void DMA1_Stream6_IRQHandler(void)
{
	if (DMA1_pfGlbDmaTransferCompleteCbfHandler[stream_6])
	{
		DMA1_pfGlbDmaTransferCompleteCbfHandler[stream_6]();
	}
}
void DMA1_Stream7_IRQHandler(void)
{
	if (DMA1_pfGlbDmaTransferCompleteCbfHandler[stream_7])
	{
		DMA1_pfGlbDmaTransferCompleteCbfHandler[stream_7]();
	}
}


void DMA2_Stream0_IRQHandler(void)
{
	if (DMA2_pfGlbDmaTransferCompleteCbfHandler[stream_0])
	{
		DMA2_pfGlbDmaTransferCompleteCbfHandler[stream_0]();
	}
}
void DMA2_Stream1_IRQHandler(void)
{
	if (DMA2_pfGlbDmaTransferCompleteCbfHandler[stream_1])
	{
		DMA2_pfGlbDmaTransferCompleteCbfHandler[stream_1]();
	}
}
void DMA2_Stream2_IRQHandler(void)
{
	if (DMA2_pfGlbDmaTransferCompleteCbfHandler[stream_2])
	{
		DMA2_pfGlbDmaTransferCompleteCbfHandler[stream_2]();
	}
}
void DMA2_Stream3_IRQHandler(void)
{
	if (DMA2_pfGlbDmaTransferCompleteCbfHandler[stream_3])
	{
		DMA2_pfGlbDmaTransferCompleteCbfHandler[stream_3]();
	}
}
void DMA2_Stream4_IRQHandler(void)
{
	if (DMA2_pfGlbDmaTransferCompleteCbfHandler[stream_4])
	{
		DMA2_pfGlbDmaTransferCompleteCbfHandler[stream_4]();
	}
}
void DMA2_Stream5_IRQHandler(void)
{
	if (DMA2_pfGlbDmaTransferCompleteCbfHandler[stream_5])
	{
		DMA2_pfGlbDmaTransferCompleteCbfHandler[stream_5]();
	}
}
void DMA2_Stream6_IRQHandler(void)
{
	if (DMA2_pfGlbDmaTransferCompleteCbfHandler[stream_6])
	{
		DMA2_pfGlbDmaTransferCompleteCbfHandler[stream_6]();
	}
}
void DMA2_Stream7_IRQHandler(void)
{
	if (DMA2_pfGlbDmaTransferCompleteCbfHandler[stream_7])
	{
		DMA2_pfGlbDmaTransferCompleteCbfHandler[stream_7]();
	}
}
