#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    _Bool bool_a;
    bool bool_b;
    int int_a;

    printf("sizeof(int_a):%zd\n", sizeof(int_a));
    printf("sizeof(bool_a):%zd sizeof(bool_a):%zd\n",
     sizeof(bool_a), sizeof(bool_b));
    printf("true:%d false:%d\n", true, false);
    return 0;
}

// 空白字符(空格,制表符,换行符): ' '，'\t','\n'
// 排除空白字符: c != ' ' && c != '\t' && c != '\n'
// 检查空白字符: c != ' ' || c != '\t' || c != '\n'
//
// c提供了检查空白字符的函数isspace(),函数原型声明在ctype.h头文件
// isspace(c),c为空白字符,函数返回值为真,c为非空白字符,函数返回值为假



