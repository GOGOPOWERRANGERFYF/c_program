// 带参数的函数
#include <stdio.h>

void while_loop_function(int n);

void main(void)
{
    char c;
    int a;
    float f;
    //自动类型转换
    c = 'A';
    a = 5.5F;
    f = 10;
    while_loop_function(c);
    while_loop_function(a);
    while_loop_function(f);
    return;
}

void while_loop_function(int n)
{
    while (n-- > 0){
        printf("-");
    }
    printf("\n");
    return;
}

