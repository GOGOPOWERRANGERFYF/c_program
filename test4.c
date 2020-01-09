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
//原码(sign符号 magnitude大小) 补码(two's complement) 反码(one's complement) 都是机器数,
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
//*补数加减法核心知识点(武林神功之一啊)
//附注: 10补数,9补数 2补数(two's complement),1补数(one's complement)的概念,知乎收藏夹[数字电路设计-第二讲]
//      理解末端进位,可以判断 被减数和减数 之间的大小
//      十进制:9补数,10补数
//      二进制:1补数,2补数
//      20191227个人理解: 9补数,让每一位值都变成9,比如333,求它的9补数,333+666=999,让每一数位值都为9
//                       999再加1,每一位都满10进1,所以333的10补数是667,这就是所谓的10补数
//      需特别注意:0的10补数是0,而不是套公式所得到的值,因为计算机中w位数截断(计算机中这个没错,但从数学上讲,这个有疑问,待确认)
//                5的10补数是5,50的十补数是50
//                two's complement 001和111为一对二补数,分别映射有符号整数1和-1
//      20191229 继续啃十补数,十补数的减法运算(二补数原理也是相同的)
//        被减数和减数数位不同时,取补数时位数以位数长的为准
//        设被减数为m,减数为n,w以参与运算的数中数位最长的为准
//       A.m,n为正数,减数为负数的话,-(-n)=+n,无讨论意义:(20200101补充)
//        m-n ---> m + (10^w - n) = m - n + 10^w
//        1) 如果 m ≥ n, m-n≥0,则减去10^w就可得到正确结果(模除效果也一样,模为10^w)
//        2) 如果 m < n, m-n<0,则再求补数, 10^w - (m - n + 10^w) = -m + n = n-m(这里模除,模为10^w,结果也是还n-m)
//           -->加符号 -(n-m)得到正确结果       
//        举例: m≥n:
//                010-001 ---> 010-001+1000 = 001 + 1000 = 1001 -->1000就是所谓的溢出部分,减去即可(模除1000结果一致)
//              m<n:
//                001-010 ---> 001-010+1000 = -001+1000 = 1000 - 001(得到001的2补数)= 111
//                111求-001这个正确结果: 先求10补数-->001,再加上负号-001。。。OK!打完收工
//       B.m为负数,n为正数,因为n为负数的话,-(-n)=+n就没有讨论的意义了,:(20200101补充)
//        举例: -4-2=-6 --> 6+8 = (10-4)+(10-2) = (-4-2)+10+10 = 4 + 10
//             减去10--十补数之和(模除10效果一样)后再求十补数加负号才得到正确结果
//        -001-001 --> 111+111=1110  1110-1000(1110 mod 1000)=110  110十补数=010 --加负号-> -010 (十进制-2)
//
//  *处理器提供了一套它能支持的运算操作集合,称为指令集.
//   输入程序和数据:1+2 --> 计算机中:001+010=011 -->输出:3
//   输入程序和数据:7+7 --> 计算机中(设w=3):111+111=1(110) -->110-->输出:6 (溢出)
//                                                          |--->计算机 数据+指令得到的数据,映射到什么值与它无关
//
//  additive inverse:加法逆元(或称相反数),对于任意一个数n,n和其加法逆元之和为加法单位元(即为零)
//      例如: 7的加法逆元为-7,-0.5的加法逆元为0.5
//      -(-x)为什么等于x:x+(-x)=0=(-x)+x,-x为x的加法逆元,x也是-x的加法逆元,-(-x)为-x的加法逆元等于x
//                      x加上它的相反数-x等于0,-x加上它的相反数-(-x)等于0,因此-(-x)=x
//  加法单位元:在加法运算的集合中,加法单元位加上集合内的任何一个数x,和都会等于这个数x.
//      例如: x+0=x=0+x
//  乘法逆元:在实数范围内, x * 1/x =1,x和1/x互为乘法逆元(x不可能为0,因为1/0无意义),乘法单位元为1.
//            x *  1/x = 1;
//           -x * -1/x = 1;
//
//20191214暂时小结
//     (以这个小结的为准,
//     之前的笔记因为个人理解不到位,还有国内课程教材真的不行啊...
//     英文原版>国内翻译>国内教材。。。
//     以看了国外书籍后的理解为准,毕竟这玩意别人才是原创...):
//     
//     位向量(bit vector) --(函数function)[映射map]--> 真值    (位向量和真值一一对应,唯一性)
//     
//     sign magnitude(符号+大小,国内所谓的原码,这翻译不直观):
//        真值encode成sign magnitude--映射-->位向量,反之,位向量=sign magnitude--[映射]-->真值
//     
//     one's complement(国内译反码现在的机器基本都用two's complement了,这里就不展开了,理解什么是9补数和1补数就行了)
//
//     two's complement(二补数,国内译补码):
//        真值encode成two's complement--映射-->位向量,反之,位向量=two's complement--[映射]-->真值
//        two's complement 001和111互为二补数,分别映射有符号整数1和-1
//
//     two's complemnt的加减法,本质就是位向量的模运算(详情阅读上面模运算的笔记)
//        二补数(补码)的运算结果正确,是位向量模运算后的余数映射到的真值结果与真值运算的结果相同,
//        当然前提是参与运算的数和结果要在补码映射的范围内,不然发生溢出,结果错误
//
//===================================================================================
//20191222 继续啃《深入理解计算机系统第三版》 P60 整数运算
// 无符号数加法(unsigned addition):----------------------------------------------------------start
//    取值范围: 0 <= x,y < 2^w
//    w位无符号数加法运算: 0 <= x+y < 2^w + 2^w
//                        0 <= x+y < 2 * 2^w
//                        0 <= x+y < 2^w+1       其实x+y实际小于2^w -1,因为x+y最大只能到2^w -2
//
//   假设w=3   0 <= x,y < 2^w --> 0 <= x,y < 2^3 --> 0 <= x,y < 8
//             0 <= x+y < 2^3 + 2^3 -1 = 2*2^3 -1 = 2*8-1 --> x,y取最大值, 7+7 < 15
//                                             or = 2^(3+1) -1 = 2^4 -1
//             二进制表示: x_max + y_max =111+111=1110 < 10000(d:2^w+1=2^3+1) -1=1111 
//
//  *无符号加法的核心知识点,无符号数加法的溢出检测:
//    s=x+y >= x,则没有溢出
//    如果结果溢出了,s=x+y-2^w=x+(y-2^w), 由上我们已知y<2^w,所以y-2^w<0
//             所以 s=x+(y-2^w) < x
//    推导出结论: s>x,没有溢出; s<x,溢出
//
// 取模运算: 10 mod 2=0(10对2取模,等于10除于2的余数)
//                   05 商
//               2   10       十位的1捆(10根/捆)辣条不够分成两捆
//                   10       把十位的1捆拆散成10根放到个位
//                   10       10根可以分成两份,5根一份(商)
//                    0 余    余数为0
//           1 mod 10(1对10取模)
//                    0 商
//               10   1
//                    1 余
//                             +u/w w位无符号数加法(和模2^w,可以被视为一种形式的模运算)
//w(word)     s(sum)           u(unsigned)/w(word)                            x,y=[0,2^w -1]
//  w=3   s=x+y=[0,2^w+1 -2]   s=x +u/w y=x+y mod 2^w(x+y对2^w取模)
//            1(110) -------                         (x+y除于2^w的余数)
//            1(101)       |
//            1(100)       |
//            1(011)     map3
//            1(010)       |
//            1(001)       |
//            1(000)-map1--|
//              111--map2--|--map2-> 111                                            111
//              110        |--map3-> 110                                            110        
//              101        |         101                                            101
//              100        |         100                                            100          
//              011       map1       011                                            011
//              010        |         010                                            010
//              001        |         001                                            001
//              000--map0--|-map0&1->000                                            000
//  x+y --映射(这里map short for mapper,map:地图)--> x +u/w y
//  s(sum)列中末端进位的数值就是溢出的s
//加法逆元(或称 相反数): 例如, 7的加法逆元是-7
//*unsigned encode无符号整数编码的本质: 一个数的十进制转换成二进制,这个二进制的位表示就是这个数的无符号整数编码
//   十进制数2和3,用2位二进制编码(无符号整数编码)表示,分别是[10],[11]
//   2+3的和等于5,用二进制编码表示是[101],这里机器位数2位,丢弃最高位,我们得到位表示[01],映射十进制值1
//   结果与 binary:101 mod 100 = 01   decimal:5 mod 4 = 1  模除结果一致
//   B2U本质就是一个数的二进制转十进制: B2U[111] = 1*2^2 + 1*2^1 + 1*2^0   B2U[100] = 1*2^2 + 0*2^1 + 0*2^0
//                                   B2U[111-100] = 1*2^2 + 1*2^1 + 1*2^0 - (1*2^2 + 0*2^1 + 0*2^0)
//                                   B2U[11] = 1*2^1 + 1*2^0
//                                     |--> bianry: 11
//   [辣条,辣条,辣条]的数量--位置计数法--|                     (两个数字表示的辣条数量都是一致的)
//                                     |--> decimal: 3
//
// 二补数加法(two's complement addition)---------------------------------------------------start
// 预备数学知识: start
//  下面三个指数幂统称整数指数幂
//  正整数指数幂的定义: w个2相乘的积记作2^w,称为2的w次幂
//  负整数指数幂的定义: 负指数幂等于把幂指数变号后所得的幂的倒数  2^-w = 1/2^w
//  零指数幂(底数为非零整数,因为除数不能为0,0作除数毫无意义): 
//         2^w/2^w=1  2^w *1/2^w=1  2^w*2^-w =1  2^(w-w)=1  2*2*2/2*2*2=1(除于一次2相当于分母的幂指数减一次1,w-1)
//         2^0=1
//
//  2*2^(w-1)=2^1 * 2^(w-1) 
//           =2^1+w-1 = 2^w
//  2^w/2^1=2^(w-1) 就是w个2相乘,除于2,不就还剩w-1个2相乘
//         =2^w * 1/2^1    1/2^1符合2^-1的定义
//         =2^w * 2^-1 =第一行的结果
//  *个人见解:为什么把2^-w定义为1/2^w幂指数变号得到的幂的倒数
//   2^3=2*2*2
//   2^3 *2=2^3 *2^1=2*2*2*2=2^4
//   2^3/2^1=2^3 *1/2^1=2*2*2/2=2^2=2^(3-1)  -->所以定义 1/2^1=2^-1 (*2^1增加两倍,*2^-1刚好缩小两倍)
//                                              这样正整数指数幂和负整数指数幂作用刚好相反
//   英文定义感觉更容易理解:
//   The power (or exponent) of a number says how many times to use the number in a multiplication(乘法). 
//   A negative exponent means how many times to divide by the number   
//   
//  2^w   乘法: 2^a * 2^b-->2^(a+b)
//        除法: 2^a/2^b-->2^(a-b)
//        举例: 2^3 * 2^2 = 2*2*2 * 2*2 = 2^5 = 2^(3+2)
//              2^3 / 2^2 = 2*2*2 / 2*2 =2 8分成4份,1/4四分之一份等于2 
//                        = 2^1 = 2^(3-2)
//              2*2*2 / 2*2 = 2*2*2 * 1/(2*2)
//  *数学乘除法的精髓,升华人生的知识点,理解完感觉自己飞升进入新境界了--' ...:
//      除法的本质,分成相同的份数(有存在余数的情况)
//      除法竖式的本质:(没有什么是一根辣条不能解决的,如果不能,那就一捆...)
//                   63.5
//              2   127.0   桌子2:1捆辣条(100根/捆) 桌子1:2捆辣条(10根/捆) 桌子0:7根辣条
//                  12     1.桌子2:1捆辣条(100根),没法分成两捆了(100根/捆),拆散分成10小捆(10根/捆)放到桌子1,
//                    7    2.桌子1:现在有12捆(10根/捆),分成2份,每份6捆
//                    6    3.桌子0:7根辣条,分成两份,每份3根,余1根,1根用刀分成10份,放到桌子-1
//                    10   4.桌子-1:10份(1份/0.1根),再平均分成两份,变成5份
//                    10
//                     0  
//      乘法的本质,将相同的数加起来的快捷方式,运算结果成为积,从哲学角度讲,乘法是加法由量变到质变的结果
//
//*武林绝学知识点之一,二补数转无符号数 和 无符号数转二补数的本质:
//        -->       w-1
// B2U(w)[ x 位向量]= ∑ x(i) * 2^i
//                i=0
//        -->                         w-2
// B2T(w)[ x 位向量]= x(w-1)*-2^(w-1) + ∑ x(i) * 2^i
//                                    i=0
//        -->
//  binary(x)  two's complement(x)   unsigned(x)       
//    [011]            3                  3
//    [010]            2                  2
//    [001]            1                  1
//    [000]            0                  0
//    [111]           -1                  7
//    [110]           -2                  6
//    [101]           -3                  5 
//    [100]           -4                  4
// 通过观察上表的规律,B2U和B2T两个函数(function),T2U 和 u2T 的推导:
// 这里的_w是指下标w,表示字长   
//             |----> = x (x>=0)  这里的x是指二补数的x
//   T2U_w(x) -| 
//             |----> = x + 2^w (x<0)
//  1. x>=0的情况比较直观,直接看B2U和B2T两个函数就可以直接看出,
//     输入相同编码(位向量),在xi=x(w-1)=0时(也就是无符号数编码和二补数编码最高位为0时),
//     函数输出的结果是一样的,所以映射到的真值相等
//  2. x<0的情况,
//     输入相同编码,在xi=x(w-1)=1时,
//     B2U B2T 输出结果 只有x(w-1)位的位权是不同的,余下的数位 数值和位权都一致,所以结果也是一致的
//             无符号编码: x(w-1)位位权  2^(w-1)
//             二补数编码: x(w-1)位位权 -2^(w-1)     
//     所以T2U(x),只要 -2^(w-1) + 2^w                 +剩下的位*位权之和 (无符号和二补数的和都一样)
//                    = -2^(w-1) + 2*2^(w-1)         +剩下的位*位权之和  
//                    = -2^(w-1) + 2^(w-1) + 2^(w-1) +剩下的位*位权之和 
//                    = 2^(w-1)                      +剩下的位*位权之和  
//                                     -->        -->
// U2T原理跟上面的T2U是一样的,这里就不详细展开了(要详细了解可以看《深入理解计算机系统第三版》P51):
//  1. x(unsigned)<=x(T's_c_max),B2U(w)[x]和B2T(w)[x]映射到的真值x是相等的
//  2. x(unsigned)>x(T's_c_max),理解的关键点:2^(w-1) - 2^(w-1) -2^(w-1)
//                                          =2^(w-1) - 2*2^(w-1)
//                                          =2^(w-1) - 2^w
//
//二补数加法(two's-complement addition)
//  w位二进制位置计数系统,有2^w种组合方式,平分成两组,2^w/2=2^w * 2^-1=2^(w-1),
//  一半代表非负数(非负数还要有一个组合代表0),一半代表负数,得到如下取值范围,
//  取值范围: -2^w-1 <= x,y <= 2^w-1 -1
//  它们的和: -2^w-1 + -2^w-1 <= x+y <= 2^w-1 -1 + 2^w-1 -1
//  
// 对取模运算(这里暂时主要讨论整数的取模运算)做个小小的了结:
//  注: modulo(模数) division(分裂,除法) modulo division(模除法) division operation(除法运算)
//      multiplication(乘法)
//  modulo operation(模除,取模操作,取模运算):模除得到的是一个数除以另一个数的余数.
//  给定两个正整数:被除数a和除数n, a modulo n(缩写为a mod n)得到的是使用欧几里德除法(带余除法)时a/n的余数
//  通常情况下a和n都是整数(对实数,浮点数取模也是可以的,这里暂时不讨论),余数r的取值范围[0,n-1],
//  a mod 1恒等于0(a/1,除法本质:/1分成1份,肯定等于这个数本身啊,也肯定不存在余数啊,所以恒=0),a mod 0未定义
//  
//       (110)
//       (101)
//       (100)        
//        011
//        010
//        001
//        000
//        111
//        110
//        101
//        100
//      1(011)
//      1(010)
//      1(001)
//      1(000)
//
//======================================================================================================
//20200103 真值与编码之间的数学原理的个人的一点理解:
//20200105 囧 越写越长了。。。以最新写的为准,越往下越新...
//二补数编码(two's complement encode)
//
//       二补数编码          十进制真值    二进制真值
//  w=3  011       --map-->     3     =   011
//       100       --map-->    -4     =  -100
//
//  binary(真值)                                                    decimal(真值)
//   -100 + -100                                                  = -4 + -4        真值的运算
// = -1000
//
//  (1000-100)+(1000-100) = 100 + 100 (二补数+二补数) -->把减法转换成二补数的加法来运算求结果
// = -100 + -100 + 1000 + 1000 
// = -1000 + 1000 + 1000              (-1000为 -100 + -100 的正确运算结果)
// = -1000 + 10000     
// =  1000                            (1000为减法运算正确结果的绝对值的二补数)
// =   000 + 1000
//   1000(减法转换为二补数加法运算后得到的结果)
//   --> 1000的二补数是1000                               1000 + 1000 = 1 0000(二补数之和)
//   --> 再加上负号= -1000,得到减法运算的正确结果
//这是补数运算的数学原理
//
//上面的例子在计算机中的运算
//  直接看上例中这一步: = 000 + 1000 = 1000
//  因为计算机的计算数位位数是有限的,这里假设字长w=3,计算机只保留结果最后3位,相当于截断了结果1000
//  计算机中得到的运算结果是000,相当于1000 mod 1000 = 000(000和0是一样的)
//  所以计算机运算得到的这个例子的结果并不是 真值运算结果的绝对值的二补数,
//  因此最后用B2T函数映射到了一个错误的真值(即所谓的溢出)
//  1000二补数编码被截断了最高位,最高位为负位权,相当于要减去一个数得到运算结果,
//  现在舍去了这一位,运算结果再加上这个数就得到舍去最高位后的映射结果
//
//理解的关键点: 计算机运算的截断相当于数学中的模除(modulo)
//             -001的二补数编码就是该数的绝对值的二补数,即001的二补数111
//             减法转二补数加法运算,从运算过程可以看出,结果由三部分组成:
//
//              1) 被减数为非负数(减数为非负数,减去一个负数等于加上这个数,就没讨论意义了):
//                 真值运算结果 + 减数的绝对值和其绝对值的二补数之和
//
//                    1.1) 如果真值运算结果大于等于0,则直接得到结果(二补数编码中,正整数的编码其实就是其二进制数),
//                         因为被计算机运算舍去最高位(截断结果)相当于模除了减数的绝对值和其绝对值的二补数之和
//                         (计算机中参与运算的两个数数值位数肯定是相同的,位数不足的也会填充到位数相等,
//                          二补数之和肯定是会末端进位的)
//                    1.2) 如果真值运算结果小于0,则得到结果是这个负数真值运算结果的绝对值的二补数
//                         因此得到的结果是负数真值结果的二补数,通过函数B2T可以直接映射到正确的真值结果
//                         (二补数编码,负整数的编码本质就是其绝对值的二补数,二进制数)
//                         例如: w=3  真值结果= -001
//                                    则计算机运算结果= 111, 111就是-001的二补数编码
//                                    B2T(111)=(这里省略计算的公式) -001 = -1
//                         
//             2) 被减数为负数:
//                真值运算结果 +  被减数的绝对值和其绝对值的二补数之和 + 减数的绝对值和其绝对值的二补数之和
//                (因为计算机中参与运算的数的数值位数相同,
//                 因此 被减数的绝对值和其绝对值的二补数之和 = 减数的绝对值和其绝对值的二补数之和)
//                 得到 负数真值结果的二补数 + 被减数或减数的绝对值和其绝对值的二补数之和
//                 被减数或减数的绝对值和其绝对值的二补数之和(计算机截断结果相当于模除掉这部分)
//                 = 负数真值结果的绝对值的二补数(也是负数真值结果的二补数编码)
//                 在计算机中这个二补数编码 --映射--> 负数真值结果
//                 w=3        -001 + -001 = -010, |-010|=010
//                二补数运算:   111 +  111           = 1110  
//                           = 1000-001 + 1000-001 
//                           = 1 0000 - 010
//                           001的二补数 + 001的二补数 = 010的二补数,所以二补数运算的结果等于负数真值运算结果的绝对值的二补数
//20200105主要看下面这一段就行了:
//  二补数运算举例: 
//    1) 计算机:
//     -100 + -100 + -100
//      101 +  100                (先计算前面两个) 
//    = 1000 - 100 + 1000 - 100
//    = -1000 + 10000             (-100 + -100 = -1000)
//    =  1000                     (-1000的4位二补数,也是-1000在计算机中的二补数编码,这里假设字长w=3)
//  w=3,这里截断数位,结果=000
//     000 + 100
//   = 000 + 1000 + -100
//   = 000 + 100
//   = 100  B2T--map--> -4
//  所以计算机中: -4 + -4 + -4 = -4-4-4 运行结果= -4
//
// 如果字长w不受限制,是可以计算出正确结果的:
//    -100 + -100 + -100
//     100 +  100                (先计算前面两个)
//  =  1000 - 100 + 1000 - 100
//  = -1000 + 10000             (-100 + -100 = -1000)
//  =  1000                     (-1000的4位二补数,也是-1000在计算机中的二补数编码,这里假设字长w=3)
//  
//    -1000 + -0100 = -1100
//  =  1000 +  1100
//  =  10000 - 1000 + 10000 - 0100
//  =  -1100 + 100000 
//  = -01100 + 100000 
//  =  10100 B2T--map--> (-12)10 (-01100)2=(-1100)2                        
//  (10100为-1100的5位二补数,也是-1100在计算机中的二补数编码,计算机中w至少5位才能存储真值-1100)  
//  (负数在计算机中都是以二补数编码储存的)                   
//
// decimal |  binary  | unsigned encode | two's complement encode 
//    7        111          111                  0111
//   -7       -111           -                   1001
//   -8      -1000           -                   1000
//二补数编码比二进制数字长(数位)多一位才能储存这个二进制数
//注:1000属于特殊情况,1000的4位(w=4)二补数位就是1000
// 1111的二补数编码01111
//-1111的二补数编码,编码过程: 
// -01111 --> |-01111| --> 01111 --> 10000(一补数) --> 10001(二补数)
//
//无符号编码: 7 -->  111 --> 111
//          -7 --> -111 -->  -
//
//通过十补数运算来理解-->计算机中的二补数运算
//(原理一样,但二进制数运算有其特殊性,计算机中算法也有其特殊性):
//  9 - 4 = 09 - 04 (等价于09 + -04) = 05
// --> 减法转十补数加法运算(计算机运用的十补数加法运算,数学中并不需要这样算) 
// --> 09 + 96 
//   = 09 + 100 - 04 
//   = 09 - 04 + 100 
//   = 05 + 100 
//   = 105            
// --> 105减去溢出部分100(与105mod100结果一样)
// --> 得到正确结果05 
//
// 4 - 9 = 04 - 09(等价于04 + -09) = -05
// --> 04 + 91
//   = 04 + 100 - 09
//   = 04 - 09 + 100
//   = -05 + 100
//   =  95            (95为05的二位十补数)
// --> 求95的二位十补数,得到05
// --> 再加上负号,得到正确结果 -05   
//
// -4-4 = -04-04(等价于-04 + -04) = -08
// --> 96 + 96
//   = 100 - 04 + 100 -04
//   = -08 + 100 + 100
//   =  92 + 100
//   = 192                   (舍去最高位,截断结果,再求2位十补数加负号,得到结果-08)
//
//*发生溢出是因为字长有限,字长不受限制的话减法转十补数/二补数的加法是永远可以得到正确结果的
// 真值结果非负数,补数运算结果就模除得到正确结果,真值结果为负数,补数运算结果就求相同数位补数再加负号即可得到正确结果
//======================================================================================================
void limits_head_constants(void); //函数声明,function declaration
void unsigned_int_operation(void);
void integer_multiplication(void);//multiplication乘法
void a_modulo_n(void);
void integer_constants_limits(void);

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
    printf("4294967295 hexadecimal: %x,decimal: %u\n", 4294967295, 4294967295);
    //decimal(4294967296): 1 0000 0000 0000 0000 0000 0000 0000 0000
    //int constant 4byte:    0000 0000 0000 0000 0000 0000 0000 0000
    // --> printf --> 0
    printf("4294967296 hexadecimal: %x,decimal: %u\n", 4294967296, 4294967296);
    //decimal(-4294967296): - 1 0000 0000 0000 0000 0000 0000 0000 0000
    //two's complement:       1 0000 0000 0000 0000 0000 0000 0000 0000
    //int constant 4byte:       0000 0000 0000 0000 0000 0000 0000 0000
    // --> printf --> 0
    //*注:-1000类型的负数的二补数编码属于特殊情况,其它都是二补数编码比真值数码多一位储存
    printf("-4294967296 decimal: %u\n", -4294967296);
    //decimal(-4294967295): - 1111 1111 1111 1111 1111 1111 1111 1111
    // --> 二补数编码储存:   - 1111 1111 1111 1111 1111 1111 1111 1111 
    // --> 需要33bit:     - 0 1111 1111 1111 1111 1111 1111 1111 1111
    //two's complement:     1 0000 0000 0000 0000 0000 0000 0000 0001
    //整数常量4byte:           0000 0000 0000 0000 0000 0000 0000 0001
    // --> printf --> 1
    printf("-4294967295 decimal: %d, unsigned: %u\n", -4294967295, -4294967295);
    
    limits_head_constants();
    unsigned_int_operation();
    integer_multiplication();
    a_modulo_n();
    integer_constants_limits();
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

void integer_multiplication(void)
{
    short int a=2, b=6, c=16384, r;
    // short int 16384   binary: 0100000000000000         
    //                         * 0000000000000010
    //                           0000000000000000
    //                          0100000000000000
    //                          01000000000000000
    //                    w=16   1000000000000000 (结果为0100000000000000像左移一位)
    printf("2*6=%hi,overflow:2*16384=%hi\n", r=a*b, r=c*a);
    return;
}

void a_modulo_n(void)
{
    short unsigned int a=11, n=2;
    // %操作符为整数取模,fmod()函数包含在math.h里,浮点数取模
    // (short int)1 对整型常量进行强制类型转换
    printf("a mod n = %hu, a mod 1 =%hu\n",a%n, a%(short int)1);
    printf("sizeof((short unsigned int)1): %d\n", sizeof((short unsigned int)1));
    printf("sizeof(a*(short unsigned int)1):%d\n", sizeof(a*(short unsigned int)1));
    printf("sizeof(a*n): %d\n", sizeof(a*n));
    return;
}

void integer_constants_limits(void)
{
    long long int lli1 = 9223372036854775807;
    //备忘:test2.c是在Linux系统下写的。。。
    //c标准规定long int型大于等于int,存储字长看编译系统(4byte\8byte)
    //整数常量作为有符号整数编码,即用二补数编码储存
    //储存长度是可变的,4byte和8byte两种字长(gcc编译系统的原因)
    //clang编译系统使用64为绝对地址储存整数常量
    //C语言标准,C编译器也还是在不断发展的,目前clang和gcc为主流
    //写C还是用linux比较好,编译系统比较新
    //4byte[-2^31,2^31-1], 8byte[-2^63,2^63-1]
    printf("sizeof(long long int):%d\n",sizeof(lli1));
    printf("sizeof(2147483647):%d\n", sizeof(2147483647));
    printf("sizeof(2147483648):%d\n", sizeof(2147483648));
    printf("sizeof(4294967296):%d\n", sizeof(4294967296));
    printf("sizeof(9223372036854775807):%d\n", sizeof(9223372036854775807));
    //溢出:printf("sizeof(9223372036854775808):%d\n", sizeof(9223372036854775808));
    //printf--> -1 现在用的编译系统的问题,long int和int都是32bit,%ld跟%d一样...
    printf("9223372036854775807 d:%d\n", 9223372036854775807);
    printf("9223372036854775807 ld:%ld\n", 9223372036854775807);
    printf("9223372036854775807 lld:%lld\n", 9223372036854775807);
    //printf("sizeof(9223372036854775808) lld:%lld\n", 9223372036854775808);
    //编译时报错,整数常量字长最长为64bit,
    //0111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111
    //最大有符号整数
    printf("-9223372036854775807 lld:%lld\n", -9223372036854775807);
    //printf("-9223372036854775808 lld:%lld\n", -9223372036854775808);
    printf("9223372036854775808u llu:%llu\n", 9223372036854775808u);
    return;
}



