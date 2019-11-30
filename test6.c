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
// 数符            指数                      尾数
//           阶符1bit 阶码7bit
// 1bit            8bit                    23bit
//  0           0   10              (隐含1.) 1011    注:非真实存储数据,只是描述存储了哪部分
//     
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






