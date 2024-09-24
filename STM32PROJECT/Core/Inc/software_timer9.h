/*
 * software_timer.h
 *
 *  Created on: 21 thg 9, 2024
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER9_H_
#define INC_SOFTWARE_TIMER9_H_


#define LED_Pins (ENM0_Pin|ENM1_Pin|ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin|ENM6_Pin|ENM7_Pin)
#include "main.h"
void setTimer(int index, int value);
int isTimerExpired(int index);

void timerRun();
void updateLEDMatrix (int index );
void Ex9_run();
void displayMatrix(uint8_t num);
void shiftColLeft();
void shiftColRight();
void shiftRowUp();
void shiftRowDown();
#endif /* INC_SOFTWARE_TIMER9_H_ */
