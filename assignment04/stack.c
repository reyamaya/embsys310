#include "stack.h"
#include "bool.h"
#include<assert.h>
#define STACK_SIZE 10

//Stack declaration
int stack[STACK_SIZE];

//Pointer to bottom (growing) of stack
int* stackPtr = 0;

/*******************************************************************/
/*******************************************************************/
void stack_init(void)
{
    int i;
    for (i = 0; i < STACK_SIZE; i++)
    {
        stack[i] = 0;
    }
    stackPtr = stack;
}

/*******************************************************************/
/*******************************************************************/
Bool isEmpty(void)
{
    //Ensures that stackPtr is inialized
    assert(stackPtr != 0);
    return (stackPtr == &stack[0]) ? TRUE : FALSE;
}

/*******************************************************************/
/*******************************************************************/
Bool isFull(void)
{
    //Ensures that stackPtr is inialized
    assert(stackPtr != 0);
    return (stackPtr == &stack[STACK_SIZE]) ? TRUE: FALSE;
}

/*******************************************************************/
/*******************************************************************/
int push(int i)
{  
    if (!isFull())
    {
        *stackPtr = i;
        stackPtr++;
        return 0;
    }
    return -1;    
}

/*******************************************************************/
/*******************************************************************/
int pop(int* data)
{
    if(!isEmpty())
    {
        stackPtr--;
        *data = *stackPtr;
        *stackPtr = 0;        
        return 0;
    }
    return -1;
}

/*******************************************************************/
/*******************************************************************/
int peek(int* topElement)
{
    if(isEmpty())
        return -1;    
    if(stackPtr != stack)
        *topElement = *(stackPtr - 1);
    else    
        *topElement = *stackPtr;
    
    return 0;
}
