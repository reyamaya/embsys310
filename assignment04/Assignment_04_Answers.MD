# Problems:
### 1 a) What instructions does the compiler produce in assembly for "writing" to the RCC_AHB2ENR bit when using bit band address?
- The compiler produces:
MOVS	R0, #1
STR.W 	R0, [R8]

### 1 b) What were the instructions produced when writing to the RCC_AHB2ENR without using bit-banding?
- The instructions produced were:
LDR.N	R0, [PC, #0x44]
LDR 	R1, [R0]
ORRS.W	R1, R1, #1
STR 	R1, [R0]

### 2 a) How does the calling function “func2” pass the values to the called function “func1”?
-  The calling function passes values to the called function via registers R0-R3. 
It also passes the value of a reused register (R0) in my case, to SP register, since
it overwrites the value in R0. Then, the value form SP is loaded onto R4 inside of the 
called (func1) scope. 

### 2 b) What extra code did the compiler generate before calling the function “func1” with the multiple arguments?
- It pushed R7 and LR to the stack, it moved the five argument values to R0-R3 registers, and it stored the value of R0 (the overwritten register) to the SP register.

### 2 c) What extra code did the compiler generate inside the called function “funct1” with the list of multiple arguments?
- It pushed R4 and R5 onto the stack. It loaded R4 with the value from SP offset by #0x8. 

### 2 d) Any other observations?
- The compiler preserved different registers in different functions. In func2, it preserved the value of LR to know where to return to after execution. It did not save LR in func1 scope as it returned to a hardcoded address (rigth after the first instruction in func2). Another observation is that it moved the value of a register (R0) in func2 to SP register, before moving a new value into R0. 




