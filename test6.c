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
//-----------------------------------------------------------------------------------
// 11(2) 1*2^1 + 1*2^0         10(2) 1*2^1 + 0*2^0
//         /2     /2   位值 1         /2      /2    位值 0
//       1*2^0                       1*2^0    
//         /2          位值 1         /2            位值 1
//-----------------------------------------------------------------------------------
// 101(2) 1*2^2 + 0*2^1 + 1*2^0
//         /2      /2       /2    位值 1
//        1*2^1   0*2^0
//         /2      /2             位值 0
//        1*2^0   
//         /2                     位值 1
//-----------------------------------------------------------------------------------
//个人理解:位权 除 2,除到位权为1,位值*位权=位值*1=位值
//        两种情况: a. 1*1=1; b. 0*1=0 
//        所以：结果为1，则位值为1;结果为0,则位值为0。
//理解关键:前一位的权值比当前位的权值大一个2^1,
//        所以当前位的权值被除到结果为1(2^0)时,前一位的权值被除到结果为2^1
//===================================================================================
//二进制浮点数小数部分转换十进制:
// .101 = 1*2^-1 + 0*2^-2 + 1*2^-3
//      = 1/2^1  + 0/2^2  + 1/2^3 
//      = 1/2    + 0/4    + 1/8
//      = 0.5    + 0      + 0.125   = 0.625
//十进制浮点数小数部分转换二进制:
// 0.625 * 2 = (1/2 *2) + (1/8 *2)
// 1.25      = 1        +  1/4    
// 0.25      =             1/4       ---->   1
// 0.25  * 2 =             1/4 *2
// 0.5       =             1/2       ---->   0
// 0.5   *2  =             1/2 *2
// 1.0       =             1         ---->   1
// 得到 (.101)2 
// 原理: (.111)2 = 1/2 + 1/4 + 1/8
//       第一次乘2,得到小数点后第一位数值,如果数值是1的话,乘2的结果肯定有整数1,反之,则数值为0
//       第二次乘2,得到小数点后第二位数值,跟上面道理是一样的,后面的依此类推
//       二进制,数值不是0就是1,真舒服...
//       数值为1的话,肯定能余1,为0的话就不会有余数1啦
//===================================================================================
//十进制乘法理解:
//        11
//      * 11
//     ------
//        11
//       11
//    -------
//       121
//1. 第二行第一个数  a:1个1,结果放在个位  b:1个10,结果放在十位,是1,十位的权值是10
//2. 第二行第二个数  a:10个1,结果放在十位,是1  b:10个10,结果放在百位,是1
//二进制也是一样的,位置计数法原理都一样,举一反三。。。举一反N
//===================================================================================
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
//===================================================================================
//offset binary code 偏移二进制码
//小知识点:w(字长)=3,000的2补数是000
//                                                       offset binary code
//                                           excess_3(bias=(2^w-1)-1=3)    excess_4(bias=2^w-1=4)
//  decimal code | two's complement binary |      (bias binary=011)           (bias binary=100)                      
//        3                 011                         110                       111 
//        2                 010                         101                       110
//        1                 001                         100                       101
//        0                 000                         011                       100
//       -1                 111                       1(010)                    1(011)
//       -2                 110                       1(001)                    1(010)
//       -3                 101                       1(000)                    1(001)
//       -4                 100                         111                     1(000)
//由上表可看出: excess_3与IEEE754标准的excess_127原理是一样的,只是exponent field的字长word不一样
//因此同理可得: 000,111用作 非规格化值 和 特殊值 的移码(课本译作阶码,移码有多个专业名字,具体看英文wiki,太多不想记,脑子不够用...)
//             [001,110]用作 规格化值(standard format) 的移码,观察移码映射到的十进制值,可通过移码(把移码编码当无符号整数编码看)直观地比较大小
//             这就是用移码做指数字段编码的原理
//20200102*: w位二进制数计算,移码减偏置量还等于加偏置量前的补码(二补数)的本质
//           1) 加移码后结果没有溢出,011+011=110, 110-011=110+(1000-011)=110-011+1000(加二补数的本质)
//              结果溢出,计算机只保留w=3位,得到正确结果,又得到011
//           2) 加移码后结果溢出,计算机只保留结果w=3位,例如: 001-011=001+(1000-011)=001-011+1000=1001-011
//
//计算机中浮点数最直观的理解:
//                    sign   exponent    mantissa
//float(单精度浮点型): 0      0000 0000   0000 0000 0000 0000 0000 001   最小非规格化数  
//  二进制表示: value(binary)   = 0.0000 0000 0000 0000 0000 001 * 10^(0000 0001-0111 1111)   excess_127=bias=127(decimal)=0111 1111(binary)
//                             = 0.0000 0000 0000 0000 0000 001 * 10^(-0111 1110)
//  十进制表示: value(decimal)  = 1/2^23 * 2^(-126)
//                             = 2^(-23) * 2^(-126)
//                             = 2^(-149)
//  最小非规格化数(十进制表示) = M * 2^E = 2^-23 * 2^(-126) = 2^(-149) 
//                                                        ≈ 1.4 * 10^(-45)  
//
//                    sign   exponent    mantissa
//float(单精度浮点型): 0      0000 0001   0000 0000 0000 0000 0000 000   最小规格化数  
//  二进制表示: value(binary)   = 1.0000 0000 0000 0000 0000 000 * 10^(0000 0001-0111 1111)   excess_127=bias=127(decimal)=0111 1111(binary)
//                             = 1.0000 0000 0000 0000 0000 000 * 10^(-0111 1110)
//  十进制表示: value(decimal)  = 1*2^0 * 2^(-126) = 2^-126
//                             = 1/2^126
//                             ≈ 1.2 * 10^-38
//
//                    sign   exponent    mantissa
//float(单精度浮点型): 0      1111 1110   1111 1111 1111 1111 1111 111   最大规格化数  
//   二进制表示: value(binary)  = 1.1111 1111 1111 1111 1111 111 * 10^(1111 1110-0111 1111)   excess_127=bias=127(decimal)=0111 1111(binary)
//                             = 1+(1-0.0000 0000 0000 0000 0000 001) * 10^(0111 1111)
//                             = [1+(1- 10^-00010111] * 10^(0111 1111)
//  十进制表示: value(decimal)  = [1+(1- 2^-23)] * 2^127
//                             = (2 - 2^-23) * 2^127
//                             = 2*2^127 - 2^-23 * 2^127
//                             = 2^(1+127) - 2^(-23+127)
//                             = 2^128 - 2^104
//                             = 2^128 - 2^104
//                             = 2^128 - 2^104
//                             ≈ 3.4 * 10^38 = 3.4e38
//
//结论:浮点数有正负0,正负float取值范围是对称的,float的取值范围[-3.4e38,3.4e38],double/long double同理
//-----------------------------------------------------------------------------------
// 6.75(10) >> 110.11(2)
// 科学计数法  十进制 123.456*10^2(10) 1.23456*10^4(10) 0.123456*10^5(10)
//            二进制 A: 1.1011*2^2(2)   整数部分最高位1放小数点前
//                  B: 0.11011*2^3(2)  整数部分最高位1放小数点后   
//计算机中以A方式存储浮点数的尾数,默认隐含1.
//在内存中尾数以1011存储,整数部分最高位肯定为1,隐藏1.，原因如下:
//不以B方式储存是为了节省存储空间吧...到底是不是要去问创造C语言的大佬(￣ェ￣;)
//计算机中浮点数的存储方式(以float 6.75 为例,float数据类型存储长度为4个字节byte 32位bit):
//以下内容在《计算机科学导论》P36 更详细
//附加知识点:尾数以符号加绝对值表示法储存(sign+mantissa) 《计算机科学导论》P30
// 符号            指数                     定点数    科学计数法
// 符号            指数                     尾数      规范化
//           阶符1bit 阶码7bit
// 1bit            8bit                   23bit
//  0           0   10              (隐含1.)1011    注:非真实存储数据,只是描述存储了哪部分(小数点左边保留一位数码)
// 0|1             余码             (隐含1.)10110000000000000000000 尾数右边填充0直到填满23位存储单元
//比较两个浮点数大小的先后顺序,出现数值相等的情况才会继续下一步,不相等则直接得到比较大小的结果:
// 先比较 (个人假想,待验证)符号位sign   (+ > -) (0 > 1)   这个是我自己想的... 等后面看到教程或书籍有提到才能证实--'
//        指数exponent    规范化后 指数越大当然浮点数越大
//        尾数mantissa   用比较整数的方法比较大小  从高位向低位比较   01110 > 01101
//===================================================================================
//fractional 分数的,小数的
//fraction 分数,小数
//standard 标准
//移码(偏码.增码.译码,余码)
//offset binary:偏移二进制码
//excess:超过,超过的量 1)excess_127:偏移量127(IEEE754偏移量) 2)excess_128(标准偏移量)
//IEEE754标准 移码(计算机中存储的移码)
//-----------------------------------------------------------------------------------
//《深入理解计算机系统》(第三版) P80 图2-35 理解计算机浮点数格式的秘籍啊......
//指数exponent的值分三种情况,以float数据类型为例:
//  A. 规格化的值: 
//     exponent field为[0000 0001,0111 1111] --> [1,254]
//     E= e-127(bias偏置值) = [1,254]-127  ---> [-126,127]
//                          = [0000 0001,0111 1111] - [0111 1111]  
//     M(尾数的值) = 1+f(描述小数值 .f-1 f-2 ...)
//     mantissa尾数 隐含1. ,所以规格化的值无法表示0         
//
//  B. 非规格化的值: 
//     阶码字段全是0,exponent field指数字段(书本译作阶码)为[0000 0000]
//     E= 1-127(bias偏置值) = -126
//     M(尾数的值) = f(描述小数值)
//     mantissa尾数 隐含0.(书本不隐含1.)
//     sign为0,exponent全为0: 1) mantissa全为0     表示 +0
//                            2) mantissa: M = f  表示 +0.bbb...
//     sing为1,exponent全为0: 1) mantissa全为0     表示 -0
//                            2) mantissa: M = f  表示 -0.bbb...
//
//  C  特殊值:
//     a) exponent field[1111 1111],小数域全为0[0000 0000 0000 0000 000]
//        sign为0,+∞ 正无穷
//        sign为1,-∞ 负无穷
//        
//     b) exponent field[1111 1111],小数域为非0,结果值被称为"NaN"(Not a Number)
//看完上面这段文字如果你一脸懵逼,你是不是怀疑人生,觉得自己很蠢,你就是个傻子,哈哈哈哈~
//没事~接下来直接看下面这个正浮点数的表~哈哈哈哈哈哈哈哈 
//
//正浮点数: 1) 这里的f表示小数部分,小数=整数部分.小数部分
//         2) 下表中 假设指数字段3bit,尾数字段2bit,符号位不说也知道是1bit吧
//                     sign  exponent  mantissa    word
//             float   1bit   8bit      23bit   4byte 32bit
//             double  1bit  11bit      52bit   8byte 64bit
//         3) b(bias偏置量)=2^(3-1)-1=3
//         4) e:假定阶码(指数)字段是一个无符号整数所表示的值
//            E:偏置之后的阶码(指数)值
//
//  --------------------bias(binary)------------------------bias(decimal)-------------------------------------------------------------------
//             float   1000 0000 - 0000 0001=0111 1111     1*2^7 - 1 = 127  
//             double  同上,位数填满到11位                   1*2^10 - 1 = 1023
//     -------位表示bit representation--------             
//     sign[S]   exponent[E]    mantissa[M]       [S]  [E]decimal--fraction  [M]mantissa  ---------------[value]--------------
//   非规格数---------------------------------           e  E=(1-b)   2^E     binary      binary *decimal      decimal fraction
//       0           000         00   (0+f)        +    0   -2       1/4      0.00       (0.00)2 * 2^-2   (0*1 + 0*1/2 + 0*1/4) * 1/4 = 0/16
//       0           000         01   (0+f)        +    0   -2       1/4      0.00       (0.01)2 * 2^-2   (0*1 + 0*1/2 + 1*1/4) * 1/4 = 1/16 
//       0           000         10   (0+f)        +    0   -2       1/4      0.00       (0.10)2 * 2^-2   (0*1 + 1*1/2 + 0*1/4) * 1/4 = 2/16
//       0           000         11   (0+f)        +    0   -2       1/4      0.00       (0.11)2 * 2^-2   (0*1 + 1*1/2 + 1*1/4) * 1/4 = 3/16 
//   规格数-----------------------------------
//       0           001         00   (1+f)        +    1   -2       1/4      1.00       (1.00)2 * 2^-2   (1*1 + 0*1/2 + 0*1/4) * 1/4 = 4/16
//       0           001         01   (1+f)        +    1   -2       1/4      1.01       (1.01)2 * 2^-2   (1*1 + 0*1/2 + 1*1/4) * 1/4 = 5/16
//       0           001         10   (1+f)        +    1   -2       1/4      1.10       (1.10)2 * 2^-2   (1*1 + 1*1/2 + 0*1/4) * 1/4 = 6/16
//       0           001         11   (1+f)        +    1   -2       1/4      1.11       (1.11)2 * 2^-2   (1*1 + 1*1/2 + 1*1/4) * 1/4 = 7/16
//
//       0           010         00   (1+f)        +    2   -1       1/2      1.00       (1.00)2 * 2^-1   (1*1 + 0*1/2 + 0*1/4) * 1/2 = 8/16
//       0           010         01   (1+f)        +    2   -1       1/2      1.01       (1.01)2 * 2^-1   (1*1 + 0*1/2 + 1*1/4) * 1/2 = 10/16
//       0           010         10   (1+f)        +    2   -1       1/2      1.10       (1.10)2 * 2^-1   (1*1 + 1*1/2 + 0*1/4) * 1/2 = 12/16
//       0           010         11   (1+f)        +    2   -1       1/2      1.11       (1.11)2 * 2^-1   (1*1 + 1*1/2 + 1*1/4) * 1/2 = 14/16
//
//       0           011         00   (1+f)        +    3    0        1       1.00       (1.00)2 * 2^0    (1*1 + 0*1/2 + 0*1/4) *  1  = 16/16
//       0           011         01   (1+f)        +    3    0        1       1.01       (1.01)2 * 2^0    (1*1 + 0*1/2 + 1*1/4) *  1  = 20/16 
//       0           011         10   (1+f)        +    3    0        1       1.10       (1.10)2 * 2^0    (1*1 + 1*1/2 + 0*1/4) *  1  = 24/16
//       0           011         11   (1+f)        +    3    0        1       1.11       (1.11)2 * 2^0    (1*1 + 1*1/2 + 1*1/4) *  1  = 28/16 
//
//       0           100         00   (1+f)        +    4    1        2       1.00       (1.00)2 * 2^1    (1*1 + 0*1/2 + 0*1/4) *  2  = 32/16
//       0           100         01   (1+f)        +    4    1        2       1.01       (1.01)2 * 2^1    (1*1 + 0*1/2 + 1*1/4) *  2  = 40/16
//       0           100         10   (1+f)        +    4    1        2       1.10       (1.10)2 * 2^1    (1*1 + 1*1/2 + 0*1/4) *  2  = 48/16
//       0           100         11   (1+f)        +    4    1        2       1.11       (1.11)2 * 2^1    (1*1 + 1*1/2 + 1*1/4) *  2  = 56/16
//
//       0           101         00   (1+f)        +    5    2        4       1.00       (1.00)2 * 2^2    (1*1 + 0*1/2 + 0*1/4) *  4  = 64/16
//       0           101         01   (1+f)        +    5    2        4       1.01       (1.01)2 * 2^2    (1*1 + 0*1/2 + 1*1/4) *  4  = 80/16
//       0           101         10   (1+f)        +    5    2        4       1.10       (1.10)2 * 2^2    (1*1 + 1*1/2 + 0*1/4) *  4  = 96/16
//       0           101         11   (1+f)        +    5    2        4       1.11       (1.11)2 * 2^2    (1*1 + 1*1/2 + 1*1/4) *  4  = 112/16
//
//       0           110         00   (1+f)        +    6    3        8       1.00       (1.00)2 * 2^3    (1*1 + 0*1/2 + 0*1/4) *  8  = 128/16
//       0           110         01   (1+f)        +    6    3        8       1.01       (1.01)2 * 2^3    (1*1 + 0*1/2 + 1*1/4) *  8  = 160/16
//       0           110         10   (1+f)        +    6    3        8       1.10       (1.10)2 * 2^3    (1*1 + 1*1/2 + 0*1/4) *  8  = 192/16
//       0           110         11   (1+f)        +    6    3        8       1.11       (1.11)2 * 2^3    (1*1 + 1*1/2 + 1*1/4) *  8  = 224/16
//   特殊值-----------------------------------
//       0           111         00   (1+f)        +∞ 正无穷       
//       0           111         ...  (1+f)        NaN(Not a Number)    
//   ----------------------------------------
//负浮点数道理同上[-0,-∞]
//===================================================================================
int main(void)
{
    //power 幂 科学计数法 1*10^8、2.234*10^6
    //exponent 指数计数法中的指数 指数计数法 1.334e10、2.14e-3
    //实数的两种格式,在C语言中可以像下面=后面那样这样省略:
    //decimal notation 11.11, 0.11=.11, 11.0=11 
    //exponential notation 1.23e2, 0.23e4=.23e4, 23.0e4=23e4, 19.11e-1=19.11 
    float f1 = 1e6, f2 = .001234, f3 = 123, f4 = 666.666, f_var, f_infinity, f_min;
    double d1, d2 = 666.666;
    long double ld1, ld2 = 6.6666666;
    //format specifier:格式说明符(c primer plus中文版翻转换说明,我觉得格式说明符更好)
    //format specifier example: %d %f...
    //decimal notation 十进制计数法 notation 记号,符号
    //exponential notation 指数计数法,e指数计数,
    printf("These is decimal notation float: %f, %f, %f, %f,.\n", f1, f2, f3, f4);
    printf("These is decimal notation double: %f, %f.\n", d1, d2);
    printf("These is exponential notation float: %e, %e, %e, %e.\n", f1, f2, f3, f4);
    printf("These is exponetial notation double: %e, %e.\n\n", d1, d2);
    //*注意:windows下用gcc编译(8.1.0),long double存在问题(网上说的,我linux系统删了,没法验证,但现在在windows7下确实输出结果有问题)
    printf("These is decimal notation long double: %Lf, %Lf.\n", ld1, ld2);
    printf("These is exponetial notation long double: %Le, %Le.\n\n", ld1, ld2);
    //float有效为最少6位,double有效位至少10位,long double有效位至少13位,有效位就是小数点后保留的位数
    //char constant(字符常量)与int constant(整数常量一样),占4个字节
    //*编译器默认假定浮点数常量为double型,8个字节，64位,想要float或long double constant的在后面加suffix后缀
    //浮点数常量后面加f或F,编译器会把这个浮点数常量看作float类型
    //浮点数常量后面加l(L小写)或L,则编译器会看作long double类型,建议加L,小写L跟1(阿拉伯数字一)太像了。。。
    //suffix:后缀
    printf("Size of float/double/long double constant(no suffix): %d,%d,%d.\n", \
        sizeof(111.111111), sizeof(111.1111111111e-2), sizeof(111.1111111111111));
    printf("Size of float constant(have suffix f or F): %d.\n", sizeof(111.11F));
    printf("Size of long double constant(have suffix L): %d.\n", sizeof(111.11L));
    printf("Size of float variable: %d.\n", sizeof(f1));
    printf("Size of dobule variable: %d.\n", sizeof(d1));
    printf("Size of long dobule variable: %d.\n", sizeof(ld1));
    printf("sizeof(f1*2.0f): %d, sizeof(2.0f*2.0f): %d, sizeof(2.0f*2.0): %d\n", \
        sizeof(f1*2.0f), sizeof(2.0f*2.0f), sizeof(2.0f*2.0));
    printf("sizeof(2e10+1.0):%d\n", sizeof(2e10+1.0));
    //printf("This is double:%.10f\n", d2);
    //printf("This is long double:%.20Lf\n", ld2);
    //*知识点:C99标准添加的十六进制浮点数常量格式: 
    // 1.ap10  mantisa:(1.a)16; 重点->p10=2^10  
    printf("float (hexadecimal,(mantissa)16*(10)16^E): %a\n", f_var=5.5F); //%a format specifier,以16进制hexadecimal指数形式输出浮点数
    printf("float (hexadecimal,(mantissa)16*(10)16^E): %a\n", f_var=1.2e-38F);
    printf("float Max(hexadecimal,(mantissa)16*(10)16^E): %a\n", f_var=3.4e38);
    printf("float Min(hexadecimal,(mantissa)16*(10)16^E): %a\n", f_var=-3.4e38);
    printf("float Max(hexadecimal,(mantissa)16*(10)16^E): %a\n", f_var=3.4e38);
    printf("float Min(hexadecimal,(mantissa)16*(10)16^E): %a\n", f_var=-3.4e38);
    printf("float Max(decimal): %f\n", f_var=3.4e38);
    printf("float Min(decimal): %f\n", f_var=-3.4e38);
    //infinity 无穷,无限
    printf("float +infinity(hexadecimal,(mantissa)16*(10)16^E): %a\n", f_infinity=3.4e39);
    printf("float +infinity(hexadecimal,(mantissa)16*(10)16^E): %a\n", f_infinity=3.5e38);
    printf("float -infinity(hexadecimal,(mantissa)16*(10)16^E): %a\n", f_infinity=-3.4e39);
    printf("float -infinity(hexadecimal,(mantissa)16*(10)16^E): %a\n", f_infinity=-3.5e38);

    return 0;
}




