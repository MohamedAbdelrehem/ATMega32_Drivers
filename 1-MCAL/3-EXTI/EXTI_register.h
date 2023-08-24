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

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define GICR *((volatile u8 *)0x5B) // General Interrupt Control Register ( for INT0 & INT1 & INT2  enable)
#define GICR_INT1 7
#define GICR_INT0 6
#define GICR_INT2 5

#define GIFR *((volatile u8 *)0x5A) // General Interrupt Flag Register  ( for INT0 & INT1 & INT2  check flag)

#define MCUCR *((volatile u8 *)0x55) // MCU Control Register            ( for INT0 & INT1 sence control)
#define MCUCR_ISC11 3
#define MCUCR_ISC10 2
#define MCUCR_ISC01 1
#define MCUCR_ISC00 0

#define MCUCSR *((volatile u8 *)0x54) // MCU Control and Status Register ( for INT2  sence control)
#define MCUCSR_ISC2 6

#endif /* EXTI_REGISTER_H_ */