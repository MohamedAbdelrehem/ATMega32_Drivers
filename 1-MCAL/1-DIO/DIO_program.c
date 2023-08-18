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

#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_TYPES.h"

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_register.h"

DIO_ErrorDetection DIO_u8SetPinDirection(DIO_PortGroup Copy_u8Port, DIO_PinNumber Copy_u8Pin, DIO_PortDirection Copy_u8Direction)
{
    DIO_ErrorDetection Local_u8ErrorState = DIO_enumERROR_NO;

    if (Copy_u8Pin <= DIO_enumPIN7)
    {
        if (Copy_u8Direction == DIO_enumPIN_INPUT)
        {
            switch (Copy_u8Port)
            {
            case DIO_enumPORTA:
                CLR_BIT(DDRA, Copy_u8Pin);
                break;
            case DIO_enumPORTB:
                CLR_BIT(DDRB, Copy_u8Pin);
                break;
            case DIO_enumPORTC:
                CLR_BIT(DDRC, Copy_u8Pin);
                break;
            case DIO_enumPORTD:
                CLR_BIT(DDRD, Copy_u8Pin);
                break;
            default:
                Local_u8ErrorState = DIO_enumERROR;
                break;
            }
        }
        else if (Copy_u8Direction == DIO_enumPIN_OUTPUT)
        {
            switch (Copy_u8Port)
            {
            case DIO_enumPORTA:
                SET_BIT(DDRA, Copy_u8Pin);
                break;
            case DIO_enumPORTB:
                SET_BIT(DDRB, Copy_u8Pin);
                break;
            case DIO_enumPORTC:
                SET_BIT(DDRC, Copy_u8Pin);
                break;
            case DIO_enumPORTD:
                SET_BIT(DDRD, Copy_u8Pin);
                break;
            default:
                Local_u8ErrorState = DIO_enumERROR;
                break;
            }
        }
        else
        {
            Local_u8ErrorState = DIO_enumERROR;
        }
    }
    else
    {
        Local_u8ErrorState = DIO_enumERROR;
    }

    return Local_u8ErrorState;
}

// Set Port Direction input or output
DIO_ErrorDetection DIO_u8SetPortDirection(DIO_PortGroup Copy_u8Port, DIO_PortDirection Copy_u8Direction)
{
    DIO_ErrorDetection Local_u8ErrorState = DIO_enumERROR_NO;

    switch (Copy_u8Port)
    {
    case DIO_enumPORTA:
        DDRA = Copy_u8Direction;
        break;
    case DIO_enumPORTB:
        DDRB = Copy_u8Direction;
        break;
    case DIO_enumPORTC:
        DDRC = Copy_u8Direction;
        break;
    case DIO_enumPORTD:
        DDRD = Copy_u8Direction;
        break;
    default:
        Local_u8ErrorState = DIO_enumERROR;
        break;
    }

    return Local_u8ErrorState;
}

DIO_ErrorDetection DIO_u8SetPinValue(DIO_PortGroup Copy_u8Port, DIO_PinNumber Copy_u8Pin, DIO_PinValue Copy_u8Value)
{
    DIO_ErrorDetection Local_u8ErrorState = DIO_enumERROR_NO;

    if (Copy_u8Pin <= DIO_enumPIN7)
    {
        if (Copy_u8Value == DIO_enumPIN_LOW)
        {
            switch (Copy_u8Port)
            {
            case DIO_enumPORTA:
                CLR_BIT(PORTA, Copy_u8Pin);
                break;
            case DIO_enumPORTB:
                CLR_BIT(PORTB, Copy_u8Pin);
                break;
            case DIO_enumPORTC:
                CLR_BIT(PORTC, Copy_u8Pin);
                break;
            case DIO_enumPORTD:
                CLR_BIT(PORTD, Copy_u8Pin);
                break;
            default:
                Local_u8ErrorState = DIO_enumERROR;
                break;
            }
        }
        else if (Copy_u8Value == DIO_enumPIN_HIGH)
        {
            switch (Copy_u8Port)
            {
            case DIO_enumPORTA:
                SET_BIT(PORTA, Copy_u8Pin);
                break;
            case DIO_enumPORTB:
                SET_BIT(PORTB, Copy_u8Pin);
                break;
            case DIO_enumPORTC:
                SET_BIT(PORTC, Copy_u8Pin);
                break;
            case DIO_enumPORTD:
                SET_BIT(PORTD, Copy_u8Pin);
                break;
            default:
                Local_u8ErrorState = DIO_enumERROR;
                break;
            }
        }
        else
        {
            Local_u8ErrorState = DIO_enumERROR;
        }
    }
    else
    {
        Local_u8ErrorState = DIO_enumERROR;
    }

    return Local_u8ErrorState;
}
DIO_ErrorDetection DIO_u8SetPortValue(DIO_PortGroup Copy_u8Port, DIO_PinValue Copy_u8Value)
{
    DIO_ErrorDetection Local_u8ErrorState = DIO_enumERROR_NO;

    switch (Copy_u8Port)
    {
    case DIO_enumPORTA:
        PORTA = Copy_u8Value;
        break;
    case DIO_enumPORTB:
        PORTB = Copy_u8Value;
        break;
    case DIO_enumPORTC:
        PORTC = Copy_u8Value;
        break;
    case DIO_enumPORTD:
        PORTD = Copy_u8Value;
        break;
    default:
        Local_u8ErrorState = DIO_enumERROR;
        break;
    }

    return Local_u8ErrorState;
}
DIO_ErrorDetection DIO_u8GetPinValue(DIO_PortGroup Copy_u8Port, DIO_PinNumber Copy_u8Pin, DIO_PinValue *Copy_pu8Value)
{
    DIO_ErrorDetection Local_u8ErrorState = DIO_enumERROR_NO;

    if ((Copy_pu8Value != NULL) && (Copy_u8Pin <= DIO_enumPIN7))
    {
        switch (Copy_u8Port)
        {
        case DIO_enumPORTA:
            *Copy_pu8Value = GET_BIT(PINA, Copy_u8Pin);
            break;
        case DIO_enumPORTB:
            *Copy_pu8Value = GET_BIT(PINB, Copy_u8Pin);
            break;
        case DIO_enumPORTC:
            *Copy_pu8Value = GET_BIT(PINC, Copy_u8Pin);
            break;
        case DIO_enumPORTD:
            *Copy_pu8Value = GET_BIT(PIND, Copy_u8Pin);
            break;
        default:
            Local_u8ErrorState = DIO_enumERROR;
            break;
        }
    }
    else
    {
        Local_u8ErrorState = DIO_enumERROR;
    }

    return Local_u8ErrorState;
}
DIO_ErrorDetection DIO_u8TogglePinValue(DIO_PortGroup Copy_u8Port, DIO_PinNumber Copy_u8Pin)
{
    DIO_ErrorDetection Local_u8ErrorState = DIO_enumERROR_NO;

    if (Copy_u8Pin <= DIO_enumPIN7)
    {
        switch (Copy_u8Port)
        {
        case DIO_enumPORTA:
            TOGGLE_BIT(PORTA, Copy_u8Pin);
            break;
        case DIO_enumPORTB:
            TOGGLE_BIT(PORTB, Copy_u8Pin);
            break;
        case DIO_enumPORTC:
            TOGGLE_BIT(PORTC, Copy_u8Pin);
            break;
        case DIO_enumPORTD:
            TOGGLE_BIT(PORTD, Copy_u8Pin);
            break;
        default:
            Local_u8ErrorState = DIO_enumERROR;
            break;
        }
    }
    else
    {
        Local_u8ErrorState = DIO_enumERROR;
    }

    return Local_u8ErrorState;
}