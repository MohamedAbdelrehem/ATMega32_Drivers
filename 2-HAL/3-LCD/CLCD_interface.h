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
/************************         Version:1.10                       *************************/
/*********************************************************************************************/
/*********************************************************************************************/

/*Preprocessor file guard*/
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#ifndef STD_TYPES_H_
#include "../../4-LIB/STD_TYPES.h"
#endif

void CLCD_voidInit(void);

void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendData(u8 Copy_u8Data);

// const bec what he will pass will not be changed
void CLCD_voidSendString(const u8 *Copy_pu8String);

void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);
void CLCD_voidClear(void);

// void CLCD_voidWriteSpecialCharacter(u8 *Copy_pu8SpecialCharacter, u8 Copy_u8BlockNumber);
#endif
