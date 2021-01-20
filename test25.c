// 第12章 存储类别.链接和内存管理
#include <stdio.h>
#include <stdlib.h>
void memory_allocation(void);

void main(void){
    memory_allocation();
    return;
}

// malloc 全称:memory allocation
// allocation 分配,拨给的场地
void memory_allocation(void){
    // 使用malloc()函数创建数组
    char * char_pointer;
    int * int_pointer;
    int_pointer = (int *)malloc(4 * sizeof(int));
    *int_pointer = 1;
    *(int_pointer + 1) = 2;
    *(int_pointer + 2) = 3;
    *(int_pointer + 3) = 4;

    printf("%zd\n", sizeof(int));
    printf("%d\n", 4 * sizeof(int));

    printf("%d\n", *int_pointer);
    printf("%d\n", *(int_pointer + 1));
    printf("%d\n", *(int_pointer + 2));
    printf("%d\n", *(int_pointer + 3));
    return;
}