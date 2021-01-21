#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#define N 20
typedef float height;
typedef int randomNumber;
void sieve_of_erathosthenes(void);

void main(void){
    //height h1 = 1.72;
    //printf("person height: %.2fm\n", h1);

    //randomNumber counter, rn1;
    //printf("sizeof(rand()) %dbyte.\n", sizeof(rand()));
    //for (counter = 1; counter < 6; counter++){
    //    rn1 = rand();
    //    printf("random number: %d\n", rn1);
    //}

    sieve_of_erathosthenes();
    return;
}
// 《算法:C语言实现》 
//  第二部分 数据结构
//  abstract data type 抽象数据类型
//  int float char 这些为c语言内置数据类型
//  定义3.1 数据类型是值的集合和在这些值上的操作集  
//  declare 声明

// ascii to integer function
// atoi()


// sieve of erathosthenes 埃拉托色尼筛法,也称素数筛
// 找出一定范围内的所有素数
// 素数(质数prime number),在大于1的自然数中,除了1和自然数自身,无法被其它自然数整除的数
// 在大于1的自然数中,除了1和自然数自身,能被其它自然数整除的数称为合数
// 遍历从2开始(1能被自己和1整除),然后把2的倍数筛掉,
// 因为它们不仅能被1和自己整除,知道还能被2整除,肯定不是素数
void sieve_of_erathosthenes(void){
    int index, i, sequence1[N], sequence2[N];    
    // 自动存储类型,数组不初始化,元素会有垃圾值,并不一定是0
    // 一个十六进制位相当于四个二进制位
    for (i = 0; i < N; i++){
        printf("array sequence1 element (hex): %08x\n", sequence1[i]);
    }
    // 与指定初始化器一致,只要有一个元素初始化了,剩余的元素会被编译器初始化为0
    sequence2[15] = 5;
    for (i = 0; i < N; i++){
        printf("array sequence2 element (hex): %08x\n", sequence2[i]);
    }
     
    //for (index = 2; index < N; index++) sequence[index] = 1;
    //for (index = 0; index < N; index++) printf("index%2d: %d\n",index , sequence[index]);
    return;
}