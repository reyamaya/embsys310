/*******************************************************************************
File name       : delay.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    PUBLIC delay         // Exports symbols to other modules

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
Function Name   : delay
Description     : loops until input value reaches 0, then exits

C Prototype     : void delay(uint8_t duration)
                : Where duration indicates the total number of loops.
Parameters      : R0: uint8_t duration
Return value    : None
*******************************************************************************/  
  
delay
    // <TODO> Implement function in assembly
    PUSH {R4, LR}      // Pushes R4 and LR to the stack. LR to return to calling function. R4 as it will be used in this function
    MOV R4, R0         // Argument is passed via R0 to delay(R0). Moving the value from R0 to R4 in order to use R4.
    CMP R4, #0x0       // Compares #0 to the value in R4 to determine if iteration needs to happen.
    BEQ EndLoop        // If argument passed to delay() is #0 then no iteration needs to happen. Function will go to the end and exit.
StartLoop              // Label to comeback to while iterating in the while loop. Speghetti code.
    SUBS R4, R4, #0x1  // If argument passed to delay() is greater than zero, subtract one from argument.
    CMP R4, #0x0       // Compares if the value in R4 has reached #0.
    BNE StartLoop      // If value in R4 is not zero, go to label StartLoop (start of loop).
EndLoop                // Label used to jump to when argument passed to function is #0.
    POP {R4, LR}       // Pops (restores) the values that R4 and LR had prior to entering this function.
    BX LR              // Branch with exchange to the value in the LR.
    END                // End of the function label.
