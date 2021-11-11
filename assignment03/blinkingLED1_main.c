#include <time.h>

#define RCC_BASE    0x40021000
#define GPIOA_BASE  0x48000000

#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_MODER  (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR   (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define GPIOA_MODER_OUTPUT (1 << 11)
#define GPIOA_ODR_OD5 (1 << 5)

void delay(unsigned int);

int main()
{
    {//Start Problem 1 and Problem 2 - Blinking LED1 and using XOR bit wise 
     //operator  
        unsigned int numLoops = 0;

        //Enable the clock for GPIOA
        RCC_AHB2ENR |= 0x1; 
        
        //Set Port A as output
        GPIOA_MODER ^= GPIOA_MODER_OUTPUT;
       
        while (numLoops < 5)
        {
            //Turn LED ON - Set GPIOA Pin 5 to Output Data
            delay(1);
            GPIOA_ODR ^= GPIOA_ODR_OD5;
            
            //Turn LED OFF - Setp GPIOA Pin 5 to Null
            delay(1);
            GPIOA_ODR ^= GPIOA_ODR_OD5;
            
            numLoops++;
        }   
        delay(10);
    }//End Problem 1 and Problem 2
    
    return 0;
}

void delay (unsigned int secs) 
{
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until the finish time.
}