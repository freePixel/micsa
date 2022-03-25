/*
 * keypad.h
 *
 *  Created on: Mar 22, 2022
 *      Author: tiago
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "stm32f4xx_hal.h"

#include "Inc/main.h"



//DEFINIR PINOS AQUI!





void USR_KEYPAD_GetInput(GPIO_PinState* data);/*

Load keypad data into data array, format: ROW1 , ROW2 , ROW3 , ROW4 , COL1 , COL2 , COL3
*/


int USR_KEYPAD_GetFrequency(); //return current tone frequency



#endif
