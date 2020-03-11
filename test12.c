// 类型转换(type conversions)
#include <stdio.h>
void part_one_type_conversion(void);
void assignment_statement_type_conversion(void);

void main(void)
{
    part_one_type_conversion();
    assignment_statement_type_conversion();
    return;
}

void part_one_type_conversion(void)
{
    // 1.当类型转换出现在表达式,无论signed或unsigned的char和short,都会转换成int
    // 较小类型转换为较大类型(size小->大),这些转换称为升级(promotion)
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
    printf("%u\n", 2147483648U);
    printf("%d\n", 2147483648U);
    //<深入理解计算机系统第三版>P79 非规格化的值: mantissa尾数是不隐含1的
    //当exponent阶码全为0时,表示的是浮点数的非规格化形式
    // B2U binary当做unsigned --mapper映射--> 真值true value
    // printf()会把float参数转换成double,因此 %f和%lf在printf函数是一样的,在scanf函数才会区分
    //*非规格化值的用途之一: 表示浮点数的0 (规格化值尾数隐含1.所以无法表达浮点数0)
    //*非规格化值exponent: 0000 0000 000(double); 0000 0000(float)
    //*规格化值的setoff/bias偏置量: bias_1024 , bias_255
    //*非规格化值mantissa尾数全为0: 直接2^0,不用再减去偏置量; 浮点数的0有正负之分 
    //*非规格化值mantissa尾数非全0: 
    //   阶码exponent要减去偏置量(二补数运算,非二补数编码运算,我自己为了方便理解乱创的概念,别较真...)
    printf("9223372036854775808LU %%f: %f\n", 9223372036854775808LU);
    printf("9223372036854775808LU %%e: %e\n", 9223372036854775808LU);
    printf("9223372036854775808LU %%a: %a\n", 9223372036854775808LU);
    printf("---------------- size: 16 character\n");
    printf("%16lx (%%16lx):2251799813685248LU\n", 2251799813685248LU);
    printf("2251799813685248LU %%f: %f\n", 2251799813685248LU);
    printf("2251799813685248LU %%a: %a\n", 2251799813685248LU);

    //printf("%d\n", 2147483648U);
    return;
}

void assignment_statement_type_conversion(void)
{
    short int astc_a, astc_x = 10;
    int astc_b = 2147483647, astc_y;
    //在赋值表达式中,计算结果会转换成 被赋值变量 的类型
    //可能会降级(demotion),也可能会升级(promotion)
    printf("%zd\n", sizeof(astc_a = astc_b));
    astc_a = astc_b;
    printf("%hd\n", astc_b);

    //赋值表达式计算结果升级(promotion)的情况
    printf("%zd\n", sizeof(astc_y = astc_x));
    return;
}


