#include <stdio.h>
// C99新增_Bool类型   
// 表示真或假的变量称为布尔变量(boolean variable)
// _Bool类型变量只能储存1(真)或0(假)
// 把非零值赋给_Bool类型变量是,该变量会被设置为1(这反映C把所有非零值视为真)
int main(void)
{
    _Bool a = 1, b = 'a', c = 0, d = 88;
    printf("a = 1: %3d\n", a);
    printf("b = 'a': %d\n", b);
    printf("c = 0: %3d\n", c);
    printf("d = 88: %2d\n", d);
    return 0;
}





