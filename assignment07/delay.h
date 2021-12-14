#ifndef __DELAY_H__
#define __DELAY_H__

#define SYS_CLOCK_HZ      4000000u  //Default clock after startup
#define SYSTICK_BASE      0xE000E010
#define STK_CTRL_OFFSET   0x00
#define STK_CTRL          (*(int *)(SYSTICK_BASE + STK_CTRL_OFFSET))
#define STK_LOAD_OFFSET   0x04
#define STK_LOAD          (*(int *)(SYSTICK_BASE + STK_LOAD_OFFSET))
#define STK_VAL_OFFSET    0x08
#define STK_VAL           (*(int *)(SYSTICK_BASE + STK_VAL_OFFSET))

void delay(unsigned int iteration);

#endif
