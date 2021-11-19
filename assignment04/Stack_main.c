#include<assert.h>
#include "bool.h"
#include "stack.h"

int main()
{
    int topElement;
    int data, data2;
    int peekStatus;
    int empty;
    int full;
    int result;
    int partialStack[] = {5, 6, 1};
    int fullStack[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i;
    
     /*******************************************************************/
    //Test 1: Peek into empty stack
    /*******************************************************************/
    //Setup
    stack_init();
    
    //Execute
    peekStatus = peek(&topElement);   
    
    //Verify
    assert(-1 == peekStatus);        
    
    /*******************************************************************/
    //Test 2: Checking that stack is empty
    /*******************************************************************/
    //Setup/Execute:
    empty = isEmpty();
    
    //Verify
    assert(1 == empty);
       
    /*******************************************************************/
    //Test 3: Push three element into stack and retreive top.
    //LIFO
    /*******************************************************************/
    //Setup
    for(i = 0; i < sizeof(partialStack)/sizeof(partialStack[0]); i++)
    {
        result = push(partialStack[i]);
        if(result == -1)
            break;
    }
    //Execute:
    peekStatus = peek(&topElement);
        
    //Verify
    assert(0 == result);
    assert(1 == topElement);
    
    /*******************************************************************/
    //Test 3: Pop top element from stack.
    //LIFO
    /*******************************************************************/
    //Setup/Execute
    result = pop(&data);
    
    //Verify
    assert(0 == result);
    assert(1 == data);
    
    /*******************************************************************/
    //Test 4: Check if stack is full. Stack is partially full.
    /*******************************************************************/
    //Setup/Execute
    full = isFull();
    
    //Verify
    assert(0 == full);
    
    /*******************************************************************/
    //Test 5: Empty the stack. Stack is partially filled.
    /*******************************************************************/
    //Setup/Execute
    result = pop(&data);
    result = pop(&data);
    
    //Verify
    assert(0 == result);
    assert(5 == data);    
    
    /*******************************************************************/
    //Test 6: Popping an empty stack.
    /*******************************************************************/
    //Setup/Execute
    result = pop(&data2);
    
    //Verify
    assert(-1 == result);
    assert(5 != data2);    
    
    /*******************************************************************/
    //Test 7: Fill the stack.
    /*******************************************************************/  
    for(i = 0; i < sizeof(fullStack)/sizeof(fullStack[0]); i++)
    {
        result = push(fullStack[i]);
        if(result == -1)
            break;
    }
    
    //Verify
    assert(0 == result);
    
    /*******************************************************************/
    //Test 8: Peek top of stack. LIFO
    /*******************************************************************/  
    //Setup/Execute:
    peekStatus = peek(&topElement);
    
    //Verify
    assert(0 == result);
    assert(9 == topElement);
    
    /*******************************************************************/
    //Test 9: Push one more element to full stack
    /*******************************************************************/  
    //Setup/Execute:
    result = push(fullStack[5]);
    
    //Verify
    assert(-1 == result);
    
    /*******************************************************************/
    //Test 10: Checking that stack is full
    /*******************************************************************/  
    //Setup:
    full = 1000;//Clearing out previous result
    
    //Execute:
    full = isFull();
    
    //Verify
    assert(1 == full);
    
    /*******************************************************************/
    //Test 11: Checking that stack is empty
    /*******************************************************************/  
    //Setup:
    empty = 1000;//clearing out previous result
    
    //Execute:
    empty = isEmpty();
    
    //Verify
    assert(0 == empty);
    
    return 0;
}
