//ascii(american standard code for information interchange):美国信息交换标准代码
//包含0~9,大小写字母和常用符号,用一个字节的数据表示
//unicode(unique universal uniform character encode):唯一 通用 统一 字符编码
//utf-8(8-bit unicode transformation format):8比特位unicode转换格式

/*
    |<--compilation system编译系统
    |
    |--> cpp(pre-processor)预处理器
    |--> ccl(compiler)编译器
    |--> assembler(as)汇编器:将指令转变为机器码
    |--> linker(ld is short for link editor)链接器


*/


//program:程序,编码指令
//这一段代码以字节序列的方式存储在文件中,每个字符都对应一个ascii码,中文字符是unicode码
//只由ascii码构成的文件称为文本文件,所有其他文件都称为二进制文件
//所有数据都是一串比特表示,区分不同数据对象的唯一方法是读取数据对象上下文,
//在不同的上下文中,一个相同的字节序列可能表示一个整数,浮点数,字符串或机器指令.


#include <stdio.h> \\standard input & output . head头文件
//stdio.h是C编译器软件包的标准库的一个文件,它提供键盘输入和屏幕输出的支持
int main(void)
{
    printf("hello world!\n")
}
//屏幕上显示的这段代码只是ascii码对应的字体文件的屏幕输出(这只是我个人的简化理解)

