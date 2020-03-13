#include <stdio.h>

//scanf()函数返回值,读取成功返回1,读取失败返回0
void main(void)
{
    long int num;
    unsigned short int status;
    
    status = scanf("%ld", &num);
    printf("%hu\n", status);
    return;
}


