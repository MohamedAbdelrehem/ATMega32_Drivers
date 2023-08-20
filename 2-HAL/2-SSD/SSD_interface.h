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

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#ifndef STD_TYPES_H_
#include "../../4-LIB/STD_TYPES.h"
#endif

typedef enum
{
    SSD_enumCOMMON_CATHODE,
    SSD_enumCOMMON_ANODE
} SSD_Type;

typedef enum
{
    SSD_enumPORTA,
    SSD_enumPORTB,
    SSD_enumPORTC,
    SSD_enumPORTD,
} SSD_PortGroup;

typedef enum
{
    SSD_enumPIN0,
    SSD_enumPIN1,
    SSD_enumPIN2,
    SSD_enumPIN3,
    SSD_enumPIN4,
    SSD_enumPIN5,
    SSD_enumPIN6,
    SSD_enumPIN7,
} SSD_EnablePin;
typedef struct SSD_str
{
    // SSD PORT
    SSD_PortGroup Struct_enumDataPort;
    // SSD Type
    SSD_Type Struct_enumType;
    // SSD Enable PORT
    SSD_PortGroup Struct_enumEnablePort;
    // SSD Enable Pin
    SSD_EnablePin Struct_enumEnablePin;
} SSD_str;
#define SSD_MAX 10

// Initialize SSD
void SSD_voidInit(SSD_str *Struct_pu8SSDConfig);
// function to set number
void SSD_voidSetNumber(SSD_str *Struct_pu8SSDConfig, u8 Copy_u8SSDNumber);

void SSD_voidEnable(SSD_str *Struct_pu8SSDConfig);
void SSD_voidDisable(SSD_str *Struct_pu8SSDConfig);

#endif
