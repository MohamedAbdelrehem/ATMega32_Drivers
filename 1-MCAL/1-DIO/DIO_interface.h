/*********************************************************************************************/
/*********************************************************************************************/
/**   __  __     _                      _     _   _        _     _         _                **/
/**  |  \/  |___| |_  __ _ _ __  ___ __| |   /_\ | |__  __| |___| |_ _ ___| |_  ___ _ __    **/
/**  | |\/| / _ \ ' \/ _` | '  \/ -_) _` |  / _ \| '_ \/ _` / -_) | '_/ -_) ' \/ -_) '  \   **/
/**  |_|  |_\___/_||_\__,_|_|_|_\___\__,_| /_/ \_\_.__/\__,_\___|_|_| \___|_||_\___|_|_|_|  **/
/*********************************************************************************************/
/************************         Author: Mohamed Abdelrehem         *************************/
/************************         Layer:  MCAL                       *************************/
/************************         SWC:    DIO                        *************************/
/************************         Version:1.00                       *************************/
/*********************************************************************************************/
/*********************************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

// return 0 in case everything running ok and 1 in case error
typedef enum
{
    DIO_enumERROR_NO,
    DIO_enumERROR
} DIO_ErrorDetection;

// Dirction of pin input or output
typedef enum
{
    DIO_enumPIN_INPUT,
    DIO_enumPIN_OUTPUT
} DIO_PinDirection;

// Output of Pin high or low
typedef enum
{
    DIO_enumPIN_LOW,
    DIO_enumPIN_HIGH
} DIO_PinValue;

// Pin Number
typedef enum
{
    DIO_enumPIN0,
    DIO_enumPIN1,
    DIO_enumPIN2,
    DIO_enumPIN3,
    DIO_enumPIN4,
    DIO_enumPIN5,
    DIO_enumPIN6,
    DIO_enumPIN7,
} DIO_PinNumber;

// Port Name
typedef enum
{
    DIO_enumPORTA,
    DIO_enumPORTB,
    DIO_enumPORTC,
    DIO_enumPORTD
} DIO_PortGroup;

// Dirction of the port input or output
typedef enum
{
    DIO_enumPORT_INPUT = 0,
    DIO_enumPORT_OUTPUT = 0xFF
} DIO_PortDirection;

// Direction Of Port All High Or Low
typedef enum
{
    DIO_enumPORT_LOW,
    DIO_enumPORT_HIGH = 0xFF
} DIO_u8PortValueAll;

DIO_ErrorDetection DIO_u8SetPinDirection(DIO_PortGroup Copy_u8Port, DIO_PinNumber Copy_u8Pin, DIO_PortDirection Copy_u8Direction);
DIO_ErrorDetection DIO_u8SetPortDirection(DIO_PortGroup Copy_u8Port, DIO_PortDirection Copy_u8Direction);

DIO_ErrorDetection DIO_u8SetPinValue(DIO_PortGroup Copy_u8Port, DIO_PinNumber Copy_u8Pin, DIO_PinValue Copy_u8Value);
DIO_ErrorDetection DIO_u8SetPortValue(DIO_PortGroup Copy_u8Port, DIO_PinValue Copy_u8Value);

DIO_ErrorDetection DIO_u8GetPinValue(DIO_PortGroup Copy_u8Port, DIO_PinNumber Copy_u8Pin, DIO_PinValue *Copy_pu8Value);

DIO_ErrorDetection DIO_u8TogglePinValue(DIO_PortGroup Copy_u8Port, DIO_PinNumber Copy_u8Pin);

#endif