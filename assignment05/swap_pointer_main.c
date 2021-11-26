void swap_pointer(int**, int**);
int isEqual (int*, int*);

int main()
{
    int x = 0x20000000;
    int y = 0x20000000;
    int* ptr1 = &x;
    int* ptr2 = &y;
    
    swap_pointer(&ptr1, &ptr2);
    
    isEqual(&x, &y);
}

void swap_pointer(int** ptr_x, int** ptr_y)
{
    int* ptrTemp = *ptr_x;
    *ptr_x = *ptr_y;
    *ptr_y = ptrTemp;
}

int isEqual(int* x, int*y)
{
    if(*x == *y)
        return 0;
    
    return 1;
}