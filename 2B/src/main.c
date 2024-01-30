/*
 * ECE 153B
*
 * Name(s): Michael Wong, Bharat Kathi
 * Section: Tuesday, 7 PM
 * Lab: 2C
 */

#include "stm32l476xx.h"
#include "EXTI.h"
#include "LED.h"
#include "SysClock.h"

int main() {
	// Initialization
	System_Clock_Init();
	LED_Init();
	EXTI_Init();
	
	while(1);
	return 0;
}
