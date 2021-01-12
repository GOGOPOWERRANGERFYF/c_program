// 第十章 数组和指针
//
#include <stdio.h>
void array_a(void);

void main(void){
    array_a();
    return;
}

void array_a(void){
    // 只存储单个值的变量有时也称标量变量(scalar variable)
    int i1 = 1;
    // 从ANSI C开始支持这种初始化,
    // 不支持ANSI的编译器需要在数组声明前加static
    // 逗号分隔的值列表
    int array1[5] = {2,4,6,8,10};
    return;
}