/*
 * Nvic.c
 *
 *  Created on: May 15, 2022
 *      Author: dahroug
 */

#include 	"Std_types.h"
#include	"Bit_utils.h"

#include 	"Nvic.h"
#include 	"Nvic_prv.h"


/*		Enable IRQn	 Interrupt Request	*/
Std_enuErrorStatus NVIC_enuEnableIRQ(IRQn_t enu_tIRQn)
{
	/*
	 * NVIC_BASE->NVIC_ISERx[enu_tIRQn/32] |=  1<<(enu_tIRQn%32);
	 */
	u8 NumOfRegister = NVIC_ZERO;
	u8 NumOfBit = NVIC_ZERO;

	Std_enuErrorStatus Loc_enuErrorStatus = OK;

	if(enu_tIRQn > IRQN_NUM)
	{
		Loc_enuErrorStatus = INVALID_ARG ;
	}
	else
	{
		NumOfRegister   = enu_tIRQn / REG_SIZE;
		NumOfBit 		= enu_tIRQn % REG_SIZE;

		NVIC_BASE->NVIC_ISERx[NumOfRegister] |= (u32) ((u32)NVIC_ONE<< NumOfBit);
	}
	return Loc_enuErrorStatus;
}

/*		Disable IRQn	            	*/
Std_enuErrorStatus NVIC_enuDisableIRQ(IRQn_t enu_tIRQn)
{

	/*
	 * NVIC_BASE->NVIC_ICERx[enu_tIRQn/32] |=  1<<(enu_tIRQn%32);
	 */

	u8 NumOfRegister;
	u8 NumOfBit;

	Std_enuErrorStatus Loc_enuErrorStatus = OK;

	if(enu_tIRQn > IRQN_NUM)
	{
		Loc_enuErrorStatus = INVALID_ARG ;
	}
	else
	{
		NumOfRegister   = enu_tIRQn / REG_SIZE;
		NumOfBit 		= enu_tIRQn % REG_SIZE;

		NVIC_BASE->NVIC_ICERx[NumOfRegister] |= (u32) ((u32)NVIC_ONE << NumOfBit);
	}
	return Loc_enuErrorStatus;
}

/*		Set IRQn pending	        	*/
Std_enuErrorStatus NVIC_enuSetPendingIRQ (IRQn_t enu_tIRQn)
{
	/*
	 * NVIC_BASE->NVIC_ISPRx[enu_tIRQn/32] |=  1<<(enu_tIRQn%32);
	 */

	u8 NumOfRegister;
	u8 NumOfBit;

	Std_enuErrorStatus Loc_enuErrorStatus = OK;

	if(enu_tIRQn > IRQN_NUM)
	{
		Loc_enuErrorStatus = INVALID_ARG ;
	}
	else
	{
		NumOfRegister   = enu_tIRQn / REG_SIZE;
		NumOfBit 		= enu_tIRQn % REG_SIZE;

		NVIC_BASE->NVIC_ISPRx[NumOfRegister] |= (u32) ((u32)NVIC_ONE << NumOfBit);
	}
	return Loc_enuErrorStatus;
}

/*		Clear IRQn pending status		*/
Std_enuErrorStatus NVIC_enuClearPendingIRQ(IRQn_t enu_tIRQn)
{
	/*
	 * NVIC_BASE->NVIC_ICPRx[enu_tIRQn/32] |=  1<<(enu_tIRQn%32);
	 */

	u8 NumOfRegister;
	u8 NumOfBit;

	Std_enuErrorStatus Loc_enuErrorStatus = OK;

	if(enu_tIRQn > IRQN_NUM)
	{
		Loc_enuErrorStatus = INVALID_ARG ;
	}
	else
	{
		NumOfRegister   = enu_tIRQn / REG_SIZE;
		NumOfBit 		= enu_tIRQn % REG_SIZE;

		NVIC_BASE->NVIC_ICPRx[NumOfRegister] |= (u32) ((u32)NVIC_ONE << NumOfBit);
	}
	return Loc_enuErrorStatus;
}

/*		Return the IRQ number of the active interrupt		*/
Std_enuErrorStatus NVIC_enuGetActive(IRQn_t enu_tIRQn,pu8 Add_pu8ActiveStatus)
{
	/*
	 * pointer= (NVIC_BASE->NVIC_IABRx[enu_tIRQn/32]>>(enu_tIRQn%32)) & 0x01;
	 */

	u8 NumOfRegister;
	u8 NumOfBit;

	Std_enuErrorStatus Loc_enuErrorStatus = OK;

	if(enu_tIRQn > IRQN_NUM)
	{
		Loc_enuErrorStatus = INVALID_ARG ;
	}
	else if(Add_pu8ActiveStatus == NULL)
	{
		Loc_enuErrorStatus =NULL_PTR ;
	}
	else
	{
		NumOfRegister   = enu_tIRQn / REG_SIZE;
		NumOfBit 		= enu_tIRQn % REG_SIZE;

		*Add_pu8ActiveStatus = (u8)((NVIC_BASE->NVIC_IABRx[NumOfRegister] >> NumOfBit) & NVIC_ONE);
	}
	return Loc_enuErrorStatus;
}

Std_enuErrorStatus NVIC_enuConfigPriority (PriorityCfg_t Copy_tenuIPRCfg)
{
	Std_enuErrorStatus Loc_enuReturnErrStatusValue = OK;

  if (Copy_tenuIPRCfg > NVIC_MAX_PRI_CFGS)
  {
	  Loc_enuReturnErrStatusValue = INVALID_ARG;
  }
  else if (Copy_tenuIPRCfg < GRP8_SUB2)
  {
	  Copy_tenuIPRCfg = GRP16_SUB0;
  }
  else
  {
	  AIRCR = (AIRCR_KEY|Copy_tenuIPRCfg);
  }
  return Loc_enuReturnErrStatusValue;
}

/*		 Set priority for IRQn	    	*/
Std_enuErrorStatus NVIC_enuSetPriority (IRQn_t enu_tIRQn, PriorityCfg_t Copy_tenuIPRCfg, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority)
{
	/*
	 * NVIC_BASE->NVIC_ICPRx[enu_tIRQn/32] |=  priority;
	 * 										   3  2  1  0
	 * 										0x ff ff ff xx
	 * 										0x ff ff xx ff
	 * 										0x ff xx ff ff
	 * 										0x xx ff ff ff
	 */

	Std_enuErrorStatus Loc_enuErrorStatus = OK;

	u8 Loc_u8GroupPriMaxNum =    NVIC_ZERO;
	u8 Loc_u8SubPriMaxNum   =    NVIC_ZERO;
	u8 Loc_u8GrpShift       =    NVIC_ZERO;
	u8 Loc_u8GrpSubEmbeddedPri = NVIC_ZERO;

	u8 NumOfRegister_IPR = NVIC_ZERO;
	u8 NumOfBit_IPOffset = NVIC_ZERO;

	if(enu_tIRQn > IRQN_NUM || Copy_tenuIPRCfg > NVIC_MAX_PRI_CFGS || Copy_u8GroupPriority > NVIC_IPR_GRP15 || Copy_u8SubPriority > NVIC_IPR_SUP15)
	{
		Loc_enuErrorStatus = INVALID_ARG ;
	}

	else
	{

		switch (Copy_tenuIPRCfg)
		{
			case GRP16_SUB0:
				Loc_u8GroupPriMaxNum =  NVIC_IPR_GRP15;
				Loc_u8SubPriMaxNum   =  NVIC_IPR_SUP0;

				Loc_u8GrpShift       = NVIC_ZERO;
			break;

			case GRP8_SUB2:
				Loc_u8GroupPriMaxNum =  NVIC_IPR_GRP7;
				Loc_u8SubPriMaxNum   =  NVIC_IPR_SUP1;

				Loc_u8GrpShift       = NVIC_ONE;
			break;

			case GRP4_SUB4:
				Loc_u8GroupPriMaxNum =  NVIC_IPR_GRP3;
				Loc_u8SubPriMaxNum   =  NVIC_IPR_SUP3;

				Loc_u8GrpShift       = NVIC_TWO;
			break;

			case GRP2_SUB8:
				Loc_u8GroupPriMaxNum =  NVIC_IPR_GRP1;
				Loc_u8SubPriMaxNum   =  NVIC_IPR_SUP7;

				Loc_u8GrpShift       = NVIC_THREE;
			break;

			case GRP0_SUB16:
				Loc_u8GroupPriMaxNum =  NVIC_IPR_GRP0;
				Loc_u8SubPriMaxNum   =  NVIC_IPR_SUP15;

				Loc_u8GrpShift       = NVIC_FOUR;
			break;

		}

		if (Copy_u8GroupPriority > Loc_u8GroupPriMaxNum  || Copy_u8SubPriority > Loc_u8SubPriMaxNum)
		{
			Loc_enuErrorStatus = INVALID_ARG ;
		}
		else
		{
			Loc_u8GrpSubEmbeddedPri =  ( ( (Copy_u8GroupPriority << Loc_u8GrpShift) | Copy_u8SubPriority) << NVIC_FOUR);

			NumOfRegister_IPR       = enu_tIRQn / NVIC_FOUR;
			NumOfBit_IPOffset 		= enu_tIRQn % NVIC_FOUR;

			NVIC_BASE->NVIC_IPRx[NumOfRegister_IPR] |= (Loc_u8GrpSubEmbeddedPri << (NumOfBit_IPOffset * NVIC_BYTE_BITS) );
		}

	}

	return Loc_enuErrorStatus;
}
