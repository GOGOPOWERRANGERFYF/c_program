#include <stdio.h>

void main(void)
{
    int i_a = 1, i_b = 1;
    // 看了运行结果,i++后缀模式,表达式本身没自增
    //             ++i前缀模式,变量值本身自增
    printf("%d %d\n", i_a, i_a++);
    printf("%d %d\n", i_b, ++i_b);
    return;
}


