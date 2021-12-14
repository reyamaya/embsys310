#include <stdint.h>
#include "stm32l475xx.h"
#include "system_stm32l4xx.h"
#include "delay.h"

void SysTick_Handler(void);

unsigned int milliseconds = 1000;

int main()
{
  //Enable the AHB clock for GPIOA
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
  
  //Enable the AHB clock for GPIOB
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
  
  //Set GPIOA Port 5 in output mode
  GPIOA->MODER |= GPIO_MODER_MODE5_0;
  GPIOA->MODER ^= GPIO_MODER_MODE5_1;
  
  //Set GPIOB Port 14 in output mode
  GPIOB->MODER |= GPIO_MODER_MODE14_0;
  GPIOB->MODER ^= GPIO_MODER_MODE14_1;
  
  //Turn LED 1 On
  GPIOA->ODR ^= GPIO_ODR_OD5;
  
  delay(milliseconds);

  while(1)
  {
  }

  return 0;
}

void SysTick_Handler(void)
{         
  GPIOA->ODR ^= GPIO_ODR_OD5;
  GPIOB->ODR ^= GPIO_ODR_OD14;
}
