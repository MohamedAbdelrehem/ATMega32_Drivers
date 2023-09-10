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

#ifndef HAL_STEPPER_MOTOR_STEPPER_CONFIG_H_
#define HAL_STEPPER_MOTOR_STEPPER_CONFIG_H_

/*
 Options:-

     1-DIO_enumPORTA
     2-DIO_enumPORTB
     3-DIO_enumPORTC
     4-DIO_enumPORTD

 */

#define STEPPER_PORT DIO_enumPORTA

/*
 Options:-

     1-DIO_enumPIN0
     2-DIO_enumPIN1
     3-DIO_enumPIN2
     4-DIO_enumPIN3
     5-DIO_enumPIN4
     6-DIO_enumPIN5
     7-DIO_enumPIN6
     8-DIO_enumPIN7

 */

#define STEPPER_BLUE_PIN DIO_enumPIN0
#define STEPPER_PINK_PIN DIO_enumPIN1
#define STEPPER_YELLOW_PIN DIO_enumPIN2
#define STEPPER_ORANGE_PIN DIO_enumPIN3

#endif /* HAL_STEPPER_MOTOR_STEPPER_CONFIG_H_ */