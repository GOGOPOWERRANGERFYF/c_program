// 第十章 数组和指针
//
#include <stdio.h>
void array_a(void);
void designated_initializer(void);
int array_element_assignment(void);

void main(void){
    array_a();
    designated_initializer();
    array_element_assignment();
    return;
}

void array_a(void){
    // 只存储单个值的变量有时也称标量变量(scalar variable)
    int i1 = 1;

    const int birthday[3] = {1987,11,9};
    // 从ANSI C开始支持这种初始化,
    // 不支持ANSI的编译器需要在数组声明前加static
    // 逗号分隔的值列表
    int array1[5] = {2,4,6,8,10};
    int array2[5];
    // 初始化列表的元素个数少于数组元素个数时,编译器会把剩余的元素初始化为0
    // 初始化列表的元素个数多于数组元素个数时,编译器会把提示错误
    int array3[5] = {2,4};
    // 让编译器自动匹配数组元素个数并初始化
    int array_auto1[] = {1,2,3,4,5,6,7,8};

    // storage class存储类别
    // 数组与其他变量类似,可以把数组创建成不同存储类别
    // 第十二章将介绍存储类别的相关内容
    // 自动存储类别: 数组在函数内部声明,且声明没有使用static关键字
    // 变量和数组不同的存储类别有不同的属性

    // 自动存储类别数组使用前需要赋初值,如果没有赋值,
    // 编译器使用的值是内存相应位置的现有值.

    // 对于其他一些存储类别的变量和数组,如果声明时未初始化
    // 编译器会把它们的值设置为0
    // 如果是自动存储类别,数组的值是随机变动的(所以static为静止的固定值为0)
    printf("array2[0]: %d\n", array2[0]);
    printf("array3[0]: %d\n", array3[3]);
    printf("array_auto1[0]: %d\n", array_auto1[7]);
    // size 大小,尺码
    printf("array size of array2: %d bytes\n", sizeof(array2));
    return;
}

// designated 指定;指明
// initializer 初始值;初始化程序
// designated initializer 指定初始化器 (C99标准)
// 指定初始化的元素
void designated_initializer(void){
    int array1[5] = {[4]=15};
    // 声明数组后,可以借助数组下标subscript(索引index)给数组元素赋值
    int array2[2];
    array2[1] = 5;

    printf("%d\n", array1[4]);
    printf("%d\n", array2[1]);
    return;
}

// 给数组元素赋值
int array_element_assignment(void){
    // c不允许把数组作为一个单元赋给另一个数组 
    int array1[5];
    int i;
    // 花括号初始化列表 只能在数组初始化时使用,声明之后是没有办法使用的
    // error错误: array1[5] = {1,2,3,4,5};
    // error错误: array1 = {1,2,3,4,5};
    // array1[5] = 1; 数组下标越界
    // array1数组的最后一个元素array1[5-1]
    for (i = 0; i < 5; i++){
        array1[i] = 2 * i;
        printf("array1[%d]: %d\n", i, array1[i]);
    }
    return 0;
}
// 在C标准中,使用越界下标的结果是未定义的
// 编译器是不会检查使用的数组下标是否越界的
// 程序可以编译运行,但运行结果会很奇怪,或异常中止

