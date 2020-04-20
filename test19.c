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
// && 与
// || 或
// !  非