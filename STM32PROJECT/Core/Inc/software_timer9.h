/*
 * software_timer.h
 *
 *  Created on: 21 thg 9, 2024
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER9_H_
#define INC_SOFTWARE_TIMER9_H_

#define LED_Pins (ROW0_Pin|ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin)
#include "main.h"
void setTimer(int index, int value);
int isTimerExpired(int index);

void timerRun();
void displayMatrix(uint8_t num);
void Ex9_run();
void updateLEDMatrix (int index );

#endif /* INC_SOFTWARE_TIMER9_H_ */
