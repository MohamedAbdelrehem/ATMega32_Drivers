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
// /************************         Version:1.10                       *************************/
// /*********************************************************************************************/
// /*********************************************************************************************/

/* File guard */
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#ifndef STD_TYPES_H_
#include "../../4-LIB/STD_TYPES.h"
#endif

/*
 * Description: This function is used to initialize the external interrupt (INT0, INT1, INT2)
 * Inputs: void
 * Output: void
 */
void EXTI_voidInterruptInit(void);
/*
 * Description: This function is used to enable the external interrupt (INT0, INT1, INT2)
 * Inputs: Copy_enumIntereptPin -> The interrupt pin to be enabled
 * 		   Either: EXTI_enumINT0, EXTI_enumINT1, EXTI_enumINT2
 * Output: void
 */
void EXTI_voidInterruptPinEnable(EXTI_IntereptPin Copy_enumIntereptPin);
/*
 * Description: This function is used to disable the external interrupt (INT0, INT1, INT2)
 * Inputs: Copy_enumIntereptPin -> The interrupt pin to be disabled
 * 		   Either: EXTI_enumINT0, EXTI_enumINT1, EXTI_enumINT2
 * Output: void
 */
void EXTI_voidInterruptPinDisable(EXTI_IntereptPin Copy_enumIntereptPin);
/*
 * Description: This function Returns the interrupt flag value of the selected interrupt pin
 * Inputs: Copy_enumIntereptPin -> The interrupt pin to be disabled
 * 		   Either: EXTI_enumINT0, EXTI_enumINT1, EXTI_enumINT2
 * Output: u8 -> The interrupt flag value
 * 		   Either: 0 -> Interrupt flag is not set
 * 		   		   1 -> Interrupt flag is set
 */
u8 EXTI_u8InterruptFlagValue(EXTI_IntereptPin Copy_enumIntereptPin);

#endif /* EXTI_INTERFACE_H_ */
