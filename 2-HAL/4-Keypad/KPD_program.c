/*********************************************************************************************/
/*********************************************************************************************/
/**   __  __     _                      _     _   _        _     _         _                **/
/**  |  \/  |___| |_  __ _ _ __  ___ __| |   /_\ | |__  __| |___| |_ _ ___| |_  ___ _ __    **/
/**  | |\/| / _ \ ' \/ _` | '  \/ -_) _` |  / _ \| '_ \/ _` / -_) | '_/ -_) ' \/ -_) '  \   **/
/**  |_|  |_\___/_||_\__,_|_|_|_\___\__,_| /_/ \_\_.__/\__,_\___|_|_| \___|_||_\___|_|_|_|  **/
/*********************************************************************************************/
/************************         Author: Mohamed Abdelrehem         *************************/
/************************         Layer:  HAL                        *************************/
/************************         SWC:    KEYPAD                     *************************/
/************************         Version:1.00                       *************************/
/*********************************************************************************************/
/*********************************************************************************************/

#include "../../4-LIB/STD_TYPES.h"

#include "../../1-MCAL/1-DIO/DIO_interface.h"

#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_private.h"

void KPD_voidInit(void)
{

	/*set column pins as Output*/
	DIO_u8SetPinDirection(KPD_PORT,KPD_COLUMN0_PIN,DIO_enumPIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_COLUMN1_PIN,DIO_enumPIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_COLUMN2_PIN,DIO_enumPIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_COLUMN3_PIN,DIO_enumPIN_OUTPUT);
	/*set column pins High*/
    DIO_u8SetPinValue(KPD_PORT, KPD_COLUMN0_PIN, DIO_enumPIN_HIGH);
    DIO_u8SetPinValue(KPD_PORT, KPD_COLUMN1_PIN, DIO_enumPIN_HIGH);
    DIO_u8SetPinValue(KPD_PORT, KPD_COLUMN2_PIN, DIO_enumPIN_HIGH);
    DIO_u8SetPinValue(KPD_PORT, KPD_COLUMN3_PIN, DIO_enumPIN_HIGH);

	/*set Rows pins as Input*/
	DIO_u8SetPinDirection(KPD_PORT,KPD_ROW0_PIN,DIO_enumPIN_INPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_ROW1_PIN,DIO_enumPIN_INPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_ROW2_PIN,DIO_enumPIN_INPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_ROW3_PIN,DIO_enumPIN_INPUT);
	/*set pull-up resistors with high */
    DIO_u8SetPinValue(KPD_PORT, KPD_ROW0_PIN, DIO_enumPIN_HIGH);
    DIO_u8SetPinValue(KPD_PORT, KPD_ROW1_PIN, DIO_enumPIN_HIGH);
    DIO_u8SetPinValue(KPD_PORT, KPD_ROW2_PIN, DIO_enumPIN_HIGH);
    DIO_u8SetPinValue(KPD_PORT, KPD_ROW3_PIN, DIO_enumPIN_HIGH);
}
u8 KPD_u8GetPressedKey(void)
{
    u8 Local_u8PressedKey, Local_u8ColumnIndex, Local_u8RowIndex;
    KPD_States KPD_u8ButtonState=KPD_enumNOT_PRESSED;
    static u8 Local_u8KPDArr[KPD_ROW_SIZE][KPD_COLUMN_SIZE] = KPD_ButtonsArr;
    static u8 Local_u8KPDColumnArr[KPD_COLUMN_SIZE] = {KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN};
    static u8 Local_u8KPDRowArr[KPD_ROW_SIZE] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};
    for (Local_u8ColumnIndex = 0; Local_u8ColumnIndex < KPD_COLUMN_SIZE; Local_u8ColumnIndex++)
    {
        /* Activate current column */
        DIO_u8SetPinValue(KPD_PORT, Local_u8KPDColumnArr[Local_u8ColumnIndex], DIO_enumPIN_LOW);
        for (Local_u8RowIndex = 0; Local_u8RowIndex < KPD_ROW_SIZE; Local_u8RowIndex++)
        {
            // read the current row
            DIO_u8GetPinValue(KPD_PORT, Local_u8KPDRowArr[Local_u8RowIndex], &KPD_u8ButtonState);
            if (KPD_u8ButtonState == KPD_enumPRESSED)
            {
                Local_u8PressedKey = Local_u8KPDArr[Local_u8ColumnIndex][Local_u8RowIndex];
                /*Polling(busy waiting) until release*/
                while (KPD_u8ButtonState == KPD_enumPRESSED)
                {
                    DIO_u8GetPinValue(KPD_PORT, Local_u8KPDRowArr[Local_u8RowIndex], &KPD_u8ButtonState);
                }

                return Local_u8PressedKey;
            }
        }

        /*Deactivate current Column*/
        DIO_u8SetPinValue(KPD_PORT, Local_u8KPDColumnArr[Local_u8ColumnIndex], DIO_enumPIN_HIGH);
    }

    return KPD_enumNOT_PRESSED;
}
