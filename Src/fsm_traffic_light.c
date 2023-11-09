/*
 * fsm_traffic_light.c
 *
 *  Created on: Nov 5, 2023
 *      Author: anhxa
 */

#include "fsm_traffic_light.h"

void fsm_traffic_light(){
	switch(fsm_status){
		case INIT:
			/* Finite state machines CODE BEGIN Init */
			clearAllLed();
			fsm_status = RED_GREEN;
			setTimer1(RED_GREEN_PREIOD + green_add); 	// Set timer for normal traffic light
			setTimer2(100); 							// Set timer for counter of led 7 segment
			setTimer3(TIMER_LED); 						// Set timer for blink with frequency 2Hz
			counter1_7_segment = (RED_GREEN_PREIOD + RED_AMBER_PREIOD + red_add) / FREQUENCY_SYSTEM; // Create timer of led 7 segment
			counter2_7_segment = (RED_GREEN_PREIOD + green_add) / FREQUENCY_SYSTEM; // Create timer of led 7 segment
			/* Finite state machines CODE END Init */
			break;
		case RED_GREEN:
			/* CODE BEGIN Status */
			//TODO
			red_green();
			led_7_segment();
			/* Change status of finite state machines */
			if(timer1_flag == 1){
				timer2_flag = 0;
				fsm_status = RED_AMBER;
				setTimer1(RED_AMBER_PREIOD + amber_add);
				setTimer2(100);
				counter1_7_segment = (RED_AMBER_PREIOD + amber_add) / FREQUENCY_SYSTEM;
				counter2_7_segment = (RED_AMBER_PREIOD + amber_add) / FREQUENCY_SYSTEM;
			}
			/*****************************/
			/* Count the time the light is on */
			if(timer2_flag == 1){
				counter1_7_segment--;
				counter2_7_segment--;
				setTimer2(100);
			}
			/*****************************/
			/* Change status to modify time status*/
			if(isButton1Pressed() == 1){
				clearAllLed();
				fsm_status = MAN_RED;
				timer1_flag = 0;
				timer2_flag = 0;
				counter1_7_segment = 1;
				counter2_7_segment = (RED_GREEN_PREIOD + RED_AMBER_PREIOD + red_add) / FREQUENCY_SYSTEM;

			}
			/*****************************/
			/* CODE END Status */
			break;
		case RED_AMBER:
			/* CODE BEGIN Status */
			//TODO
			red_amber();
			led_7_segment();
			/* Change status of finite state machines */
			if(timer1_flag == 1){
				timer2_flag = 0;
				fsm_status = GREEN_RED;
				setTimer1(RED_GREEN_PREIOD + green_add);
				setTimer2(100);
				counter1_7_segment = (RED_GREEN_PREIOD + green_add) / FREQUENCY_SYSTEM;
				counter2_7_segment = (RED_GREEN_PREIOD + RED_AMBER_PREIOD + red_add) / FREQUENCY_SYSTEM;
			}
			/*****************************/
			/* Count the time the light is on */
			if(timer2_flag == 1){
				counter1_7_segment--;
				counter2_7_segment--;
				setTimer2(100);
			}
			/*****************************/
			/* Change status to modify time status*/
			if(isButton1Pressed() == 1){
				clearAllLed();
				fsm_status = MAN_RED;
				timer1_flag = 0;
				timer2_flag = 0;
				counter1_7_segment = 1;
				counter2_7_segment = (RED_GREEN_PREIOD + RED_AMBER_PREIOD + red_add) / FREQUENCY_SYSTEM;
			}
			/*****************************/
			/* CODE END Status */
			break;
		case GREEN_RED:
			/* CODE BEGIN Status */
			//TODO
			green_red();
			led_7_segment();
			/* Change status of finite state machines */
			if(timer1_flag == 1){
				timer2_flag = 0;
				fsm_status = RED_AMBER;
				setTimer1(RED_AMBER_PREIOD + amber_add);
				setTimer2(100);
				counter1_7_segment = (RED_AMBER_PREIOD + amber_add) / FREQUENCY_SYSTEM;
				counter2_7_segment = (RED_AMBER_PREIOD + amber_add) / FREQUENCY_SYSTEM;
			}
			/*****************************/
			/* Count the time the light is on */
			if(timer2_flag == 1){
				counter1_7_segment--;
				counter2_7_segment--;
				setTimer2(100);
			}
			/*****************************/
			/* Change status to modify time status*/
			if(isButton1Pressed() == 1){
				clearAllLed();
				fsm_status = MAN_RED;
				timer1_flag = 0;
				timer2_flag = 0;
				counter1_7_segment = 1;
				counter2_7_segment = (RED_GREEN_PREIOD + RED_AMBER_PREIOD + red_add) / FREQUENCY_SYSTEM;
			}
			/*****************************/
			/* CODE END Status */
			break;
		case AMBER_RED:
			/* CODE BEGIN Status */
			//TODO
			amber_red();
			led_7_segment();
			/* Change status of finite state machines */
			if(timer1_flag == 1){
				timer2_flag = 0;
				fsm_status = RED_GREEN;
				setTimer1(RED_GREEN_PREIOD + green_add);
				setTimer2(100);
				counter1_7_segment = (RED_GREEN_PREIOD + RED_AMBER_PREIOD + red_add) / FREQUENCY_SYSTEM;
				counter2_7_segment = (RED_AMBER_PREIOD + amber_add) / FREQUENCY_SYSTEM;
			}
			/*****************************/
			/* Count the time the light is on */
			if(timer2_flag == 1){
				counter1_7_segment--;
				counter2_7_segment--;
				setTimer2(100);
			}
			/*****************************/
			/* Change status to modify time status*/
			if(isButton1Pressed() == 1){
				clearAllLed();
				fsm_status = MAN_RED;
				timer1_flag = 0;
				timer2_flag = 0;
				counter1_7_segment = 1;
				counter2_7_segment = (RED_GREEN_PREIOD + RED_AMBER_PREIOD + red_add) / FREQUENCY_SYSTEM;
			}
			/*****************************/
			/* CODE END Status */
			break;
		case MAN_RED:
			/* CODE BEGIN Status */
			//TODO
			led_7_segment();
			/* Blink led */
			if(timer3_flag == 1){
				man_red();
				setTimer3(TIMER_LED);
			}
			/*****************************/
			/* Change status to modify time for led amber */
			if(isButton1Pressed() == 1){
				clearAllLed();
				fsm_status = MAN_AMBER;
				counter1_7_segment = 2;
				counter2_7_segment = (RED_AMBER_PREIOD + amber_add) / FREQUENCY_SYSTEM;
			}
			/*****************************/
			/* Modify time */
			if(isButton2Pressed() == 1){
				counter2_7_segment++;
				if(counter2_7_segment > 99){
					counter2_7_segment = 1;
				}
			}
			/*****************************/
			/* Save time */
			if(isButton3Pressed() == 1){
				red_add = counter2_7_segment * FREQUENCY_SYSTEM - (RED_AMBER_PREIOD + RED_GREEN_PREIOD);
			}
			/*****************************/
			/* CODE END Status */
			break;
		case MAN_AMBER:
			/* CODE BEGIN Status */
			//TODO
			led_7_segment();
			/* Blink led */
			if(timer3_flag == 1){
				man_amber();
				setTimer3(TIMER_LED);
			}
			/*****************************/
			/* Change status to modify time for led green */
			if(isButton1Pressed() == 1){
				clearAllLed();
				fsm_status = MAN_GREEN;
				counter1_7_segment = 3;
				counter2_7_segment = (RED_GREEN_PREIOD + green_add) / FREQUENCY_SYSTEM;
			}
			/*****************************/
			/* Modify time */
			if(isButton2Pressed() == 1){
				counter2_7_segment++;
				if(counter2_7_segment > 99){
					counter2_7_segment = 1;
				}
			}
			/*****************************/
			/* Save time */
			if(isButton3Pressed() == 1){
				amber_add = counter2_7_segment * FREQUENCY_SYSTEM - RED_AMBER_PREIOD;
			}
			/*****************************/
			/* CODE END Status */
			break;
		case MAN_GREEN:
			/* CODE BEGIN Status */
			//TODO
			led_7_segment();
			/* Blink led */
			if(timer3_flag == 1){
				man_green();
				setTimer3(TIMER_LED);
			}
			/*****************************/
			/* Run traffic light after modify time */
			if(isButton1Pressed() == 1){
				clearAllLed();
				fsm_status = RED_GREEN;
				setTimer1(RED_GREEN_PREIOD + green_add);
				setTimer2(100);
				setTimer3(TIMER_LED);
				counter1_7_segment = (RED_GREEN_PREIOD + RED_AMBER_PREIOD + red_add) / FREQUENCY_SYSTEM;
				counter2_7_segment = (RED_GREEN_PREIOD + green_add) / FREQUENCY_SYSTEM;
			}
			/*****************************/
			/* Modify time */
			if(isButton2Pressed() == 1){
				counter2_7_segment++;
				if(counter2_7_segment > 99){
					counter2_7_segment = 1;
				}
			}
			/*****************************/
			/* Save time */
			if(isButton3Pressed() == 1){
				green_add = counter2_7_segment * FREQUENCY_SYSTEM - RED_GREEN_PREIOD;
			}
			/*****************************/
			/* CODE END Status */
			break;
		default:
			break;
	}
}
