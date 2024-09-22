/*
 * software_timer.h
 *
 *  Created on: 21 thg 9, 2024
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER3_H_
#define INC_SOFTWARE_TIMER3_H_

#include "main.h"
void setTimer(int index, int value);
int isTimerExpired(int index);
void display7SEG(int num);
void update7SEG ( int index );
void Ex3_run();
void timerRun();



#endif /* INC_SOFTWARE_TIMER3_H_ */
