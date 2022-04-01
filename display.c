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

	HAL_Delay(1);


	USR_DISPLAY_ActivateSeg(1);
	USR_DISPLAY_SetSegment(_n2);

	HAL_Delay(1);
	USR_DISPLAY_ActivateSeg(2);
	USR_DISPLAY_SetSegment(_n3);

	HAL_Delay(1);

	USR_DISPLAY_ActivateSeg(3);
	USR_DISPLAY_SetSegment(_n4);

	HAL_Delay(1);

	//free memory
	free(_n1);
	free(_n2);
	free(_n3);
	free(_n4);


}
/*	ASSUMINDO QUE OS SEGMENTOS ESTÃO NO SEGUINTE FORMATO
 *
 *
 *
 *   AAAAAAA
 *  F       B
 *  F       B
 *   GGGGGGG
 *  E		C
 *  E		C
 *   DDDDDDD  .DP
 *
 *   DISPLAY 0              DISPLAY 1  ...
 *
 */
 void USR_DISPLAY_DecodeChar(char value , char* data) //write into data pointer decoded value
{
	switch(value)
	{
	case '0':
		strcpy(data , "00000011");
		break;
	case '1':
		strcpy(data , "10011111");
		break;
	case '2':
		strcpy(data , "00100101");
		break;
	case '3':
		strcpy(data , "00001101");
		break;
	case '4':
		strcpy(data , "10011001");
		break;
	case '5':
		strcpy(data , "01001001");
		break;
	case '6':
		strcpy(data , "01000001");
		break;
	case '7':
		strcpy(data , "00011111");
		break;
	case '8':
		strcpy(data , "00000001");
		break;
	case '9':
		strcpy(data , "00001001");
		break;

	case 'x':
		strcpy(data , "11111111");
		break;

	case '-':
		strcpy(data , "11111101");
		break;

	}
}

 void USR_DISPLAY_SetSegment(char* arr)
{
	HAL_GPIO_WritePin(SEGA_GPIO_Port , SEGA_Pin , (int)(arr[0] - 48));
	HAL_GPIO_WritePin(SEGB_GPIO_Port , SEGB_Pin , (int)(arr[1] - 48));
	HAL_GPIO_WritePin(SEGC_GPIO_Port , SEGC_Pin , (int)(arr[2] - 48));
	HAL_GPIO_WritePin(SEGD_GPIO_Port , SEGD_Pin , (int)(arr[3] - 48));
	HAL_GPIO_WritePin(SEGE_GPIO_Port , SEGE_Pin , (int)(arr[4] - 48));
	HAL_GPIO_WritePin(SEGF_GPIO_Port , SEGF_Pin , (int)(arr[5] - 48));
	HAL_GPIO_WritePin(SEGG_GPIO_Port , SEGG_Pin , (int)(arr[6] - 48));
	HAL_GPIO_WritePin(SEGP_GPIO_Port , SEGP_Pin , (int)(arr[7] - 48));
}

 void USR_DISPLAY_ActivateSeg(int n)
{
	int _free[4] = {0,0,0,0};
	_free[n] = 1;
	HAL_GPIO_WritePin(D0_GPIO_Port , D0_Pin , _free[0]);
	HAL_GPIO_WritePin(D1_GPIO_Port , D1_Pin , _free[1]);
	HAL_GPIO_WritePin(D2_GPIO_Port , D2_Pin , _free[2]);
	HAL_GPIO_WritePin(D3_GPIO_Port , D3_Pin , _free[3]);

}
