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
    // *和变量名之间有没有空格都行
    // 通常指针声明时空格,解引用变量时省略空格
    int a = 10, b, * int_pointer1;
    // & 地址运算符 P624
    // 把int类型变量a的地址赋给int_pointer1
    // 这里的地址是指虚拟地址,不是物理地址
    int_pointer1 = &a;
    // 个人理解为啥叫间接运算符
    // 通过指针变量保存的另一个变量的地址
    // &a 地址运算符,给出变量a的地址
    // pointer = &a 变量a的地址赋给指针变量
    // b = *pointer 间接运算符,后面可跟指针变量名或地址
    //  给出存储在指针变量的地址指向的值
    // 以上两步可以直接一步解决: b = a
    // 所以叫间接运算符
    b = *int_pointer1;
    printf("%d\n", b);
    return 0;
}
// 9.7.2 声明指针

// 注意: 指针是一个新类型,不是整数类型,一些用来处理整数的操作
//      不能用来处理指针.
//      指针类型 转换说明 %p
