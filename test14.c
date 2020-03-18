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
    while (status == 1){
        sum = num + sum;
        printf("sum: %ld\n", sum);
        printf("input integer:");
        status = scanf("%ld", &num);
    }
    printf("Game Over!\n");
    return;
}

