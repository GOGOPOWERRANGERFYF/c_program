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
    int * int_pointer;
    int_pointer = malloc(8);
    printf("%p\n", int_pointer);
    return;
}