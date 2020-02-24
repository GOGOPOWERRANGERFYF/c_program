#include <stdio.h>
//定义符号常量,预编译时后面的字符串替换前面的符号常量(文本)
#define OPERATORS "= + - * /"
void while_block(void);

int main(void)
{
    // operator:运算符; expression:表达式; statement:语句
    // = 赋值运算符
    //格式字符串中的转换说明%s,后面的待输出项类型和熟练要与转换说明相匹配
    printf("These is operators: %s\n", OPERATORS);
    while_block();
    return 0;
}

void while_block(void)
{
    //这里的 =运算符 表示 初始化而不是 赋值
    const int ONE = 1;
    //把整数值0赋给变量start,赋值表达式
    int start = 0;
    // C的当前标准
    //(早期C标准的lvalue: left value
    //,rvalue: right value的定义已经不能满足当前的状况)
    // 左:
    //  *modifiable lvalue(可修改的左值)
    //  object locator value(对象定位值)
    // 右:
    //  常量,变量,可求值的表达式
    //  *value of an expression(表达式的值)
    //《c primer plus第六版》中文版的定义:
    //赋值语句的目的是把值储存到内存位置,储存值的内存存储区域称为数据对象(data object)
    //我自己根据《c primer plus第六版》英文版的翻译
    //考虑一个赋值语句.它的目的是储存一个值在一个内存位置.
    //数据对象是一个 用于存储整个值的数据存储区域的 通用术语

    while(start<10)/* starting the while loop  */
    //花括号之间的内容是要被重复的内容,用计算机术语说,就是程序循环这些语句
    /* start of block,花括号以及花括号括起来的部分被称为block */
    {                           
    // 目前个人的理解,下面整句为赋值语句,start + 1为表达式,待验证... 
        start = start + 1;      
        printf("%d\n", start);
    }                           /* end of block */
    printf("The End!\n");
    return;
}




