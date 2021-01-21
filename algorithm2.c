#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
typedef float height;
typedef int randomNumber;

void main(void){
    //height h1 = 1.72;
    //printf("person height: %.2fm\n", h1);

    randomNumber counter, rn1;
    printf("sizeof(rand()) %dbyte.\n", sizeof(rand()));
    for (counter = 1; counter < 6; counter++){
        rn1 = rand();
        printf("random number: %d\n", rn1);
    }
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


// sieve of erathosthenes 埃拉托斯特尼筛法,也称素数筛
// 找出一定范围内的所有素数
void sieve_of_erathosthenes(void){
    
    return;
}