#include <stdio.h>
//汇编知识(这玩意边看边查就好,不常用的话记不住的,搞不好掉头发...):
// movl 把内存内容赋给寄存器
// q l w b 分别为 64bit 32bit 16bit 8bit
// leal 把内存地址赋给寄存器
// %rbp 寄存器,寄存器种类个数很多,硬件会不断发展的,知道是寄存器就好了
//-4(%rbp) 把低位4个byte赋值
//$1 1为立即数,立即数前必须放一个$
//

void main(void)
{
    int i_a = 1, i_b = 1;
    long int li_a = 1;
    // ++ 递增运算符(increment operator),将其运算对象operand递增1
    // 看了运行结果,i++后缀模式,表达式本身没自增
    //             ++i前缀模式,表达式本身有自增
    //test_base.c 重要知识点(编译系统的编译过程)
    //gcc --help查看gcc帮助文档
    //通过汇编文件(文本格式)理解
    printf("%d %d\n", i_a, i_a++);
    printf("%d %d\n", i_b, ++i_b);
    return;
}


