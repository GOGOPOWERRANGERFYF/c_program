// 草稿纸
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
int function10(void);
void function11(int n);
//void function12(char * c[]);
void function12();
void function13();
void sieve_of_erathosthenes(void);

int main(void)
{
    //char name[3] = "fy";
    //int a, b;
    //printf("NAME(%%s): %s\n", NAME);
    //printf("NAME(%%c%%c,enter key:ascii(decimal)=%%d): *%c%c%d*\n"
    //    , name[0], name[1], name[2]);
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
    //function10();
    //function11(1);
    //function12();
    //function13();
    sieve_of_erathosthenes();
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

int function10(void){
    int i = 1;
    long int li;
    float f = 0.75;
    // 基于目前个人知识水平的理解,
    // 《计算机组成》P32 寻址方式
    //《计算机组成》P34 间接和指针
    // &i为int变量i的指针的值
    //个人推论(根据目前的知识水平推论):
    //  &float变量 不同的变量类型,分配的虚拟地址(指针的值)不同
    //  打印函数待打印列表(, float变量),%x为int类型的转换说明
    //  cpu Load(write,fetch)的操作数地址为 
    //      按int类型变量 分配的 操作数的指针
    //          Move (int类型指针) R1
    //  但编译器生成的为 float类型操作数的值和指向float类型变量的指针
    //      两个指针的值(虚拟地址)不相同
    //  因此读取不到正确的操作数的值
    printf("%p\n", &i);
    printf("%lx\n", &i);
    //printf("%x\n", *&i);
    //printf("%x\n", *(float *)&i);
    printf("%x\n", *(int *)&f);
    return 0;
}

void function11(int n){
    // function 缩写:func/fn
    printf("recursive call level%d -> n = %d location: %p\n", n, n, &n);
    if (n < 3){
        function11(n + 1);
    }
    printf("recursive call level%d <- n = %d location: %p\n", n, n, &n);
    return;
}

//void function12(char * c[]){
void function12(){
    int a, b;
    // incomplete type 不完整类型
    // 无法确认该描述符大小的类型
    // 例如: int * i[]; 一个数组没有指定大小
    // 但可以作为 函数原型 和 函数头 的形参

    //int * i[] = &a;

    // 指针数组
    int * i[2];
    i[0] = &a;
    i[1] = &b;
    printf("sizeof(i): %zd\n", sizeof(i));
    printf("i[0]: %p\n", i[0]);
    printf("i[1]: %p\n", i[1]);
    printf("&a: %p\n", &a);
    printf("&b: %p\n", &b);
    return;
}

void function13(){
    char character_string[] = {"This is character string!"};
    printf("sizeof(character_string): %zd bytes\n", sizeof(character_string));
    printf("character_string[0](decimal): %hu\n", character_string[0]);
    printf("character_string[25](decimal): %hu\n", character_string[25]);
    return;
}

void sieve_of_erathosthenes(void){
    int i, j, ;
    return;
}