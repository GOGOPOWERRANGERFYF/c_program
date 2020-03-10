#include <stdio.h>
void main(void)
{
    return;
}

// 表达式和语句
// 1. 大多数语句(statement)由表达式(expression)构成
// 2. 表达式由运算符(operator)和运算对象(operand)组成
// 3. 运算符操作的对象就是运算对象(operand)
// 4. 运算对象可以是常量,变量或二者的结合,例如:
//       5
//       -8
//       a
//       a + 5
//       b = 6 + 5 赋值表达式
//       b = a + 5 赋值表达式
//       b > 10    关系表达式
//       a * (b + 6) 
//       --> b + 6 是它的子表达式(subexpression),子表达式即较小的表达式
//       --> 两个子表达式的乘积
// 5. 每个表达式都有一个值,要获得这个值,必须根据运算符优先级规定的顺序来执行操作
//    a. 赋值表达式的值与赋值操作符(=)左边变量的值相同
//    b. 关系表达式的值不是1就是0
//  
//