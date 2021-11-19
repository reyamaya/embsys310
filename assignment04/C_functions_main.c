void func1(int, int, int, int, int);
void func2(void);

int main()
{
    func2();
    
  return 0;
}

void func1(int argOne, int argTwo, int argThree, int argFour, int argFive)
{
    int sum = argOne + argTwo + argThree + argFour + argFive;
    while(sum < 5);
}

void func2(void)
{
    func1(1, 2, 3, 4, 5);
}