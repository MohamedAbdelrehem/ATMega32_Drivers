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
/************************         Version:1.00                       *************************/
/*********************************************************************************************/
/*********************************************************************************************/

/*Preprocessor file guard*/
#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

#define CLCD_DATA_PORT DIO_enumPORTD
#define CLCD_CONTROL_PORT DIO_enumPORTC
#define CLCD_CONTROL_RS_PIN DIO_enumPIN5
#define CLCD_CONTROL_RW_PIN DIO_enumPIN6
#define CLCD_CONTROL_E_PIN DIO_enumPIN7

#endif
