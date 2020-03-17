#include <stdio.h>

//scanf()函数返回值,读取成功返回1,读取失败返回0
void main(void)
{
    long int num, sum = 0L;
    unsigned short int status;
    
    printf("input integer:");
    status = scanf("%ld", &num);
    printf("status: %hu\n", status);
    while (status == 1){
        printf("sum: %ld\n", num);
        sum = num + sum;
        printf("input integer:");
        scanf("%ld", &num);
    }
    printf("Game Over!");
    return;
}

