// 学习笔记
// 20200626:
//  浮点数运算复习
//      加法: 阶码算成与大的阶码一致,尾数相加
//      减法: 阶码算成与大的阶码一致,尾数大-尾数小 --> 尾数大+尾数小的二补数 --> 模除 --> 得到尾数运算结果再规格化
//      乘法: 阶码相乘*尾数相乘 重点:小数点的移位
//            小数点移位示例: 1.011 * 1.111 = 1.011 * 1000 * 1.111 * 1000  = 1011 * 1111
//                                            ____________   ____________    ____   ____
//                                                1000            1000       1000   1000
//                                                                           
//                             1111 / 10 = 111.1   (2)10 = (10)2
//                             (1000/10)2 = (8/2)10 --> (0100)2 (4)10
//  提示: 这只是数学理论的运算,cpu怎么实现目前知识水平有限还不了解...

// date： 20200722
// 运算符优先级operator precedence暂时小结(不全):
// ()圆括号 
// !逻辑运算符非,+/-正负符号,++/--自增自减运算符
// + - * / % 加减乘除 模除 
// == != > >= < <= 关系运算符 
// &&逻辑运算符与and >> ||逻辑运算符或or
// =赋值运算符和+=等组合赋值运算符 
// ,逗号运算符comma

// \ 转移字符 escape character
// \b等 转移序列
// c语言代码语句太长时,加\后可继续另起一行的原因,个人查阅网上资料后的理解:
// \ 后加 enter键(ascii[decimal:10],为非显示字符), \的作用就是把这个字符转义
// 所以编译器就不会把这一行的代码结尾当作这一语句的结尾

//   位权(weight):  10^1 10^0    1/10 1/100 (这里的权重用十进制表示)
// 十进制(decimal):   1    1  .    1     1  
//                              10^-1 10^-2                               
//
//   位权(weight):   2^1  2^0    1/2   1/4  (这里的权重用十进制表示)
// 二进制(binary):     1   1   .   1    1
//                              2^-1  2^-2                               
// 形象化的解释:
//  1. 十进制 0.1 1根棍子掰成10等份,一份就是0.1 
//  2. 二进制 0.1 1根棍子掰成2等份,一份就是0.1
//  十进制的0.1五份 = 二进制0.1一份
//  十进制0.1权重1/10; 二进制0.1权重1/2 （这里的权重统一用十进制表示)
//  理解十进制和二进制转换的关键: 十进制和二进制的位权统一用十进制表示
// 1/2 + 1/4 + 1/8
// 1 - 1/2 + 1/2 - 1/4 + 1/4 - 1/8 = 1 - 1/8
//
// 不管任何进制,本质就是位置计数法:
// 通俗理解,用符号记录有多少根牙签
//--------------------------------------------------------------------
// 第四层: 
//牙签总数 = 四个牙签数(十进制)之和,所以牙签总数之和为十进制数 = (3.75)10 decimal
//--------------------------------------------------------------------
// 第三层: 二进制的每个数位表示多少根牙签(十进制decimal),即4个十进制数表示牙签数
//         (2)10   (1)10    (1/2)10   (1/4)10     十进制          decimal
//--------------------------------------------------------------------
// 第二层: 二进制每一位的位权,即第一层的二进制的每一位的1份表示几根牙签,这里用
//        十进制表示(其他进制也可以,十进制是我们日常常用的,而且这里就是为了理解
//        二进制转换为十进制的本质)
//        (2^1)10  (2^0)10  (2^-1)10  (2^-2)10  位权/权重 十进制    decimal
//--------------------------------------------------------------------
// 第一层: 用二进制表示总共有多少根牙签 
//            1        1.       1       1                二进制     binary
//--------------------------------------------------------------------

//计算机组成原理
// endianness 端序
// big endian 大端序: 数据高位存低地址
// little endian 小端序: 数据低位存低地址

// (x-y)=u
// 2(x-y)=2u
// x-y + x-y = 2u
// 2x - 2y = 2u

//1. (x-y)=u
//2. (x-y) * (x-y) = u * u
// (x-y) * (x-y)等于(x-y)个(x-y)相加
//3. x*(x-y) - y*(x-y) = u^2
// 

// 二进制乘法:
//  十进制乘法参考: 248 * 8 = 248 * 5 + 248 * 3
//  1010 * 1010 = 1010 * (1000 + 10)
// 二进制除法
//  暂时不研究,cpu的乘法和除法运算有空看一下chrome收藏夹