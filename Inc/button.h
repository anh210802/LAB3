/*
 * button.h
 *
 *  Created on: Nov 5, 2023
 *      Author: anhxa
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE 	SET
#define PRESSED_STATE 	RESET

#define TIMER_LONG_PRESS_1	200
#define TIMER_LONG_PRESS_2	200
#define TIMER_LONG_PRESS_3	200

int isButton1Pressed();
int isButton1LongPressed();

int isButton2Pressed();
int isButton2LongPressed();

int isButton3Pressed();
int isButton3LongPressed();

void getKeyInput();
#endif /* INC_BUTTON_H_ */
