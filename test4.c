#include <stdio.h>
//二进制数0000 0001(机器数+1) 补码1111 1111(二进制数+1的补码,机器数-1的补码) 
//1000 0001(机器数-1的原码,机器数-1补码转原码,符号位不变)
//二进制数运算 0000 0010
//            +1111 1111 (-1的二进制数补码,非机器数-1补码) 
//            取余位后的结果与(0000 0010 - 0000 0001结果相同,同余定理)
//            1111 1111 数学意义上它是0000 0001补码(设计计算机电路时用1111 1111代表机器数-1补码)
//            所以符号位不变,余位取反+1这个转换规则并不是数学意义上的转换,而是人为规定的,实际的二进制数并没有所谓符号位
//            只是在计算机电路中这样转换得到机器数规定的-1补码,计算机中负数都以补码储存
//            十进制表述运算就是: 任何数-1(数学意义上的原码)等于任何数+1(数学意义上补码),取余位结果相同
//1.被减数大于等于减数绝对值,运算后直接得到结果
//2.被减数小于减数,运算后得到结果的补数
//数学运算时负数结果有负数符号,但机器数没有+-符号,而是用最高位表示符号位
//所以结果最高位为0,计算机就判定结果为正,最高位为1则判定结果为负数的，且为补码，得到正确结果还要
//根据机器数的补码转换规则转换成原码(所以才会有符号位不变,余位取反加1这种非数学意义上的补码转换规则。。。)
//再往下深究在计算机中具体怎么实现就要到数字电路了,差不多得了--',以后有时间再深入理解...
int main(void)
{
    short int  x,s,a = 6,b = -7;
    unsigned short int i;
    char c;
    
    s = a + b;

    printf("s=a+b = %hd\n", s);
    printf("s=a+b = %hx\n", s);
    printf("s=a+b = %hx\n", a + b);
    printf("size of i:%d\n", sizeof(i));
    printf("s=a+b = %hu\n", a + b);
    //整数常量255 4byte 0000 0000 0000 0000 0000 0000 1111 1111
    //赋值给char 1111 1111(只保留最后1byte)是负数-1的补码 
    //转换说明 short int 1111 1111 1111 1111 负数填充1111 1111
    printf("%hd %hx\t %hx %hx\n", c = 255, c = 255, x = -255, -255);
    //0111 1111 整数填充 0000 0000 0111 1111 前面填充0000 0000
    printf("%hd\v %hx\n", c = 127, c = 127);
    printf("%hd\n", x = 32768); 
    printf("\x41 \077\n"); //转移序列 \xhh十六进制
    printf("what is you name\" \n");
    printf("%hx\n", 1-2);
    return 0;
}






