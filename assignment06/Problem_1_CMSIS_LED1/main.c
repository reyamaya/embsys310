#include <stdint.h>
#include "stm32l475xx.h"
#include "system_stm32l4xx.h"
#include "delay.h"

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
  
  unsigned int iterations = 0;
  while(iterations < 20)
  {
    //Add a delay to see the LED 1 turn on
    delay(1);
       
    //Set GPIOA Port 5 to output. Turn LED 1 On
    GPIOA->ODR |= GPIO_ODR_OD5;
    
    //Add a delay to see the LED 2 turn on
    delay(1);
    
    //Set GPIOB Port 14 to output. Turn LED 2 On
    GPIOB->ODR |= GPIO_ODR_OD14;
  
    //Add a delay to see the LED 1 turn off
    delay(1);
  
    //Set GPIOA Port 5 to not output. Turn LED 1 Off
    GPIOA->ODR ^= GPIO_ODR_OD5;
    
    //Add a delay to see the LED 1 turn off
    delay(1);
  
    //Set GPIOB Port 14 to not output. Turn LED 2 Off
    GPIOB->ODR ^= GPIO_ODR_OD14;
  
    iterations++;
  }
  
  //Reset GPIOA Port 5 
  GPIOA->MODER |= GPIO_MODER_MODE5_1;
  
  //Reset GPIOB Port 14 
  GPIOB->MODER |= GPIO_MODER_MODE14_1;
  
  //Disable the AHB clock for GPIOA
  RCC->AHB2ENR ^= RCC_AHB2ENR_GPIOAEN;
  
  //Disable the AHB clock for GPIOB
  RCC->AHB2ENR ^= RCC_AHB2ENR_GPIOBEN;
  
  return 0;
}