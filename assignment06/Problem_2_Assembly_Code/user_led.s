/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

GPIOA_BASE  EQU 0x48000000
GPIOA_ODR   EQU 0x14
GPIOA_BIT_5 EQU 0x20

control_user_led1
    // <TODO> Implement function in assembly
    PUSH {R0, R2-R3, R8}          // Push R0 to the stack in case that it gets corrupted. Pushes R2-R3 and R8 to the stack as they will be used.
    LDR R2, =GPIOA_BASE           // Load into R2 GPIOA_BASE as an address.
    ADD R2, R2, #GPIOA_ODR        // Add the constant number 0x14 to R2 and store the result in R2. 
    LDR R3, [R2]                  // Load the value in the address of R2 into R3.
    MOV R8, LR                    // Move/Store the LR address into a temporary variable (R8 in this case). LR will be modified.
    CMP R0, #0x0                  // Checks to see if the first argument (via R0) passed to the function is #0. #0 means turn LED off.
    ITE EQ                        // Checks if R0 == #0x0
    EOREQ R3, R3, #GPIOA_BIT_5    // If R0 is #0x0 then XOR the value inside of R3 with #0x20. Turns bit for GPIOA Port 5 off (1 XOR 1 = 0).
    ORRNE R3, R3, #GPIOA_BIT_5    // If R0 is not #0x0 then OR the value inside of R3 with #0x20. Turns bit for GPIOA Port 5 on (1 OR 0 = 1, 1 OR 1 = 1)
    STRB R3, [R2]                 // Stores the result (GPIOA_BIT_5 on or off) into the address pointed to by R2; this is the GPIOA_ODR register address. At this time LED turns on or off.
    MOV R0, R1                    // Moves the second parameter (R1) passed down to this function into R0. R0 will be the argument passed down to the called function delay(). 
    BL delay                      // Branch into (call) delay() function. Pass R0 as the argument (only one argument needed by delay(arg)).
    MOV LR, R8                    // After exiting the delay() function, control is passed back to this function. LR is restored by re-assigning it the value temporarily held by R8.  
    POP {R0, R2-R3, R8}           // Restore the values that R0, R2, R3, and R8 had before entering this function.
    BX LR                         // Branch to the LR address, which is the address of the caller function. Provide control back to the caller function. Return is void so R0 returns nothing of use.  

    END                           // Symbolizes/flags the end of the function.
