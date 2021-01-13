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
    int array2[5];
    // storage class存储类别
    // 数组与其他变量类似,可以把数组创建成不同存储类别
    // 第十二章将介绍存储类别的相关内容
    // 自动存储类别: 数组在函数内部声明,且声明没有使用static关键字
    // 不同的存储类别有不同的属性
    const int birthday[3] = {1987,11,9};
    // 数组使用前需要赋初值,如果没有赋值,
    // 编译器使用的值是内存相应位置的现有值.
    printf("%d\n", array2[0]);
    return;
}