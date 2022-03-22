/*
 * display.h
 *
 *  Created on: Mar 21, 2022
 *      Author: tiago
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "stm32f4xx_hal.h"



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

//DEFINE OUTPUT PINS HERE!
#define SEGA GPIO_PIN_0
#define SEGB 0
#define SEGC 0
#define SEGD 0
#define SEGE 0
#define SEGF 0
#define SEGG 0
#define SEGP 0 //PONTO .  (DP)
#define DISP0 0
#define DISP1 0
#define DISP2 0
#define DISP3 0

//"PUBLIC"

//coloca o valor no segmento ex: USR_DISPLAY_SetString('2' , '3' , 'a' , 'b') deve aparecer no display o valor 23ab
void USR_DISPLAY_SetString(char n1 , char n2 , char n3 , char n4);

//"PRIVATE"

//coloca o array no display, '11100001' -> ativa SEGA , SEGB , SEGC , PONTO
//ordem: A,B,C,D,E,F,G,P
void USR_DISPLAY_SetSegment(char* arr);

//ativa o segmento n, (0 à esquerda , 3 à direita)
void USR_DISPLAY_ActivateSeg(int n);
void USR_DISPLAY_DecodeChar(char value , char* s);




#endif /* DISPLAY_H_ */
