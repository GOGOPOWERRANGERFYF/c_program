// ANSI(american national standards institute):美国国家标准学会
#include <stdio.h>
#include <string.h>

void main()
{
    //c_var[40]是一个可容纳40个字符的数组
    char c_var[40];
    // \b 光标向左移一位,一个字符占一位 
    printf("Input You Name:__________\b\b\b\b\b\b\b\b\b\b");
    scanf("%s", c_var);
    printf("My Name is: %s", c_var);
    return;
}


