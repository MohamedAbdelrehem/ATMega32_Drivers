/*********************************************************************************************/
/*********************************************************************************************/
/**   __  __     _                      _     _   _        _     _         _                **/
/**  |  \/  |___| |_  __ _ _ __  ___ __| |   /_\ | |__  __| |___| |_ _ ___| |_  ___ _ __    **/
/**  | |\/| / _ \ ' \/ _` | '  \/ -_) _` |  / _ \| '_ \/ _` / -_) | '_/ -_) ' \/ -_) '  \   **/
/**  |_|  |_\___/_||_\__,_|_|_|_\___\__,_| /_/ \_\_.__/\__,_\___|_|_| \___|_||_\___|_|_|_|  **/
/*********************************************************************************************/
/************************         Author: Mohamed Abdelrehem         *************************/
/************************         Layer:  HAL                        *************************/
/************************         SWC:    LED                        *************************/
/************************         Version:1.00                       *************************/
/*********************************************************************************************/
/*********************************************************************************************/

#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_TYPES.h"

#include "../../1-MCAL/1-DIO/DIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

void LED_voidInitialization(LED_str *Struct_pu8LedConfig)
{
	DIO_u8SetPinDirection(Struct_pu8LedConfig->Strct_enumPort, Struct_pu8LedConfig->Strct_enumPin, DIO_enumPIN_OUTPUT);
}

void LED_voidControl(LED_str *Struct_pu8LedConfig, LED_Value Copy_u8LedValue)
{
	if (Copy_u8LedValue == LED_enumHIGH)
	{
		if (Struct_pu8LedConfig->Strct_enumConnectionType == LED_enumCON_SOURCE)
		{
			DIO_u8SetPinValue(Struct_pu8LedConfig->Strct_enumPort, Struct_pu8LedConfig->Strct_enumPin, DIO_enumPIN_HIGH);
		}
		else if (Struct_pu8LedConfig->Strct_enumConnectionType == LED_enumCON_SINK)
		{
			DIO_u8SetPinValue(Struct_pu8LedConfig->Strct_enumPort, Struct_pu8LedConfig->Strct_enumPin, DIO_enumPIN_LOW);
		}
	}
	else if (Copy_u8LedValue == LED_enumLOW)
	{
		if (Struct_pu8LedConfig->Strct_enumConnectionType == LED_enumCON_SOURCE)
		{
			DIO_u8SetPinValue(Struct_pu8LedConfig->Strct_enumPort, Struct_pu8LedConfig->Strct_enumPin, DIO_enumPIN_LOW);
		}
		else if (Struct_pu8LedConfig->Strct_enumConnectionType == LED_enumCON_SINK)
		{
			DIO_u8SetPinValue(Struct_pu8LedConfig->Strct_enumPort, Struct_pu8LedConfig->Strct_enumPin, DIO_enumPIN_HIGH);
		}
	}
}
void LED_voidToggle(LED_str *Struct_pu8LedConfig)
{
	DIO_u8TogglePinValue(Struct_pu8LedConfig->Strct_enumPort, Struct_pu8LedConfig->Strct_enumPin);
}

void LED_voidTurnOn(LED_str *Struct_pu8LedConfig)
{

	if (Struct_pu8LedConfig->Strct_enumConnectionType == LED_enumCON_SOURCE)
	{
		DIO_u8SetPinValue(Struct_pu8LedConfig->Strct_enumPort, Struct_pu8LedConfig->Strct_enumPin, DIO_enumPIN_HIGH);
	}
	else if (Struct_pu8LedConfig->Strct_enumConnectionType == LED_enumCON_SINK)
	{
		DIO_u8SetPinValue(Struct_pu8LedConfig->Strct_enumPort, Struct_pu8LedConfig->Strct_enumPin, DIO_enumPIN_LOW);
	}
}
void LED_voidTurnOff(LED_str *Struct_pu8LedConfig)
{
	if (Struct_pu8LedConfig->Strct_enumConnectionType == LED_enumCON_SOURCE)
	{
		DIO_u8SetPinValue(Struct_pu8LedConfig->Strct_enumPort, Struct_pu8LedConfig->Strct_enumPin, DIO_enumPIN_LOW);
	}
	else if (Struct_pu8LedConfig->Strct_enumConnectionType == LED_enumCON_SINK)
	{
		DIO_u8SetPinValue(Struct_pu8LedConfig->Strct_enumPort, Struct_pu8LedConfig->Strct_enumPin, DIO_enumPIN_HIGH);
	}
}
