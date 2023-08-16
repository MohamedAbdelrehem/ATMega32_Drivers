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

#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

// Switch state
typedef enum
{
	SW_enumOFF,
	SW_enumON
} SW_Status;
// Switch port
typedef enum
{
	SW_enumPORTA,
	SW_enumPORTB,
	SW_enumPORTC,
	SW_enumPORTD
} SW_PortGroup;

// Switch Pin
typedef enum
{
	SW_enumPIN0,
	SW_enumPIN1,
	SW_enumPIN2,
	SW_enumPIN3,
	SW_enumPIN4,
	SW_enumPIN5,
	SW_enumPIN6,
	SW_enumPIN7
} SW_Pin;
// Switch Type
typedef enum
{
	SW_enumPullDown,
	SW_enumPullUpExternal,
	SW_enumPullUpInternal,
} SW_PullType;
typedef struct
{
	// Switch port
	SW_PortGroup Struct_enumPort;
	// Switch pin
	SW_Pin Struct_enumPin;
	// Switch pull type
	SW_PullType Struct_enumPullType;
} SW_str;

void SW_voidInitialize(SW_str *Struct_pu8LedConfig);
SW_Status SW_enumGetValue(SW_str *Struct_pu8LedConfig);
#endif
