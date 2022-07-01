/*
 * GPIO.c
 *
 *  Created on: Mar 27, 2022
 *      Author: dahroug
 */

#include "Std_types.h"
#include "Bit_utils.h"
#include "Gpio.h"

typedef struct
{
	volatile u32 GPIOx_MODER;
	volatile u32 GPIOx_OTYPER;
	volatile u32 GPIOx_OSPEEDR;
	volatile u32 GPIOx_PUPDR;
	volatile u32 GPIOx_IDR;
	volatile u32 GPIOx_ODR;
	volatile u32 GPIOx_BSRR;
	volatile u32 GPIOx_LCKR;
	volatile u32 GPIOx_AFRL;
	volatile u32 GPIOx_AFRH;

}GPIOx_Register_t;

#define 	GPIO_16_VAR_VAL						((u16)0xFFFF)

#define 	GPIO_PIN_CLR_MSK			        ((u32)0x00000003)
#define 	GPIO_CLR_OTYPER_MSK		            ((u32)0x00000001)
#define 	GPIO_MODE_MSK			            ((u32)0x00000003)
#define 	GPIO_PUPD_MSK			            ((u32)0x00000030)
#define 	GPIO_OTY_MSK			            ((u32)0x00000800)

#define 	GPIO_AFRL_MSK						((u16)0x00FF)
#define 	GPIO_AFRH_MSK						((u16)0xFF00)

#define 	GPIO_ZERO 				            0
#define 	GPIO_ONE				            1
#define 	GPIO_PIN_MODE_BITS		            2
#define 	GPIO_PINS				            16

#define 	GPIO_MODE_CFG_VAR_PUPD_SHFT_MSK		4
#define 	GPIO_MODE_CFG_VAR_OTY_SHFT_MSK		8


GPIO_ErrorStatus_t Gpio_Init (GPIO_ChannelPinCfg_t* Add_pstrPinCfg)
{
	GPIO_ErrorStatus_t Loc_enuReturnStatus = GPIO_Ok;

	GPIOx_Register_t* Loc_AddPort = Add_pstrPinCfg->Port;

	u8 Loc_u8Iter = GPIO_ZERO;

	u32 Loc_u32TmpCfg = GPIO_ZERO;


	if (Add_pstrPinCfg == NULL)
	{
		Loc_enuReturnStatus = GPIO_errorNullPtr;
	}

	for (Loc_u8Iter = GPIO_ZERO; Loc_u8Iter < GPIO_PINS; Loc_u8Iter++)
	{
		if (GET_BIT(Add_pstrPinCfg->Pin, Loc_u8Iter) == GPIO_ONE)
		{
			Loc_u32TmpCfg = Add_pstrPinCfg->Mode & GPIO_MODE_MSK;
			Loc_AddPort->GPIOx_MODER &= ~(GPIO_PIN_CLR_MSK << (Loc_u8Iter * GPIO_PIN_MODE_BITS));
			Loc_AddPort->GPIOx_MODER |= Loc_u32TmpCfg << (Loc_u8Iter * GPIO_PIN_MODE_BITS);

			Loc_u32TmpCfg = (Add_pstrPinCfg->Mode & GPIO_PUPD_MSK) >> GPIO_MODE_CFG_VAR_PUPD_SHFT_MSK;
			Loc_AddPort->GPIOx_PUPDR &= ~(GPIO_PIN_CLR_MSK << (Loc_u8Iter * GPIO_PIN_MODE_BITS));
			Loc_AddPort->GPIOx_PUPDR |= Loc_u32TmpCfg << (Loc_u8Iter * GPIO_PIN_MODE_BITS);

			Loc_u32TmpCfg = (Add_pstrPinCfg->Mode & GPIO_OTY_MSK) >> GPIO_MODE_CFG_VAR_OTY_SHFT_MSK;
			Loc_AddPort->GPIOx_OTYPER &= ~(GPIO_CLR_OTYPER_MSK << Loc_u8Iter );
			Loc_AddPort->GPIOx_OTYPER  |= Loc_u32TmpCfg << Loc_u8Iter;

			Loc_AddPort->GPIOx_OSPEEDR &= ~(GPIO_PIN_CLR_MSK << (Loc_u8Iter * GPIO_PIN_MODE_BITS));
			Loc_AddPort->GPIOx_OSPEEDR  |= Loc_u32TmpCfg << (Loc_u8Iter * GPIO_PIN_MODE_BITS);
		}
	}

	return Loc_enuReturnStatus;
}


GPIO_ErrorStatus_t Gpio_setPinValue (void * GPIO_pvPort, u16 Copy_u16Pin , u8 Copy_u8Value)
{
	GPIOx_Register_t* Loc_AddPort = GPIO_pvPort;

	GPIO_ErrorStatus_t Loc_tenuErrorStatusReturnValue = GPIO_Ok;

	if (Copy_u8Value == GPIO_HIGH)
	{
		Loc_AddPort->GPIOx_BSRR = (u32)Copy_u16Pin;
	}
	else if (Copy_u8Value == GPIO_LOW)
	{
		Loc_AddPort->GPIOx_BSRR = ( (u32)Copy_u16Pin ) << GPIO_PINS;
	}
	else
	{
		Loc_tenuErrorStatusReturnValue = GPIO_InvalidArgument;
	}

	return Loc_tenuErrorStatusReturnValue;
}

GPIO_ErrorStatus_t Gpio_ReadPinValue(GPIO_ChannelPinCfg_t * Add_strGpioCfg, pu8 Add_pu8Value)
{
	GPIO_ErrorStatus_t Loc_tenuReturnErrorStatusValue = GPIO_Ok;

	GPIOx_Register_t* Loc_AddPort = Add_strGpioCfg->Port;

	if (Add_pu8Value == NULL || Add_strGpioCfg == NULL)
	{
		Loc_tenuReturnErrorStatusValue = GPIO_errorNullPtr;
	}
	else
	{
		if (Loc_AddPort->GPIOx_IDR & Add_strGpioCfg->Pin)
		{
			*Add_pu8Value = GPIO_HIGH;
		}
		else
		{
			*Add_pu8Value = GPIO_LOW;
		}
	}

	return Loc_tenuReturnErrorStatusValue;
}

/* This function is used to set only one PIN with an AF at a time ... */
GPIO_ErrorStatus_t Gpio_SetPinAlternateFunc(void * GPIO_pvPort, u16 Copy_u16Pin, u32 Copy_u32AlternateFunction)
{
	GPIO_ErrorStatus_t Loc_enuReturnErrorStatusValue = GPIO_Ok;

	GPIOx_Register_t*  Loc_AddPort = GPIO_pvPort;

	if (Copy_u16Pin & GPIO_AFRL_MSK)
	{
		Loc_AddPort->GPIOx_AFRL |= Copy_u32AlternateFunction;
	}
	else if (Copy_u16Pin & GPIO_AFRH_MSK)
	{
		Loc_AddPort->GPIOx_AFRH |= Copy_u32AlternateFunction;
	}
	else
	{
		Loc_enuReturnErrorStatusValue = GPIO_InvalidArgument;
	}


	return Loc_enuReturnErrorStatusValue;
}

GPIO_ErrorStatus_t Gpio_setPortValue (void * GPIO_pvPort, u16 Copy_u16Value)
{
	GPIO_ErrorStatus_t Loc_enuReturnErrorStatusValue = GPIO_Ok;

	GPIOx_Register_t*  Loc_AddPort = GPIO_pvPort;

	if (!Loc_AddPort)
	{
		Loc_enuReturnErrorStatusValue = GPIO_errorNullPtr;
	}
	else
	{
		Loc_AddPort->GPIOx_ODR |= Copy_u16Value;
	}
	return Loc_enuReturnErrorStatusValue;
}


