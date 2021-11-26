/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function for division
*******************************************************************************/   

    PUBLIC swapCharsAsm // Exports symbols to other modules
                        // Making swapCharsAsm available to other modules.
    
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
Function Name   : swapCharsAsm
Description     : Calls C code to print a string; 
                  computes the square of its input argument
C Prototype     : int swapCharsAsm(char* x, char* y)
                : Where x and y are chars to swap 
Parameters      : R0: char x, R1: char y
Return value    : R0
*******************************************************************************/  
  
swapCharsAsm
    LDR R2,[R0]         // load the value in the address inside of R0 (first arguement) into R2 (temp variable)
    LDR R3,[R1]         // load the value in the address of R1 (second argument) into R3 (temp variable)
    STRB R3,[R0]        // store the least significant byte of R3 into R0. Only strore one byte as char is one byte long
    STRB R2,[R1]        // store the least significant byte for R2 into R1. Only store one byte to elimate garbage from the stack's address.
    
    MOV R3, #0          // Clears the data in R3 by setting all of the bits to 0
    LDRB R3, [R0]       // Moves the first byte (least significant byte) from R0 into R3
    MOV R2, #0          // Clears the data in R2 by setting all of the bits to 0
    LDRB R2, [R1]       // Moves the first byte (least significant byte) from R1 into R2
    
    CMP R2, R3          // Subtracts the value in R3 from the value in R2. Sets the Zero flag to 0 or 1. This flag will be checked in EQ/NE
    ITT NE              // IF THEN THEN, if Not Equal (Z == 0), Then move 1 to R0 and branch out to the LR (give control to calling function) with result in R0 as return value
    MOVNE R0, #0x1      // Move 1 to R0 if Result of CMP is NE (Z==0)
    BXNE LR             // return (with function result in R0)
    
    MOV R0, #0x0        // Move 0 to R0 if CMP results in Z==1 (EQ)
    BX  LR              // Branch to LR with result in R0

    END
