// 类型转换(type conversions)
#include <stdio.h>
void main(void)
{
    short int a = 1;
    unsigned short int b = 1;

    printf("sizeof(a) %%zd: %zd\n", sizeof(a));
    //短整型变量a,出现在表达式(expression,表达式由运算符和运算对象组成)会被自动转换成int
    printf("sizeof(-a) %%zd: %zd\n", sizeof(-a));
    printf("sizeof(a+1) %%zd: %zd\n", sizeof(a+1));
    
    printf("sizeof(b) %%zd: %zd\n", sizeof(b));
    printf("sizeof(-b) %%zd: %zd\n", sizeof(-b));
    printf("sizeof(b+1) %%zd: %zd\n", sizeof(b+1));
    return;
}



