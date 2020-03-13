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
    while_loop_function(10);
    return;
}

// 函数头圆括号中包含了一个int类型变量n的声明
void while_loop_function(int n)
{
    while (n-- > 0){
        printf("-");
    }
    printf("\n");
    return;
}

// formal argument / formal parameter 形参(形式参数)
// actual argument / actual parameter 实参(实际参数)
// C99标准中:
//    actual argument / actual parameter term术语 argument实参
//    formal argument / formal parameter term术语 parameter形参
// 1.形参是函数头圆括号中声明的变量,例如: 上面程序的变量n
// 2.实参是函数调用时提供的值,例如: 上面程序的变量c,a,f;常量10;
//                                         表达式也可以,比如 c+1
//
// void while_loop_function(int n) 函数头
// 圆括号中的变量声明创建了称为形参的变量n
//
// while_loop_function(10); 函数调用(function call)
// 把实参10传递给函数
//