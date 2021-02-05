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
//  

//  调和级数(与直觉相反,调和级数是发散的)
//  
