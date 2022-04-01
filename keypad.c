/*
 * keypad.c
 *
 *  Created on: 22/03/2022
 *      Author: tiago
 */


#include "keypad.h"
#include <stdlib.h>
#include <string.h>


char USR_KEYPAD_GetInput()
{
	/*	LINHA 1 DO TECLADO NÃO FUNCIONA!
		USR_KEYPAD_ActivateRow(0);
		HAL_Delay(10);
		if(HAL_GPIO_ReadPin(COL1_GPIO_Port , COL1_Pin)) return '1';
		if(HAL_GPIO_ReadPin(COL2_GPIO_Port , COL2_Pin)) return '2';
		if(HAL_GPIO_ReadPin(COL3_GPIO_Port , COL3_Pin)) return '3';
*/


		USR_KEYPAD_ActivateRow(1);
		HAL_Delay(1);
		if(HAL_GPIO_ReadPin(COL1_GPIO_Port , COL1_Pin)) return '4';
		if(HAL_GPIO_ReadPin(COL2_GPIO_Port , COL2_Pin)) return '5';
		if(HAL_GPIO_ReadPin(COL3_GPIO_Port , COL3_Pin)) return '6';

		USR_KEYPAD_ActivateRow(2);
		HAL_Delay(1);
		if(HAL_GPIO_ReadPin(COL1_GPIO_Port , COL1_Pin)) return '7';
		if(HAL_GPIO_ReadPin(COL2_GPIO_Port , COL2_Pin)) return '8';
		if(HAL_GPIO_ReadPin(COL3_GPIO_Port , COL3_Pin)) return '9';


		USR_KEYPAD_ActivateRow(3);
		HAL_Delay(1);
		if(HAL_GPIO_ReadPin(COL1_GPIO_Port , COL1_Pin)) return '*';
		if(HAL_GPIO_ReadPin(COL2_GPIO_Port , COL2_Pin)) return '0';
		if(HAL_GPIO_ReadPin(COL3_GPIO_Port , COL3_Pin)) return '#';



		return 0;

}


void USR_KEYPAD_ActivateRow(int n)
{
	HAL_Delay(1);
	int _free[4] = {0,0,0,0};
	_free[n] = 1;
	HAL_GPIO_WritePin(ROW1_GPIO_Port , ROW1_Pin , _free[0]);
	HAL_GPIO_WritePin(ROW2_GPIO_Port , ROW2_Pin , _free[1]);
	HAL_GPIO_WritePin(ROW3_GPIO_Port , ROW3_Pin , _free[2]);
	HAL_GPIO_WritePin(ROW4_GPIO_Port , ROW4_Pin , _free[3]);


}


int USR_KEYPAD_GetFrequency()
{

	char s  = USR_KEYPAD_GetInput();
	switch(s)
	{
	case '1':
		return 44;
		break;
	case '2':
		return 80;
		break;
	case '3':
		return 75;
		break;
	case '4':
		return 47;
		break;
	case '5':
		return 84;
		break;
	case '6':
		return 20;
		break;

	case '7':
		return 28;
		break;

	case '8':
		return 83;
		break;

	case '9':
		return 70;
		break;
	case '0':
		return 263;
		break;
	case '*':
		return 240;
		break;
	case '#':
		return 30;
		break;
	}
	return 1;
}
