#include <stdio.h>
//汇编语言 assembly language
//汇编知识(这玩意边看边查就好,不常用的话记不住的,搞不好掉头发...):
// 带.前缀的语句为链接的语句
// movl 把内存内容赋给寄存器
// q l w b 分别为 64bit 32bit 16bit 8bit (大小指示符)
// leal 把内存地址赋给寄存器
// %rbp 寄存器,寄存器种类个数很多,硬件会不断发展的,知道是寄存器就好了
// $1 1为立即数,立即数前必须放一个$
// %eax 累加寄存器: 函数返回值要存放在这个累加寄存器,返回值64bit,则低32bit存%eax,高32bit存%edx
// %ebx 基地址寄存器: 存放计算中间值(个人猜测应该是前面所说的程序计算的临时值吧...),或一个指针
// push pushq 压栈
// pop 出栈
//
// objdump: gun的反汇编器(disassembler) 反汇编-->可重定位目标程序(二进制文件) 后缀为 .o
// 类似抓包工具(tcpdump) dump: v (尤指在不合适的地方)丢弃; n 垃圾场
//
// gcc -Og 优化调试(debug)体验,支持不影响调试的优化

void main(void)
{
    int i_a = 1, i_b = 1;
    long int li_a = 999;
    // ++ 递增运算符(increment operator),将其运算对象operand递增1
    // * 看了运行结果,i++后缀模式,表达式本身没自增,运算结果为本身,然后自增1
    // *             ++i前缀模式,表达式本身有自增,运算结果自增1
    //test_base.c 重要知识点(编译系统的编译过程)
    //gcc --help查看gcc帮助文档
    //通过汇编文件(文本格式)理解
    // reverse engineering 逆向工程
    //
    // 栈(stack):
    //   先进后出,后进先出
    //                |_______|
    //            16  |_______|  <-- -16(%rbp)
    //            15  |_______|
    //            14  |_______|
    //            13  |_______|
    //            12  |_______|
    //            11  |_______|
    //             9  |_______|
    //             8  |_______|
    //             7  |_______|  <-- -8(%rbp)
    //             6  |_______|
    //             5  |_______|
    //             4  |_______|
    //             3  |_______|  <-- -4(%rbp)
    //             2  |_______|
    //             1  |_______|
    //             0  |_______|  <-- stack top(栈顶随着压栈和出栈变化)
    //                | 1byte |
    //
    // 注: %rbp只有在 -O0 不优化的编译条件下,还具有帧指针的含义

    li_a = li_a + 1;
    
    //i_a++;
    //++i_b;
    
    i_a = i_a++;
    i_b = ++i_b;
    printf("i_a = i_a++; %d\n", i_a);
    printf("i_b = ++i_b; %d\n", i_b);
    
    //printf("%d %d\n", i_a, i_a++);
    //printf("%d %d\n", i_b, ++i_b);
    return;
}

// 1B = 8bit
// 1KB = 1024B
// 1MB = 1024KB
// 1GB = 1024MB
// 1TB = 1024GB
// 32位cpu和64位cpu是指cpu一次能够处理的数据宽度
// 总线位宽(带宽),这个概念暂时不展开
// 直接说地址总线位宽
// 以32位地址总线位宽为例:
// 32位系统一般有32跟地址总线,可提供的可寻物理地址范围为 2^32B (2^32种组合方式)
// 2^10 * 2^10 * 2^10 * 2^2 种组合
// 1024 * 1024 * 1024 * 4   B
// 1024 * 1024 * 4         KB
// 1024 * 4                MB
// 4                       GB  这个过程反过来更好理解
// 一个物理地址指向一个1B内存空间(虚拟地址与物理地址的映射由操作系统决定)
// RAM random access memory 随机存取存储器 主存(内存),CPU高速缓存
// ROM read only memory 只读存储器 多用于存放固件
//
// 《深入理解计算机系统第三版》P113 机器级代码 machine-level code
// optimize 优化 gcc -O
// ISA(指令集架构,instruction set architecture)
// PC(程序计数器,program counter.在x86-64中用%rip示),给出将要执行的下一条指令在内存中的地址
// IR(指令寄存器 instruction register)
// ip(instruction pointer) r我暂时理解为register吧...
// 数据结构的知识: stack 栈; heap 堆
//
// 数据格式:《深入理解计算机系统第三版》P119
//   字节byte 8位
//   字word 16位
//   双字double word 32位   "long word"
//   四字quad word 64位
// 数据格式:《深入理解计算机系统第三版》P119 图3-1
//   C语言数据类型在x86-64中的大小
// 
// 数据格式:《深入理解计算机系统第三版》P120 图3-2
// CPU通用目的寄存器
// %rbp register buttom pointer 基址寄存器
// %rsp register stack pointer 栈指针寄存器
//
// immediate 立即数(立即的)
//


