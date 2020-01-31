// ANSI(american national standards institute):美国国家标准学会
// 'x' 一个字符   | x |    |
// "x" 一个字符串 | x | \0 |
// \0 空字符:null character(非打印字符)
//scanf()函数会自动添加空字符
//scnaf() 只会读取fyfa fyfb中的fyfa
//字符串常量 编译器会添加空字符
#include <stdio.h>
#include <string.h>      /* 该头文件提供strlen()函数 */
//编译程序的时候,程序中的符号常量会被替换成所定义的值(常量),编译时替换(compile-time substitution)
#define NAME "Fu YunFeng." /* 定义符号常量 */
#define PI 3.14159         /* 定义符号常量(symbolic constant) */
void code_new_line(void);
void circle_float_arithmetic(void);
void circle_double_arithmetic(void);

void main(void)
{
    //c_var[40]是一个可容纳40个字符的数组
    //该字符数组占用内存中连续 1*40个字节byte
    //定义字符类型数组
    char c_var[40];
    //该短整型数组占用内存中连续 2*5个字节byte
    short int si_var[5];
    printf("character string 字符串,string constant Name: %s\n", NAME);
    // \b 光标向左移一位,一个字符占一位 
    printf("Input You Name:__________\b\b\b\b\b\b\b\b\b\b");
    scanf("%s", c_var);
    printf("My Name is:%s\n", c_var);
    //strlen()函数获取字符串的长度,获取空字符(null character)之前的字符串的长度
    // strlen()函数 和 sizeof运算符 返回值为无符号整数类型(unsigned integer)  注:网上说的...不知道对不对
    // 输出返回值用%zd或%u,C99和C11标准用%zd,较早的C用%u
    // sizeof运算符用法示例: 1)sizeof(object);  2)sizeof object;  3)sizeof(type);
    printf("string length, strlen(c_var): %u\n", strlen(c_var));
    printf("string length, strlen(NAME): %u\n", strlen(NAME));
    printf("sizeof(c_var): %u\n", sizeof(c_var));
    //计算机主存每字节都有一个唯一的物理地址(physical address),物理寻址physical addressing
    //&取数组变量的地址(虚拟地址virtual address\虚拟寻址virtual addressing)
    //CPU芯片上的内存管理单元(memory management unit: MMU)将虚拟地址转换成物理地址
    //《深入理解计算机系统第三版》 P560 
    printf("sizeof(&c_var): %u\n", sizeof(&c_var));
    //&c_var是数组第一个字节的虚拟地址(个人理解,待验证)
    printf("lx(&c_var)/64bit virtual address(hexadecimal): %lx\n", &c_var);
    printf("sizeof(si_var): %u\n", sizeof(si_var));
    printf("sizeof(&si_var): %u\n", sizeof(&si_var));

    code_new_line();
    circle_float_arithmetic();
    circle_double_arithmetic();
    return;
}

void code_new_line(void)
{
    printf("233333333333333333333333333333333333333333, This is my name: %s\n", NAME);
    //处理很长的printf()语句的两种方法:
    // 1)
    printf("233333333333333333333333333333333333333333, This is my name: %s\n",
     NAME);
    // 2)
    printf("233333333333333333333333333333333333333333, ");
    printf("This is my name: %s\n", NAME);
    return;
}

//格式说明符(format specific)
// [1] scanf()
//     float: %f %e %a
//     double: %lf %le %la
//     long double: %Lf %Le %La
// [2] printf()
//     float: %f %e %a
//     double: %f %e %a
//     long double: %f %e %a
// 浮点数不加后缀,默认double类型
void circle_float_arithmetic(void)
{
    float r, l, a;
    printf("sizeof(r): %zd, sizeof(PI): %zd\n",
     sizeof(r), sizeof(PI));
    printf("input r(floating-point number):______\b\b\b\b\b\b");
    scanf("%f", &r);
    l = 2.0 * PI * r;
    a = PI * r * r;
    printf("circle_l: %f, circle_a: %f\n", l, a);
    //printf("circle_l: %e, circle_a: %e\n", l, a);
    //printf("circle_l: %a, circle_a: %a\n", l, a);
    return;
}

void circle_double_arithmetic(void)
{
    double d_r, d_l, d_a;
    printf("sizeof(d_r): %zd,sizeof(PI): %zd\n",
     sizeof(d_r), sizeof(PI));
    printf("input d_r(floating-point number):______\b\b\b\b\b\b");
    scanf("%lf", &d_r);
    d_l = 2.0 * PI * d_r;
    d_a = PI * d_r * d_r;
    printf("circle_l: %.15f, circle_a: %.15f\n", d_l, d_a);
    //printf("circle_l: %e, circle_a: %e\n", d_l, d_a);
    //printf("circle_l: %a, circle_a: %a\n", d_l, d_a);
    return;
}



