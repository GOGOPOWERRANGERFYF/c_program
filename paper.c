#include <stdio.h>
#include <string.h>
#define NAME "fyf"
int function1(void);
int function2(void);
int function3(void);
int function4(void);
int function5(int a, int b);
int function6(void);
int function7(void);
void function8(void);
int function9(void);

int main(void)
{
    char name[3] = "fy";
    int a, b;
    printf("NAME(%%s): %s\n", NAME);
    printf("NAME(%%c%%c,enter key:ascii(decimal)=%%d): *%c%c%d*\n"
        , name[0], name[1], name[2]);
    //function1();
    //function2();
    //function3();
    //function4();
    //while (scanf(" %d %d", &a, &b)){
    //    if (a >= b){
    //        function5( a, b);
    //        printf("a >= b\n\n");
    //    }
    //    else {
    //        function5( a, b);
    //        printf("a < b\n\n");
    //    }
    //}
    //printf("input is not integer\n");
    function9();
    return 0;
}

int function1(void)
{
    int a, b, r;
    r = scanf(" %d %d", &a, &b);
    printf("a = %d, b = %d.\n", a, b);
    printf("function scanf return value = %d.\n", r);
    printf("r size = %u.\n", sizeof(r));
    return 0;
}

int function2(void)
{
    int a, b;
    while(scanf(" %d %d", &a, &b) == 2){
        printf("signal_a\n");
        continue;
        printf("signal_b\n");
    }
    printf("over!\n");
    return 0;
}

int function3(void)
{
    int n;
    while (scanf("%d", &n) == 1){
        if (n > 10)
            continue;
        else
            break;
    }
    printf("n <= 10\n");
    return 0;
}

int function4(void)
{
    char c1, c2;
    //while (scanf("%c%c", &c1, &c2) == 2){
    //    printf("%d%d\n", c1, c2);
    //}
    while (scanf("%c", &c1) == 1){
        printf("%d\n", c1);
    }
    return 0;
}

int function5(int a, int b)
{
    printf("a = %d, b = %d.\n", a, b);
    return 0;
}

int function6(void)
{
    int i, j, n = 0, a[6][6];
    for (i = 0; i < 6; i++){
        for (j = 0; j < 6; j++){
            a[i][j] = n++;
            printf(" a[%d][%d]=%3d;", i, j, a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

int function7(void)
{
    int i, j, n = 10;
    double x;
    for (i = 0; i < n; i++){
        for (j = i; j < n; j++){
            printf(" %d", j);
        }
        printf("\n");
    }
    return 0;
}

// 打印浮点数的内存存储值(C IEEE754标准值),内存中实际值牵涉到
// 大小端,不同CPU,编译器,X86 X64等不同,实际的值会有顺序的排列不同
// 涉及到计算机组成原理,编译的知识...这部分内容之后再补齐
// 用memcpy函数,调用c内置函数可以得到理论结果,
// 但并不能帮助知道内存的实际存储形式,所以后期要补齐短板知识
void function8(void){
    int a;
    float f = 0.75f;
    double d = 0.75;
    //1/2 + 1/4 + 1/8
    //1 - 1/2 + 1/2 - 1/4 + 1/4 - 1/8 = 1 - 1/8
    //0.11 
    //1.1 * (2^-1)10
    //sign:
    //0
    //exponent (bias_1023)
    //真值：-0000 0000 001
    //      1111 1111 111 二补数 
    //      0111 1111 111 bias_1023
    //    1|0111 1111 110 exponent
    //mantissa: 
    //1000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
    //0 0111 1111 110 1000 后面12个0000
    //内存拷贝函数
    //函数原型声明在<sting.h>
    //string 串,一串,线,一系列,一连串
    memcpy( &a, &f, 4);
    printf("%x\n", a);
    //printf("%d\n", sizeof(f));
    //printf("%d\n", 
    //strlen("0011111111101000000000000000000000000000000000000000000000000000"));
}

int function9(void){
    int int_temp;
    long int long_int_temp;
    double array1[2], a = 0.75f, b = 1.5f,
     * int_pointer1, * int_pointer2;
    
    int_pointer1 = &a;
    int_pointer2 = &a;
    array1[0] = *int_pointer1;
    array1[1] = *int_pointer2;
    
    printf("sizeof(int_pointer1): %d\n", sizeof(int_pointer1));
    printf("%%p: %p\n", int_pointer1);
    printf("%%p: %p\n", int_pointer2);
    //printf("%f\n", array1[0]);
    //printf("%f\n", array1[1]);
    //printf("%lx\n", int_pointer1);
    //printf("%lx\n", int_pointer2);
    //printf("%#lx\n", int_pointer1);
    //printf("%#lx\n", int_pointer2);
    //printf("%8d\n", 8);
    memcpy( &int_temp, &a, 4);
    memcpy( &long_int_temp, &a, 8);
    printf("int_temp: %x\n", int_temp);
    printf("long_int_temp: %lx\n", long_int_temp);
    // 强制类型转换为long int类型变量的指针
    // 1. 储存空间大小
    // 2. 数据类型
    printf("%lx\n", *(long int *)&a);
    
    return 0;
}