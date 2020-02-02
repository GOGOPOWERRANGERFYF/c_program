// ANSI(american national standards institute):美国国家标准学会
// 'x' 一个字符   | x |    |
// "x" 一个字符串 | x | \0 |
// \0 空字符:null character(非打印字符)
//scanf()函数会自动添加空字符
//scnaf() 只会读取fyfa fyfb中的fyfa
//--------------------------------------------------------------
//conversion specification(转换说明) 例如: %d %f
// 1) printf() --> conversion specification表 《c primer plus第六版》P195
//--------------------------------------------------------------
//字符串常量 编译器会添加空字符
#include <stdio.h>
#include <string.h>      /* 该头文件提供strlen()函数 */
//编译程序的时候,程序中的符号常量会被替换成所定义的值(常量),编译时替换(compile-time substitution)
//符号常量后面的内容被用来替换符号常量 《c primer plus第六版》p189
#define C 'A'
#define NAME "Fu YunFeng." /* 定义符号常量 */
#define PI 3.141593         /* 定义符号常量(symbolic constant) */
void code_new_line(void);
void circle_float_arithmetic(void);
void circle_double_arithmetic(void);
void circle_long_double_arithmetic(void);
void define_and_const(void);
void stdio_include_stddef_size_type(void);

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
    circle_long_double_arithmetic();
    define_and_const();
    stdio_include_stddef_size_type();
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
//注:long double类型有点特殊,需要考虑硬件,操作系统等因素,虽然编译器有定义这个类型,我暂时用不到就不折腾了...
// [1] scanf()
//     float: %f %e %a
//     double: %lf %le %la
//     long double: %Lf %Le %La
// [2] printf()
//     %f %e 默认保留小数点后六位
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
    printf("circle_l(f): %f, circle_a(f): %f\n", l, a);
    printf("circle_l(e): %e, circle_a(e): %e\n", l, a);
    printf("circle_l(a): %a, circle_a(a): %a\n", l, a);
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
    printf("circle_l(f): %f, circle_a(f): %f\n", d_l, d_a);
    printf("circle_l(e): %e, circle_a(e): %e\n", d_l, d_a);
    printf("circle_l(a): %a, circle_a(a): %a\n", d_l, d_a);
    return;
}

void circle_long_double_arithmetic(void)
{
    float f_a = 1.3F;
    double d_a = 1.3;
    printf("sizeof(f_a): %zd\n", sizeof(f_a));
    printf("%.60f\n", f_a);
    printf("%.60e\n", f_a);
    printf("%.60a\n", f_a);
    printf("sizeof(d_a): %zd\n", sizeof(d_a));
    printf("%.60f\n", d_a);
    printf("%.60e\n", d_a);
    printf("%.60a\n", d_a);
    return;
}

void define_and_const(void)
{
    //const关键字(key woird)限定一个变量为只读,赋值编译器会报错
    // short long signed unsigned const 限定符
    //用法比define更灵活
    // PI = 5.555; 符号常量不能更改其内容
    // csi_b = 88; const限定变量只读,不可更改
    const short int csi_a = 55, csi_b = 66;
    printf("csi_a(%%hd)%hd\n", csi_a);
    printf("csi_b(%%hd)%hd\n", csi_b);
    // 计算机中储存的是 3.14159的近似值
    // %%   printf()转换说明 打印一个百分号
    printf("PI(%%f): %f\n", PI);
    printf("PI(%%.10f): %.10e\n", PI);
    // double类型 尾数52位,因此只能计算最长值 %.13a,超过这个长度后面只是填充0而已
    printf("PI(%%.13a): %.13a\n", PI);
    printf("PI(%%.15a): %.15a\n", PI);
    return;
}
// printf("格式化字符串/转换说明", 待打印列表)
// 待打印列表项: 常量,变量,表达式的值
// 《c primer plus第六版》P200 表4.5 转换说明修饰符
// 需要注意的: l和整数转换说明使用,L和浮点数转换说明使用

void stdio_include_stddef_size_type(void)
{
    //underlying type(底层类型)
    // stddef.h头文件中, #define __SIZE_TYPE__ long unsigned int
    // 
    printf("sizeof(int):%d\n", sizeof(int));
    printf("sizeof(sizeof(int):%d --> long unsigned int\n",
     sizeof(sizeof(int)));
    return;
}


