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

// 20200909测试
