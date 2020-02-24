#include <stdio.h>
//定义符号常量,预编译时后面的字符串替换前面的符号常量(文本)
#define OPERATORS "+ - * /"
void while_statements(void);

int main(void)
{
    // operator:运算符; expression:表达式; statement:语句
    //格式字符串中的转换说明%s,后面的待输出项类型和熟练要与转换说明相匹配
    printf("These is operators: %s\n", OPERATORS);
    while_statements();
    return 0;
}

void while_statements(void)
{
    int start = 0;
    while(start<10)
    {
        start = start + 1;
        printf("%d\n", start);
    }
    printf("The End!\n");
    return;
}




