#include <stdio.h>
//exponent指数 指数计数法:1.0e9
//             科学计数法:1.0*10^9
//                   数字:1000000000
int main(void)
{
    float f1 = 111.111;

    printf("%d\n",f1);
    printf("%d\n", sizeof(f1));
    
    return 0;
}


