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


// 数学知识(0是否为自然数并没有定论):
// 质数(素数): 质数是指在大于1的自然数中,除了1和它本身外没有其它因数的自然数
//            除了1和本身,还有其它因数的称为合数
// (* 0和1既不是素数也不是合数)
// 因数(约数)factor; 质因数(素因数)
// 合数都能分解成质因数
// 分解质因数:每个合数都能写成几个质数相乘的形式,其中每个质数都是这个合数的因数(质因数)
//              合数=质因数*质因数...的形式
//  把一个合数用质因数相乘的形式表示出来,叫做分解质因数.分解质因数值只针对合数
// 下面都是野路子理解(还是要补一下上面的数学知识)......
// sieve of erathosthenes 埃拉托色尼筛法,也称素数筛
// 找出一定范围内的所有素数
// 首先2为质数
// 遍历从2开始,穷举包含质因数2的所有合数(在N的范围以内)
// *合数n只能分解出1~n之间的质因数(大于n就分解出小数了,就不是自然数了)
// 遍历从3开始,穷举包含质因数3的合数
// (为什么从3*3开始,因为2*j筛选包含质因数2的合数时已经把筛过了,没必要再筛了)
// 遍历从5开始,穷举包含质因数5的合数
// (为什么不从5*2,5*3,5*4开始遍历,因为1,3已算在分解出质因数2的合数中,已筛过,
//  2已算在分解出质因数3的合数中,已筛过,没必要重复)
//  但5*5之后的自然数还是存在重复筛的(计算质因数2和质因数3已筛过),有部分存在重复计算
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
        // 例如: i * j = 2 * 2 = 4; sequence[i*j]=sequence[4]=4 
        //      4没有必要再循环乘以后面的元素了,因为乘积与2与后面的元素乘积是重叠的(都是2的倍数)
        //      再计算一遍纯属多余
        //      数组遍历到已经被赋值为0的元素,肯定时前面某个元素值的倍数,因此无需再计算
        if (sequence[i])
            //数组: i[0] ... i[N-1] 
            //元素:   0  ... N-1
            //这里的数组下标与元素的值时一致的
            // i =2 j = 2 i*j --> 2乘以自身至N-1,但乘积大于N时停止循环,
            // 因为已经超出了我们寻找素数的范围
            // 筛选2和N之间的可以整除2的合数,筛掉,将元素设置为0
            // 
            // 1能被所有自然数整除,且1不是素数(1是广义的素数)
            // 1和3之间自然数只有2,2并不能乘以任何自然数等于3
            //
            // 理解素数筛的关键:
            // 1和n之间的自然数并没有相乘等于n的,n为素数
            // n+1只有乘以小数才有可能等于n,除去1和n本身,只能在[2,n-1]区间内找自然数
            // 2为最小的质数
            // 筛到n时,[2,n-1]区间的自然数已经相互相乘过了,包括各个数自身相乘
            // 如果乘积没有等于n的,n为质数,反之,n为合数
            for (j = i; i * j < N; j++) sequence[i * j] = 0;
    for (i = 2; i < N; i++)
        if (sequence[i])
            printf("%d\n", i);  
    return;
}