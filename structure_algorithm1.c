#include <stdio.h>
int funciton_recursion();

void main(void){
    funciton_recursion(5);
    return;
}
// data structures and algorithm analysis in c
// 《数据结构与算法分析 c语言描述 第2版》
//
// 1.2 数学知识复习(P2): 
// 1.2.1 指数 
//  太简单了,懒得写笔记了,实在忘了直接看书吧,就在第2页
//
// 1.2.2 对数
//  log2 N (读法:以2为底的N的对数)
//  在计算机科学中,除非有特别声明,所有对数都是以2为底  
//  定理: log AB =  log A + log B
//  证明: 令Z = log AB, x = log A, Y = log B
//          2^Z = AB, 2^X = A, 2^Y = B
//          2^Z = 2^X * 2^Y (Z个2相乘=X个2乘以Y个2)
//          因此Z = X + Y
//  知道怎么证明定理时重点,没必要死记硬背定理,
//  因为...不经常用的话现在记住了以后也会忘记
//  但证明方法可以记住啊,举一反三可以证明所有定理,
//  还能保住头发,岂不美哉~
//  剩余的定理直接翻书吧,就在第二页,懒得写了...人生苦短,我选(偷懒)python...

// 1.2.3 级数
//  级数是将数列的项依次用加号连接起来的函数
//  例子(等比数列和/几何级数):
//  geometric 几何
//  progression 进展
//  sequence 序列
//  geometric sequence 等比数列/几何数列
//  geometric progression 几何级数
//  common ratio 公比
//  a为等比数列首项(首项r的指数为0,r^0 = 1),r为公比
//  一般项/通项 an = a*r^n-1
//  N∑i=0 = a*r^i
//  N∑i=0 = 1*2^i (公比2,对所有项,后一个项除以前一个项得到常数r,r为公比) 
//
//  求和公式推导:
//  当|r| ≥ 1时:
//  S = a*r^0 + a*r^1 + a*r^2 + ... + a*r^n
// rS =         a*r^1 + a*r^2 + ... + a*r^n + a*r^(n+1)
//  
//  rS - S = a*r^(n+1) - a*r^0
//  注: S个(r-1) = S个(r-1)相加就会得到Sr - S*1 = Sr - S = rS - S
//  (r - 1)S = a * (r^n+1 - r^0)
//  (r - 1)S = a * (r^n+1 - r^0)
//         S = a * (r^n+1 - r^0) / (r - 1)
//         S = a * (r^n+1 - 1) / (r - 1)
//         S = a * (r^n+1 - 1) / (r - 1)
//
//  设a=1,r=2时,得到:
//  N∑i=0 a*r^i = N∑i=0 1*2^i = N∑i=0 2^i  
//  = a * (r^n+1 - r^0) / (r - 1) = 
//  = 1 * (2^n+1 - 2^0) / (2 - 1) = 
//  = 1 * (2^n+1 - 1) / (2 - 1) = 2^n+1 - 1 
//
//  几何序列:
//  1.发散几何级数
//  这里|r| ≥ 1
//  N∑i=0 2^i = 2^N+1 - 1
//  N∑i=0 A^i = (A^N+1 - 1) / (A - 1)
//  2.收敛级数
//  如果0<A<1
//  N∑i=0 A^i ≤ 1 / (1 - A)
//  收敛级数公式的推导理解不够透彻,后面还要继续补强,现在暂时跳过
//
//  算术序列/算术数列/等差数列 arithmetic sequence
//  算术级数 arithmetic progression    
//  公差 common difference
//  N∑i=1 i = N*(N+1)/2 ≈ N^2/2  (参照高斯算法:我自己的理解,高斯算法适用于等差数列)
//  例子:
//  N∑i=1 3k-1 
//  第一种方法(不喜欢,对我来说理解起来不够直观):
//  --> 2 + 5 + 8 + ... + (3k-1)
//  --> k = N  
//  --> N个(3k-1)相加,k从1到N
//  --> 3(1+2+...+N) - N个1 
//  --> 3(1+2+...+N) - (1+1+...+1) 
//  --> 3(1+2+...+k) - k
//  --> 3k(k+1)/2 - k
//  第二种方法(本质高斯算法,本质的本质是相邻通项等差,一个通项加公差,另一个通项减公差,和不变)
//  --> k(3k-1 + 2)/2  
//  --> k(3k+1)/2
//  以上两个公式得到的结果是一致的

//  整数序列:平方数
//  平方和
//  N∑i=1 i^2
//  平方和公式推导:
//  设N∑i=1 i^2 = x
//    N∑i=1 i^3 - (i-1)^3 = N^3
//-------------------------------------------------
//  提示: 1-0 + 8-1 + 27-8 + ... + i^3-(i-1)^3
//      1 8 27 ... (i-1)^3 i^3
//    0 1 8 27 ... (i-1)^3
//  相减后通项抵消得到结果 i^3
//-------------------------------------------------
//    i^3 - (i-1)^3 
//  = i^3 - (i-1)(i-1)(i-1)   
//  提示: (i-1)个(i-1)(i-1)等于i个(i-1)(i-1)减1个(i-1)(i-1)
//        (3-1)个2 等于 2个2
//        (3-1)个2 等于 3个2减1个2 等于 2个2
//        (3个2): 2  2  2 
//                     |2
//            (3-1)个2 |1个2
//  = i^3 - [i(i-1)(i-1) - 1(i-1)(i-1)]
//  = i^3 - [(i*i-i*1)(i-1) - (i-1)(i-1)]
//  = i^3 - [(i^2-i)(i-1) - (i-1)(i-1)]
//  = i^3 - (i^2-i)(i-1) + (i-1)(i-1)
//  = i^3 - (i^2-i)(i-1) + i(i-1) - 1(i-1)
//  = i^3 - (i^2-i)(i-1) + i^2-i - i+1
//  = i^3 - [i^2(i-1) - i(i-1)] + i^2-i - i+1
//  = i^3 - i^2(i-1) + i(i-1) + i^2-i - i+1
//  = i^3 - i^2(i-1) + i^2-i + i^2-i - i+1
//-------------------------------------------------
//  提示 i^2个(i-1)等于 (i-1) + (i-1) + ... + (i-1)
//                         总共i^2个(i-1)
//-------------------------------------------------
//  = i^3 - (i^3-i^2) + i^2-i + i^2-i - i+1
//  = i^3 - i^3 + i^2 + i^2-i + i^2-i - i+1
//  = 3i^2 - 3i + 1
//
//  设N∑i=1 i^2 = x
//  N∑i=1 i^3 - (i-1)^3 = N^3
//   N∑i=1 i^3 - (i-1)^3 
// = N∑i=1 3i^2 - 3i + 1
// = 3x - 3*N(N+1)/2 + N = N^3
//   3x - 3*N(N+1)/2 + N = N^3
//   3x = N^3 + 3*N(N+1)/2 -N
//   3x = N^3 + 3*N(N+1)/2 -N
//   3x = 2N^3/2 + 3*N(N+1)/2 - 2N/2
//    提示: 三头猪 竖排 切成两半
//          三头猪 分别 切成两半 结果都是一样的
//          10 / 2 = 5
//          5/2 + 5/2 = 2.5 + 2.5 = 5
//   3x = (2N^3 + 3*N(N+1) - 2N) / 2
//   3x = (2N^3 + 3N^2 + 3N - 2N) / 2
//    x = 2N^3 + 3N^2 + N / 6
//      提取公因式N
//    x = N(2N^2 + 3N + 1) / 6
//    x = N(N^2 + N^2 + 2N + +N + 1) / 6
//-------------------------------------------------
//  提示: (n+1)^2 = (n+1)(n+1) = n(n+1) + 1(n+1)
//      = n^2 + n + n + 1
//      = n^2 + 2n + 1
//-------------------------------------------------
//    x = N(N^2 + 2N + 1 + N^2 + N) / 6
//    x = N[(N + 1)(N + 1) + N(N + 1)] / 6
//    x = N(N + 1)[(N + 1) + N] / 6
//    x = N(N + 1)(2N + 1) / 6
//  呜呜呜...终于推导出来了...
//  

//  harmonic series 调和级数
//  调和级数(与直觉相反,调和级数是发散的)
//  ∞∑k=1 1/k = 1 + 1/2 + 1/3 + ...
//  证明发散的方法: 简单了解一下,留着以后再研究...
//  ∞∑k=1 1/k 
//= 1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 + 1/7 + 1/8 ... + 1/n + ...
//= 1 + 1/2 + (1/3 + 1/4) + (1/5 + 1/6 + 1/7 + 1/8) ... + 1/n + ...
//> 1 + 1/2 + (1/4 + 1/4) + (1/8 + 1/8 + 1/8 + 1/8) ... + 1/n + ...
//> 1 + 1/2 +      1/2    +           1/2           ... + 1/n + ...
//  --> ∞
//  
//  合并的个数规律
//  2^0 + 2^1 + 2^2 + 2^4 + ... + 2^n + ...

//  ∫ 读作sum 是数学的一个积分,积分是微分的逆运算
//  欧拉常数
//  调和数
//  Hn = 1 + 1/2 + 1/3 + ... + 1/n = n∑k=1 1/k ≈ ㏒eN ???
//  自然常数 e = (1 + 1/n)^n
//  一脸懵逼,以后再回来补吧,先啃后面的内容了...

//  模运算(modulo)
//  A≡B(mod N) A与B模N同余 
//  81≡91(mod 10) 81与91模10同余 


//  2.5 证明方法
//  证明数据结构分析中的结论,最常用的两个方式是:归纳法和反证法
//  
//  归纳法证明
//  归纳,指归拢并使有条理
//  也指一种推理方法,由一系列具体事实概括出一般原理
//  第一步: 基准情形(base case)
//  第二步: 归纳假设(inductive hypothesis)
//  证明的归纳过程如下:
//  1. 首先证明n=1成立  <-- 这就是所谓的基本情形(base case)吧
//  2. 然后证明从n=m成立推导出n=m+1也成立   (这里应用演绎推理)
//     第2步核心思想:证明假设n=m时公式成立,推导出n=m+1时公式也成立
//  3. 根据上两条从n=1成立推导出n=1+1,也就是2成立
//  4. 后面就跟多米诺骨牌一样,证明n=3,n=4,n=5成立...
//  5. 不断重复第三个过程(这就是所谓归纳推理的地方)
//  6. 最后得出结论,对于任意非0自然数,公式成立
//  
//  基本情形: 第一个多米诺骨牌时会倒的
//  归纳假设: 假设某个多米诺骨牌会倒时(至少第1个多米诺骨牌会倒),
//            与它相邻的后一个多米诺骨牌也会倒
//
//  斐波那契数列 wiki
//  F0 = 0;
//  F1 = 1;
//  Fn = Fn-2 + Fn-1 (n≥2)
//
//  0 1 1 2 3 5 ...
//  1 1 2 3 5 ...
//  
//  书本中的序列左移了一位
//  F0 = 1;
//  F1 = 1;
//  Fi = Fi-1 + Fi-2 (n≥1) 这都什么玩意...
//  
//  5/3 * 3/5 
//  理解上面运算的关键点
//--> 把5/3分成5份,5*(1/3)等于5个1/3
//--> 1/3 * 1/5, 1/3根辣条再分成5份,每份1/15
//
//  归纳法证明
//  1. 斐波那契数列的Fi<(5/3)^i
//  2. 平方和公式
//  已经理解了何为归纳法
//  上面两个具体例子看书就好,懒得写了,推论方法都是一样的

//  反证法
//  理解书中例子的关键: 假设数N非质数,但它有不能被前面的任一质数整除
//  由此推翻假设,得出结论
//  假设它是合数,但是不能分解质因数,因此它不是合数

//  1.3 递归简论
//  
//  华氏温度转换成摄氏温度的公式: C = 5(F-32)/9
//  
int funciton_recursion(int x){
    //有时候数学函数以不太标准的形式来定义
    //例子: 在非负整数集上定义一个函数F
    //它满足F(0)=0且f(n)=2f(n-1)+n^2
    //正如f(n)=2f(n-1)+n^2若没有F(0)=0这个条件在数学上没有意义
    //1.C的递归函数没有基准情形,也没有任何意义; 
    //2.这里的没有意义与《c primer plus》C的递归调用中
    //不能让递归调用停止递归的程序无意义 相呼应.
    //上面两点联系起来理解
    //我个人通俗的理解就是要使递归有个停止条件,不然无限递归毫无意义
    if (x == 0){
        printf("%p: F(0) = %d.\n", &x, x); 
        //给主调函数返回0
        return 0;
    }
    //上面的if代码处理基准情形(base case)
    //即此时函数的值可以直接算出而不用使用递归
    else
        //这里用到了C语言的递归调用
        //下面的代码执行递归调用
        printf("%p: F(n)=2F(n-1)+n^2 = %d.\n",
        &x ,x = 2 * funciton_recursion(x - 1) + x * x); 
        //给主调函数返回x
        return x;
}