**1.	Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.**
* What is the value of the “counter” from the “Locals” window? 
   *	The value is **0x80000000**

* What is the value of the “counter” in the “Registers” window? 
	  *	The value is **0x80000000**
	  
* Please note down which flags are set in the APSR register. And explain why
	  *	**N has value 1 and V has value 1**. Since counter is a signed number (int), it can only make use of 31 bits. Thus, adding 1 to 0x7FFFFFFF
	  	forces a bit to be carried-over to the MSB; which results in overflow (since the 32nd bit is used). 
			That 32nd bit (MSB) is reserved as the signed bit. The carried-over bit turns that MSB into a 1; which is considered as negative in signed numbers. 
			
**2.	If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter”**
* What happens to the value of “counter” in the “Locals” window?
  *	The value of “counter” overflows and wraps around to **0x00000000**.
  
* Please note down which are set in the APSR register. And explain why. 
  *	**Z has value of 1 and C has value of 1**. The Zero flag of the APSR is set because the number stored in R1 after executing the instruction 
  	“adding 1 to 0xFFFFFFFF in R1” is zero (0x00000000). The Carry/Borrow flag is set because adding 1 to 0xFFFFFFFF results in overflow. 

**3. Change the “counter” variable type in your code to “unsigned int”. Inject the values “0x7FFFFFFF” then step thru the program to increment the “counter” once:**
* What is the value of “counter” in the “Locals” window after incrementing for each value?
  * The value of counter in the "Locals" window is **0X80000000**

* Please note down which flags are set in the APSR register. And explain why.
  *	**Flags set are N and V.** The bit[31] is set to the N flag. Since this bit is set to 1, the flag is set. The processor does not differentiate whether 
  	this is a negative or positive number. The compiler will choose what CPU instruction to use when using the value of the unsigned int 
		(positive 0X80000000). The overflow, V, flag is set because the processor does not know whether the variable is signed or unsigned, it is a 32 bit digit that 
		it is processing. Furthermore, since the assembly instruction ADDS is the same for signed and 		unsigned values, when 0x7FFFFFFF ADDS #1 is executed, the CPU 
		sets the V flag to signify that if this was a signed operation, the operation went out of bounds as the sign bit was changed (this operation went above the magnitude 
		bits (bit[0] - bit[30])).

**4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” then step thru the program to increment the “counter” once:**
* What is the value of “counter” in the “Locals” window after incrementing for each value?
  *	The value of counter in the Locals window is **0x00000000**
  
* Please note down which are set in the APSR register. And explain why.
  *	**Z and C are set**. Z is set since the result of the last instruction execution was 0. C is set since there was an unsigned overflow on the addition 
  	(last digit is 0 carry 1. 1 gets discarded as the 32bit number (counter) cannot hold it).

**5. Move the “counter’ variable outside of main (at the top of the file):**
* What is the scope of the variable “counter”?
  *	The scope of counter is **Global**.
  
* Is it still visible in the “Locals” view?
  *	**No, it is no longer visible in the locals view** as it is outside of the scope of the triggered main function.

* In which window view can we track “counter” now?
  *	We can track the variable in the **Watch view**.

* What is the address of the “counter” variable in memory?
  * The address of counter is **0x20000000**
  
**6. Change the source code to the following, then run the program in the simulator:**
* What is the value of “counter” at the end of the program (halting at the return 0 statement)
  *	The value of “counter” at the end of the program is **0x00000004**
  
* Explain why the counter value has changed?
  * The **pointer p_int was given (assigned) the address of counter (0x20000000)**. 
  	This pointer is then used to grab (dereference) the value at that address and increment it 3 times. Then, the object counter itself is incremented onces.

**7. Change the setting of IAR to run the same program on the evaluation board.**
* What is the address where “counter” is stored?
  *	Counter in the development board is stored in address **0X20000000**

* Is the “counter” variable stored in RAM or ROM?
  * This variable address is part of RAM1. So, the counter variable is stored in **RAM**.
  
* What is the value of “counter” at the end of the program (halting at the return 0 statement).
  * The value is **0x00000004**
