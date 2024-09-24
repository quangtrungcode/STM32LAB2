/*
 * software_timer.c
 *
 *  Created on: 21 thg 9, 2024
 *      Author: ADMIN
 */
#include "software_timer9.h"
#define MAX_COUNTER 10
#define TIMER_TICK 10

int timer_counter[MAX_COUNTER];
int timer_flag[MAX_COUNTER];
const int MAX_LED_MATRIX = 8;
 int index_led_matrix = 0;
 uint8_t matrix_buffer [8] = {0xFF , 0xC0 , 0x80 , 0x33 , 0x33 , 0x80 , 0xC0 , 0xFF };
 uint16_t segmentPins[8] = {ROW0_Pin,ROW1_Pin,ROW2_Pin,ROW3_Pin,ROW4_Pin,ROW5_Pin,ROW6_Pin,ROW7_Pin};
 void displayMatrix(uint8_t num){
	 for(int i=0;i<MAX_LED_MATRIX;i++){
		 HAL_GPIO_WritePin(GPIOB, segmentPins[i], (num&(0x80>>i))?SET:RESET);
	 }
 }
 void Ex9_run(){
// 	 if(index_led_matrix>=8) index_led_matrix=0;
// 	 updateLEDMatrix(index_led_matrix++);
	 updateLEDMatrix(1);
  }
  void updateLEDMatrix (int index ) {
 	 HAL_GPIO_WritePin(GPIOA, LED_Pins, SET);
 		 switch ( index ) {
 		 case 0:
 			// HAL_GPIO_WritePin(GPIOA, LED_Pins & ~ENM0_Pin, SET);
 			 HAL_GPIO_WritePin(GPIOA, ENM0_Pin, RESET);
 			 displayMatrix(matrix_buffer[index]);
 		 break ;
 		 case 1:
 			// HAL_GPIO_WritePin(GPIOA, LED_Pins & ~ENM1_Pin, SET);
 			 HAL_GPIO_WritePin(GPIOA, ENM1_Pin, RESET);
 			 displayMatrix(matrix_buffer[index]);
 		 break ;
 		 case 2:
 			// HAL_GPIO_WritePin(GPIOA, LED_Pins & ~ENM2_Pin, SET);
 			 HAL_GPIO_WritePin(GPIOA, ENM2_Pin, RESET);
 			 displayMatrix(matrix_buffer[index]);
 		 break ;
 		 case 3:
 			// HAL_GPIO_WritePin(GPIOA, LED_Pins & ~ENM3_Pin, SET);
 			 HAL_GPIO_WritePin(GPIOA, ENM3_Pin, RESET);
 			 displayMatrix(matrix_buffer[index]);
 		 break ;
 		 case 4:
 			// HAL_GPIO_WritePin(GPIOA, LED_Pins & ~ENM4_Pin, SET);
 			 HAL_GPIO_WritePin(GPIOA, ENM4_Pin, RESET);
 			 displayMatrix(matrix_buffer[index]);
 		 break ;
 		 case 5:
 			// HAL_GPIO_WritePin(GPIOA, LED_Pins & ~ENM5_Pin, SET);
 			 HAL_GPIO_WritePin(GPIOA, ENM5_Pin, RESET);
 			 displayMatrix(matrix_buffer[index]);
 		 break ;
 		 case 6:
 			// HAL_GPIO_WritePin(GPIOA, LED_Pins & ~ENM6_Pin, SET);
 			 HAL_GPIO_WritePin(GPIOA, ENM6_Pin, RESET);
 			 displayMatrix(matrix_buffer[index]);
 		 break ;
 		 case 7:
 			// HAL_GPIO_WritePin(GPIOA, LED_Pins & ~ENM7_Pin, SET);
 			 HAL_GPIO_WritePin(GPIOA, ENM7_Pin, RESET);
 			 displayMatrix(matrix_buffer[index]);
 		 break ;
 		 default :
 			 HAL_GPIO_WritePin(GPIOA, LED_Pins , SET);
 		 break ;
 	}
  }
void setTimer(int index, int value){
	timer_counter[index]=value/TIMER_TICK;
	timer_flag[index]=0;
}

int isTimerExpired(int index){
	if(timer_flag[index]==1){
		timer_flag[index]=0;
		return 1;
	}
	return 0;
}

void timerRun(){
	for(int i=0;i<MAX_COUNTER;i++){
		if(timer_counter[i]>0){
			timer_counter[i]--;
			if(timer_counter[i]<=0) timer_flag[i]=1;
		}
	}
}
