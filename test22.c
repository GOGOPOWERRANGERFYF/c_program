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

// 9.7.1 *间接运算符(乘法运算法与间接运算符都是*)
//  direction 方向;动向
//  indirection 迂回;间接
//  indirection operator 间接运算符
//   

int pointer_a(void){
    int a = 10, b, *int_pointer1;
    // & 地址运算符 P624
    // 把int类型变量a的地址赋给int_pointer1
    // 这里的地址是指虚拟地址,不是物理地址
    int_pointer1 = &a;
    // 个人理解为啥叫间接运算符
    // 通过指针变量保存的另一个变量的地址
    // &a 取地址运算符,取变量a的地址
    // pointer = &a 变量a的地址赋给指针变量
    // b = *pointer 间接运算符,通过指针变量保存的a变量地址找到变量a的值
    // 以上两步可以直接一步解决: b = a
    // 所以叫间接运算符
    b = *int_pointer1;
    printf("%d\n", b);
    return 0;
}