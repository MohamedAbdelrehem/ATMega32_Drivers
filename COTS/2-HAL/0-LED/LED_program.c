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

void LED_voidControl(LED_str *Struct_pu8Led, LED_Value Copy_u8Value)
{
    if (Copy_u8Value == LED_enumHIGH)
    {
        DIO_u8SetPinValue(Struct_pu8Led->Strct_enumPort, Struct_pu8Led->Strct_enumPin, DIO_enumPIN_HIGH);
    }
    else if (Copy_u8Value == LED_enumLOW)
    {
        DIO_u8SetPinValue(Struct_pu8Led->Strct_enumPort, Struct_pu8Led->Strct_enumPin, DIO_enumPIN_LOW);
    }
}
void LED_voidToggle(LED_str *Struct_pu8Led)
{
    DIO_u8TogglePinValue(Struct_pu8Led->Strct_enumPort, Struct_pu8Led->Strct_enumPin);
}
void LED_voidTurnOn(LED_str *Struct_pu8Led)
{
    DIO_u8SetPinValue(Struct_pu8Led->Strct_enumPort, Struct_pu8Led->Strct_enumPin, DIO_enumPIN_HIGH);
}
void LED_voidTurnOff(LED_str *Struct_pu8Led)
{
    DIO_u8SetPinValue(Struct_pu8Led->Strct_enumPort, Struct_pu8Led->Strct_enumPin, DIO_enumPIN_LOW);
}