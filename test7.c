// ANSI(american national standards institute):美国国家标准学会
#include <stdio.h>
#include <string.h>
void short_int_array(void);

void main(void)
{
    //c_var[40]是一个可容纳40个字符的数组
    //该数组占用内存中连续 1*40个字节byte
    char c_var[40];
    // \b 光标向左移一位,一个字符占一位 
    printf("Input You Name:__________\b\b\b\b\b\b\b\b\b\b");
    scanf("%s", c_var);
    printf("My Name is: %s\n", c_var);
    // strlen()函数获取字符串的长度
    printf("string length: %d\n", strlen(c_var));

    short_int_array();
    return;
}

void short_int_array(void)
{
    //短整型数组
    //该数组占用内存中连续 2*5个字节byte
    short int si_array_a[5];
    printf("sizeof(si_array_a): %d", sizeof(si_array_a));
    return;
}



