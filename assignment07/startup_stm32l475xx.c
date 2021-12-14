#include "stm32l4xx_it.h"
#pragma section = "CSTACK"

void __iar_program_start(void);

void Unused_Handler(void);

void Unused_Handler(void)
{
    while(1);
}

int const __vector_table[] @ ".intvec" = {
  (int)__section_end("CSTACK"), //0x0000    Stack Pointer
  (int)__iar_program_start,     //0x0004    Reset Vector
  (int)NMI_Handler,             //0x0008    NMI
  (int)HardFault_Handler,       //0x000C    Hard fault
  (int)MemManage_Handler,       //0x0010    Memory management fault
  (int)BusFault_Handler,        //0x0014    Bus fault
  (int)UsageFault_Handler,      //0x0018    Usage fault
   0,                           //0x001C    Reserve
   0,                           //0x0020    Reserve 
   0,                           //0x0024    Reserve 
   0,                           //0x0028    Reserve
  (int)SVC_Handler,             //0x002C    SVCall
  (int)DebugMon_Handler,        //0x0030    Debug
   0,                           //0x0034    Reserve
  (int)PendSV_Handler,          //0x0038    PendSV
  (int)SysTick_Handler          //0x003C    Systick
};

__weak void NMI_Handler(void)
{
    Unused_Handler();
}

// When the SP register drops below the start of RAM,
// the processor enters the HardFault exception
__weak void HardFault_Handler(void)
{
    Unused_Handler();
}

__weak void MemManage_Handler(void)
{
    Unused_Handler();
}

__weak void BusFault_Handler(void)
{
    Unused_Handler();
}

__weak void UsageFault_Handler(void)
{
    Unused_Handler();
}

// The below is another way of achieving the above...
#pragma weak SVC_Handler = Unused_Handler
#pragma weak DebugMon_Handler = Unused_Handler
#pragma weak PendSV_Handler = Unused_Handler
//#pragma weak SysTick_Handler = Unused_Handler


//__weak void SVC_Handler(void)
//{
//    Unused_Handler();
//}
//
//__weak void DebugMon_Handler(void)
//{
//    Unused_Handler();
//}
//
//__weak void PendSV_Handler(void)
//{
//    Unused_Handler();
//}
//
__weak void SysTick_Handler(void)
{
    Unused_Handler();
}


// **** Overriding the default __low_level_init **** //
// Remember that this code, while written in C, it will execute
// before variable initialization is done
int __low_level_init(void);

int __low_level_init(void)
{
    // specify whatever low level setup needed in the hardware
    return 1;
}