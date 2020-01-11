#include <stdio.h>
// Floating-Point Operations 浮点数运算
// addition:
//    
//
//exponent指数 指数计数法:1.0e9
//             科学计数法:1.0*10^9
//                   数字:1000000000
void main(void)
{
    float f1 = 111.111, fa = 1.4, fb = 0.1;
    // 1.4 --> 1.
    // 0.1 --> 0.
    printf("f1(d):%d\n",f1);
    printf("sizeof(f1):%d\n", sizeof(f1));
    printf("fa:%.10f,fa:%.6a\n", fa, fa);
    printf("fb:%.10f,fb:%.6a\n", fb, fb);
    printf("fa + fb(f):%f,fa + fb(a): %a\n", fa + fb, fa + fb);
    printf("fa - fb(f):%f,fa + fb(a): %a\n", fa - fb, fa - fb);
    return;
}


