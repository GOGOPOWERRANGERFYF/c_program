#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define INPUT_FINISH_FLAG '|'
#define LINE_FLAG '\n'
int text_counter(void);

int main(void)
{
    _Bool bool_a;
    bool bool_b;
    int int_a;

    printf("sizeof(int_a):%zd\n", sizeof(int_a));
    printf("sizeof(bool_a):%zd sizeof(bool_a):%zd\n",
     sizeof(bool_a), sizeof(bool_b));
    printf("true:%d false:%d\n", true, false);

    text_counter();
    return 0;
}

// 空白字符(空格,制表符,换行符): ' '，'\t','\n'
// 排除空白字符: c != ' ' && c != '\t' && c != '\n'
// 检查空白字符: c != ' ' || c != '\t' || c != '\n'
//
// c提供了检查空白字符的函数isspace(),函数原型声明在ctype.h头文件
// isspace(c),c为空白字符,函数返回值为真,c为非空白字符,函数返回值为假

int text_counter(void)
{
    bool word_flag = false;
    char ch;
    int lines_counter = 0;    
    int words_counter = 0;

    while ((ch = getchar()) != INPUT_FINISH_FLAG){
        // lines
        if (ch == '\n'){
            lines_counter++;
        }
        // words
        // 遇到第一个非空白字符
        // 如果 字符为非空白字符 且 单词标记为假(伪代码,大白话...)
        if (!isspace(ch) && !word_flag){
            words_counter++;            
            word_flag = true;
        }
        // 读取非空白字符之后读取到的首个空白字符
        // 重置word_flag为假
        // 如果 字符为空白字符 且 单词标记为真
        if (isspace(ch) && word_flag){
            word_flag = false;
        }
    }

    printf("words number:%d\n", words_counter);
    printf("lines number:%d\n", lines_counter);
    return 0;
}



