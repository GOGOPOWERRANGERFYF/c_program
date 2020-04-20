#include <stdio.h>
#define SPACE ' '
#define COMMA ','
int char_count(void);

int main(void)
{
    char_count();
    return 0;
}

int char_count(void)
{
    char ch;
    unsigned int count = 0;

    while ((ch = getchar()) != '.'){
        if (ch != SPACE && ch != COMMA){
            count++;
        }
    }

    printf("character count: %d\n", count);
    return 0;
}

// 逻辑运算符
// && 与  左右两个运算对象都为真,整个表达式的值为真
// || 或  左右两个运算对象只要有一个为真,整个表达式的值为真
// !  非  运算对象为真,整个表达式的值为假;运算对象为假,整个表达式的值为真
// operator precedence 运算符优先级
// 逻辑运算符的优先级比关系运算符低


