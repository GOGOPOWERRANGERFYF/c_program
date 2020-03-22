#include <stdio.h>
#include <math.h>
int main(void)
{
    const double PI = 3.14159;
    double double_input;
    //while循环经常依赖测试表达式作比较,
    //这样的表达式被称为关系表达式(relational expression)
    //出现在关系表达式中的运算符被称为关系运算符(relational operator)
    // <c primer plus第六版> P328 表6.1 关系运算符
    // absolute value 绝对值
    scanf("%lf", &double_input);
    // fabs函数,返回值为浮点数的绝对值
    // double_input和PI的差的绝对值小于等于0.0001,while循环才会结束
    while (fabs(double_input - PI) > 0.0001){
        printf("No! input again: ");
        scanf("%lf", &double_input);
    }
    return 0;
}

//表达式一定有一个值,关系表达式也不例外
//表达式为真的值是1,表达式为假的值是0
//  while (q){
//      printf("q\n");
//  }
//  测试表达式q的值为真1



