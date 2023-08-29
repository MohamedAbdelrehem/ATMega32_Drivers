/*********************************************************************************************/
/*********************************************************************************************/
/**   __  __     _                      _     _   _        _     _         _                **/
/**  |  \/  |___| |_  __ _ _ __  ___ __| |   /_\ | |__  __| |___| |_ _ ___| |_  ___ _ __    **/
/**  | |\/| / _ \ ' \/ _` | '  \/ -_) _` |  / _ \| '_ \/ _` / -_) | '_/ -_) ' \/ -_) '  \   **/
/**  |_|  |_\___/_||_\__,_|_|_|_\___\__,_| /_/ \_\_.__/\__,_\___|_|_| \___|_||_\___|_|_|_|  **/
/*********************************************************************************************/
/************************         Author: Mohamed Abdelrehem         *************************/
/************************         Layer:  HAL                        *************************/
/************************         SWC:    Character LCD              *************************/
/************************         Version:1.20                       *************************/
/*********************************************************************************************/
/*********************************************************************************************/

#include "../../4-LIB/STD_TYPES.h"

#include <util/delay.h>
// #include <avr/delay.h>

#include "../../1-MCAL/1-DIO/DIO_interface.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

void CLCD_voidInit(void)
{
    // pins direction init
    //  All Pins as OutPut pins
    DIO_u8SetPortDirection(CLCD_DATA_PORT, DIO_enumPORT_OUTPUT);
    DIO_u8SetPinDirection(CLCD_CONTROL_PORT, CLCD_CONTROL_RS_PIN, DIO_enumPIN_OUTPUT);
    DIO_u8SetPinDirection(CLCD_CONTROL_PORT, CLCD_CONTROL_RW_PIN, DIO_enumPIN_OUTPUT);
    DIO_u8SetPinDirection(CLCD_CONTROL_PORT, CLCD_CONTROL_E_PIN, DIO_enumPIN_OUTPUT);

    /*Wait for more than 30ms after VDD rises to 4.5V.*/
    _delay_ms(30);
    /*Function set command: 8bit init, 2 lines, 5*8 Font size*/
    CLCD_voidSendCommand(0b00111000);
    // SendCommand contain 2ms delay so no need for the 39u sec
    /*Display on off control: display enable, disable cursor, no blinking cursor*/
    CLCD_voidSendCommand(0b00001100);
    // SendCommand contain 2ms delay so no need for the 39u sec
    /*Clear Display*/
    CLCD_voidSendCommand(1);
    // SendCommand contain 2ms delay so no need for the 1.53ms
}

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
    /*Set RS pin to low command*/
    DIO_u8SetPinValue(CLCD_CONTROL_PORT, CLCD_CONTROL_RS_PIN, DIO_enumPIN_LOW);
    /*Set RW pin to low for write*/
    DIO_u8SetPinValue(CLCD_CONTROL_PORT, CLCD_CONTROL_RW_PIN, DIO_enumPIN_LOW);
    /*Set command to data pins*/
    DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Command);
    /*Send Enable pulse*/
    DIO_u8SetPinValue(CLCD_CONTROL_PORT, CLCD_CONTROL_E_PIN, DIO_enumPIN_HIGH);
    _delay_ms(2);
    DIO_u8SetPinValue(CLCD_CONTROL_PORT, CLCD_CONTROL_E_PIN, DIO_enumPIN_LOW);
}
void CLCD_voidSendData(u8 Copy_u8Data)
{
    /*Set RS pin to high command*/
    DIO_u8SetPinValue(CLCD_CONTROL_PORT, CLCD_CONTROL_RS_PIN, DIO_enumPIN_HIGH);
    /*Set RW pin to low for write*/
    DIO_u8SetPinValue(CLCD_CONTROL_PORT, CLCD_CONTROL_RW_PIN, DIO_enumPIN_LOW);
    /*Set data to data pins*/
    DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Data);
    /*Send Enable pulse*/
    DIO_u8SetPinValue(CLCD_CONTROL_PORT, CLCD_CONTROL_E_PIN, DIO_enumPIN_HIGH);
    _delay_ms(2);
    DIO_u8SetPinValue(CLCD_CONTROL_PORT, CLCD_CONTROL_E_PIN, DIO_enumPIN_LOW);
}

void CLCD_voidSendString(const u8 *Copy_pu8String)
{
    u8 Local_u8Counter = 0;
    while (Copy_pu8String[Local_u8Counter] != '\0')
    {
        CLCD_voidSendData(Copy_pu8String[Local_u8Counter]);
        Local_u8Counter++;
    }
}

void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
    u8 Local_u8Address;
    if (Copy_u8XPos == 0)
    {
        /*Location at first line*/
        Local_u8Address = Copy_u8YPos;
    }
    else if (Copy_u8XPos == 1)
    {
        /*Location at second line*/
        Local_u8Address = Copy_u8YPos + 0x40;
    }
    /*Set bit number 7 to set DDRAM Address to write in specific location*/
    CLCD_voidSendCommand(Local_u8Address + 0b10000000);
}
void CLCD_voidClear(void)
{
    CLCD_voidSendCommand(0b00000001); // or (1)
}
void CLCD_voidWriteSpecialCharacter(u8 *Copy_pu8SpecialCharacter, u8 Copy_u8BlockNumber, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
    u8 Local_u8CGRAMAddress = 0, Local_u8Iterator;
    /* Calculate the CGRAM Address whose each block is 8 bytes */
    Local_u8CGRAMAddress = Copy_u8BlockNumber * 8;

    /* Send CG Ram address command to LCD, with setting 6 bits , clearing clearing bit 7 */
    CLCD_voidSendCommand(Local_u8CGRAMAddress + 64);

    /* Write the pattern into the CGRAM */
    for (Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
    {
        CLCD_voidSendData(Copy_pu8SpecialCharacter[Local_u8Iterator]);
    }

    CLCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos);

    CLCD_voidSendData(Copy_u8BlockNumber);
}
