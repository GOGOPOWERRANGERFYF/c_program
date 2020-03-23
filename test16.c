#include <stdio.h>
#include <stdbool.h>
// C99新增_Bool类型   
// 表示真或假的变量称为布尔变量(boolean variable)
// _Bool类型变量只能储存1(真)或0(假)
// 把非零值赋给_Bool类型变量是,该变量会被设置为1(这反映C把所有非零值视为真)
int bool_variable(void);

int main(void)
{
    _Bool a = 1, b = 'a', c = 0, d = 88
    , e = "abcd";
    printf("a = 1: %3d\n", a);
    printf("b = 'a': %d\n", b);
    printf("c = 0: %3d\n", c);
    printf("d = 88: %2d\n", d);
    printf("e = \"abcd\": %2d\n", d);

    bool_variable();
    return 0;
}

int bool_variable(void)
{
    // C99提供老stdbool.h头文件,该头文件定义了_Bool的别名bool,
    // 把true和false定义为1和0的符号常量
    // 包含了该头文件后,代码可以与C++兼容,true和false,bool为c++的关键字
    bool a;
    int b;
    while (scanf("%d", &b)){
        printf("true\n");
    }
    printf("false\n");
    return 0;
}


