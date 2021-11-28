#include <time.h>
#include "delay.h"

void delay (unsigned int secs) 
{
    unsigned int finishTime = time(0) + secs;   // Get finishing time.
    while (time(0) < finishTime);               // Loop until the finish time.
}