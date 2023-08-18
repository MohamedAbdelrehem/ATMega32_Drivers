/*********************************************************************************************/
/*********************************************************************************************/
/**   __  __     _                      _     _   _        _     _         _                **/
/**  |  \/  |___| |_  __ _ _ __  ___ __| |   /_\ | |__  __| |___| |_ _ ___| |_  ___ _ __    **/
/**  | |\/| / _ \ ' \/ _` | '  \/ -_) _` |  / _ \| '_ \/ _` / -_) | '_/ -_) ' \/ -_) '  \   **/
/**  |_|  |_\___/_||_\__,_|_|_|_\___\__,_| /_/ \_\_.__/\__,_\___|_|_| \___|_||_\___|_|_|_|  **/
/*********************************************************************************************/
/************************         Author: Mohamed Abdelrehem         *************************/
/************************         Layer:  HAL                        *************************/
/************************         SWC:    7-Segment Dispaly          *************************/
/************************         Version:1.00                       *************************/
/*********************************************************************************************/
/*********************************************************************************************/

#include "../../4-LIB/STD_TYPES.h"
#include "../../1-MCAL/1-DIO/DIO_interface.h"

#include "SSD_private.h"
#include "SSD_config.h"
#include "SSD_interface.h"

static u8 Local_u8SSDNumbers[10] = SSD_NUMBER_ARR;

void SSD_voidInitialization(SSD_str *Struct_pu8SSDConfig)
{
    DIO_u8SetPortDirection(Struct_pu8SSDConfig->Struct_enumDataPort, DIO_enumPORT_OUTPUT);
    DIO_u8SetPinDirection(Struct_pu8SSDConfig->Struct_enumEnablePort, Struct_pu8SSDConfig->Struct_enumEnablePin, DIO_enumPIN_OUTPUT);
}
void SSD_voidSetNumber(SSD_str *Struct_pu8SSDConfig, u8 Copy_u8SSDNumber)
{
    if (Copy_u8SSDNumber < SSD_MAX)
    {
        if (Struct_pu8SSDConfig->Struct_enumType == SSD_enumCOMMON_CATHODE)
        {
            DIO_u8SetPortValue(Struct_pu8SSDConfig->Struct_enumDataPort, Local_u8SSDNumbers[Copy_u8SSDNumber]);
        }
        else if (Struct_pu8SSDConfig->Struct_enumType == SSD_enumCOMMON_ANODE)
        {
            DIO_u8SetPortValue(Struct_pu8SSDConfig->Struct_enumDataPort, ~(Local_u8SSDNumbers[Copy_u8SSDNumber]));
        }
    }
    else
    {
        DIO_u8SetPortValue(Struct_pu8SSDConfig->Struct_enumDataPort, ~(Local_u8SSDNumbers[Copy_u8SSDNumber]));
    }
}
void SSD_voidEnable(SSD_str *Struct_pu8SSDConfig)
{
    if (Struct_pu8SSDConfig->Struct_enumType == SSD_enumCOMMON_CATHODE)
    {
        DIO_u8SetPinValue(Struct_pu8SSDConfig->Struct_enumEnablePort, Struct_pu8SSDConfig->Struct_enumEnablePin, DIO_enumPIN_LOW);
    }
    else if (Struct_pu8SSDConfig->Struct_enumType == SSD_enumCOMMON_ANODE)
    {
        DIO_u8SetPinValue(Struct_pu8SSDConfig->Struct_enumEnablePort, Struct_pu8SSDConfig->Struct_enumEnablePin, DIO_enumPIN_HIGH);
    }
}
void SSD_voidDisable(SSD_str *Struct_pu8SSDConfig)
{
    if (Struct_pu8SSDConfig->Struct_enumType == SSD_enumCOMMON_CATHODE)
    {
        DIO_u8SetPinValue(Struct_pu8SSDConfig->Struct_enumEnablePort, Struct_pu8SSDConfig->Struct_enumEnablePin, DIO_enumPIN_HIGH);
    }
    else if (Struct_pu8SSDConfig->Struct_enumType == SSD_enumCOMMON_ANODE)
    {
        DIO_u8SetPinValue(Struct_pu8SSDConfig->Struct_enumEnablePort, Struct_pu8SSDConfig->Struct_enumEnablePin, DIO_enumPIN_LOW);
    }
}
