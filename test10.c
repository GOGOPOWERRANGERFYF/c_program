#include <stdio.h>

void main(void)
{
    int i_a = 1, i_b = 1;
    // ++ 递增运算符(increment operator),将其运算对象operand递增1
    // 看了运行结果,i++后缀模式,表达式本身没自增
    //             ++i前缀模式,表达式本身有自增
    printf("%d %d\n", i_a, i_a++);
    printf("%d %d\n", i_b, ++i_b);
    return;
}


