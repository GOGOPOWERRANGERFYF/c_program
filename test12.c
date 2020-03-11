// 类型转换(type conversions)
#include <stdio.h>
void part_one_type_conversion(void);

void main(void)
{
    part_one_type_conversion();
    return;
}

void part_one_type_conversion(void)
{
    // 1.
    short int a = 1;
    unsigned short int b = 1;
    // american standard code for information interchange 美国信息交换标准码
    //'A'字符(character)ascii码 十进制:65 
    char c = 'A';

    printf("sizeof(a) %%zd: %zd\n", sizeof(a));
    //短整型变量a,出现在表达式(expression,表达式由运算符和运算对象组成)会被自动转换成int
    printf("sizeof(-a) %%zd: %zd\n", sizeof(-a));
    printf("sizeof(a+1) %%zd: %zd\n", sizeof(a+1));
    
    printf("sizeof(b) %%zd: %zd\n", sizeof(b));
    printf("sizeof(-b) %%zd: %zd\n", sizeof(-b));
    printf("sizeof(b+1) %%zd: %zd\n", sizeof(b+1));
    
    printf("sizeof(c) %%zd: %zd\n", sizeof(c));
    printf("sizeof(c) %%zd: %zd\n", sizeof(-c));
    printf("sizeof(c) %%zd: %zd\n", sizeof(c+1));
    printf("expression: c+1 %%c: %c\n", c+1);
    printf("ascii(decimal:126) %%c: %c\n", 126);
    return;
}

