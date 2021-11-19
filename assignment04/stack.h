#ifndef __STACK_H__
#define __STACK_H__

#include "bool.h"

//Initialize the stack internals
void stack_init(void);

//Checks if stack is empty
Bool isEmpty(void);

//Checks if stack if full
Bool isFull(void);

//Pushes element onto stack. Returns (0) if successful, -1 otherwise
int push(int i);

//Pops element off stack. Returns (0) if successful, -1 otherwise
int pop(int* data);

//Peaks top element of stack. Returns -1 if stack is not initialized
int peek(int* topElement);

#endif