/*
 * Dma.h
 *
 *  Created on: May 12, 2022
 *      Author: dahroug
 */

#ifndef        DMA_H_
#define        DMA_H_

/*
 *                             Source and destination address
 * ----------------------------------------------------------------------------------
 * |Bits DIR[1:0] of the |Direction			   |Source address | Destination address|
   |DMA_SxCR register    |		   			   |               |					|
 * ----------------------------------------------------------------------------------
 * | 00					 |Peripheral-to-memory |DMA_SxPAR	   |DMA_SxM0AR          |
 * | 01					 |Memory-to-peripheral |DMA_SxM0AR     |DMA_SxPAR           |
 * | 10					 |Memory-to-memory     |DMA_SxPAR      |DMA_SxM0AR          |
 * | 11					 |reserved             |               |                    |
 * ----------------------------------------------------------------------------------
 */

typedef enum
{
	stream_0,
	stream_1,
	stream_2,
	stream_3,
	stream_4,
	stream_5,
	stream_6,
	stream_7
}streams_t;

typedef enum
{
	DMA_1,
	DMA_2
}DMA_Id_t;

typedef enum{

	Dma_DISABLE,
	Dma_ENABLE
}State_t;



typedef struct
{
	DMA_Id_t    DMA;																												//used
	void*   	MemoryAddress;
	void*   	PeripheralMemory2Address;
	streams_t   Stream;							// used
	u32		    Data_Transfer_Dir; 				//macro
	u32		    DmaStreamPriority;		   		//macro
	u32 		DmaChannel;        				//Macro
	u32			DmaDoubleBufferMode;
	u32			DmaDataBlockItemsToTransfer;
	u32 		DmaPeripheralControl;            // when you dont know how much data will be transferred and it will depend on hardware
	u32 		DmaPincMemMode;
	u32 		DmaMincMode;
	u32 		DmaSingleBurstTransactions;
	u32 		DmaPeriMemPtrSize;
	u32 		DmaCircularMode;
	u32 		DmaInterruptsModes;
}DMA_strCfg;


/* --------------------------DMA_LISR register macro section (* READ ONLY *) ------------------------------ */
#define 	DMA_LISR_TCIF0			            ((u32)0x00000020)
#define 	DMA_LISR_TCIF1			            ((u32)0x00000800)
#define 	DMA_LISR_TCIF2			            ((u32)0x00200000)
#define 	DMA_LISR_TCIF3			            ((u32)0x08000000)

#define 	DMA_LISR_HTIF0			            ((u32)0x00000010)
#define 	DMA_LISR_HTIF1			            ((u32)0x00000400)
#define 	DMA_LISR_HTIF2			            ((u32)0x00100000)
#define 	DMA_LISR_HTIF3			            ((u32)0x04000000)

#define 	DMA_LISR_TEIF0			            ((u32)0x00000008)
#define 	DMA_LISR_TEIF1			            ((u32)0x00000200)
#define 	DMA_LISR_TEIF2			            ((u32)0x00080000)
#define 	DMA_LISR_TEIF3			            ((u32)0x02000000)

#define 	DMA_LISR_DMEIF0			            ((u32)0x00000004)
#define 	DMA_LISR_DMEIF1			            ((u32)0x00000100)
#define 	DMA_LISR_DMEIF2			            ((u32)0x00040000)
#define 	DMA_LISR_DMEIF3			            ((u32)0x01000000)

#define 	DMA_LISR_FEIF0			            ((u32)0x00000001)
#define 	DMA_LISR_FEIF1			            ((u32)0x00000040)
#define 	DMA_LISR_FEIF2			            ((u32)0x00010000)
#define 	DMA_LISR_FEIF3			            ((u32)0x00400000)


/* --------------------------DMA_HISR register macro section (* READ ONLY *)------------------------------ */
#define 	DMA_HISR_TCIF4			            ((u32)0x00000020)
#define 	DMA_HISR_TCIF5			            ((u32)0x00000800)
#define 	DMA_HISR_TCIF6			            ((u32)0x00200000)
#define 	DMA_HISR_TCIF7			            ((u32)0x08000000)

#define 	DMA_HISR_HTIF4			            ((u32)0x00000010)
#define 	DMA_HISR_HTIF5			            ((u32)0x00000400)
#define 	DMA_HISR_HTIF6			            ((u32)0x00100000)
#define 	DMA_HISR_HTIF7			            ((u32)0x04000000)

#define 	DMA_HISR_TEIF4			            ((u32)0x00000008)
#define 	DMA_HISR_TEIF5			            ((u32)0x00000200)
#define 	DMA_HISR_TEIF6			            ((u32)0x00080000)
#define 	DMA_HISR_TEIF7			            ((u32)0x02000000)

#define 	DMA_HISR_DMEIF4			            ((u32)0x00000004)
#define 	DMA_HISR_DMEIF5			            ((u32)0x00000100)
#define 	DMA_HISR_DMEIF6			            ((u32)0x00040000)
#define 	DMA_HISR_DMEIF7			            ((u32)0x01000000)

#define 	DMA_HISR_FEIF4			            ((u32)0x00000001)
#define 	DMA_HISR_FEIF5			            ((u32)0x00000040)
#define 	DMA_HISR_FEIF6			            ((u32)0x00010000)
#define 	DMA_HISR_FEIF7			            ((u32)0x00400000)


/* DMA_LIFCR register macro section */
#define 	DMA_LIFCR_CTCIF0	                ((u32)0x00000020)
#define 	DMA_LIFCR_CTCIF1	                ((u32)0x00000800)
#define 	DMA_LIFCR_CTCIF2	                ((u32)0x00200000)
#define 	DMA_LIFCR_CTCIF3	                ((u32)0x08000000)

#define 	DMA_LIFCR_CHTIF0	                ((u32)0x00000010)
#define 	DMA_LIFCR_CHTIF1	                ((u32)0x00000400)
#define 	DMA_LIFCR_CHTIF2	                ((u32)0x00100000)
#define 	DMA_LIFCR_CHTIF3	                ((u32)0x04000000)

#define 	DMA_LIFCR_CTEIF0	                ((u32)0x00000008)
#define 	DMA_LIFCR_CTEIF1	                ((u32)0x00000200)
#define 	DMA_LIFCR_CTEIF2	                ((u32)0x00080000)
#define 	DMA_LIFCR_CTEIF3	                ((u32)0x02000000)

#define 	DMA_LIFCR_CDMEIF0	                ((u32)0x00000004)
#define 	DMA_LIFCR_CDMEIF1	                ((u32)0x00000100)
#define 	DMA_LIFCR_CDMEIF2	                ((u32)0x00040000)
#define 	DMA_LIFCR_CDMEIF3	                ((u32)0x01000000)

#define 	DMA_LIFCR_CFEIF0		            ((u32)0x00000001)
#define 	DMA_LIFCR_CFEIF1		            ((u32)0x00000040)
#define 	DMA_LIFCR_CFEIF2		            ((u32)0x00010000)
#define 	DMA_LIFCR_CFEIF3		            ((u32)0x00400000)


/* DMA_HIFCR register macro section */
#define 	DMA_HIFCR_CTCIF4			        ((u32)0x00000020)
#define 	DMA_HIFCR_CTCIF5			        ((u32)0x00000800)
#define 	DMA_HIFCR_CTCIF6			        ((u32)0x00200000)
#define 	DMA_HIFCR_CTCIF7			        ((u32)0x08000000)

#define 	DMA_HIFCR_CHTIF4			        ((u32)0x00000010)
#define 	DMA_HIFCR_CHTIF5			        ((u32)0x00000400)
#define 	DMA_HIFCR_CHTIF6			        ((u32)0x00100000)
#define 	DMA_HIFCR_CHTIF7			        ((u32)0x04000000)

#define 	DMA_HIFCR_CTEIF4			        ((u32)0x00000008)
#define 	DMA_HIFCR_CTEIF5			        ((u32)0x00000200)
#define 	DMA_HIFCR_CTEIF6			        ((u32)0x00080000)
#define 	DMA_HIFCR_CTEIF7			        ((u32)0x02000000)

#define 	DMA_HIFCR_CDMEIF4	                ((u32)0x00000004)
#define 	DMA_HIFCR_CDMEIF5	                ((u32)0x00000100)
#define 	DMA_HIFCR_CDMEIF6	                ((u32)0x00040000)
#define 	DMA_HIFCR_CDMEIF7	                ((u32)0x01000000)

#define 	DMA_HIFCR_CFEIF4			        ((u32)0x00000001)
#define 	DMA_HIFCR_CFEIF5			        ((u32)0x00000040)
#define 	DMA_HIFCR_CFEIF6			        ((u32)0x00010000)
#define 	DMA_HIFCR_CFEIF7			        ((u32)0x00400000)

/******************************************************DMA_SxCR********************************************/
/*      DMA_SxCR       Channel*/
#define     DMA_SxCR_CHANNEL_0                  ((u32)0x00000000)
#define     DMA_SxCR_CHANNEL_1                  ((u32)0x02000000)
#define     DMA_SxCR_CHANNEL_2                  ((u32)0x04000000)
#define     DMA_SxCR_CHANNEL_3                  ((u32)0x06000000)                                         //configuration parameter
#define     DMA_SxCR_CHANNEL_4                  ((u32)0x08000000)
#define     DMA_SxCR_CHANNEL_5                  ((u32)0x0A000000)
#define     DMA_SxCR_CHANNEL_6                  ((u32)0x0C000000)
#define     DMA_SxCR_CHANNEL_7                  ((u32)0x0E000000)

/*      DMA_SxCR       Memory Burst Transfer*/
#define 	DMA_SxCR_MBURST_SINGLE	            ((u32)0x00000000)
#define 	DMA_SxCR_MBURST_INCR4	            ((u32)0x00800000)
#define 	DMA_SxCR_MBURST_INCR8	            ((u32)0x01000000)										 //configuration parameter
#define 	DMA_SxCR_MBURST_INCR16	            ((u32)0x01800000)

/*      DMA_SxCR       Peripheral Burst Transfer*/
#define 	DMA_SxCR_PBURST_SINGLE	            ((u32)0x00000000)  										//configuration parameter
#define 	DMA_SxCR_PBURST_INCR4	            ((u32)0x00200000)
#define 	DMA_SxCR_PBURST_INCR8	            ((u32)0x00400000)
#define 	DMA_SxCR_PBURST_INCR16	            ((u32)0x00600000)

/*      DMA_SxCR       Currrent Target ,, only available at double buffer mode*/
#define 	DMA_SxCR_CT_MEM1			        ((u32)0x00080000) //by DMA_SxM1AR pointer

/*      DMA_SxCR       double buffer mode*/
#define 	DMA_SxCR_CDBM_ON			        ((u32)0x00040000) //by DMA_SxM1AR pointer

/*      DMA_SxCR       Priority*/
#define     DMA_SxCR_PL_LOW                     ((u32)0x00000000)
#define     DMA_SxCR_PL_MEDIUM                  ((u32)0x00010000)
#define     DMA_SxCR_PL_HIGH                    ((u32)0x00020000)									 //configuration parameter
#define     DMA_SxCR_PL_V_HIGH                  ((u32)0x00030000)

/*      DMA_SxCR      Peripheral incrment offset size , it has no meaning if PINC bit is 0*/
#define 	DMA_SxCR_PINCOS_32_BIT_ALIGN		((u32)0x00008000)

/*      DMA_SxCR       Memory Data Size */
#define     DMA_SxCR_MSIZE_BYTE                 ((u32)0x00000000)									 //configuration parameter
#define     DMA_SxCR_MSIZE_HALF_WORD            ((u32)0x00002000)
#define     DMA_SxCR_MSIZE_WORD                 ((u32)0x00004000)

/*      DMA_SxCR       Peripheral Data Size */
#define     DMA_SxCR_PSIZE_BYTE                 ((u32)0x00000000)
#define     DMA_SxCR_PSIZE_HALF_WORD            ((u32)0x00000800)								     //configuration parameter
#define     DMA_SxCR_PSIZE_WORD                 ((u32)0x00001000)

/*      DMA_SxCR       Memory Increment Mode */
#define 	DMA_SxCR_MINC					    ((u32)0x00000400)									 //configuration parameter

/*      DMA_SxCR       Peripheral Increment Mode */
#define 	DMA_SxCR_PINC					    ((u32)0x00000200)									 //configuration parameter

/*      DMA_SxCR       Peripheral-Memory Memory Increment Mode */
#define 	DMA_SxCR_PM_M_INC					((u32)0x00000600)									 //configuration parameter

/*      DMA_SxCR       Circular Mode */
#define 	DMA_SxCR_CIRC_EN					((u32)0x00000100)								     //configuration parameter

/*      DMA_SxCR       Memory Data Size */
#define     DMA_SxCR_DIR_P_M                    ((u32)0x00000000)
#define     DMA_SxCR_DIR_M_P                    ((u32)0x00000040)									 //configuration parameter
#define     DMA_SxCR_DIR_M_M                    ((u32)0x00000080)

/*      DMA_SxCR      Peripheral flow Controller */
#define 	DMA_SxCR_PFCTRL_ON					((u32)0x00000020)

/*      DMA_SxCR      Transfer complete interrupt enable */
#define 	DMA_SxCR_TCIE_EN					((u32)0x00000010)

/*      DMA_SxCR     Half transfer interrupt enable */
#define 	DMA_SxCR_HTIE_EN					((u32)0x00000008)

/*      DMA_SxCR    Transfer error  interrupt enable */
#define 	DMA_SxCR_TEIE_EN					((u32)0x00000004)

/*      DMA_SxCR     Direct Mode error interrupt enable */
#define 	DMA_SxCR_DMEIE_EN					((u32)0x00000002)

/*      DMA_SxCR       interrupt enable */
#define     DMA_SxCR_EN                 	    ((u32)0x00000001)




/**************************************************DMA_SxNDTR*******************************************************/

#define    DMA_SxNDTR_NDT                       ((u32)0x0000FFFF)							 //configuration parameter

/**************************************************DMA_SxFCR*********************************************************/

#define    DMA_SxFCR_FEIE                       ((u32)0x00008000)

#define    DMA_SxFCR_FS_O_Q                     ((u32)0x00000000)
#define    DMA_SxFCR_FS_Q_H                     ((u32)0x00000008)
#define    DMA_SxFCR_FS_H_TQ                    ((u32)0x00000010)
#define    DMA_SxFCR_FS_TQ_F                    ((u32)0x00000018)
#define    DMA_SxFCR_FS_EMPTY                   ((u32)0x00000020)
#define    DMA_SxFCR_FS_FULL                    ((u32)0x00000028)

#define    DMA_SxFCR_DM_DIS				        ((u32)0x00000004)

#define    DMA_SxFCR_FTH_Q				        ((u32)0x00000000)
#define    DMA_SxFCR_FTH_H				        ((u32)0x00000001)
#define    DMA_SxFCR_FTH_TQ				        ((u32)0x00000002)
#define    DMA_SxFCR_FTH_FULL			        ((u32)0x00000003)

/**************************************************DMA_function prototypes************************************************/
Std_enuErrorStatus  DMA_tenuInit(DMA_strCfg* Add_StrDmaCfg);
Std_enuErrorStatus 	DMA_vidStart (DMA_Id_t Copy_tenuDmaChannel ,streams_t   Copy_tenuStream);
Std_enuErrorStatus  DMA_vidStop (DMA_Id_t Copy_tenuDmaChannel ,streams_t Copy_tenuStream);

Std_enuErrorStatus 	DMA1_tenuRegisterCallBackTransferComplete ( streams_t Copy_tenuDmaStream , pfunc Add_UserTransferCompleteFunc);
Std_enuErrorStatus 	DMA2_tenuRegisterCallBackTransferComplete ( streams_t Copy_tenuDmaStream , pfunc Add_UserTransferCompleteFunc);


#endif		   /* DMA_H_ */
