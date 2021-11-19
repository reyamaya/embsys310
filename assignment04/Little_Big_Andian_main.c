void show_little_big_endian(int n, char* inPtr, char* outPtr);

int main()
{
    unsigned int test = 0xDEADBEEF;
    int size = sizeof(test);
    char outArr[32];
    
    show_little_big_endian(size, (char*)(&test), outArr);
    
  return 0;
}

void show_little_big_endian(int n, char* inPtr, char* outPtr)
{
    int i;
    for(i = 0; i < n; i++)
    {
        outPtr[i] = inPtr[i];
    }    
}


