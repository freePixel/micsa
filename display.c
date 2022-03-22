/*
 * display.c
 *
 *  Created on: Mar 21, 2022
 *      Author: tiago
 */

#include "display.h"
#include <stdlib.h>
#include <string.h>

void USR_DISPLAY_SetString(char n1 , char n2 , char n3 , char n4)
{
	//allocate space
	char* _n1 = (char*)malloc(8);
	char* _n2 = (char*)malloc(8);
	char* _n3 = (char*)malloc(8);
	char* _n4 = (char*)malloc(8);

	//decode value into display-segment data
	USR_DISPLAY_DecodeChar(n1 , _n1);
	USR_DISPLAY_DecodeChar(n2 , _n2);
	USR_DISPLAY_DecodeChar(n3 , _n3);
	USR_DISPLAY_DecodeChar(n4 , _n4);

	USR_DISPLAY_ActivateSeg(0);
	USR_DISPLAY_SetSegment(_n1);

	USR_DISPLAY_ActivateSeg(1);
	USR_DISPLAY_SetSegment(_n2);

	USR_DISPLAY_ActivateSeg(2);
	USR_DISPLAY_SetSegment(_n3);

	USR_DISPLAY_ActivateSeg(3);
	USR_DISPLAY_SetSegment(_n4);

	//free memory
	free(_n1);
	free(_n2);
	free(_n3);
	free(_n4);
}

 void USR_DISPLAY_DecodeChar(char value , char* data) //write into data pointer decoded value
{
	switch(value)
	{
	case '0':
		strcpy(data , "11111100");
		break;
	case '1':
		strcpy(data , "01100000");
		break;
	case '2':
		strcpy(data , "11011010");
		break;
	case '3':
		strcpy(data , "11110010");
		break;
	case '4':
		strcpy(data , "01100110");
		break;
	case '5':
		strcpy(data , "10110110");
		break;
	case '6':
		strcpy(data , "10111110");
		break;
	case '7':
		strcpy(data , "11100000");
		break;
	case '8':
		strcpy(data , "11111110");
		break;
	case '9':
		strcpy(data , "11110110");
		break;

	}
}

 void USR_DISPLAY_SetSegment(char* arr)
{
	HAL_GPIO_WritePin(GPIOA , SEGA , (int)(arr[0] - 48));
	HAL_GPIO_WritePin(GPIOA , SEGB , (int)(arr[1] - 48));
	HAL_GPIO_WritePin(GPIOA , SEGC , (int)(arr[2] - 48));
	HAL_GPIO_WritePin(GPIOA , SEGD , (int)(arr[3] - 48));
	HAL_GPIO_WritePin(GPIOA , SEGE , (int)(arr[4] - 48));
	HAL_GPIO_WritePin(GPIOA , SEGF , (int)(arr[5] - 48));
	HAL_GPIO_WritePin(GPIOA , SEGG , (int)(arr[6] - 48));
	HAL_GPIO_WritePin(GPIOA , SEGP , (int)(arr[7] - 48));
}

 void USR_DISPLAY_ActivateSeg(int n)
{
	int _free[4] = {0,0,0,0};
	_free[n] = 1;
	HAL_GPIO_WritePin(GPIOA , DISP0 , _free[0]);
	HAL_GPIO_WritePin(GPIOA , DISP1 , _free[1]);
	HAL_GPIO_WritePin(GPIOA , DISP2 , _free[2]);
	HAL_GPIO_WritePin(GPIOA , DISP3 , _free[3]);

}
