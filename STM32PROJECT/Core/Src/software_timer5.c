/*
 * software_timer.c
 *
 *  Created on: 21 thg 9, 2024
 *      Author: ADMIN
 */
#include "software_timer5.h"
#define MAX_COUNTER 10
#define TIMER_TICK 10

int timer_counter[MAX_COUNTER];
int timer_flag[MAX_COUNTER];

int hour = 15 , minute = 8 , second = 50;
int counter=0;
const int MAX_LED = 4;
 int index_led = 0;
 int led_buffer [4] = {1 , 5 , 0 , 8};

 void updateClockBuffer (){
 	led_buffer[0]=hour/10;
 	led_buffer[1]=hour%10;
 	led_buffer[2]=minute/10;
 	led_buffer[3]=minute % 10;
 }
 void Ex5_run(){
 	second ++;
 	 if ( second >= 60) {
 		 second = 0;
 		 minute ++;
 	}
 	if( minute >= 60) {
 		 minute = 0;
 		 hour ++;
 	}
 	if( hour >=24) {
 		 hour = 0;
 	}
 	updateClockBuffer();
 }

 void display7SEG(int num) {
       const uint8_t segmentMap[10] = {
    		   	  0b11111100, // 0
    		      0b01100000, // 1
    		      0b11011010, // 2
    		      0b11110010, // 3
    		      0b01100110, // 4
    		      0b10110110, // 5
    		      0b10111110, // 6
    		      0b11100000, // 7
    		      0b11111110, // 8
    		      0b11110110  // 9
       };
       HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, (segmentMap[num] & 0b10000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
       HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, (segmentMap[num] & 0b01000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
       HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, (segmentMap[num] & 0b00100000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
       HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, (segmentMap[num] & 0b00010000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
       HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, (segmentMap[num] & 0b00001000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
       HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, (segmentMap[num] & 0b00000100) ? GPIO_PIN_RESET : GPIO_PIN_SET);
       HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, (segmentMap[num] & 0b00000010) ? GPIO_PIN_RESET : GPIO_PIN_SET);
   }
 void update7SEG ( int index ) {
	 switch ( index ) {
	 case 0:
	 // Display the first 7 SEG with led_buffer [0]
		 HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		 HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		 HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		 display7SEG(led_buffer[index]);
	 break ;
	 case 1:
	 // Display the second 7 SEG with led_buffer [1]
		 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		 HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		 HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		 HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		 display7SEG(led_buffer[index]);
	 break ;
	 case 2:
	 // Display the third 7 SEG with led_buffer [2]
		 HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		 HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		 HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		 display7SEG(led_buffer[index]);
	 break ;
	 case 3:
	 // Display the forth 7 SEG with led_buffer [3]
		 HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		 HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		 HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		 display7SEG(led_buffer[index]);
	 break ;
	 default :
		 HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		 HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		 HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	 break ;
	 }
 }
 void led_blinky(){
 	if(counter>=2) counter=0;
 	counter++;
 	if(counter<=1) HAL_GPIO_WritePin(DOT_GPIO_Port,DOT_Pin , RESET);
 	else HAL_GPIO_WritePin(DOT_GPIO_Port,DOT_Pin , SET);
 }
void Ex4_run(){
	if(index_led>=MAX_LED) {
		index_led=0;
	}
		update7SEG(index_led++);
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
