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

#include <util/delay.h>

#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"

#include "../../1-MCAL/1-DIO/DIO_interface.h"

#include "STEPPER_interface.h"
#include "STEPPER_private.h"
#include "STEPPER_config.h"

void STEPPER_voidInit(STEPPER_str *Copy_strStepper)
{
	DIO_u8SetPinDirection(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_OUTPUT);
	DIO_u8SetPinDirection(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_OUTPUT);
	DIO_u8SetPinDirection(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_OUTPUT);
	DIO_u8SetPinDirection(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_OUTPUT);

	DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
	DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
	DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
	DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
}

void STEPPER_voidOn(u8 Copy_u8Direction, u16 Copy_u16Speed, u16 Copy_u16Degree, STEPPER_str *Copy_strStepper)
{
	u32 Local_u32Iterator = 0;
	static u8 Local_u8location = 0;
	static u8 Local_u8Counter[4] = {0, 0, 0, 0};

	if (Copy_u8Direction == STEPPER_CLOCK_WISE)
	{

		while (1)
		{

			if (Copy_u16Degree == 0)
			{
				Local_u8location = 0;
				break;
			}

			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_HIGH);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
			_delay_ms(Copy_u16Speed);

			Local_u8Counter[Copy_strStepper->Strct_SteperNo]++;
			if (Copy_u16Degree == 45)
			{
				Local_u8location = 1;
				break;
			}

			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_HIGH);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_HIGH);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
			_delay_ms(Copy_u16Speed);

			Local_u8Counter[Copy_strStepper->Strct_SteperNo]++;
			if (Copy_u16Degree == 90)
			{
				Local_u8location = 2;
				break;
			}

			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_HIGH);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
			_delay_ms(Copy_u16Speed);

			Local_u8Counter[Copy_strStepper->Strct_SteperNo]++;
			if (Copy_u16Degree == 135)
			{
				Local_u8location = 3;
				break;
			}

			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_HIGH);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_HIGH);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
			_delay_ms(Copy_u16Speed);

			Local_u8Counter[Copy_strStepper->Strct_SteperNo]++;
			if (Copy_u16Degree == 180)
			{
				Local_u8location = 4;
				break;
			}

			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_HIGH);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
			_delay_ms(Copy_u16Speed);

			Local_u8Counter[Copy_strStepper->Strct_SteperNo]++;
			if (Copy_u16Degree == 225)
			{
				Local_u8location = 5;
				break;
			}

			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_HIGH);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_HIGH);
			_delay_ms(Copy_u16Speed);

			Local_u8Counter[Copy_strStepper->Strct_SteperNo]++;
			if (Copy_u16Degree == 270)
			{
				Local_u8location = 6;
				break;
			}

			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_HIGH);
			_delay_ms(Copy_u16Speed);

			Local_u8Counter[Copy_strStepper->Strct_SteperNo]++;
			if (Copy_u16Degree == 315)
			{
				Local_u8location = 7;
				break;
			}

			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_HIGH);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
			DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_HIGH);
			_delay_ms(Copy_u16Speed);

			Local_u8Counter[Copy_strStepper->Strct_SteperNo]++;
			if (Copy_u16Degree == 315)
			{
				Local_u8location = 8;
				break;
			}
		}
	}

	else if (Copy_u8Direction == STEPPER_ANTI_CLOCK_WISE)
	{

		if (Local_u8Counter[Copy_strStepper->Strct_SteperNo] == 8)
		{
			goto pos0;
		}
		else if (Local_u8Counter[Copy_strStepper->Strct_SteperNo] == 7)
		{
			goto pos1;
		}
		else if (Local_u8Counter[Copy_strStepper->Strct_SteperNo] == 6)
		{
			goto pos2;
		}
		else if (Local_u8Counter[Copy_strStepper->Strct_SteperNo] == 5)
		{
			goto pos3;
		}
		else if (Local_u8Counter[Copy_strStepper->Strct_SteperNo] == 4)
		{
			goto pos4;
		}
		else if (Local_u8Counter[Copy_strStepper->Strct_SteperNo] == 3)
		{
			goto pos5;
		}
		else if (Local_u8Counter[Copy_strStepper->Strct_SteperNo] == 2)
		{
			goto pos6;
		}
		else if (Local_u8Counter[Copy_strStepper->Strct_SteperNo] == 1)
		{
			goto pos7;
		}
		else if (Local_u8Counter[Copy_strStepper->Strct_SteperNo] == 0)
		{
			goto pos8;
		}

	pos0:
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_HIGH);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_HIGH);
		_delay_ms(Copy_u16Speed);
		Local_u8Counter[Copy_strStepper->Strct_SteperNo]--;
		//			if(Copy_u16Degree==45)break;
	pos1:
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_HIGH);
		_delay_ms(Copy_u16Speed);
		Local_u8Counter[Copy_strStepper->Strct_SteperNo]--;
		//			if(Copy_u16Degree==90)break;
	pos2:
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_HIGH);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_HIGH);
		_delay_ms(Copy_u16Speed);
		Local_u8Counter[Copy_strStepper->Strct_SteperNo]--;
		//			if(Copy_u16Degree==135)break;
	pos3:
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_HIGH);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
		_delay_ms(Copy_u16Speed);
		Local_u8Counter[Copy_strStepper->Strct_SteperNo]--;
		//			if(Copy_u16Degree==180)break;
	pos4:
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_HIGH);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_HIGH);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
		_delay_ms(Copy_u16Speed);
		Local_u8Counter[Copy_strStepper->Strct_SteperNo]--;
		//			if(Copy_u16Degree==225)break;
	pos5:
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_HIGH);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
		_delay_ms(Copy_u16Speed);
		Local_u8Counter[Copy_strStepper->Strct_SteperNo]--;
		//			if(Copy_u16Degree==270)break;
	pos6:
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_HIGH);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_HIGH);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
		_delay_ms(Copy_u16Speed);
		Local_u8Counter[Copy_strStepper->Strct_SteperNo]--;
		//			if(Copy_u16Degree==315)break;
	pos7:
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_HIGH);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
		_delay_ms(Copy_u16Speed);
		Local_u8Counter[Copy_strStepper->Strct_SteperNo]--;
	pos8:
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_HIGH);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
		DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_HIGH);
		_delay_ms(Copy_u16Speed);
		Local_u8Counter[Copy_strStepper->Strct_SteperNo]--;
	}
}

void STEPPER_voidOff(STEPPER_str *Copy_strStepper)
{

	DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
	DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
	DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
	DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
}

// void STEPPER_voidOn(u8 Copy_u8StepType, u8 Copy_u8Direction, u8 Copy_u16Speed, u16 Copy_u16Degree, STEPPER_str *Copy_strStepper)
//{
//
//	u32 Local_u32Iterator = 0;
//	u32 local_u32counter =  (((u32)Copy_u16Degree * 256) / 45) / 4;
//	if (Copy_u8StepType == STEPPER_FULL_STEP)
//	{
//
//		if (Copy_u8Direction == STEPPER_CLOCK_WISE)
//		{
//
//			for (Local_u32Iterator = 0; Local_u32Iterator < local_u32counter; Local_u32Iterator++)
//			{
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_HIGH);
//				_delay_ms(Copy_u16Speed);
//			}
//		}
//		else if (Copy_u8Direction == STEPPER_ANTI_CLOCK_WISE)
//		{
//
//			for (Local_u32Iterator = 0; Local_u32Iterator < (((u32)Copy_u16Degree * 256) / 45) / 4; Local_u32Iterator++)
//			{
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_HIGH);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
//				_delay_ms(Copy_u16Speed);
//			}
//		}
//	}
//	else if (Copy_u8StepType == STEPPER_HALF_STEP)
//	{
//
//		if (Copy_u8Direction == STEPPER_CLOCK_WISE)
//		{
//
//			for (Local_u32Iterator = 0; Local_u32Iterator < (((u32)Copy_u16Degree * 512) / 45) / 8; Local_u32Iterator++)
//			{
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_HIGH);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_HIGH);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_HIGH);
//				_delay_ms(Copy_u16Speed);
//			}
//		}
//		else if (Copy_u8Direction == STEPPER_ANTI_CLOCK_WISE)
//		{
//
//			for (Local_u32Iterator = 0; Local_u32Iterator < (((u32)Copy_u16Degree * 512) / 45) / 8; Local_u32Iterator++)
//			{
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_HIGH);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_HIGH);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_HIGH);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
//				_delay_ms(Copy_u16Speed);
//
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumBlue_Pin, DIO_enumPIN_HIGH);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumPink_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumYellow_Pin, DIO_enumPIN_LOW);
//				DIO_u8SetPinValue(Copy_strStepper->Strct_enumPort, Copy_strStepper->Strct_enumOrange_Pin, DIO_enumPIN_LOW);
//				_delay_ms(Copy_u16Speed);
//			}
//		}
//	}
// }
