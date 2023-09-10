/*********************************************************************************************/
/*********************************************************************************************/
/**   __  __     _                      _     _   _        _     _         _                **/
/**  |  \/  |___| |_  __ _ _ __  ___ __| |   /_\ | |__  __| |___| |_ _ ___| |_  ___ _ __    **/
/**  | |\/| / _ \ ' \/ _` | '  \/ -_) _` |  / _ \| '_ \/ _` / -_) | '_/ -_) ' \/ -_) '  \   **/
/**  |_|  |_\___/_||_\__,_|_|_|_\___\__,_| /_/ \_\_.__/\__,_\___|_|_| \___|_||_\___|_|_|_|  **/
/*********************************************************************************************/
/************************         Author: Mohamed Abdelrehem         *************************/
/************************         Layer:  HAL                        *************************/
/************************         SWC:    STEPPER                    *************************/
/************************         Version:1.00                       *************************/
/*********************************************************************************************/
/*********************************************************************************************/

#ifndef HAL_STEPPER_MOTOR_STEPPER_INTERFACE_H_
#define HAL_STEPPER_MOTOR_STEPPER_INTERFACE_H_

#ifndef STD_TYPES_H_
#include "../../4-LIB/STD_TYPES.h"
#endif

#define STEPPER_FULL_STEP 1
#define STEPPER_HALF_STEP 0

#define STEPPER_CLOCK_WISE 1
#define STEPPER_ANTI_CLOCK_WISE 0

typedef enum
{
    STEPPER_enumLOW,
    STEPPER_enumHIGH
} STEPPER_Value;

// STEPPER Port

#define STEPPER_enumPORTA 0
#define STEPPER_enumPORTB 1
#define STEPPER_enumPORTC 2
#define STEPPER_enumPORTD 3

// STEPPER Pin

#define STEPPER_enumPIN0 0
#define STEPPER_enumPIN1 1
#define STEPPER_enumPIN2 2
#define STEPPER_enumPIN3 3
#define STEPPER_enumPIN4 4
#define STEPPER_enumPIN5 5
#define STEPPER_enumPIN6 6
#define STEPPER_enumPIN7 7

// Sink/Source
typedef enum
{

    STEPPER_enumCON_SOURCE,
    STEPPER_enumCON_SINK
} STEPPER_ConnectionType;

typedef struct STEPPER_str
{
    // Port,Pin,Sink/Source
    u8 Strct_enumPort;
    u8 Strct_enumBlue_Pin;
    u8 Strct_enumPink_Pin;
    u8 Strct_enumYellow_Pin;
    u8 Strct_enumOrange_Pin;
    u8 Strct_SteperNo;
} STEPPER_str;

void STEPPER_voidInit(STEPPER_str *Copy_strStepper);
void STEPPER_voidOff(STEPPER_str *Copy_strStepper);
void STEPPER_voidOn(u8 Copy_u8Direction, u16 Copy_u16Speed, u16 Copy_u16Degree, STEPPER_str *Copy_strStepper);

#endif /* HAL_STEPPER_MOTOR_STEPPER_INTERFACE_H_ */
