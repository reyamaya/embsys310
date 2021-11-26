/*******************************************************************************
File name       : divAsm.s
Description     : Assembly language function for division
*******************************************************************************/   

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr       // myCstr defined outside this file.
    
    PUBLIC divAsm     // Exports symbols to other modules
                        // Making divAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables.
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
Function Name   : divAsm
Description     : Calls C code to print a string; 
                  computes the square of its input argument
C Prototype     : int divAsm(val)
                : Where val is the value to divide by 2
Parameters      : R0: integer val
Return value    : R0
*******************************************************************************/  
  
divAsm
    PUSH {R0, LR}       // Preserve R0 (as it is the 1st argument)and the LR (return address)
    LDR R0,=myCstr      // loads the address of string into R0
    LDR R0,[R0]         // load R0 with the value from the address in R0
    BL  PrintString     // Call PrintString to print the value passed by R0 (the string)
    POP {R0,LR}         // Restore R0 and LR
    MOV R1, #2          // Moves constant number 2 into R1. R1 = 2
    UDIV R0, R0, R1     // R0 = R0 / R1 
    BX LR               // return (with function result in R0)

    END
