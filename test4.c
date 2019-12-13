#include <stdio.h>
//c库中的文件<limits.h>定义了一组常量,用来限定编译器complier运行的这台机器的整型数据类型的取值范围
#include <limits.h> 
//预备知识:
//+1元:我有1元钱; -1元:我欠某人1块钱,也可以说我有-1元钱...
//1-2= 怎么得到结果-1
//1-2 = -2+1 = -1*2 + -1*-1 = -1*[2+(-1)] = -1*(2-1) = -1*1 = -1 (一个-1)
//-----------------------------------------------------------------------------------
//上面第三步还有一个知识点: 1 = -1*-1 (负负得正)
//那负数乘负数为什么得正呢。。。
//2-2 = 2+(-2) = 0
//[2+(-2)] * (-3) = 0 * (-3)
//2*(-3) + (-2)*(-3) = 0 乘法分配律
//(-6) + (-2)*(-3) = 0
//两边同时+6    6+(-6) + (-2)*(-3) = 6+0
// (-2)*(-3) = 0 + 6 = 6 由此推到出负负得正的结论  
//日常生活中的解释: 我欠甲人3元,欠乙人3元, 我拥有(-3) + (-3) = -6元, 再-(-6),现实生活中(-)要还6元,
//但我现在身上有0元,所以我要先赚6元,所以0+6
//所以要-(-6)要减去负债6元 = +6赚6元 
//-----------------------------------------------------------------------------------
//上面第四步还有一个知识点，公因式(commom factor)
// a*c + c*b = c*(a+b) 提取公因式
//-----------------------------------------------------------------------------------
//理解的关键点一:二进制数的原码补码 与 机器数的原码补码 有所不同
//理解的关键点二:平时我们已经习惯十进制的思维,所以用十进制举例来解释二进制的机器码原理,更有助于理解
//              mod模为10,0~9十个基数,+表示正数,-表示负数(机器码中0表示正数,1表示负数原理是一样的);
//              取值范围:-10~+9,根据机器码补码规则,用-0表示-10;
//              -9是+1对于模10的补数,根据机器码的规则,用-9(相当于机器码中的补码)代表-1(所以符号位不变,数值位求补码)
//              《计算机科学导论第三版》P32 图3-8 有助于具象化理解 关键点二
//
//二进制数原码和补码是相互的,二进制数原码0000 0001 补码1111 1111;二进制数原码1111 1111 补码0000 0001
//二进制数0000 0001(机器数+1) 补码1111 1111(二进制数+1的补码,机器数-1的补码) 
//1000 0001(机器数-1的原码,机器数-1补码转原码,符号位不变)
//-----------------------------------------------------------------------------------
//二进制数运算 0000 0010
//参考:《计算机科学导论第三版》 P34 图3-9  P55 二进制补码加减法  P57 第一段话
//理解机器码补码加减运算关键点一：
//    引入数学概念:模运算
//                 模是一个计量器的计数范围
//                 计算机的数据位数(字长)是有限的,计算机也可以看成是一个计量器,所以必然是模运算,
//                 比如说钟表,它所能表示的整点情况只有十二种,所以它的模是12
//    a.在模运算中,假设模为M,一个整数和一个负数互为补数时,两个数的绝对值之和为模
//    b.在模运算中,减去一个数等于加上这个数的补数
//     模运算:   M=10  8+10=8
//                     9+(-6)=3   9+4=3 
//                                9+(-6)+10=3
//    补数是一种处理有符号数的方法,用于变换数字的符号.在计算机科学应用中被称为"补码"
//    补码的定义: [x补] = M + x  
//            1) x >= 0, 模M作为超出部分要被舍去,[x补]=x,因此正数的补码就是其本身
//            2) x < 0, [x补]就是x以M为模的补数
//    一个数的补数等于模加这个补数,再取模求余.
//
//-----------------------------------------------------------------------------------
//理解机器码补码加减运算关键点二：
//    参与运算的每个数和结果要在分配的二进制位的定义范围内,超出了就发生溢出错误了
//理解重点:(以4bit字长为例)本质就是[0000,1111]之间的数进行加法运算(同余定理解决了减法变加法的问题),
//        且结果还在[0000,1111]中, 结果代表的实际数字在设计计算机时规定了,根据规定方法换算得到原码即可,
//        但机器码原码所代表的实际数字(数学意义上的数字)也是设计计算机时人为规定的.
//
//     +1111 1111 (-1的二进制数补码,非机器数-1补码) 
//     取余位后的结果与(0000 0010 - 0000 0001结果相同,同余式)
//     1111 1111 数学意义上它是0000 0001补码(设计计算机电路时用1111 1111代表机器数-1补码)
//     所以符号位不变,余位取反+1这个转换规则并不是数学意义上的转换,而是人为规定的,实际的二进制数并没有所谓符号位
//     只是在计算机电路中这样转换得到机器数规定的-1补码,计算机中负数都以补码储存
//     十进制表述运算就是: 任何数-1(数学意义上的原码)等于任何数+1(数学意义上补码),取余位结果相同
//1.被减数大于等于减数绝对值,运算后直接得到结果
//2.被减数小于减数,运算后得到结果的补数
//数学运算时负数结果有负数符号,但机器数没有+-符号,而是用最高位表示符号位
//所以结果最高位为0,计算机就判定结果为正,最高位为1则判定结果为负数的，且为补码，得到正确结果还要
//根据机器数的补码转换规则转换成原码(所以才会有符号位不变,余位取反加1这种非数学意义上的补码转换规则。。。)
//-----------------------------------------------------------------------------------
// 补码    用补码代表相应的有符号整数
// 011               3
// 010               2
// 001               1
// 000               0
// 111              -1
// 110              -2
// 101              -3
// 100              -4
// mod模1000,减001等于加它的补码111,先别管它在计算机中所代表的的有符号整数
// 计算机设计中规定的,用001表示+1,第一位符号位0表示正;用001的补码111表示-1,符号位1表示负
// 
//再往下深究在计算机中具体怎么实现就要到数字电路了,差不多得了--',以后有时间再深入理解...
//
//===================================================================================
//看来一堆资料后,最具象化,最简单的理解来了!!!不需要公式！！！
//计算机的字长是固定的,可以把计算机看成是一个计量器,
//比如说钟表就是一个计量器,钟表是对时间的计量,钟表上的计量值是有限的，所以进行的是模运算，模为12(这里只考虑整点值)
//再引申到计算机,假设非负整数n为字长,则计算机的模为2^n
//再拿钟表来理解,日常接触的东西,更容易理解,原理都是一样的
//比如说现在指针指向1点(现在是凌晨1点),然后+1(也就是顺时针转1格,顺时针计量值越来越大,所以是加法)
//然后指针指向2, 1+1=2
//也可以时光倒流,回到3个小时前(也就是-3,计量器逆时针转,往计量值越来越小的方向转,当然转回上一个模时计量值会重置为最大值),
//然后指针指向了10,不能理解得话就这样想,凌晨1点,时光倒流3小时,不就是前天10点吗(这是指针是指向计量值10)
//这里转折来了,我们可以把这个钟表计量器改良一下,改成计量值[0,15],相当于n=4,
//用计量值[0,7]代表非负整数[0,7];
//用计量值[8,15]代表负整数[-8,-1];
//(其实你可以用计量值代表任何数字,字母,表情符等,任何东西都行,只要你想得到的,十二生肖也行,这并不影响模和计量值的计算)
//接着上面,1-3,指针指向计量值14,而我们刚刚用计量值14代表负整数-2,所以得到结果-2
//参与运算的数和结果不能超过我们所规定的范围,否则会出现溢出,大于所代表的最大值,则正溢出,小于所代表的最小值则负溢出.
//n=2,取值范围[-2,1],计算机大部分才有补码方式储存数据,像下面那样:
//         00  01  10  11  
//         0   +1  -2  -1
//1+1=2,超出取值范围,正溢出,(01)+(1)2=(10)2,计量值10在该例子中表示-2
//-2-1=-3,(10)2-(1)2=(01)2,计量值01代表+1,当然,真实的计算机运算中机器码是以补码相加来进行运算的,计算机只有加法器
//实际上就是模2^n的加减法运算,这个知识点还没看。。。第二天再看。。。准备睡觉
//然而事情并没有这么简单。。。补码的数学原理还要去啃一下《深入理解计算机系统》(原书第三版),呜呜呜~要崩溃了。。。--·
//
//===================================================================================
//《深入理解计算机系统》(原书第三版) 第二章 2.2 整数表示,看完了对计算机数据的存储理解更深入了
//学习还是要找对书啊~
//向量:有大小和方向
//bit vector(位向量)
//∑(求和符号,读音为sigma)
//负权值(负权重,negative weight) 
//w=2,补码(二补数two's complement)  B2T(11) = 1*(-2^1) + 1*2^0 = -1
//权值(权重weight value): 权值为负怎么理解呢
//附加知识点：十进制也好,二进制也罢,本质都是{计数系统},混合进制计数系统也是可以的,
//           例如,111,数位0,2为十进制,数位1为八进制. 则它们的权值为[1,10,80]
//我个人的理解->有两个人,拥有1块钱的有一人,欠债2块钱的有一人,补码11,数位0的权值为1,数位1的权值为-2,
//所以他们一共有多少钱?有上面B2T(11)函数可得结果
//
//unsigned encodings 无符号数编码
//原码(sign magnitude) 补码(two's complement) 反码(one's complement) 都是机器数,
//机器数所对应的真正数值,称真值
//
// binary    unsigned    sign magnitude    one's complement    two's complement
//  000        0               0                0                   0
//  001        1               1                1                   1
//  010        2               2                2                   2
//  011        3               3                3                   3
//  100        4              -0               -3                  -4
//  101        5              -1               -2                  -3
//  110        6              -2               -1                  -2
//  111        7              -3               -0                  -1
//
//附注: 10补数,9补数 2补数(two's complement),1补数(one's complement)的概念,知乎收藏夹[数字电路设计-第二讲]
//
void limits_head_constants(void); //函数声明,function declaration
void unsigned_int_operation(void);

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
    
    limits_head_constants();
    unsigned_int_operation();
    return 0;
}

void limits_head_constants(void)
{
    printf("int Max:%d\n", INT_MAX);
    printf("int Min:%d\n", INT_MIN);
    printf("unsigned int Max:%u\n", UINT_MAX);
    return;
}

void unsigned_int_operation(void)
{
    short unsigned int us1 = 10, us2 = 20, result;
    //无符号数一般不这样用,这里只是验证一下无符号数的编码储存
    result = us1 - us2; 
    //本质是位向量的运算(bit vector),加上模和补数的知识,转换说明相当于"function",最后得到(映射到真值)结果,
    //映射到啥就是啥了~ 

    //数学术语双射,《深入理解计算机系统》(原书第三版)P44 无符号数编码,补码编码的唯一性
    //个人心得:w(字长:计算机分配的数据存储长度)一样的情况下,binary都一样,只是映射到不同的真值,
    //         映射到unsigned,反射回binary,这个binary就是unsigned encodings；
    //         映射到two's complement number，反射回binary,这个binary就是补码编码
    //注:个人心得未必正确,只是目前个人的理解.

    //B2U[w](x:bit vector) {二进制数binary to 无符号数编码unsigned encodings} =映射--> 无符号整数(真值)
    //U2B[w](x:decimal value) {二补数(补码)two's complement to 二进制数binary } =反射--> 二进制数(补码表示)

    //B2T[w](x:bit vector) {二进制数binary to 二补数(补码)two's complement} =映射--> 有符号整数(真值)
    //T2B[w](x:decimal value) {二补数(补码)two's complement to 二进制数binary } =反射--> 二进制数(补码表示)
    printf("Wrong result:%hu,Right result:%hd,Right result:%hu\n", result, result, us1 + us2);
    return;
}









