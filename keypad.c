/*
 * keypad.c
 *
 *  Created on: 22/03/2022
 *      Author: tiago
 */


#include "keypad.h"
#include <stdlib.h>
#include <string.h>


void USR_KEYPAD_GetInput(GPIO_PinState* data)
{
	*data = 	(HAL_GPIO_ReadPin(ROW1_GPIO_Port,  ROW1_Pin));
	*(data+1) = (HAL_GPIO_ReadPin(ROW2_GPIO_Port , ROW2_Pin));
	*(data+2) = (HAL_GPIO_ReadPin(ROW3_GPIO_Port , ROW3_Pin));
	*(data+3) = (HAL_GPIO_ReadPin(ROW4_GPIO_Port , ROW4_Pin));
	*(data+4) = (HAL_GPIO_ReadPin(COL1_GPIO_Port , COL1_Pin));
	*(data+5) = (HAL_GPIO_ReadPin(COL2_GPIO_Port , COL2_Pin));
	*(data+6) = (HAL_GPIO_ReadPin(COL3_GPIO_Port , COL3_Pin));
}




static int tones[] = {697,770,852,941,1209,1336,1477};

int USR_KEYPAD_GetFrequency()
{
	GPIO_PinState* arr = malloc(7);
	int out_freq = 0;
	USR_KEYPAD_GetInput(arr);

	for(int i=0;i<4;i++)
	{
		if(arr[i] == GPIO_PIN_RESET)
			out_freq += 1;
	}

	free(arr);

	return out_freq;
}
