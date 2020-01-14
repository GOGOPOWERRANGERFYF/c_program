#include <stdio.h>
// Floating-Point Operations 浮点数运算
// addition:
//exponent指数 指数计数法:1.0e9
//             科学计数法:1.0*10^9
//                   数字:1000000000
void main(void)
{
    float f1 = 111.111, fa = 1.4, fb = 0.1, \
    fc = 1.3999999, fd = 1.3999995, fe = 1.3999994;
    double dd = 1.3999995, de = 1.3999994;

    printf("f1(d):%d\n",f1);
    printf("sizeof(f1):%d\n", sizeof(f1));
    //format specific %f 默认保留小数点后六位
    printf("fa(f):%f\n", fa);
    printf("fb(f):%f\n", fb);
    printf("fc(f):%f, fc(a):%a\n", fc);
    printf("fd(f):%f, fd(a):%a\n", fd);
    printf("fe(f):%f, fe(a):%a\n", fe);
    //float double 格式说明符都是 %f
    printf("dd(f):%f, dd(a):%a\n", fd);
    printf("de(f):%f, de(a):%a\n", fe);
    printf("fa(.10f):%.10f,fa(a):%a\n", fa, fa);
    printf("fb(.10f):%.10f,fb(a):%a\n", fb, fb);
    printf("fa(.6a):%.6a\n", fa);
    printf("fb(.6a):%.6a\n", fb);
    
    printf("fa + fb(float):%f,fa + fb(a): %a\n", fa + fb, fa + fb);
    printf("fa - fb(float):%f,fa + fb(a): %a\n", fa - fb, fa - fb);
    printf("fa + fb(.6a): %.6a\n", fa + fb);
    printf("fa + fb(.6a): %.6a\n", fa - fb);
    return;
    // 1.4 -->  
    //  整数部分:    2 | 1 --> 余 1
    //  小数部分:  0.4 * 2 = 0.8 --> 0
    //            0.8 * 2 = 1.6 --> 1
    //            0.6 * 2 = 1.2 --> 1
    //            0.2 * 2 = 0.4 --> 0
    //            0.4 * 2 = 0.8 --> 0
    //            0.8 * 2 = 1.6 --> 1
    //            0.6 * 2 = 1.2 --> 1
    //            0.2 * 2 = 0.4 --> 0
    //            0.4 * 2 = 0.8 --> 0
    //            0.8 * 2 = 1.6 --> 1
    //            0.6 * 2 = 1.2 --> 1
    //            0.2 * 2 = 0.4 --> 0
    //            0.4 * 2 = 0.8 --> 0
    //            0.8 * 2 = 1.6 --> 1
    //            0.6 * 2 = 1.2 --> 1
    //            0.2 * 2 = 0.4 --> 0
    //            0.4 * 2 = 0.8 --> 0
    //            0.8 * 2 = 1.6 --> 1
    //            0.6 * 2 = 1.2 --> 1
    //            0.2 * 2 = 0.4 --> 0
    //            0.4 * 2 = 0.8 --> 0
    //            0.8 * 2 = 1.6 --> 1
    //            0.6 * 2 = 1.2 --> 1
    //            0.2 * 2 = 0.4 --> 0 rounding
    // 1.4(binary): 1. 0110 0110 0110 0110 0110 011|0 * (2^0)10
    //              1.  6    6    6    6    6     6(rounding)    
    // S      E               M
    // 0  01111111  01100110011001100110011           
    //                              
    // 0.1 -->
    //  整数部分:   2 | 0 --> 余 0   
    //  小数部分:  0.1 * 2 = 0.2 --> 0
    //            0.2 * 2 = 0.4 --> 0
    //            0.4 * 2 = 0.8 --> 0
    //            0.8 * 2 = 1.6 --> 1
    //            0.6 * 2 = 1.2 --> 1
    //            0.2 * 2 = 0.4 --> 0
    //            0.4 * 2 = 0.8 --> 0
    //            0.8 * 2 = 1.6 --> 1
    //            0.6 * 2 = 1.2 --> 1
    //            0.2 * 2 = 0.4 --> 0
    //            0.4 * 2 = 0.8 --> 0
    //            0.8 * 2 = 1.6 --> 1
    //            0.6 * 2 = 1.2 --> 1
    //            0.2 * 2 = 0.4 --> 0
    //            0.4 * 2 = 0.8 --> 0
    //            0.8 * 2 = 1.6 --> 1
    //            0.6 * 2 = 1.2 --> 1
    //            0.2 * 2 = 0.4 --> 0
    //            0.4 * 2 = 0.8 --> 0
    //            0.8 * 2 = 1.6 --> 1
    //            0.6 * 2 = 1.2 --> 1
    //            0.2 * 2 = 0.4 --> 0
    //            0.4 * 2 = 0.8 --> 0
    //            0.8 * 2 = 1.6 --> 1
    //            0.6 * 2 = 1.2 --> 1
    //            0.2 * 2 = 0.4 --> 0
    //            0.4 * 2 = 0.8 --> 0
    //            0.8 * 2 = 1.6 --> 1
    //
    // 0.1(binary): 0.0001 1001 1001 1001 1001 100|11001 * (2^0)10
    //      规格化: 0 0001.10011001100110011001100|1 * (2^-4)10       
    //        -->       1.10011001100110011001100|1(rounding) * (2^-4)10
    //        -->       1. 1001 1001 1001 1001 1001 101|0(rounding) * (2^-4)10
    //                  1.  9    9    9    9    9    a  * (2^-4)10
    //                  1.  9    9    9    9    9    a  * (p^-4)10
    //
    // 1.4 + 0.1 =  1. 0110 0110 0110 0110 0110 011 * (2^0)10
    //              1. 1001 1001 1001 1001 1001 100 * (2^-4)10
    //              
    //1. 0110 0110 0110 0110 0110 011 * (2^0)10 + 1. 1001 1001 1001 1001 1001 100 * (2^-4)10
    //[1. 0110 0110 0110 0110 0110 011  + 1. 1001 1001 1001 1001 1001 100 * (2^-4)10] * (2^0)10
    //[1. 0110 0110 0110 0110 0110 011  + 0. 0001 1001 1001 1001 1001 1001 100] * (2^0)10
    //
    //        1.01100110011001100110011
    //        0.000110011001100110011001(rounding)--|
    //        0.00011001100110011001101 <-----------|
    //        1.10000000000000000000000
}





