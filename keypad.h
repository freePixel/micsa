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






void USR_KEYPAD_ActivateRow(int n);

char USR_KEYPAD_GetInput();/*

Load keypad data into data array, format: ROW1 , ROW2 , ROW3 , ROW4 , COL1 , COL2 , COL3
*/


int USR_KEYPAD_GetFrequency(); //return current tone frequency



#endif
