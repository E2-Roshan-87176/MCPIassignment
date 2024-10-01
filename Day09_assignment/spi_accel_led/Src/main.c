/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "led.h"
#include "accel.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	//char str[32];
	LIS_Data val;
	SystemInit();
	LedInit(LED_GREEN_PIN);
	LedInit(LED_ORANGE_PIN);
	LedInit(LED_BLUE_PIN);
	LedInit(LED_RED_PIN);
	//UartInit(9600);
	//UartPuts("Lis3dsh Accel Demo!\r\n");
	LIS_Init();
	while(1){
		if(LIS_IsDataAvail())
		{
			val= LIS_GetData();

			(val.x<-1000)?(LedOn(LED_GREEN_PIN)):(LedOff(LED_GREEN_PIN));
			(val.x>1000)?(LedOn(LED_RED_PIN)):(LedOff(LED_RED_PIN));
			(val.y>1000)?(LedOn(LED_ORANGE_PIN)):(LedOff(LED_ORANGE_PIN));
			(val.y<-1000)?(LedOn(LED_BLUE_PIN)):(LedOff(LED_BLUE_PIN));

		}
		DelayMs(100);
	}


	return 0;
}







