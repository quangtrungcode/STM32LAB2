/*
 * software_timer.h
 *
 *  Created on: 21 thg 9, 2024
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER4_H_
#define INC_SOFTWARE_TIMER4_H_

#include "main.h"
void setTimer(int index, int value);
int isTimerExpired(int index);
void led_blinky();
void display7SEG(int num);
void update7SEG ( int index );
void Ex4_run();
void timerRun();



#endif /* INC_SOFTWARE_TIMER4_H_ */
