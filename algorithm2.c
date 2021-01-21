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
    int i, j, sequence[N], sequence1[N], sequence2[N];    
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

    // 0和1非素数,索引2至N-1元素设置为1,默认为素数,待运算后确认为非素数再设置为0 
    // for循环对索引2(包括2)之后元素赋值,与指定初始化器一致,未初始化元素编译器会初始化为0
    for (i = 2; i < N; i++) sequence[i] = 1;
    for (i = 2; i < N; i++)
        if (sequence[i])
            //数组: i[0] ... i[N-1] 
            //元素:   0  ... N-1
            // i =2 j = 2 i*j --> 2乘以自身至N-1,但乘积大于N时停止循环,
            // 因为已经超出了我们寻找素数的范围
            // 筛选2和N之间的可以整除2的合数,筛掉,将元素设置为0
            // 
            // 1能被所有自然数整除,且1不是素数(1是广义的素数)
            // 1和3之间自然数只有2,2并不能乘以任何自然数等于3
            // 1和n之间的自然数并没有相乘等于n的,n为素数
            for (j = i; i * j < N; j++) sequence[i * j] = 0;
    for (i = 2; i < N; i++)
        if (sequence[i])
            printf("%d\n", i);  
    return;
}