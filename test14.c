#include <stdio.h>
//scanf()函数返回值,读取成功返回1,读取失败返回0
void main(void)
{
    //这里用long int类型常量(constant)0L,
    //用0其实也没问题(int类型常量0会隐式转换为long int)
    //但还是建议保持数据类型的一致性
    long int num, sum = 0L;
    unsigned short int status;
    
    printf("input integer:");
    status = scanf("%ld", &num);
    printf("status: %hu\n", status);
    //该while循环的测试条件(test condition)为如下表达式(expression),也是(full expression)
    // status == 1 (这表达式结束就是一个序列点sequence point)
    // == 相等运算符(equality operator)
    // status == 1 status是否等于1
    // status = 1  赋值1给变量status
    while (status == 1){
        sum = num + sum;
        printf("sum: %ld\n", sum);
        printf("input integer:");
        status = scanf("%ld", &num);
    }
    printf("Game Over!\n");
    return;
}

// * clang是llvm编译系统(low level virtual machine)的前端
//   llvm  objdump -d -x86-asm-syntax=intel
//   与gcc objdump -d -m intel 不相同

// iteration 迭代
// multiplexer 多路复用器

// while循环的通用形式:
//     while (expression)        
//        statement
// statement可以是以分号结束的简单语句,也可以是花括号括起来的复合语句
//
// expression都是使用关系表达式,expression的值为非零,执行statement部分一次
// 再判断expression的值是否为0
// 直到expression值为0,循环停止
// 每次循环都称为一次迭代(iteration)
//



