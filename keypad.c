/*
 * keypad.c
 *
 *  Created on: 22/03/2022
 *      Author: tiago
 */


#include "keypad.h"
#include <stdlib.h>
#include <string.h>


void USR_KEYPAD_GetInput(char* data)
{
	data[0] = (char)(HAL_GPIO_ReadPin(GPIOA , ROW1) + 48);
	data[1] = (char)(HAL_GPIO_ReadPin(GPIOA , ROW2) + 48);
	data[2] = (char)(HAL_GPIO_ReadPin(GPIOA , ROW3) + 48);
	data[3] = (char)(HAL_GPIO_ReadPin(GPIOA , ROW4) + 48);
	data[4] = (char)(HAL_GPIO_ReadPin(GPIOA , COL1) + 48);
	data[5] = (char)(HAL_GPIO_ReadPin(GPIOA , COL2) + 48);
	data[6] = (char)(HAL_GPIO_ReadPin(GPIOA , COL3) + 48);
}




static int tones[] = {697,770,852,941,1209,1336,1477};

int USR_KEYPAD_GetFrequency()
{
	char* arr = malloc(7);
	int out_freq = 0;
	USR_KEYPAD_GetInput(arr);

	for(int i=0;i<4;i++)
	{
		for(int j=0;i<3;j++)
		{
			if(arr[i] == '1' && arr[4 + j] == '1')
				out_freq += tones[i] + tones[4+j];

		}
	}

	free(arr);

	return out_freq;
}
