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
}
u8 KPD_u8GetPressedKey(void)
{
    // take alot
    u8 Local_u8PressedKey = KPD_NOT_PRESSED, Local_u8ColumnIndex, Local_u8RowIndex;
    KPD_States KPD_ButtonState;
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
            DIO_u8GetPinValue(KPD_PORT, Local_u8KPDRowArr[Local_u8RowIndex], &KPD_ButtonState);
            if (KPD_ButtonState == KPD_enumPRESSED)
            {
                Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];
                /*Polling(busy waiting) unitl relase*/
                while (KPD_ButtonState == KPD_enumPRESSED)
                {
                    DIO_u8GetPinValue(KPD_PORT, Local_u8KPDRowArr[Local_u8RowIndex], &KPD_ButtonState);
                }

                return Local_u8PressedKey
            }
        }

        /*Deactivate current Column*/
        DIO_u8SetPinValue(KPD_PORT, Local_u8KPDColumnArr[Local_u8ColumnIndex], DIO_enumPIN_HIGH);
    }

    return Local_u8PressedKey;
}
