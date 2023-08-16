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
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

// Led output Value
typedef enum
{
    LED_enumLOW,
    LED_enumHIGH
} LED_Value;

// Led Port
typedef enum
{
    LED_enumPORTA,
    LED_enumPORTB,
    LED_enumPORTC,
    LED_enumPORTD
} LED_PortGroup;

// Led Pin
typedef enum
{
    LED_enumPIN0,
    LED_enumPIN1,
    LED_enumPIN2,
    LED_enumPIN3,
    LED_enumPIN4,
    LED_enumPIN5,
    LED_enumPIN6,
    LED_enumPIN7
} LED_Pin;

// Sink/Source
typedef enum
{

    LED_enumCON_SOURCE,
    LED_enumCON_SINK
} LED_ConnectionType;

typedef struct
{
    // Port,Pin,Sink/Source
    LED_PortGroup Strct_enumPort;
    LED_Pin Strct_enumPin;
    LED_ConnectionType Strct_enumConnectionType;
} LED_str;

void LED_voidInitialization(LED_str *Struct_pu8LedConfig);

void LED_voidControl(LED_str *Struct_pu8LedConfig, LED_Value Copy_u8LedValue);

void LED_voidToggle(LED_str *Struct_pu8LedConfig);

void LED_voidTurnOn(LED_str *Struct_pu8LedConfig);
void LED_voidTurnOff(LED_str *Struct_pu8LedConfig);

#endif
