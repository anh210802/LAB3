/*
 * button.c

 *  Created on: Nov 5, 2023
 *      Author: anhxa
 */

#include "button.h"

/* Init Button */
int KeyRegButton1 = NORMAL_STATE;
int KeyRegButton2 = NORMAL_STATE;
int KeyRegButton3 = NORMAL_STATE;

int KeyReg1But1 = NORMAL_STATE;
int KeyReg2But1 = NORMAL_STATE;
int KeyReg3But1 = NORMAL_STATE;
int KeyReg4But1 = NORMAL_STATE;

int KeyReg1But2 = NORMAL_STATE;
int KeyReg2But2 = NORMAL_STATE;
int KeyReg3But2 = NORMAL_STATE;
int KeyReg4But2 = NORMAL_STATE;

int KeyReg1But3 = NORMAL_STATE;
int KeyReg2But3 = NORMAL_STATE;
int KeyReg3But3 = NORMAL_STATE;
int KeyReg4But3 = NORMAL_STATE;

int TimeOutForKeyPress1 =  TIMER_LONG_PRESS_1;
int TimeOutForKeyPress2 =  TIMER_LONG_PRESS_2;
int TimeOutForKeyPress3 =  TIMER_LONG_PRESS_3;


int button1_flag = 0;
int button1_long_flag = 0;

int button2_flag = 0;
int button2_long_flag = 0;

int button3_flag = 0;
int button3_long_flag = 0;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButton1LongPressed(){
	if(button1_long_flag == 1){
		button1_long_flag = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2LongPressed(){
	if(button2_long_flag == 1){
		button2_long_flag = 0;
		return 1;
	}
	return 0;
}

int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3LongPressed(){
	if(button3_long_flag == 1){
		button3_long_flag = 0;
		return 1;
	}
	return 0;
}

void getKeyInput(){
	/* Set button 1 */
  KeyReg2But1 = KeyReg1But1;
  KeyReg1But1 = KeyRegButton1;
  KeyRegButton1 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
  if((KeyReg1But1 == KeyRegButton1) && (KeyReg1But1 == KeyReg2But1)){
    if(KeyReg2But1 != KeyReg3But1){
      KeyReg3But1 = KeyReg2But1;
      if(KeyReg3But1 == PRESSED_STATE){
    	if(KeyReg4But1 == NORMAL_STATE){
			button1_flag = 1;
    	}
    	TimeOutForKeyPress1 = TIMER_LONG_PRESS_1;
      }
    }else{
       TimeOutForKeyPress1--;
		if(TimeOutForKeyPress1 == 0){
			TimeOutForKeyPress1 = TIMER_LONG_PRESS_1;
			if(KeyReg3But1 == PRESSED_STATE){
				button1_long_flag = 1;
			}
		}
    }
  }
  /* Set button 2 */
    KeyReg2But2 = KeyReg1But2;
    KeyReg1But2 = KeyRegButton2;
    KeyRegButton2 = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
    if((KeyReg1But2 == KeyRegButton2) && (KeyReg1But2 == KeyReg2But2)){
      if(KeyReg2But2 != KeyReg3But2){
        KeyReg3But2 = KeyReg2But2;
        if(KeyReg3But2 == PRESSED_STATE){
        	if(KeyReg4But2 == NORMAL_STATE){
        		button2_flag = 1;
        	}
        	TimeOutForKeyPress2 = TIMER_LONG_PRESS_2;
        }
      }else{
         TimeOutForKeyPress2--;
         if(TimeOutForKeyPress2 == 0){
  			TimeOutForKeyPress2 = TIMER_LONG_PRESS_2;
  			if(KeyReg3But2 == PRESSED_STATE){
  				button2_long_flag = 1;
  			}
  		}
      }
    }
    /* Set button 3 */
        KeyReg2But3 = KeyReg1But3;
        KeyReg1But3 = KeyRegButton3;
        KeyRegButton3 = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);
        if((KeyReg1But3 == KeyRegButton3) && (KeyReg1But3 == KeyReg2But3)){
          if(KeyReg2But3 != KeyReg3But3){
            KeyReg3But3 = KeyReg2But3;
            if(KeyReg3But3 == PRESSED_STATE){
            	if(KeyReg4But3 == NORMAL_STATE){
            		button3_flag = 1;
            	}
            	TimeOutForKeyPress3 = TIMER_LONG_PRESS_3;
            }
          }else{
             TimeOutForKeyPress3--;
             if(TimeOutForKeyPress3 == 0){
      			TimeOutForKeyPress3 = TIMER_LONG_PRESS_3;
      			if(KeyReg3But3 == PRESSED_STATE){
      				button3_long_flag = 1;
      			}
      		}
          }
        }
}


