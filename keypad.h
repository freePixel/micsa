/*
 * keypad.h
 *
 *  Created on: Mar 22, 2022
 *      Author: tiago
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "stm32f4xx_hal.h"




//DEFINIR PINOS AQUI!

#define ROW1 0 //EG GPIO_PIN_0
#define ROW2 0
#define ROW3 0
#define ROW4 0

#define COL1 0
#define COL2 0
#define COL3 0



void USR_KEYPAD_GetInput(char* data);/*

Load keypad data into data array, format: ROW1 , ROW2 , ROW3 , ROW4 , COL1 , COL2 , COL3
*/


int USR_KEYPAD_GetFrequency(); //return current tone frequency



#endif
