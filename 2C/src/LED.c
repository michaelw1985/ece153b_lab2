/*
 * ECE 153B
 *
 * Name(s):
 * Section:
 * Lab: 2C
 */

#include "LED.h"

void LED_Init(void) {
	// Enable GPIO Clocks
	// [TODO]
	// Initialize Green LED
	// [TODO]

	//LAB1 CODE TO INIT LED
    // Enable HSI
    RCC->CR |= ((uint32_t)RCC_CR_HSION);
    while ( (RCC->CR & (uint32_t) RCC_CR_HSIRDY) == 0 );

    // Select HSI as system clock source
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_HSI;
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) == 0 );

    // Enable GPIO Clock
    RCC->AHB2ENR |= (uint32_t)RCC_AHB2ENR_GPIOAEN;
    RCC->AHB2ENR |= (uint32_t)RCC_AHB2ENR_GPIOCEN;

    // ==== Initialize Green LED ====
    // Set Mode to Output (01)
    GPIOA -> MODER |= (uint32_t)GPIO_MODER_MODE5_0;
    GPIOA -> MODER &= ~(uint32_t)GPIO_MODER_MODE5_1;
    // Set PUPD Type to Pull-Up (00)
	GPIOA -> PUPDR &= ~(uint32_t)GPIO_PUPDR_PUPD5_0;
	GPIOA -> PUPDR &= ~(uint32_t)GPIO_PUPDR_PUPD5_0;
    // Set Output type to Push-Pull (0, reset)
    GPIOA -> OTYPER &= ~(uint32_t)GPIO_OTYPER_OT5;

    // ==== Initialize User Button ====
    // Set Mode to Input (00)
    GPIOC -> MODER &= ~(uint32_t)GPIO_MODER_MODE13_0;
	GPIOC -> MODER &= ~(uint32_t)GPIO_MODER_MODE13_1;
    // Set PUPD Type to Pull-Down (10)
    GPIOC -> PUPDR &= ~(uint32_t)GPIO_PUPDR_PUPD13_0;
    GPIOC -> PUPDR &= (uint32_t)GPIO_PUPDR_PUPD13_1;
	

}

void Green_LED_Off(void) {
	GPIOA -> ODR &= ~GPIO_ODR_OD5;
}

void Green_LED_On(void) {
	GPIOA -> ODR |= GPIO_ODR_OD5;
}

void Green_LED_Toggle(void) {
	GPIOA -> ODR ^= GPIO_ODR_OD5;
}
