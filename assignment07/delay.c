#include <time.h>
#include "delay.h"

void delay (unsigned int millisecs) 
{
    STK_LOAD = ((SYS_CLOCK_HZ / 1000) * millisecs)  - 1;
    STK_VAL ^= 0x1; 
    STK_CTRL ^= 0x7;
}