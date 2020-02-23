#include <stdio.h>
//定义符号常量,预编译时后面的字符串替换前面的符号常量(文本)
#define OPERATORS "+ - * /"

int main(void)
{
    //格式字符串中的转换说明%s,后面的待输出项类型和熟练要与转换说明相匹配
    printf("These is operators: %s\n", OPERATORS);
    return 0;
}




