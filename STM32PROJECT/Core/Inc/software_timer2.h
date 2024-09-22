/*
 * software_timer2.h
 *
 *  Created on: Sep 22, 2024
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER2_H_
#define INC_SOFTWARE_TIMER2_H_

#include "main.h"

void setTimer(int index, int value);
int isTimerExpired(int index);
void display7SEG(int num);
void led_blinky();
void Ex2_run();
void timerRun();

#endif /* INC_SOFTWARE_TIMER2_H_ */
