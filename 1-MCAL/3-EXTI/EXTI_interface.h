// /*********************************************************************************************/
// /*********************************************************************************************/
// /**   __  __     _                      _     _   _        _     _         _                **/
// /**  |  \/  |___| |_  __ _ _ __  ___ __| |   /_\ | |__  __| |___| |_ _ ___| |_  ___ _ __    **/
// /**  | |\/| / _ \ ' \/ _` | '  \/ -_) _` |  / _ \| '_ \/ _` / -_) | '_/ -_) ' \/ -_) '  \   **/
// /**  |_|  |_\___/_||_\__,_|_|_|_\___\__,_| /_/ \_\_.__/\__,_\___|_|_| \___|_||_\___|_|_|_|  **/
// /*********************************************************************************************/
// /************************         Author: Mohamed Abdelrehem         *************************/
// /************************         Layer:  MCAL                       *************************/
// /************************         SWC:    EXTERNAL INTERUPT          *************************/
// /************************         Version:1.00                       *************************/
// /*********************************************************************************************/
// /*********************************************************************************************/

/* File guard */
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#ifndef STD_TYPES_H_
#include "../../4-LIB/STD_TYPES.h"
#endif

#define EXTI_enumOFF 0
#define EXTI_enumLowLevel 1
#define EXTI_enumFallingEdge 2
#define EXTI_enumRisingEdge 3
#define EXTI_enumAnyChange 4

typedef enum EXTI_IntereptPin
{
	EXTI_enumINT0,
	EXTI_enumINT1,
	EXTI_enumINT2
} EXTI_IntereptPin;

void EXTI_voidInterruptInit(void);
void EXTI_voidInterruptPinEnable(EXTI_IntereptPin Copy_enumIntereptPin);
void EXTI_voidInterruptPinDisable(EXTI_IntereptPin Copy_enumIntereptPin);
u8 EXTI_u8InterruptFlagValue(EXTI_IntereptPin Copy_enumIntereptPin);

#endif /* EXTI_INTERFACE_H_ */
