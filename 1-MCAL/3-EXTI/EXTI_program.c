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

#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

void EXTI_voidInterruptInit(void)
{
#if INT0_SENSE_MODE != EXTI_enumOFF
    /* Enable GIFR */
    SET_BIT(GICR, GICR_INT0);
/* Set sense mode */
#if INT0_SENSE_MODE == EXTI_enumLowLevel
    CLR_BIT(MCUCR, MCUCR_ISC00);
    CLR_BIT(MCUCR, MCUCR_ISC01);
#elif INT0_SENSE_MODE == EXTI_enumAnyChange // TOGGLE
    SET_BIT(MCUCR, MCUCR_ISC00);
    CLR_BIT(MCUCR, MCUCR_ISC01);
#elif INT0_SENSE_MODE == EXTI_enumFallingEdge
    CLR_BIT(MCUCR, MCUCR_ISC00);
    SET_BIT(MCUCR, MCUCR_ISC01);
#elif INT0_SENSE_MODE == EXTI_enumRisingEdge
    SET_BIT(MCUCR, MCUCR_ISC00);
    SET_BIT(MCUCR, MCUCR_ISC01);
#endif
#endif
#if INT1_SENSE_MODE != EXTI_enumOFF
    /* Enable GIFR */
    SET_BIT(GICR, GICR_INT1);
/* Set sense mode */
#if INT1_SENSE_MODE == EXTI_enumLowLevel
    CLR_BIT(MCUCR, MCUCR_ISC10);
    CLR_BIT(MCUCR, MCUCR_ISC11);
#elif INT1_SENSE_MODE == EXTI_enumAnyChange // TOGGLE
    SET_BIT(MCUCR, MCUCR_ISC10);
    CLR_BIT(MCUCR, MCUCR_ISC11);
#elif INT1_SENSE_MODE == EXTI_enumFallingEdge
    CLR_BIT(MCUCR, MCUCR_ISC10);
    SET_BIT(MCUCR, MCUCR_ISC11);
#elif INT1_SENSE_MODE == EXTI_enumRisingEdge
    SET_BIT(MCUCR, MCUCR_ISC10);
    SET_BIT(MCUCR, MCUCR_ISC11);
#endif
#endif
#if INT2_SENSE_MODE != EXTI_enumOFF
    /* Enable GIFR */
    SET_BIT(GICR, GICR_INT2);
/* Set sense mode */
#if INT2_SENSE_MODE == EXTI_enumFallingEdge
    CLR_BIT(MCUCSR, MCUCSR_ISC2);
#elif INT2_SENSE_MODE == EXTI_enumRisingEdge // TOGGLE
    SET_BIT(MCUCSR, MCUCSR_ISC2);
#endif
#endif
}
