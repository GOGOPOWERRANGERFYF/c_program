#include <stdio.h>
//定义符号常量,预编译时后面的字符串替换前面的符号常量(文本)
#define OPERATORS "+ - * /"

int main(void)
{
    printf("These is operators: %s\n", OPERATORS);
    return 0;
}

