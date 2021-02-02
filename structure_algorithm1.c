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
//  sequense 序列
//  geometric sequense 等比数列/几何数列
//  geometric progression 几何级数
//  common ratio 公比
//  a为等比数列首项,r为公比
//  一般项 an = a*r^n-1
//  N∑i=0 = a*r^i
//  N∑i=0 = 1*2^i (公比2,对所有项,后一个项除以前一个项得到常数r,r为公比) 
//  
//  几何序列:
//  1.发散几何级数
//  这里|r| ≥ 1
//  N∑i=0 2^i = 2^N+1 - 1
//  N∑i=0 A^i = (A^N+1 - 1) / (A - 1)
//  2.收敛级数
//  如果0<A<1
//  N∑i=0 A^i ≤ 1 / (1 - A)
//