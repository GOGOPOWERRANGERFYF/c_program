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
// && 与  左右两边的运算对象都为真,整个表达式的值为真
// || 或  左右两边的运算对象只要有一个为真,整个表达式的值就为真
// !  非  运算对象为真,整个表达式的值为假;运算对象为假,整个表达式的值为真
// operator precedence 运算符优先级
// 逻辑运算符的优先级比关系运算符低
//
// <c primer plus第六版> P440
//        iso646.h
// && 与    and
// || 或    or
// !  非    not

