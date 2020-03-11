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

    // unsigned int constant
    // 2^10 = 1024
    printf("%zd\n", sizeof(2147483648U));
    printf("%x\n", 2147483648U);
    //<深入理解计算机系统第三版>P79 非规格化的值: mantissa尾数是不隐含1的
    //当exponent阶码全为0时,表示的是浮点数的非规格化形式
    // B2U binary当做unsigned --mapper映射--> 真值true value
    // printf()会把float参数转换成double,因此 %f和%lf在printf函数是一样的,在scanf函数才会区分
    printf("9223372036854775808LU %%f: %f\n", 9223372036854775808LU);
    printf("9223372036854775808LU %%e: %e\n", 9223372036854775808LU);
    printf("9223372036854775808LU %%a: %a\n", 9223372036854775808LU);
    printf("---------------- size: 16 character\n");
    printf("%16lx (%%16lx):2251799813685248LU\n", 2251799813685248LU);
    printf("2251799813685248LU %%f: %f\n", 2251799813685248LU);
    printf("2251799813685248LU %%a: %a\n", 2251799813685248LU);
    printf("%u\n", 2147483648U);
    printf("%d\n", 2147483648U);
    return;
}

