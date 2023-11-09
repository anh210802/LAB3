/*
 * led_status.c
 *
 *  Created on: Nov 5, 2023
 *      Author: anhxa
 */

#include "led_status.h"

void clearAllLed(){
	HAL_GPIO_WritePin(LED0_RED_GPIO_Port, LED0_RED_Pin, SET);
	HAL_GPIO_WritePin(LED0_AMBER_GPIO_Port, LED0_AMBER_Pin, SET);
	HAL_GPIO_WritePin(LED0_GREEN_GPIO_Port, LED0_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, SET);
	HAL_GPIO_WritePin(LED1_AMBER_GPIO_Port, LED1_AMBER_Pin, SET);
	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, SET);
}
void red_green(){
	HAL_GPIO_WritePin(LED0_RED_GPIO_Port, LED0_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED0_AMBER_GPIO_Port, LED0_AMBER_Pin, SET);
	HAL_GPIO_WritePin(LED0_GREEN_GPIO_Port, LED0_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, SET);
	HAL_GPIO_WritePin(LED1_AMBER_GPIO_Port, LED1_AMBER_Pin, SET);
	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, RESET);
}
void red_amber(){
	HAL_GPIO_WritePin(LED0_RED_GPIO_Port, LED0_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED0_AMBER_GPIO_Port, LED0_AMBER_Pin, SET);
	HAL_GPIO_WritePin(LED0_GREEN_GPIO_Port, LED0_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, SET);
	HAL_GPIO_WritePin(LED1_AMBER_GPIO_Port, LED1_AMBER_Pin, RESET);
	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, SET);
}
void green_red(){
	HAL_GPIO_WritePin(LED0_RED_GPIO_Port, LED0_RED_Pin, SET);
	HAL_GPIO_WritePin(LED0_AMBER_GPIO_Port, LED0_AMBER_Pin, SET);
	HAL_GPIO_WritePin(LED0_GREEN_GPIO_Port, LED0_GREEN_Pin, RESET);
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED1_AMBER_GPIO_Port, LED1_AMBER_Pin, SET);
	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, SET);
}
void amber_red(){
	HAL_GPIO_WritePin(LED0_RED_GPIO_Port, LED0_RED_Pin, SET);
	HAL_GPIO_WritePin(LED0_AMBER_GPIO_Port, LED0_AMBER_Pin, RESET);
	HAL_GPIO_WritePin(LED0_GREEN_GPIO_Port, LED0_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED1_AMBER_GPIO_Port, LED1_AMBER_Pin, SET);
	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, SET);
}

void man_red(){
	HAL_GPIO_TogglePin(LED0_RED_GPIO_Port, LED0_RED_Pin);
	HAL_GPIO_TogglePin(LED1_RED_GPIO_Port, LED1_RED_Pin);
}
void man_amber(){
	HAL_GPIO_TogglePin(LED0_AMBER_GPIO_Port, LED0_AMBER_Pin);
	HAL_GPIO_TogglePin(LED1_AMBER_GPIO_Port, LED1_AMBER_Pin);
}
void man_green(){
	HAL_GPIO_TogglePin(LED0_GREEN_GPIO_Port, LED0_GREEN_Pin);
	HAL_GPIO_TogglePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin);
}




