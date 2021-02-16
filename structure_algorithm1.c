#include <stdio.h>
int funciton_recursion();
void print_digit(unsigned int n);
int series_sum_1(int n);

void main(void){
    int return_value;
    //funciton_recursion(5);
    //print_digit(76234);
    series_sum_1(5);
    //return_value = series_sum_1(5);
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
    //*无终止递归程序无意义
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
//  递归不是循环逻辑(circular logic)
//  通俗理解:
//    通过F(5)的到F(5)的值才是循环的
//    通过F(4)的到F(5)的值不是循环的,除非F(4)的求值又要用到F(5)的值才是循环

//  递归的两个基本法则
//  1. 基准情形(base case)  
//  你必须总有某些基准情形,它们不用递归就能求解(简而言之,就是要有终止条件)
//  2. 不断推进(making progress)
//  递归调用必须是朝向产生基准情形的方向推进
//  3. 设计法则
//  假设所有递归调用都能运行
//  4. compound interest rule
//  compound 复合物 n; 符合的 adj.
//  interest 兴趣,利益
//  书本翻译:合成效益法则
//  第4条法则的正确性将会在后面的章节给予证明
//  现在我也看不懂啥意思...
//  递归不应简单作为for循环的替代物
//  合成效益法则:求解一个问题的同一实例时,切勿在不同的递归调用中做重复性的工作
//  个人理解:所谓合成效益法则,指递归调用存在重叠

//  routine 常规
void print_digit(unsigned int n){
    if (n >= 10){
        //(实参n/10的n为主调函数的局部私有变量n)
        //(形参n为被调函数的私有局部变量)
        //被调函数的形参n接收实参n/10
        print_digit(n / 10);
        //*递归调用很关键的一点:
        // 被调函数把控制流交还给主调函数,主调函数的该递归调用语句执行结束
    }
    printf("pointer: %p, ", &n);
    printf("n = %5u,", n);
    //mod操作耗费是很大的
    // n % 10 = n - (n / 10) * 10
    printf("n %% 10 = %u\n", n % 10);
    return;
}

//  网上查找资料======================================
//  *算法的时间复杂度,用来度量算法的运行时间
//  n表示输入大小input size
//  算法执行时间的增长速度用f(n)描述
//  例如:
//  for (i = 1; i <= n, i++){    执行n+1次
//      printf("hello\n");       执行n次
//  }
//  return;                      执行1次
//  
//  得到f(n) = n+1 + n+1 = 2n+2
//  T(n) = O(f(n)) = O(n)
//  严格来说T(n)应该等于O(2n+2)
//  所以说f(n)为T(n)的上限
//  我们研究的是随着输入大小n的增大,算法运行时间增长的增速和量级
//  所以可以去掉常数项,次阶项和高阶项的系数
//  2n^2[去掉前面的系数2] + 2n[去掉] + 2[去掉]
//
//  T(n)表示算法执行的时间(或代码总的执行次数)
//  个人理解:T(n)执行时间的度量,并非我们日常生活中的准确的时间
//
//  f(n)代表T(N)的上界
//
//  big O notation 大O符号
//  网上查找资料======================================

// 第2章 算法分析 
//  数学知识:
//  相对增长率(relative rate of growth)
//  Ο big O; 大O
//  Ω 读作omega
//  第八个希腊字母小写: θ,读作theta
//  o 小o
//
//  全书将使用下面四个定义:
//  T(N)算法运行时间
//  用时间复杂度来度量
//
//  这些定义的目的是要在函数间建立一种相对级别
//  比较它们的相对增长率(relative rate of growth)
//  存在正常数c和N0
//  常数,表示常量的数,例如圆周率就是常数
//
//  1.T(N)=O(f(N))
//  定义:如果存在正常数n0和c是的当N≥n0时T(N)≤f(N),
//       则记为T(N)=O(f(N)),貌似T(N)∈O(f(N))也可以,待以后确认
//  T(N)增长速度≤f(N),T(N)以不快于f(N)的速度增长
//  f(N)是T(N)的上界upper bound
//  形象化理解,用xy轴线图,x轴代表N,y轴代表T(N),f(N)
//  T(N)增长率小于等于f(N),但N值较小时,可能存在T(N)大于f(N)的情况,
//  曲线T(N)和f(N)交叉点N=n0,
//  为了保证T(N)≤f(N)在T(N)大于f(N)的情况下成立,引入了常数c
//  下面的定义与定义1同理,算法分析主要用到T(N)=O(f(n)),
//  因此剩余的3个定义就不展开了...
//
//  2.T(N)=Ω(g(N))
//  T(N)增长速度≥g(N)
//  g(N)是T(N)的下界(lower bound)
//
//  3.T(N)=θ(h(N))
//  当且仅当T(N)=O(h(N))且T(N)=Ω(h(N))
//  T(N)增长速度=h(N),增长速度同一量级
//  一个小重点: θ的使用要结合上下文
//
//  4.T(N)=o(p(N))
//  T(N)=O(f(N))且T(N)≠θ(h(N))
//  T(N)增长速度<p(N)
//  
//  例子: 1000N和N^2
//  N比较小时,1000N比N^2大,但N^2的增长率比N大
//  最终N^2比1000N大.
//  T(N)=1000N  f(N)=N^2
//
//  个人心得:
//      1.作为数学定义,上面的四个定义要保证任何符合条件的情况下都成立
//        因此引入正常数c和n0
//        做算法分析时用到的都是典型情况(不用考虑啥正常数c和n0)
//      2.N^3, N^2, N.  在N趋向于无穷的情况下2N^2与N^3和N相比更接近与N^2    
//
//  需要掌握的重要结论:
//  法则1:
//  T1(N)=O(f(N))且T2(N)=Ω(g(N)),那么
//  (a) T1(N)+T2(N)=max(O(f(N)), Ω(g(N)))
//      通过实际例子更容易理解
//      N^2 + N^2 = 2N^2 = O(N^2) = θ(N^2)
//      N^3 + N^2 = O(N^2)  --> 去掉低阶项
//  (b) T1(N)*T2(N)=O(f(N)*g(N))
//      实际例子:
//      N^3 * N^2 = N^5 = O(N^5)
//  法则2:
//  如果T(N)是一个k次多项式,则T(N)=θ(N^k)
//  这里很简单,就不举例了...
//  法则3:
//  对任意常数k,logk N = O(N),它告诉我们对数增长得非常缓慢...
//  个人心得:这里说明了对数阶比线性阶增长速度还慢
//  法则3理解的比较浅,以后再深入理解吧,暂时到这里了
//  
//  在需要大O表示的任何分析中,低价项忽略,常数项忽略,高阶项系数也忽略
//
//  通过计算极限lim n->∞ f(N)/g(N)
//  来确定两个函数f(N)和g(N)的相对增长率
//  极限是0,这意味着f(N)=o(g(N))
//  极限是c≠0,这意味着
//  极限是∞,g(N)=o(f(N))
//  极限摆动:二者无关(在本书中将不会出现这种情形)
//  第2条不理解...
//  好吧,还是来强行理解一下...
//  极限既不是0也不是∞,而是某个非0值c...
//  好像似乎可能maybe懂了...
//
//  T(N)=O(f(N))定义中已经隐含有不等式

//  典型的函数增长率分类
//  函数        名称
//  c           常数
//  logN        对数级  
//  N           线性级
//  NlogN               根据法则1(b)得出
//  N^2         平方级
//  N^3         立方级
//  2^N         指数级

//  2.3 要分析的问题
//  N输入大小
//  average 平均的
//  Tavg(N)≤Tworst(N)
//  算法所花费的平均运行时间和最坏情况下运行时间
//  
//  最大的子序列和问题

//  2.4 运行时间计算
//      为了简化分析,不存在特定的时间单位
//      个人心得:就是之前我的理解,时间复杂度是算法运行时间的度量
//               算法分析中,大O用得最多
//  2.4.1 一个简单的例子
//        计算i=1∑N i^3
int series_sum_1(int n){
    // 程序分析
    // 声明不计时间 
    int i, series_sum;
    // 1. 占一个时间单元    
    //  1
    series_sum = 0;
    // 2. 初始化一个时间单元
    //    所有测试N+1个时间单元,第一次测试i=1,最后一次测试i=N+1
    //    自增运算N个时间单元,第一次运算i=2 -> 最后一次运算i=N+1
    //  1 + N+1 + N = 2N + 2
    for (i = 1; i <= n; i++){
        // 3. 每执行一次占用四个时间单元
        //    加法一次,乘法两次,赋值一次
        //    执行N次共占用4N个时间单元
        //  4N
        series_sum += i * i * i;
    }
    // 4. 占一个时间单元
    //  1
    return series_sum;
}
// 总量: 1 + 2N+2 + 4N + 1 = 6N+4
//  O(N)
//  个人理解:一次运算(操作)占用一个时间单元,记住一点,算法分析并不是精确计算
//           算法的运行时间.而是通过时间复杂度来度量算法运行时间(增速/量级)

//  我们忽略函数调用和返回值的开销
//  忽略函数调用我理解,忽略返回值不明白...查看汇编文件也不懂...
//  跳过返回值这个点...不理解貌似也没啥影响...

//  其实每次分析一个程序并不需要演示所有这些工作
//  我们可以采取捷径并且不影响最后结果
//  像第3句代码,无需考虑占用两个,三个,还是四个时间单元,因为都是O(1)常数级
//  第1行与for循环相比显然是不重要的(常数项与线性阶,常数会被忽略)

//  2.4.2 一般法则
//  at most 最多
//  法则1 - for循环
//  一次for循环的运行时间最多为for循环内语句(包括测试)的运行时间乘以
//  迭代(iteration)的次数
//
//  法则2 - 嵌套的for循环
//  为了便于理解,引用上面一个简单例子的数据6N+2, O(N)
//  假设外层for循环占用时间单元个数/运算次数2N+2(这里只是假设,具体问题具体分析,
//  不过即使有些差异,最后的结果是一致的)
//  (2N+2)*(6N+2) = 2N(6N+2) + 2(6N+2) = 接下去就不算了,最终结果肯定是O(N^2)
//  与O(N)*O(N)得到的结果是一致的,都是O(N^2)
//  
//  从里向外分析这些循环,在一组嵌套循环内部的一条语句总的运行时间等于这些语句的运行
//  时间乘以该组for循环所有迭代次数的乘积
//  例如:
//  1.
//  for (i = 0; i < N; i++)
//  2.
//      for (j = 0; j < N; j++)
//  3.
//          k++;
//  3执行1次,占用一个时间单元
//  内层循环执行占用1 + N+1 + N个时间单元,测试N+1次,循环体迭代N次
//  外层循环执行占用1 + N+1 + N个时间单元,测试N+1次,循环体迭代N次
//  3总的运行时间/运算次数=N * N * 1
//  最后的结果= O(N) * O(N) * O(1) = O(N^2)
//
//  法则3 - 顺序语句
//  将各个语句的运行时间求和即可(最后结果,需要掌握的重要结论法则1(a))
//  1.
//  for (i = 0; i < N; i++)
//      A[i] = 0;
//  2.
//  for (i = 0; i < N; i++)
//      for (j = 0; j < N; j++)
//          A[i] += A[j] + i + j;
//  1. O(n)
//  2. O(n^2)
//  O(n) + O(n^2) = O(N^2)

//  法则4 - if/else语句
//  if (condition)
//      statement1
//  else
//      statement2
//  一个if/else语句的运行时间不超过 测试 加上 s1和s2中
//  运行时间长的 运行时间总和
//  在某些情况下这么估计有些高,但绝对不会过低
//  个人理解:就是把时间往大的情况算...宁杀错,勿放过...

//  其他的法则都是显然的,分析的基本策略是从内部(或最深层内部)向外展开的
//  如果有函数调用,那么这些调用要首先分析.
//  如果有递归调用,这里有几个选项:
//  1. 如果递归实际上只是"稍微掩盖"的for循环...分析通常很简单
//
//  个人心得:下面的程序例子看成先执行完测试和自减/增,再执行“循环体(递归)”
//  在一般法则 法则1 - for循环 中,自增/减可以忽略,占用一次for循环的时间不多
//  最后结果都一样,算进去也没啥影响,就是增加工作量而已...
//
//  long int func(int n){
//  首先分析调用(递归调用)
//      1. 占用一个时间单元
//      if (n <= 1)
//          2.占用一个时间单元
//          return 1;
//      else
//          3.占用一个时间单元(忽略自减)
//          return n * func(n - 1);
//  }
//  n * 2 = 2n = O(n)
//  如果非要较真的话: (n - 1) * 2 + 1 * 2 = 2n = O(n) ......
//  上面的函数实际上就是一个简单的循环,所以时间复杂度为O(n)
//
//  合成效益法则:求解一个问题的同一实例时,切勿在不同的递归调用中做重复性的工作
//  个人理解:不存在重叠的递归调用()...
//  