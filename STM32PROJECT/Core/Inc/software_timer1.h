/*
 * software_timer1.h
 *
 *  Created on: 21 thg 9, 2024
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER1_H_
#define INC_SOFTWARE_TIMER1_H_

#include "main.h"
//extern int counter;
void setTimer(int index, int value);
int isTimerExpired(int index);
void display7SEG(int num);
void Ex1_run();
void timerRun();


#endif /* INC_SOFTWARE_TIMER1_H_ */
