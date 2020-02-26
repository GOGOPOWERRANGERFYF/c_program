#include <stdio.h>
//定义符号常量,预编译时后面的字符串替换前面的符号常量(文本)
#define OPERATORS "= + - * /"
void while_block(void);
void addition_substraction_operator(void);
void sign_operator(void);
void sixty_four_game(void);
void division_operator(void);

int main(void)
{
    // operator:运算符; expression:表达式; statement:语句;
    // operand:运算数,操作数;
    // = 赋值运算符(assignment operator)
    //格式字符串中的转换说明%s,后面的待输出项类型和熟练要与转换说明相匹配
    printf("These is operators: %s\n", OPERATORS);
    while_block();
    addition_substraction_operator();
    sign_operator();
    sixty_four_game();
    division_operator();
    return 0;
}

void while_block(void)
{
    //这里的 =运算符 表示 初始化而不是 赋值
    const int ONE = 1;
    
    //把整数值0赋给变量start,赋值表达式
    // 可修改的左值 = 表达式的值(包括常量,变量,可求值的表达式) 
    int start = 0;
    // C的当前标准
    //(早期C标准的lvalue: left value
    //,rvalue: right value的定义已经不能满足当前的状况)
    // 左:
    //  *modifiable lvalue(可修改的左值)
    //  object locator value(对象定位值)
    // 右:
    //  *value of an expression(表达式的值)
    //  包括常量,变量,可求值的表达式
    //《c primer plus第六版》中文版的定义:
    //赋值语句的目的是把值储存到内存位置,储存值的内存存储区域称为数据对象(data object)
    //我自己根据《c primer plus第六版》英文版的翻译
    //考虑一个赋值语句.它的目的是储存一个值在一个内存位置.
    //数据对象是一个 用于存储整个值的数据存储区域的 通用术语

    while(start<10)/* starting the while loop  */
    //花括号之间的内容是要被重复的内容,用计算机术语说,就是程序循环这些语句
    /* start of block,花括号以及花括号括起来的部分被称为block */
    {                           
    // 目前个人的理解,下面整句为赋值语句,
    // start + 1为表达式的值(可求值的表达式),它是程序计算的一个临时值,之后会被丢弃,应该是赋值给左值后丢弃吧,个人推测... 
    // 常量是由系统在main函数运行前把常量赋值给常量的...(网上的说法,也不知道对错,待以后验证吧...)
    // 只有变量是可以引用内存地址的(个人理解,待验证,目前知识水平有限...)
        start = start + 1;      
    // operand(the item项 to the left of =) = operator operate on
    //    操作数(运算数)[赋值运算符左侧的项]  = 操作数(运算数) 操作符(运算符)操作(运算) 操作数(运算数)
    //    modifiable lvalue(可修改的左值)   =  操作数(运算数) 操作符(运算符)操作(运算) 操作数(运算数)
        printf("%d\n", start);
    }                           /* end of block */
    printf("The End!\n");
    return;
}

//addition operator和subtraction operator称为bianry operator(二次元...哦,不,二元运算符XD)
//即这些运算符需要两个运算数(operand)才能完成运算
void addition_substraction_operator(void)
{
    int ao_i_a, ao_i_b, ao_i_c;
    //assignment statment,赋值语句;assigement operator,赋值运算符;
    //可修改的左值(modifiable lvalue) = 表达式的值(an value of expression)(变量,常量,可求值的表达式)
    ao_i_a = 2;
    ao_i_b = 1;
    // 关键知识点:
    // * ao_i_a + ao_i_b表达式,程序计算的一个临时值,计算完成后会被丢弃,它并不能表示特定的内存位置,
    // * 个人推理:计算出的临时值,应该直接从寄存器直接赋给变量(可修改的左值的内存存储区域:数据对象)了,很合理吧...
    // * 因此不能赋值给它
    ao_i_c = ao_i_a + ao_i_b;
    printf("ao_i_a + ao_i_b = %d\n", ao_i_c);
    ao_i_c = ao_i_a - ao_i_b;
    printf("ao_i_a - ao_i_b = %d\n", ao_i_c);
    return;
}

// sign operator(符号运算符): + 和 -
// unary operator(一元运算符),完成运算只需要一个运算数(operand)
void sign_operator(void)
{
    int so_i_a, so_i_b;
    so_i_a = 5;
    so_i_b = -so_i_a;
    printf("so_i_b = -so_i_a = %d\n", so_i_b);
    return;
}

// count初始化等于1
// while循环,循环一次,count+1
// 循环1:  count = 2
// 循环2:  count = 3
//  ... ...
// 循环63: count = 64
// 循环条件count<64,语句块循环了63次,count=64,循环停止
void sixty_four_game(void)
{
    int count = 1;
    double number = 1.0, total = 1.0;
    printf("count                ");
    printf("number                     ");
    printf("total\n");
    printf("%3d. %22.1f %25.1f\n", count, number, total);
    while(count<64)
    {
        count = count + 1;
        // * multiplication operator乘法运算符
        number = 2.0 * number;
        total = total + number;
        printf("%3d. %22.1f %25.1f\n", count, number, total);
    }
    printf("The Max of number: %22.1f\n", number);
    printf("The Max of total:  %23.1f\n", total);
    printf("The End!\n");
    return;
}

//数学知识温习,前面的c文件也有,但有点难找,懒得翻回去找了...
//除法,减法的定义:
//除于一个数等于乘于这个数的乘法逆元(倒数)
//减去一个数等于加上这个数的加法逆元(相反数)
//division operator除法运算符 /
void division_operator(void)
{
    //在C语言中,整数除法的计算结果小数部分会被丢弃,称为截断
    //C99规定 趋零截断
    printf("7/4 = %d\n", 7/4);
    //浮点数除法
    printf("7.0/4.0 = %f\n", 7.0/4.0);
    //浮点数整数混合,一般情况下,还是要避免这种情况
    //计算机并不能真正浮点数和整数相除,浮动数和整数在内存中的存储方式完全不同
    //下面两句代码中,在进行除法运算前,编译器会把整数转换为浮点数
    printf("6.0/3 = %f\n", 6.0/3);
    printf("6/3.0 = %f\n", 6/3.0);
    return;
}



