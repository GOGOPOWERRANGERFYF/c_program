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
    // 1.4

    printf("%d\n",f1);
    printf("%d\n", sizeof(f1));
    printf("%f\n", fa + fb);
    printf("%f\n", fa - fb);
    return;
}


