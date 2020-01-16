#include <stdio.h>
// Floating-Point Operations 浮点数运算
//exponent指数 指数计数法:1.0e9
//             科学计数法:1.0*10^9
//                   数字:1000000000
void float_double_limits(void);
void float_double_addition(void);
void float_double_multiplication(void);

void main(void)
{
    float f1 = 111.111, fa = 1.4, fb = 0.1, \
    fc = 1.3999999, fd = 1.3999995, fe = 1.3999994;
    double dc = 1.3999999, dd = 1.3999995, de = 1.3999994;

    printf("f1(d):%d\n",f1);
    printf("sizeof(f1):%d\n", sizeof(f1));
    //format specific %f 默认保留小数点后六位
    //                %a float默认保留小数点后六位
    //                %a double默认保留小数点后十三位
    //double 即可用 %f 也可用 %lf
    printf("fa(f):%f\n", fa);
    printf("fb(f):%f\n\n", fb);
    printf("fc(f):%f, fc(a):%a\n", fc, fc);
    printf("fd(f):%f, fd(a):%a, fd(.7a):%.7a\n", fd, fd, fd);
    printf("fe(f):%f, fe(a):%a\n\n", fe, fe);
    //float double 格式说明符都是 %f
    printf("dc(f):%f, dc(a):%a, dc(.7a):%.7a\n", dc, dc, dc);
    printf("dd(f):%f, dd(lf):%lf, dd(a):%a, dd(.7a):%.7a\n", dd, dd, dd, dd);
    printf("de(f):%f, de(a):%a, de(.7a):%.7a\n\n", de, de, de);
    
    printf("fa(.10f):%.10f,fa(a):%a\n", fa, fa);
    printf("fb(.10f):%.10f,fb(a):%a\n", fb, fb);
    printf("fa(.6a):%.6a\n", fa);
    printf("fb(.6a):%.6a\n", fb);
    printf("\n");
    
    float_double_limits();
    float_double_addition();
    float_double_multiplication();
    return;
}

void float_double_limits(void)
{
    float fa = 1.3, fb = 1.1;
    double da = 1.3, db = 1.1;
    long double lda = 1.3;
    //float: 1 8 23; size: 32
    //double: 1 11 52; size: 64
    //long double: 1 
    printf("sizeof(fa):%d\n", sizeof(fa));
    printf("sizeof(da):%d\n", sizeof(da));
    printf("sizeof(lda):%d\n", sizeof(lda));
    printf("fb(.20a):  %.20a,\nfb(.40a):  %.40a\n", fb, fb);
    printf("db(.20a):  %.20a,\ndb(.40a):  %.40a\n", db, db);
    printf("fa(.20a):  %.20a,\nfa(.40a):  %.40a\n", fa, fa);
    printf("da(.20a):  %.20a,\nda(.40a):  %.40a\n", da, da);
    //%lf double; %Lf long double
    printf("lda(.60La):%.60La\n\n", lda);
    return;
}

void float_double_addition(void)
{ 
    float fa = 1.4, fb = 0.1;
    printf("fa + fb(float):%f,fa + fb(a): %a\n", fa + fb, fa + fb);
    printf("fa - fb(float):%f,fa + fb(a): %a\n", fa - fb, fa - fb);
    printf("fa + fb(.6a): %.6a\n", fa + fb);
    printf("fa + fb(.6a): %.6a\n\n", fa - fb);
    return;
    // float double addition:
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

void float_double_multiplication(void)
{
    // (1.75)10 --> (1.11)2 * (2^0)10
    // (0.625)10 --> (0.101)2 --> (1.01)2 * (2^-1)10
    // (1.11)2 * (2^0)10  *  (1.01)2 * (2^-1)10
    // (1.11  *  1.01)2 * (2^0 * 2^-1)10
    // (1.11  *  1.01)2 * (2^-1)10
    //-------------------------------------------------
    //一般正常算法,但为什么这么算?不直观:
    //           1.11
    //         * 1.01
    //         --------
    //           1 11
    //          00 0
    //         111
    //         --------
    //       10.00 11
    // 10.0011 * 2^-1 --> 1.00011 * 2^0
    // 1.1800000000         
    //-------------------------------------------------
    // (1.75)10 --> (1.11)2 * (2^0)10   --> 1.11
    // (0.625)10 --> (0.101)2 * (2^0)10 --> 0.101
    //小数乘法的本质:
    //           (1.110)2    --> 被乘数*8(2^3)倍 1110    
    //         * (0.101)2    -->   乘数*8(2^3)倍  101
    //         ----------
    //
    //           1110
    //         *  101
    //      -----------
    //           1110
    //          0000
    //         1110
    //      -----------
    //        1000110
    // 1000110/2^6 = 1000110 * 2^-6 = 1.000110 = 1.000110 * 2^0
    //
    //数学原理: 1 * 1 = 1
    //         1*4 * 1 = 4 (2^2)
    //         1*4 * 1*4 = 16 (2^4)
    //
    //乘法本质的一点理解:
    //      102
    //    *   2
    //   --------
    //        4     拆分成两步,更好理解本质
    //      200
    // 4 + 200 = 204
    //
    float fa = 1.75, fb = 0.625;
    printf("fa * fb(.10a):%.10a, fa * fb(.10f):%.10f\n", fa * fb, fa * fb);
    return;
}








