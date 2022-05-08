/* Services */
#include "Std_types.h"
#include "Bit_utils.h"


/* driver headers*/
#include "Rcc.h"


/* REGISTER ADRESSIES MACROS to access hardware*/
#define 	RCC_CR 				                        *((volatile u32*)0x40023800)

#define 	RCC_PLLCFGR 		                        *((volatile u32*)0x40023804)

#define 	RCC_CFGR 			                        *((volatile u32*)0x40023808)
#define 	RCC_CIR				                        *((volatile u32*)0x4002380C)

#define 	RCC_AHB1RSTR 		                        *((volatile u32*)0x40023810)
#define 	RCC_AHB2RSTR		                        *((volatile u32*)0x40023814)

#define 	RCC_APB1RSTR 		                        *((volatile u32*)0x40023820)
#define 	RCC_APB2RSTR 		                        *((volatile u32*)0x40023824)

#define 	RCC_AHB1ENR 		                        *((volatile u32*)0x40023830)
#define 	RCC_AHB2ENR 		                        *((volatile u32*)0x40023834)

#define 	RCC_APB1ENR       	                        *((volatile u32*)0x40023840)
#define 	RCC_APB2ENR       	                        *((volatile u32*)0x40023844)

#define 	RCC_AHB1LPENR     	                        *((volatile u32*)0x40023850)
#define 	RCC_AHB2LPENR     	                        *((volatile u32*)0x40023854)
#define 	RCC_APB1LPENR     	                        *((volatile u32*)0x40023860)
#define 	RCC_APB2LPENR     	                        *((volatile u32*)0x40023864)
#define 	RCC_BDCR		  	                        *((volatile u32*)0x40023870)
#define 	RCC_CSR			  	                        *((volatile u32*)0x40023874)
#define 	RCC_SSCGR		  	                        *((volatile u32*)0x40023880)
#define 	RCC_PLLI2SCFGR	  	                        *((volatile u32*)0x40023884)
#define 	RCC_DCKCFGR       	                        *((volatile u32*)0x4002388c)


/*Register Reset Values*/                                                             //These values will be already in their corresponding registers once there was a reset happened or the controller had power switched ON
#define 	RCC_CR_RST_VAL		                        ((u32)0x00000081)
#define 	RCC_PLLCFGR_RST_VAL	                        ((u32)0x24003010)
#define 	RCC_CFGR_RST_VAL	    		            ((u32)0x00000000)
#define 	RCC_CIR_RST_VAL 	    		            ((u32)0x00000000)
#define 	RCC_AHB1RSTR_RST_VAL			            ((u32)0x00000000)
#define 	RCC_AHB2RSTR_RST_VAL			            ((u32)0x00000000)
#define 	RCC_APB1RSTR_RST_VAL	    	            ((u32)0x00000000)
#define 	RCC_APB2RSTR_RST_VAL			            ((u32)0x00000000)
#define 	RCC_AHB1ENR_RST_VAL	    		            ((u32)0x00000000)
#define 	RCC_AHB2ENR_RST_VAL	    		            ((u32)0x00000000)
#define 	RCC_APB1ENR_RST_VAL	    		            ((u32)0x00000000)
#define 	RCC_APB2ENR_RST_VAL	    		            ((u32)0x00000000)
#define 	RCC_AHB1LPENR_RST_VAL	    	            ((u32)0x0061900F)
#define 	RCC_AHB2LPENR_RST_VAL	    	            ((u32)0x00000080)
#define 	RCC_APB1LPENR_RST_VAL			            ((u32)0x10E2C80F)
#define 	RCC_APB2LPENR_RST_VAL   	                ((u32)0x00077930)
#define 	RCC_SSCGR_RST_VAL			                ((u32)0x00000000)
#define 	RCC_DCKCFGR_RST_VAL			                ((u32)0x00000000)


/* General Owner used MASKS & MACROS in programming*/
#define 	RCC_CLR_VAL			                        0
#define 	RCC_SYS_CLKS_NUM 	                        ((u8)3)
#define 	RCC_CLKS			                        ((u8)6)
#define 	RCC_SYSCLK_WAIT		                        ((u8)50)
#define 	RCC_STATES			                        ((u8)2)
#define     RCC_SW_RST_MSK		                        ((u32)0xFFFFFFFC)
#define 	RCC_SW_GET_CLK_MSK                          ((u32)0x00000003)

#define 	RCC_PERIPHERAL_VALIDATE		                ((u32)0x90E7F9BF)
#define 	RCC_ENABLE_BUSES_REGS		                ((u8)10)


/* PLLCFGR register private needed masks */
#define 	RCC_PLLCFGR_PLLSRC		 	                ((u8)22)

#define 	RCC_PLLCFGR_PLLP_FACTORS_NUM		        ((u8)4)
#define 	RCC_PLLCFGR_PLLSRC_OPTIONS			        ((u8)2)

#define 	RCC_PLLCFGR_RST_MSK					        ((u32)0x00400000)

#define 	RCC_PLLCFGR_PLLM_MIN		                ((u8)2)
#define 	RCC_PLLCFGR_PLLM_MAX		                ((u8)63)

#define 	RCC_PLLCFGR_PLLN_MIN		                ((u16)192)
#define 	RCC_PLLCFGR_PLLN_MAX		                ((u16)432)

#define 	RCC_PLLCFGR_PLLQ_MIN		                ((u8)2)
#define 	RCC_PLLCFGR_PLLQ_MAX		                ((u8)15)

/*PLL shifting Masks*/
#define 	RCC_PLLCFGR_SHFT_MSK_PLLN	                ((u8)6)
#define 	RCC_PLLCFGR_SHFT_MSK_PLLP	                ((u8)16)
#define 	RCC_PLLCFGR_SHFT_MSK_PLLQ	                ((u8)24)


/*___________________________ RCC_CFGR register private needed masks___________________________ */
#define 	RCC_CFGR_AHB_NUM_OF_VALID_PRESCALERS		((u8)16)
#define 	RCC_CFGR_APB1_NUM_OF_VALID_PRESCALERS		((u8)8)
#define 	RCC_CFGR_APB2_NUM_OF_VALID_PRESCALERS		((u8)8)
#define 	RCC_CFGR_MCO1_NUM_OF_VALID_PRESCALERS		((u8)4)
#define 	RCC_CFGR_MCO2_NUM_OF_VALID_PRESCALERS		((u8)4)
#define 	RCC_CFGR_RTC_NUM_OF_VALID_PRESCALERS		((u8)32)

#define 	RCC_CFGR_RST_RTCPRE_MSK			            ((u32)0xFFE0FFFF)
#define 	RCC_CFGR_RST_BUS_PIN_PRE_MSK	            ((u32)0xC0FF030F)

#define 	RCC_CFGR_SHFT_MSK_HPRE			            ((u8)4)
#define 	RCC_CFGR_SHFT_MSK_PPRE1	    	            ((u8)10)
#define 	RCC_CFGR_SHFT_MSK_PPRE2	    	            ((u8)13)
#define 	RCC_CFGR_SHFT_MSK_RTC			            ((u8)16)
#define 	RCC_CFGR_SHFT_MSK_MCO1PRE		            ((u8)24)
#define 	RCC_CFGR_SHFT_MSK_MCO2PRE		            ((u8)27)

/*___________________________________________________________________________________________________________________________*/


RccEnuSysClkStat_t	 Rcc_tenuSelectSysClk    (u8 Copy_u8SysClkType)
{
	RccEnuSysClkStat_t Loc_tenuErrStatRetVal = RCC_enuOk;

	u32 Loc_u32TempCFGR = RCC_CLR_VAL;

	u32 Loc_u32TempSWS = RCC_CLR_VAL;

	u8 Loc_u8TimeOut = RCC_SYSCLK_WAIT;

	if (Copy_u8SysClkType >= RCC_SYS_CLKS_NUM)
	{
		Loc_tenuErrStatRetVal = RCC_enuErrorSelectedSysClk;
	}
	else
	{
		Loc_u32TempCFGR  =  RCC_CFGR;
		Loc_u32TempCFGR &=  RCC_SW_RST_MSK;

		switch (Copy_u8SysClkType)
		{
			case RCC_HSI:

				if (RCC_CR & RCC_CR_HSI_RDY)
				{
					Loc_u32TempCFGR |= RCC_CFGR_SW_HSI;
					RCC_CFGR         = Loc_u32TempCFGR;
					Loc_u32TempSWS   = RCC_CFGR_SWS_HSI;
				}
				else
				{
					Loc_tenuErrStatRetVal = RCC_enuErrorClkNotRdy;    //or even the clock can be not even switched ON
				}
			break;


			case RCC_HSE:

				if (RCC_CR & RCC_CR_HSE_RDY)
				{
					RCC_CR          |= RCC_CR_CSS_ON;
					Loc_u32TempCFGR |= RCC_CFGR_SW_HSE;
					RCC_CFGR         = Loc_u32TempCFGR;
					Loc_u32TempSWS   = RCC_CFGR_SWS_HSE;
				}
				else
				{
					Loc_tenuErrStatRetVal = RCC_enuErrorClkNotRdy;    //or even the clock can be not even switched ON
				}
			break;

			case RCC_PLL:

				if (RCC_CR & RCC_CR_PLL_RDY)
				{
					Loc_u32TempCFGR |= RCC_CFGR_SW_PLL;
					RCC_CFGR         = Loc_u32TempCFGR;;
					Loc_u32TempSWS   = RCC_CFGR_SWS_PLL;
				}
				else
				{
					Loc_tenuErrStatRetVal = RCC_enuErrorClkNotRdy;    //or even the clock can be not even switched ON
				}
			break;

			default:
			break;
		}

		if (Loc_tenuErrStatRetVal == RCC_enuOk)
		{
			while (Loc_u8TimeOut -- && ((RCC_CFGR & Loc_u32TempSWS) != Loc_u32TempSWS));

			if ( (RCC_CFGR & Loc_u32TempSWS) == Loc_u32TempSWS)
			{
				Loc_tenuErrStatRetVal = RCC_enuOk;
			}
			else
			{
				Loc_tenuErrStatRetVal = RCC_enuErrorTimedOut;
			}
		}
		else
		{

		}
	}

	return Loc_tenuErrStatRetVal;
}

/*___________________________________________________________________________________________________________________________*/

RccEnuSysClkStat_t	  		Rcc_tenuClkControl  			(u8 Copy_u8Clk, u8 Copy_u8State)
{
	RccEnuSysClkStat_t Loc_tenuErrStatusRetVal = RCC_enuOk;

	u8 Loc_u8TimeOut = RCC_SYSCLK_WAIT;

	if (Copy_u8Clk >= RCC_CLKS)
	{
		Loc_tenuErrStatusRetVal = RCC_enuErrorClock;
	}
	else if (Copy_u8State >= RCC_STATES)
	{
		Loc_tenuErrStatusRetVal = RCC_enuErrorContrlStatus;
	}
	else if (Copy_u8Clk == (u8)(RCC_CFGR & RCC_SW_GET_CLK_MSK) )
	{
		Loc_tenuErrStatusRetVal = RCC_enuErrorSelectedSysClk;
	}
	else if (Copy_u8Clk == (u8)GET_BIT(RCC_PLLCFGR,RCC_PLLCFGR_PLLSRC))
	{
		Loc_tenuErrStatusRetVal = RCC_enuErrorSelectedPllClk;
	}
	else
	{
		switch (Copy_u8Clk)
		{
			case RCC_HSI:

				if (Copy_u8State == RCC_CLK_ON)
				{
					RCC_CR  |= RCC_CR_HSI_ON;

					while (Loc_u8TimeOut-- && (!(RCC_CR & RCC_CR_HSI_RDY)));

					if (!(RCC_CR & RCC_CR_HSI_RDY))
					{
						Loc_tenuErrStatusRetVal = RCC_enuErrorClkNotRdy;
					}
					else
					{

					}
				}
				else
				{
					 RCC_CR  &= ~(RCC_CR_HSI_ON);
				}
			break;

			case RCC_HSE:

				if ((RCC_BDCR & RCC_BDCR_RTC_HSE) == RCC_BDCR_RTC_HSE)
				{
					Loc_tenuErrStatusRetVal = RCC_enuErrorSelectedSysClk;
				}

				else
				{
					if (Copy_u8State == RCC_CLK_ON)
					{
						RCC_CR  |= RCC_CR_HSE_ON;

						while (Loc_u8TimeOut-- && (!(RCC_CR & RCC_CR_HSE_RDY)));

						if (!(RCC_CR & RCC_CR_HSE_RDY))
						{
							Loc_tenuErrStatusRetVal = RCC_enuErrorClkNotRdy;
						}
						else
						{

						}
					}
					else
					{
						 RCC_CR  &= ~(RCC_CR_HSE_ON);
					}
				}
			break;

			case RCC_PLL:

				if (Copy_u8State == RCC_CLK_ON)
				{
					RCC_CR  |= RCC_CR_PLL_ON;

					while (Loc_u8TimeOut-- && (!(RCC_CR & RCC_CR_PLL_RDY)));

					if (!(RCC_CR & RCC_CR_PLL_RDY))
					{
						Loc_tenuErrStatusRetVal = RCC_enuErrorClkNotRdy;
					}
					else
					{

					}
				}
				else
				{
					 RCC_CR  &= ~(RCC_CR_PLL_ON);
				}
			break;

			case RCC_PLLI2S:

				if (Copy_u8State == RCC_CLK_ON)
				{
					RCC_CR  |= RCC_CR_PLLI2S_ON;

					while (Loc_u8TimeOut-- && (!(RCC_CR & RCC_CR_PLLI2S_RDY)));

					if (!(RCC_CR & RCC_CR_PLLI2S_RDY))
					{
						Loc_tenuErrStatusRetVal = RCC_enuErrorClkNotRdy;
					}
					else
					{

					}
				}
				else
				{
					 RCC_CR  &= ~(RCC_CR_PLLI2S_ON);
				}
			break;

			case RCC_LSI:

				if (RCC_APB1ENR & RCC_APB1ENR_WWDG_EN)
				{
					Loc_tenuErrStatusRetVal = RCC_enuErrorWDGEnabled;
				}
				else if (RCC_APB1LPENR & RCC_APB1LPENR_WWDG_LPEN)
				{
					Loc_tenuErrStatusRetVal = RCC_enuErrorWDGEnabledLP;
				}
				else if (RCC_BDCR & RCC_BDCR_RTC_LSI)
				{
					Loc_tenuErrStatusRetVal = RCC_enuErrorSelectedSysClk;
				}
				else
				{
					if (Copy_u8State == RCC_CLK_ON)
					{
						RCC_CSR  |= RCC_CSR_LSI_ON;

						while (Loc_u8TimeOut-- && (!(RCC_CSR & RCC_CSR_LSI_RDY)));

						if (!(RCC_CSR & RCC_CSR_LSI_RDY))
						{
							Loc_tenuErrStatusRetVal = RCC_enuErrorClkNotRdy;
						}
						else
						{

						}
					}
					else
					{
						 RCC_CSR  &= ~(RCC_CSR_LSI_ON);
					}
				}
			break;

			case RCC_LSE:

				if (RCC_BDCR & RCC_BDCR_RTC_LSE)
				{
					Loc_tenuErrStatusRetVal = RCC_enuErrorSelectedSysClk;
				}

				else
				{
					if (Copy_u8State == RCC_CLK_ON)
					{
						RCC_BDCR  |= RCC_BDCR_LSE_ON;

						while (Loc_u8TimeOut-- && (!(RCC_BDCR & RCC_BDCR_LSE_RDY)));

						if (!(RCC_BDCR & RCC_BDCR_LSE_RDY))
						{
							Loc_tenuErrStatusRetVal = RCC_enuErrorClkNotRdy;
						}
						else
						{

						}
					}
					else
					{
						RCC_BDCR   &= ~(RCC_BDCR_LSE_ON);
					}
				}
			break;

			default:
			break;
		}
	}

	return Loc_tenuErrStatusRetVal;
}

/*___________________________________________________________________________________________________________________________*/

RccEnuSysClkStat_t			Rcc_tenuGetClkStatus 	    (u8 Copy_u8Clk)
{
	RccEnuSysClkStat_t Loc_tenuErrorStatusReturnValue = RCC_enuOk;

	if (Copy_u8Clk >= RCC_CLKS)
	{
		Loc_tenuErrorStatusReturnValue = RCC_enuErrorClock;
	}
	else
	{
		switch (Copy_u8Clk)
		{
		  	 case RCC_HSI:
		  		 if (RCC_CR & RCC_CR_HSI_RDY)
		  		 {
		  			 Loc_tenuErrorStatusReturnValue = RCC_enuHsiClkRdy;
		  		 }
		  		 else
		  		 {
		  			 Loc_tenuErrorStatusReturnValue = RCC_enuErrorClkNotRdy;
		  		 }
		  	 break;

		  	 case RCC_HSE:
		  		 if (RCC_CR & RCC_CR_HSE_RDY)
		  		 {
		  			 Loc_tenuErrorStatusReturnValue = RCC_enuHseClkRdy;
		  		 }
		  		 else
		  		 {
		  			 Loc_tenuErrorStatusReturnValue = RCC_enuErrorClkNotRdy;
		  		 }
		  	 break;

		  	 case RCC_PLL:
		  		 if (RCC_CR & RCC_CR_PLL_RDY)
		  		 {
		  			 Loc_tenuErrorStatusReturnValue = RCC_enuPllClkRdy;
		  		 }
		  		 else
		  		 {
		  			 Loc_tenuErrorStatusReturnValue = RCC_enuErrorClkNotRdy;
		  		 }
		  	 break;

		  	 case RCC_LSI:
		  		 if (RCC_CSR & RCC_CSR_LSI_RDY)
		  		 {
		  			 Loc_tenuErrorStatusReturnValue = RCC_enuLsiClkRdy;
		  		 }
		  		 else
		  		 {
		  			 Loc_tenuErrorStatusReturnValue = RCC_enuErrorClkNotRdy;
		  		 }
		  	 break;

		  	 case RCC_LSE:
		  		 if (RCC_BDCR & RCC_BDCR_LSE_RDY)
		  		 {
		  			 Loc_tenuErrorStatusReturnValue = RCC_enuLseClkRdy;
		  		 }
		  		 else
		  		 {
		  			 Loc_tenuErrorStatusReturnValue = RCC_enuErrorClkNotRdy;
		  		 }
		  	 break;

		     default:
		     break;
		}
	}

	return Loc_tenuErrorStatusReturnValue;
}

/*___________________________________________________________________________________________________________________________*/

RccEnuSysClkStat_t	 Rcc_tenuControlPeripheral (u8 Copy_u8PeriBusReg ,u32 Copy_u32Peripheral, u8 Copy_u8State)
{
	RccEnuSysClkStat_t Loc_tenuErrorStatusReturnValue = RCC_enuOk;

	if (Copy_u8State >= RCC_STATES)
	{
		Loc_tenuErrorStatusReturnValue = RCC_enuErrorContrlStatus;
	}
	else if ((Copy_u32Peripheral & RCC_PERIPHERAL_VALIDATE) == RCC_CLR_VAL)
	{
		Loc_tenuErrorStatusReturnValue = RCC_enuErrorPeripheral;
	}
	else if (Copy_u8PeriBusReg >= RCC_ENABLE_BUSES_REGS)
	{
		Loc_tenuErrorStatusReturnValue = RCC_enuErrorBus;
	}
	else
	{
		switch (Copy_u8PeriBusReg)
		{
			case RCC_AHB1EN_BUS:

				if (Copy_u8State == RCC_PERI_EN)
				{
					RCC_AHB1ENR  |= Copy_u32Peripheral;
				}
				else
				{
					RCC_AHB1ENR  &= ~(Copy_u32Peripheral);
				}
			break;

			case RCC_AHB2EN_BUS:

				if (Copy_u8State == RCC_PERI_EN)
				{
					RCC_AHB2ENR  |= Copy_u32Peripheral;
				}
				else
				{
					RCC_AHB2ENR  &= ~(Copy_u32Peripheral);
				}
			break;

			case RCC_APB1EN_BUS:

				if (Copy_u8State == RCC_PERI_EN)
				{
					RCC_APB1ENR  |= Copy_u32Peripheral;
				}
				else
				{
					RCC_APB1ENR  &= ~(Copy_u32Peripheral);
				}
			break;

			case RCC_APB2EN_BUS:

				if (Copy_u8State == RCC_PERI_EN)
				{
					RCC_APB2ENR  |= Copy_u32Peripheral;
				}
				else
				{
					RCC_APB2ENR  &= ~(Copy_u32Peripheral);
				}
			break;

			case RCC_AHB1LPEN_BUS:

				if (Copy_u8State == RCC_PERI_EN)
				{
					RCC_AHB1LPENR  |= Copy_u32Peripheral;
				}
				else
				{
					RCC_AHB1LPENR  &= ~(Copy_u32Peripheral);
				}
			break;

			case RCC_AHB2LPEN_BUS:

				if (Copy_u8State == RCC_PERI_EN)
				{
					RCC_AHB2LPENR  |= Copy_u32Peripheral;
				}
				else
				{
					RCC_AHB2LPENR  &= ~(Copy_u32Peripheral);
				}
			break;

			case RCC_APB1LPEN_BUS:

				if (Copy_u8State == RCC_PERI_EN)
				{
					RCC_APB1LPENR  |= Copy_u32Peripheral;
				}
				else
				{
					RCC_APB1LPENR  &= ~(Copy_u32Peripheral);
				}
			break;

			case RCC_APB2LPEN_BUS:

				if (Copy_u8State == RCC_PERI_EN)
				{
					RCC_APB2LPENR  |= Copy_u32Peripheral;
				}
				else
				{
					RCC_APB2LPENR  &= ~(Copy_u32Peripheral);
				}
			break;

			case RCC_BDCR_EN:

				if (Copy_u8State == RCC_PERI_EN)
				{
					RCC_BDCR  |= Copy_u32Peripheral;
				}
				else
				{
					RCC_BDCR  &= ~(Copy_u32Peripheral);
				}
			break;

			case RCC_SSCGR_EN:
				if (Copy_u8State == RCC_PERI_EN)
				{
					if (RCC_CR & RCC_CR_PLL_ON)
					{
						Loc_tenuErrorStatusReturnValue = RCC_enuErrorPLLOn;
					}
					else
					{
						RCC_SSCGR |= Copy_u32Peripheral;
					}
				}
				else
				{
					if (RCC_CR & RCC_CR_PLL_ON)
					{
						RCC_CR  &= ~(RCC_CR_PLL_ON);
						RCC_SSCGR &= ~(Copy_u32Peripheral);

					}
					else
					{
						RCC_SSCGR &= ~(Copy_u32Peripheral);
					}
				}
			break;

			default:
			break;

		}
	}

	return Loc_tenuErrorStatusReturnValue;
}

/*___________________________________________________________________________________________________________________________*/

RccEnuSysClkStat_t	  Rcc_tenuConfigPll	(u8 Copy_u8PllM, u16 Copy_u16PllN, u8 Copy_u8PllP, u8 Copy_u8PllQ, u32 Copy_u32PllSrc)
{
	RccEnuSysClkStat_t Loc_tenuErrorStatusReturnValue = RCC_enuOk;

	u32 Loc_u32TempPPLCFGR = RCC_PLLCFGR;

	if (RCC_CR & RCC_CR_PLL_ON)
	{
		Loc_tenuErrorStatusReturnValue = RCC_enuErrorPLLOn;
	}
	else if ( (Copy_u8PllM < RCC_PLLCFGR_PLLM_MIN) || (Copy_u8PllM > RCC_PLLCFGR_PLLM_MAX) )
	{
		Loc_tenuErrorStatusReturnValue = RCC_enuErrorMFactor;
	}

	else if ( (Copy_u16PllN < RCC_PLLCFGR_PLLN_MIN) || (Copy_u16PllN > RCC_PLLCFGR_PLLN_MAX) )
	{
		Loc_tenuErrorStatusReturnValue = RCC_enuErrorNFactor;
	}
	else if ( Copy_u8PllP >= RCC_PLLCFGR_PLLP_FACTORS_NUM)
	{
		Loc_tenuErrorStatusReturnValue = RCC_enuErrorPLLP;
	}
	else if ( (Copy_u8PllQ < RCC_PLLCFGR_PLLQ_MIN) || (Copy_u8PllQ > RCC_PLLCFGR_PLLQ_MAX) )
	{
		Loc_tenuErrorStatusReturnValue = RCC_enuErrorPLLQ;
	}
	else if ( ( (Copy_u32PllSrc >> RCC_PLLCFGR_PLLSRC) >= RCC_PLLCFGR_PLLSRC_OPTIONS ) || (RCC_PLLCFGR & Copy_u32PllSrc) != Copy_u32PllSrc )
	{
		Loc_tenuErrorStatusReturnValue = RCC_enuErrorPLLSRC;
	}

	else
	{
		Loc_u32TempPPLCFGR &= RCC_PLLCFGR_RST_MSK;

		Loc_u32TempPPLCFGR  |= (Copy_u8PllM  |  (Copy_u16PllN << RCC_PLLCFGR_SHFT_MSK_PLLN)
				            |  (Copy_u8PllP  << RCC_PLLCFGR_SHFT_MSK_PLLP)
					        |  (Copy_u8PllQ  << RCC_PLLCFGR_SHFT_MSK_PLLQ) | Copy_u32PllSrc);

		RCC_CFGR = Loc_u32TempPPLCFGR;
	}

	return Loc_tenuErrorStatusReturnValue;
}

/*___________________________________________________________________________________________________________________________*/

RccEnuSysClkStat_t	 		Rcc_tenuConfigBusPinPrescaler	(u8 Copy_u8AHBPrescaler, u8 Copy_u8APB1Prescaler, u8 Copy_u8APB2Prescaler,
		                                                     u8 Copy_u8MCO1Prescaler,
		                                                     u8 Copy_u8MCO2Prescaler)
{
	RccEnuSysClkStat_t Loc_tenuErrStatRetVal = RCC_enuOk;

	u32 Loc_u32TempCFGR = RCC_CFGR;

	if      (Copy_u8AHBPrescaler  >= RCC_CFGR_AHB_NUM_OF_VALID_PRESCALERS)
	{
		Loc_tenuErrStatRetVal = RCC_enuErrorBusPrescaler;
	}
	else if (Copy_u8APB1Prescaler >= RCC_CFGR_APB1_NUM_OF_VALID_PRESCALERS)
	{
		Loc_tenuErrStatRetVal = RCC_enuErrorBusPrescaler;
	}
	else if (Copy_u8APB2Prescaler >= RCC_CFGR_APB2_NUM_OF_VALID_PRESCALERS)
	{
		Loc_tenuErrStatRetVal = RCC_enuErrorBusPrescaler;
	}
	else if (Copy_u8MCO1Prescaler >= RCC_CFGR_MCO1_NUM_OF_VALID_PRESCALERS)
	{
		Loc_tenuErrStatRetVal = RCC_enuErrorPinPrescaler;
	}
	else if (Copy_u8MCO2Prescaler >= RCC_CFGR_MCO2_NUM_OF_VALID_PRESCALERS)
	{
		Loc_tenuErrStatRetVal = RCC_enuErrorPinPrescaler;
	}
	else if (RCC_CR & RCC_CR_HSE_ON)
	{
		Loc_tenuErrStatRetVal = RCC_enuErrorPrescalerHseON;
	}
	else if (RCC_BDCR & RCC_BDCR_LSE_ON)
	{
		Loc_tenuErrStatRetVal = RCC_enuErrorPrescalerLseON;
	}
	else
	{
		Loc_u32TempCFGR &= RCC_CFGR_RST_BUS_PIN_PRE_MSK;

		Loc_u32TempCFGR |= (Copy_u8AHBPrescaler   | Copy_u8APB1Prescaler | Copy_u8APB2Prescaler
				        |   Copy_u8MCO1Prescaler  | Copy_u8MCO2Prescaler);

		RCC_CFGR = Loc_u32TempCFGR;
	}

	return Loc_tenuErrStatRetVal;
}

/*_______________________________________________________________________________________________________________________________*/

RccEnuSysClkStat_t	 		Rcc_tenuSetRtcPrescaler      (u8 Copy_u8RTCPrescaler)
{
	RccEnuSysClkStat_t Loc_tenuErrStatusRetVal = RCC_enuOk;

	u32 Loc_u32TempCFGR = RCC_CFGR;

	if (Copy_u8RTCPrescaler >= RCC_CFGR_RTC_NUM_OF_VALID_PRESCALERS)
	{
		Loc_tenuErrStatusRetVal = RCC_enuErrorRtcPrescaler;
	}
	else if ( (RCC_BDCR & RCC_BDCR_RTC_HSE) == RCC_BDCR_RTC_HSE )
	{
		Loc_tenuErrStatusRetVal = RCC_enuErrorSelectedSysClk;
	}
	else
	{
		Loc_u32TempCFGR &= RCC_CFGR_RST_RTCPRE_MSK;

		Loc_u32TempCFGR |= Copy_u8RTCPrescaler;

		RCC_CFGR         = Loc_u32TempCFGR;
	}

	return Loc_tenuErrStatusRetVal;
}

/*_____________________________________________________________Handlers__________________________________________________________________*/

void __attribute__ ((section(".after_vectors"),weak))
NMI_Handler (void)
{
	RCC_CIR |= RCC_CIR_CSSC;
}

/*______________________________________________________________EOF_________________________________________________________________*/
