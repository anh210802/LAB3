/*
 * global.h
 *
 *  Created on: Nov 5, 2023
 *      Author: anhxa
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

/*
 *
 * */
#define FREQUENCY_SYSTEM	100
#define TIMER_LED			25
#define TIMER_7_SEGMENT		10

#define RED_GREEN_PREIOD 	1000
#define RED_AMBER_PREIOD	500

/*
 * SET STATUS FOR FINITE STATE MACHINE TRAFFIC LIGHT
 * */
#define INIT		0
#define RED_GREEN	1
#define RED_AMBER 	2
#define GREEN_RED	3
#define AMBER_RED	4
#define MAN_RED		5
#define MAN_AMBER	6
#define MAN_GREEN	7

/*
 * SET DISPLAY FOR LED 7 SEGMENT
 * */
#define EN0_STATE 	1
#define EN1_STATE	2
#define EN2_STATE	3
#define EN3_STATE	4


extern int fsm_status;
extern int led7seg_status;

extern int red_add;
extern int amber_add;
extern int green_add;

#endif /* INC_GLOBAL_H_ */
