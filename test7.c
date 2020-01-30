// ANSI(american national standards institute):美国国家标准学会
// 'x' 一个字符   | x |    |
// "x" 一个字符串 | x | \0 |
// \0 空字符:null character(非打印字符)
//scanf()函数会自动添加空字符
//scnaf() 只会读取fyfa fyfb中的fyfa
//字符串常量 编译器会添加空字符
#include <stdio.h>
#include <string.h>      /* 该头文件提供strlen()函数 */
#define NAME "FuYunFeng" /* 定义字符串常量 */

void main(void)
{
    //c_var[40]是一个可容纳40个字符的数组
    //该字符数组占用内存中连续 1*40个字节byte
    //定义字符类型数组
    char c_var[40];
    //该短整型数组占用内存中连续 2*5个字节byte
    short int si_var[5];
    printf("character string 字符串,string constant: %s\n", NAME);
    // \b 光标向左移一位,一个字符占一位 
    printf("Input You Name:__________\b\b\b\b\b\b\b\b\b\b");
    scanf("%s", c_var);
    printf("My Name is:%s\n", c_var);
    //strlen()函数获取字符串的长度
    printf("string length, strlen(c_var): %d\n", strlen(c_var));
    printf("string length, strlen(NAME): %d\n", strlen(NAME));
    printf("sizeof(c_var): %d\n", sizeof(c_var));
    //计算机主存每字节都有一个唯一的物理地址(physical address),物理寻址physical addressing
    //&取数组变量的地址(虚拟地址virtual address\虚拟寻址virtual addressing)
    //CPU芯片上的内存管理单元(memory management unit: MMU)将虚拟地址转换成物理地址
    //《深入理解计算机系统第三版》 P560 
    printf("sizeof(&c_var): %d\n", sizeof(&c_var));
    //&c_var是数组第一个字节的虚拟地址(个人理解,待验证)
    printf("lx(&c_var)/64bit virtual address(hexadecimal): %lx\n", &c_var);
    printf("sizeof(si_var): %d\n", sizeof(si_var));
    printf("sizeof(&si_var): %d\n", sizeof(&si_var));
    return;
}


