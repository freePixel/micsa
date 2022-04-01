/*
 * display.h
 *
 *  Created on: Mar 21, 2022
 *      Author: tiago
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "stm32f4xx_hal.h"

#include "Inc/main.h"






//"PUBLIC"

//coloca o valor no segmento ex: USR_DISPLAY_SetString('2' , '3' , '1' , '5') deve aparecer no display o valor 2315
void USR_DISPLAY_SetString(char n1 , char n2 , char n3 , char n4);

//"PRIVATE"

//coloca o array no display, '11100001' -> ativa SEGA , SEGB , SEGC , PONTO
//ordem: A,B,C,D,E,F,G,P
void USR_DISPLAY_SetSegment(char* arr);

//ativa o segmento n, (0 à esquerda , 3 à direita)
void USR_DISPLAY_ActivateSeg(int n);


void USR_DISPLAY_DecodeChar(char value , char* s);




#endif /* DISPLAY_H_ */
