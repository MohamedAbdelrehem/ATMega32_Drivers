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
	//Interrupt 0
    /* Set sense mode */
	#if(INT0_SENSE_MODE == EXTI_enumLowLevel)
        CLR_BIT(MCUCR, MCUCR_ISC00);
        CLR_BIT(MCUCR, MCUCR_ISC01);



    #elif (INT0_SENSE_MODE == EXTI_enumAnyChange) //TOGGLE
        SET_BIT(MCUCR, MCUCR_ISC00);
        CLR_BIT(MCUCR, MCUCR_ISC01);


    #elif (INT0_SENSE_MODE == EXTI_enumFallingEdge)
        CLR_BIT(MCUCR, MCUCR_ISC00);
        SET_BIT(MCUCR, MCUCR_ISC01);
    #elif (INT0_SENSE_MODE == EXTI_enumRisingEdge)
        SET_BIT(MCUCR, MCUCR_ISC00);
        SET_BIT(MCUCR, MCUCR_ISC01);
	#elif (INT0_SENSE_MODE == EXTI_enumOFF)
        do nothing
	#else
		#error "INT0 SENSE MODE ERROR"
    #endif

	//Interrupt 1
    /* Set sense mode */
    #if (INT1_SENSE_MODE == EXTI_enumLowLevel)
        CLR_BIT(MCUCR, MCUCR_ISC10);
        CLR_BIT(MCUCR, MCUCR_ISC11);

    #elif (INT1_SENSE_MODE == EXTI_enumAnyChange) //TOGGLE
        SET_BIT(MCUCR, MCUCR_ISC10);
        CLR_BIT(MCUCR, MCUCR_ISC11);

    #elif (INT1_SENSE_MODE == EXTI_enumFallingEdge)
        CLR_BIT(MCUCR, MCUCR_ISC10);
        SET_BIT(MCUCR, MCUCR_ISC11);

    #elif (INT1_SENSE_MODE == EXTI_enumRisingEdge)
        SET_BIT(MCUCR, MCUCR_ISC10);
        SET_BIT(MCUCR, MCUCR_ISC11);

	#elif (INT1_SENSE_MODE == EXTI_enumOFF)
			//do nothing
	#else
		#error "INT1 SENSE MODE ERROR"
    #endif


    //Interrupt 2
    /* Set sense mode */
    #if (INT2_SENSE_MODE == EXTI_enumFallingEdge)
        CLR_BIT(MCUCSR, MCUCSR_ISC2);

    #elif INT2_SENSE_MODE == EXTI_enumRisingEdge
        SET_BIT(MCUCSR, MCUCSR_ISC2);

	#elif (INT2_SENSE_MODE == EXTI_enumOFF)
        //do nothing

	#else
		#error "INT2 SENSE MODE ERROR"
    #endif
}

void EXTI_voidInterruptPinEnable(EXTI_IntereptPin Copy_enumIntereptPin){
	switch(Copy_enumIntereptPin){
	case EXTI_enumINT0:
        /* Enable INT0 General Interrupt Control Register */
        SET_BIT(GICR, GICR_INT0);
        break;
	case EXTI_enumINT1:
        /* Enable INT1 General Interrupt Control Register */
        SET_BIT(GICR, GICR_INT1);
        break;
	case EXTI_enumINT2:
        /* Enable INT2 General Interrupt Control Register */
        SET_BIT(GICR, GICR_INT2);
        break;
	default :
		break;
	}
}

void EXTI_voidInterruptPinDisable(EXTI_IntereptPin Copy_enumIntereptPin){
	switch(Copy_enumIntereptPin){
	case EXTI_enumINT0:
        /* Enable INT0 General Interrupt Control Register */
        CLR_BIT(GICR, GICR_INT0);
        break;
	case EXTI_enumINT1:
        /* Enable INT1 General Interrupt Control Register */
		CLR_BIT(GICR, GICR_INT1);
        break;
	case EXTI_enumINT2:
        /* Enable INT2 General Interrupt Control Register */
		CLR_BIT(GICR, GICR_INT2);
        break;
	default :
		break;
	}
}

u8 EXTI_u8InterruptFlagValue(EXTI_IntereptPin Copy_enumIntereptPin){

			switch(Copy_enumIntereptPin){
			case EXTI_enumINT0:
		        /* Enable GIFR */
				return GET_BIT(GIFR,GIFR_INTF0);
		        break;
			case EXTI_enumINT1:
		        /* Enable GIFR */
				return SET_BIT(GIFR, GIFR_INTF1);
		        break;
			case EXTI_enumINT2:
		        /* Enable GIFR */
				return SET_BIT(GIFR, GIFR_INTF2);
		        break;
			default :
				break;
			}
			return 2;
}

