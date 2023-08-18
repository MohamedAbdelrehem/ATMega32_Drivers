/*********************************************************************************************/
/*********************************************************************************************/
/**   __  __     _                      _     _   _        _     _         _                **/
/**  |  \/  |___| |_  __ _ _ __  ___ __| |   /_\ | |__  __| |___| |_ _ ___| |_  ___ _ __    **/
/**  | |\/| / _ \ ' \/ _` | '  \/ -_) _` |  / _ \| '_ \/ _` / -_) | '_/ -_) ' \/ -_) '  \   **/
/**  |_|  |_\___/_||_\__,_|_|_|_\___\__,_| /_/ \_\_.__/\__,_\___|_|_| \___|_||_\___|_|_|_|  **/
/*********************************************************************************************/
/************************         Author: Mohamed Abdelrehem         *************************/
/************************         Layer:  HAL                        *************************/
/************************         SWC:    SW                         *************************/
/************************         Version:1.00                       *************************/
/*********************************************************************************************/
/*********************************************************************************************/
#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_TYPES.h"

#include "../../1-MCAL/1-DIO/DIO_interface.h"

#include "SW_interface.h"
#include "SW_config.h"
#include "SW_private.h"

void SW_voidInitialization(SW_str *Struct_pu8LedConfig)
{
	DIO_u8SetPinDirection(Struct_pu8LedConfig->Struct_enumPort, Struct_pu8LedConfig->Struct_enumPin, DIO_enumPIN_INPUT);
	if (Struct_pu8LedConfig->Struct_enumPullType == SW_enumPullUpInternal)
	{
		// seting up internal Pull-Up Resistor
		DIO_u8SetPinValue(Struct_pu8LedConfig->Struct_enumPort, Struct_pu8LedConfig->Struct_enumPin, DIO_enumPIN_HIGH);
	}
}
SW_Status SW_enumGetValue(SW_str *Struct_pu8LedConfig)
{
	DIO_PinValue SW_Status;

	DIO_u8GetPinValue(Struct_pu8LedConfig->Struct_enumPort, Struct_pu8LedConfig->Struct_enumPin, &SW_Status);

	if ((Struct_pu8LedConfig->Struct_enumPullType == SW_enumPullUpExternal || Struct_pu8LedConfig->Struct_enumPullType == SW_enumPullUpInternal) && SW_Status == SW_enumOFF)
	{
		return SW_enumON;
	}
	else if (Struct_pu8LedConfig->Struct_enumPullType == SW_enumPullDown && SW_Status == SW_enumON)
	{
		return SW_enumON;
	}
	else
	{
		return SW_enumOFF;
	}
}
