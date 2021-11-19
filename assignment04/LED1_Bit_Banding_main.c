#include <time.h>

#define RCC_BASE             0x40021000
#define GPIOA_BASE           0x48000000
#define BIT_BAND_BASE        0x42000000
#define PERIPH_BIT_BAND_BASE 0x40000000

#define RCC_AHB2ENR     (RCC_BASE + 0x4C)
#define GPIOA_MODER     (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR       (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define GPIOA_MODER_OUTPUT (1 << 11)
#define GPIOA_ODR_OD5 (1 << 5)

void delay(unsigned int);

int main()
{
        unsigned int numLoops = 123;

        //Enable the clock for GPIOA using Bit Band
        const unsigned int AHB2ENR_Byte_Offset =  RCC_AHB2ENR - PERIPH_BIT_BAND_BASE;
        const unsigned int RCC_AHB2ENR_bit_number = 0;
        unsigned int RCC_AHB2ENR_bit_word_offset = (AHB2ENR_Byte_Offset * 32) + (RCC_AHB2ENR_bit_number * 4);
        unsigned int RCC_AHB2ENR_bit_word_addr = BIT_BAND_BASE + RCC_AHB2ENR_bit_word_offset;
        *((unsigned int *)RCC_AHB2ENR_bit_word_addr) = 0x1;
        
        //Set Port A as output
        GPIOA_MODER ^= GPIOA_MODER_OUTPUT;
       
        while (numLoops < 115)
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
    //End Problem 1 and Problem 2
    
    return 0;
}

void delay (unsigned int secs) 
{
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until the finish time.
}