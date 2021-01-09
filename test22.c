// 第九章 函数
// 9.1

// ANSA american national standards institute 美国国家标准学会
// ANSI C标准库,被分为多个系列,每一系列都有各自的头文件.
// 这些头文件除了其他内容,还包含了本系列所有的函数声明
// 函数的代码在另一个库函数的文件中
#include <stdio.h>
// ANSI C风格 函数原型 function prototype
//  void function_definition(void);
// 不识别ANSI C风格的编译器,函数声明改成:
//  void function_definition();
// 一些老版本的编译器连void都识别不了,
//  就要把没有返回值的函数声明改成:
//  int function_definition();  
//  当然最好还是换编译器
//  后面两种情况了解一下就行,按ANSI C风格写就好

// 函数原型指明了 函数的返回值类型 和 函数接受的参数类型
// 这些信息称为该函数的签名(signature)

// 下面的函数原型的签名为没有返回值,没有参数
void funciton_definition(void);
// 下面的函数原型的签名为整数类型返回值,没有参数
// int funciton_definition(void);

// 声明 带形式参数的函数原型
// 函数声明告诉编译器函数的类型
// 函数声明在函数调用前
// 函数声明在主调函数的函数体也是可以的,但必须在函数调用前
// 函数定义在函数调用前可以不用声明,但这种方法不方便阅读
// 而且函数定义可能在C库或其他文件中
// 因此通常做法是提前函数声明,把函数信息告知编译器
// 函数声明的作用:告知编译器函数的类型,函数类型指的是函数返回值的类型
// 在ANSI C标准之前,不用声明形参,而这种函数声明是有缺陷的
// 下面的语句是按照ANSI C标准的 函数原型 声明
void function_a(char c, int i);
// 函数原型声明 除了告诉编译器函数(返回值类型)类型还有参数个数和类型

// 按照ANSI C标准要求,使用函数原型(function prototype)来声明
// 函数的返回值类型、参数的个数和每个参数的类型
// 可以使用下面两种函数原型来声明:
// 第一种:
int function_b(int, int);
// 第二种:
int function_c(int a, int b);
// * 这里的变量名是假名,不必与函数定义的形式参数名一致
// 实际参数与形式参数类型不匹配,编译器会把实际参数转换成形式参数的类型
// 错误与警告的区别:错误导致无法编译,而警告仍然允许编译

// 9.2.4 无参数与未指定参数
// 旧式函数声明
//  void function();
// 函数原型
//  void funciton(void); 

void recursion_a(int);
// 或:
// void recursion_a(int n);
// 或:
// void recursion_a(int i);
// 以上三种函数原型声明都可以

int pointer_a(void);

// 全局变量 global ariable
int global_variable_a;

int main(void){
    // 局部变量 local variable
    // 该变量只属于main函数
    // 其它函数有相同变量名不会冲突
    int count = 0;
    
    // 函数表达式语句
    putchar('*');
    
    // 函数调用 function call
    funciton_definition();

    // 在函数调用中,实际参数(actual argument),简称实参
    // 提供了c和i的值
    // 实际参数是'c' 和 10,这两个参数被赋给了相应的形式参数 变量c和i
    // 形式参数是被调函数(called function)中的变量
    // 实际参数是主调函数(calling function)赋给被调函数的具体值
    // 实际参数可以是常量,变量和可求值的表达式(记得还有函数表达式,可求值为带返回值)
    // 实际参数是具体的值,该值要被赋给作为形式参数的变量
    // 被调函数使用的值从主调函数拷贝而来,因此不论被调函数如何操作,都不会影响主调函数中的原始数据
    // 上面介绍了如何把信息从主调函数传递给被调函数
    // 函数的返回值可以把信息从被调函数传回给主调函数
    function_a('c', 10);
    // 1.主调函数把实参存储在栈中,根据实参个数和类型存储 
    // 2.被调函数根据它的形参个数和类型读取栈中的实参

    pointer_a();

    // return语句的另一个作用是,终止函数并把控制返回给主调函数的一条语句
    // 函数控制流
    // return 后面可以跟 常量 变量 可求值的表达式
    //  int类型函数,return float类型变量,会隐式转换为int类型
    // return; 只有void函数才会用到这种形式
    return 0;
    // 下面这条语句将永远不会执行
    printf("This's statement will not print!");
}

// 函数定义 function definition
void function_definition(void){
    printf("This is function definition.\n");
}

// 变量c和i被称为 形式参数(formal parameter,最新标准推荐使用),简称形参
// 和定义在函数中的变量一样,形式参数也是局部变量,属于函数私有
// 这意味着在其他函数使用同名变量不会引起冲突
// *ANSI C要求每个变量前都声明其类型,不能像普通变量声明那样使用同一类型的变量列表
// void function_a(char c, i) 无效的函数头
void function_a(char c, int i){
    // 
    return;
}

// 9.3 递归
// recursion
// C允许函数调用它自己,这种调用过程成为递归
void recursion_a(int i){

    return;
}

// 9.7 指针简介
// 指针: pointer
// 从根本上看,指针是一个值为内存地址的变量(或数据对象)
// char类型变量的值是字符,int类型变量的值是整数,指针变量的值是地址

// 9.7.1 *间接运算符(乘法运算法与间接运算符都是*)
//  direction 方向;动向
//  indirection 迂回;间接
//  indirection operator 间接运算符
//   

int pointer_a(void){
    // *和变量名之间有没有空格都行
    // 通常指针声明时空格,解引用变量时省略空格
    int a = 10, b, * int_pointer1;
    // & 地址运算符 给出变量的存储地址 P624
    // 把int类型变量a的地址赋给int_pointer1
    // 这里的地址是指虚拟地址,不是物理地址
    int_pointer1 = &a;
    // 个人理解为啥叫间接运算符
    // 通过指针变量保存的另一个变量的地址
    // &a 地址运算符,给出变量a的地址
    // pointer = &a 变量a的地址赋给指针变量
    // b = *pointer 间接运算符,后面可跟指针变量名或地址
    //  给出存储在指针变量的地址指向的值
    // 以上两步可以直接一步解决: b = a
    // 所以叫间接运算符
    b = *int_pointer1;
    printf("%d\n", b);
    return 0;
}
// 9.7.2 声明指针

// 注意: 指针是一个新类型,不是整数类型,一些用来处理整数的操作
//      不能用来处理指针.
//      指针类型 转换说明 %p

// c语言是静态语言
// 指令+数据=程序
// 操作码+操作数
// 编译的具体过程看 test_base.c
// 编译器 -编译compiler-> (最终生成)机器码binary
// CPU本身并不知道数据的类型,它只是根据指令读取相应内存单元的数据
// 通过内存地址寻找内存单元
// %x转换说明 是针对 int数据类型的操作
// 指向int数据类型的指针是int类型指针
// 即使 int类型变量 和 float类型变量 在内存中的二进制数据相同
// 用printf() 和 %x 是无法得到相同的十六进制数的
// 基于个人目前知识水平的理解:
//    int数据类型和float数据类型的内存地址不同
//    在机器码中的位置不同,因此printf() + %x 这个整数类型的打印操作
//    并不能正确读取到float类型数据(变量)的地址
//    因此得不到正确的数据
//  还有很多知识短板要补,暂时只能理解到这个程度了......55555~
//  物理地址: 硬件
//  虚拟地址: OS 操作系统
//  MMU(memory management unit): 内存管理单元
//      功能包括: 虚拟地址到物理地址的转换
//  虚拟地址--(MMU)映射--物理地址

// 2.5.1 变量和常数的实现
// LOC (location缩写?)
// 汇编语法     寻址
//  LOC     绝对(直接)  操作数在一个存储单元中,指令中明确地给出这个单元的地址
//  Ri      寄存器      操作数是寄存器中的内容,指令中给出寄存器的名称(地址)
//  #value  立即        操作数在指令中被明确地给出

// 2.5.2 间接和指针
// 汇编语法  寻址
//  (Ri)    间接
//  (LOC)   间接
// P34 图2-11 间接寻址
// 重要概念: 包含一个操作数地址的寄存器或内存单元称为指针
