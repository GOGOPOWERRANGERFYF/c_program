// 第九章 函数

// 9.1
// ......
// 9.6

#include <stdio.h>
int pointer_a(void);

int main(void){
    pointer_a();
    return 0;
}

// 9.7 指针简介
// 指针: pointer
// 从根本上看,指针是一个值为内存地址的变量(或数据对象)
// char类型变量的值是字符,int类型变量的值是整数,指针变量的值是地址
int pointer_a(void){
    int a = 10, b, *int_pointer1;
    // & 地址运算符 P624
    int_pointer1 = &a;
    b = *int_pointer1;
    printf("%d\n", b);
    return 0;
}

// 9.7.1 *间接运算符(乘法运算法与间接运算符都是*)
//  