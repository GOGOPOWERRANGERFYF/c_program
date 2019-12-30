//ascii(american standard code for information interchange):美国信息交换标准代码
//包含0~9,大小写字母和常用符号,用一个字节的数据表示
//unicode(unique universal uniform character encode):唯一 通用 统一 字符编码
//utf-8(8-bit unicode transformation format):8比特位unicode转换格式
//ALU(arithmetic logic unit):算术逻辑单元
//PS(program counter):程序计数器
//USB(universal serial bus):通用串行总线
//shell是一个命令行解释器,如果输入命令行的第一个单词不是shell内置命令,那么shell会假设这个是
//可执行文件的名字,它将加载并运行这个文件

/*
    |<-- compilation system编译系统
    |
    |--> cpp(pre-processor)预处理器
    |--> ccl(compiler)编译器
    |--> assembler(as)汇编器:将指令转变为机器码
    |--> linker(ld is short for link editor)链接器
*/


//program:程序,编码指令
//这一段代码以字节序列的方式存储在文件中,每个字符都对应一个ascii码,中文字符是unicode码
//只由ascii码构成的文件称为文本文件(也有unicode文本文件),所有其他文件都称为二进制文件
//所有数据都是一串比特表示,区分不同数据对象的唯一方法是读取数据对象上下文,
//在不同的上下文中,一个相同的字节序列可能表示一个整数,浮点数,字符串或机器指令.


#include <stdio.h> \\standard input & output . head头文件
//stdio.h是C编译器软件包的标准库的一个文件,它提供键盘输入和屏幕输出的支持
//cpp(c pre-processor:预处理器)会读取stdio.h文件的内容并插入到程序文本中
//结果得到另外一个C程序,通常以.i作为文件扩展名
//源程序(文本)hello.c --[cpp]-->修改了的源程序(文本)hello.i,
//旁注:(这里的文本编码格式是utf-8, 8bit unicode transformation format);
//     utf-8可节省编码储存长度,用utf-8编码unicdoe长度可变;
//     unicode码(4字节)是兼容ascii码(1字节)的.
//hello.i --[ccl: c compiler]--> hello.s汇编程序(文本)
//hello.s --[as: assembler]--> hello.o(relocatable object program可重定位目标程序(二进制文件))
//hello.o --[ld: linker]--> hello可执行目标程序(二进制)
//把hello程序要调用到的标准C库的函数合并到hello.o程序中,
//比如调用到printf函数,printf函数存在于一个名为printf.o的单独编译的可重定位目标程序中,
//printf.o以某种方式合并到hello.o文件,ld负责处理这种合并,
//合并后得到文件hello,可执行目标文件(简称可执行文件),可以加载到内存中,有系统执行.

int main(void)
{
    printf("hello world!\n");
}
//屏幕上显示的这段代码只是ascii码对应的字体文件的屏幕输出(这只是我个人的简化理解)

