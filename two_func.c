#include <stdio.h>	//预处理器指令

void func1(void);	//函数声明 function declaration 
void func2(void);
void func3(void);

int main(void)
{
    char name;
    int age;
    name = 'F';
    age = 18;

    func1();
    printf("My name is %c, age is %d\n", name, age);
    func2();
    func3();
    return 0;
}

void func1(void)
{
    printf("Who are you?\n");
    return;
}

void func2(void)
{
    int num1, num2, sum;
    num1 = 10;
    num2 = num1 + 10;
    sum = num1 + num2;
    printf("num1 = %d, num2 = %d, sum = num1 + num2 = %d.\n", num1, num2, sum);
    return;
}

void func3(void)
{
    short int a = 32768;
    printf("c/c++ plugin is OK!\n");
    printf("short int a = %hd,not = %hu\n", a, a);
    return;
}
















