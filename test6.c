#include <stdio.h>
//===================================================================================
//二进制转十进制 1011 >> 1*2^3 + 1*2^1 + 1*2^0 = 11(10)
//十进制转二进制原理  
// 11(10) = 1*2^3 + 1*2^1 + 1*2^0    =       1*8 + 1*2 + 1*1
//           /2      /2      /2    位值 1    /2    /2    /2 
//          1*2^2 + 1*1^1                    1*4 +  1*1 
//           /2      /2            位值 1    /2    /2 
//          1*2^1                            1*2 
//           /2                    位值 0    /2
//            1                               1
//===================================================================================
// 11(2) 1*2^1 + 1*2^0         10(2) 1*2^1 + 0*2^0
//         /2     /2   位值 1         /2      /2    位值 0
//       1*2^0                       1*2^0    
//         /2          位值 1         /2            位值 1
//===================================================================================
// 101(2) 1*2^2 + 0*2^1 + 1*2^0
//         /2      /2       /2    位值 1
//        1*2^1   0*2^0
//         /2      /2             位值 0
//        1*2^0   
//         /2                     位值 1
//===================================================================================
//个人理解:位权 除 2,除到位权为1,位值*位权=位值*1=位值
//        两种情况: a. 1*1=1; b. 0*1=0 
//        所以：结果为1，则位值为1;结果为0,则位值为0。
//理解关键:前一位的权值比当前位的权值大一个2^1,
//        所以当前位的权值被除到结果为1(2^0)时,前一位的权值被除到结果为2^1
//===================================================================================
// 6.75(10) >> 110.11(2)
// 科学计数法  十进制 123.456*10^2(10) 1.23456*10^4(10) 0.123456*10^5(10)
//            二进制 A: 1.1011*2^2(2)   整数部分最高位1放小数点前
//                  B: 0.11011*2^3(2)  整数部分最高位1放小数点后   
//计算机中以A方式存储浮点数的尾数,默认隐含1.
//在内存中尾数以1011存储,整数部分最高位肯定为1,隐藏1.，原因如下:
//不以B方式储存是为了节省存储空间吧...到底是不是要去问创造C语言的大佬(￣ェ￣;)
//计算机中浮点数的存储方式(以float 6.75 为例,float数据类型存储长度为4个字节byte 32位bit):
//以下内容在《计算机科学导论》P36 更详细
//附加知识点:尾数以符号加绝对值表示法储存 《计算机科学导论》P30
// 符号            指数                     定点数    科学计数法
// 符号            指数                     尾数      规范化
//           阶符1bit 阶码7bit
// 1bit            8bit                   23bit
//  0           0   10              (隐含1.)1011    注:非真实存储数据,只是描述存储了哪部分(小数点左边保留一位数码)
// 0|1             余码             (隐含1.)10110000000000000000000 尾数右边填充0直到填满23位存储单元
//比较两个浮点数大小的先后顺序,出现数值相等的情况才会继续下一步,不相等则直接得到比较大小的结果:
// 先比较 符号位   (+ > -) (0 > 1)   这个是我自己想的... 等后面看到教程或书籍有提到才能证实--'
//        指数   规范化后 指数越大当然浮点数越大
//        尾数   用比较整数的方法比较大小  从高位向低位比较   01110 > 01101
//-----------------------------------------------------------------------------------
//这里说的都是 机器码原码 机器码补码(与数学上的补码/补数有区别) 机器码移码
//原码用 符号位+绝对值 表示
//原码  011         3      补码    011
//      010         2             010
//      001         1             001
//      000         0             000
//      101        -1             111
//      110        -2             110
//      111        -3             101
//                 -4             100   
//字长n=3时,可看出 -4只有补码没有原码,原码没有-0(100),补码中用-0(100)来表示-4
//-----------------------------------------------------------------------------------
//补码由来:  000 001 010 011 | 100 101 110 111   (1段 分隔符 2段)
//          100 101 110 111 | 000 001 010 011   (2段 分隔符 1段)
//          -4  -3  -2  -1     0   1   2   3
//特性 001与111互为补码,mod模为1000
//-----------------------------------------------------------------------------------
//移码  111   7      3    (以十进制数0为起点向上移)
//      110   6      2 
//      101   5      1 
//      100   4      0 
//      011   3     -1 
//      010   2     -2 
//      001   1     -3 
//      000   0     -4  
//特性: 通过同上面的补码对比可得出,移码和补码之间只需把符号位取反即可实现互相转换
//      移码和补码互相转换规则: 移码为非负数(0和正整数),符号位由1取反为0,得到补码
//                            移码为负数(负整数),符号位由0取反为1，,得到补码
//      移码在计算机中用来储存浮点数的指数n(2^n),数学老师说：指数有正负,指数都为整数(数学老师说:我没说过。。。)
//
// 移码可转成补码,再转原码(当然,在字长n(存储长度)一定的情况下,有一个特殊的补码(代表负数最小值那个)是没有原码的)
//-----------------------------------------------------------------------------------
//*浮点数指数在计算机中使用余码储存
//余码计数法:
//
//
int main(void) 
{
    //power 幂 科学计数法 1*10^8、2.234*10^6
    //exponent 指数计数法中的指数 指数计数法 1.334e10、2.14e-3
    float f1 = 1e6, f2 = .001234, f3 = 123., f4 = 666.666;
    double d1, d2 = 666.666;
    long double ld1;

    printf("This is float:%f,%f,%f,%f.\n", f1, f2, f3, f4);
    printf("Size of float variable:%d.\n", sizeof(f1));
    //char constant(字符常量)与int constant(整数常量一样),占4个字节
    //float constant(浮点数常量)为double float(双精度浮点型), 占8个字节.
    printf("Size of float constant:%d.\n", sizeof(111.001));
    printf("Size of dobule variable:%d.\n", sizeof(d1));
    printf("Size of long dobule variable:%d.\n", sizeof(ld1));
    printf("This is double:%lf\n", d2);
    return 0;
}






