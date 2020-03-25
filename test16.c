#include <stdio.h>
#include <stdbool.h>
// C99新增_Bool类型   
// 表示真或假的变量称为布尔变量(boolean variable)
// _Bool类型变量只能储存1(真)或0(假)
// 把非零值赋给_Bool类型变量是,该变量会被设置为1(这反映C把所有非零值视为真)
int bool_variable(void);
int for_loop(void);
int for_loop_nine_methods(void);

int main(void)
{
    _Bool a = 1, b = 'a', c = 0, d = 88
    , e = "abcd";
    printf("a = 1: %3d\n", a);
    printf("b = 'a': %d\n", b);
    printf("c = 0: %3d\n", c);
    printf("d = 88: %2d\n", d);
    printf("e = \"abcd\": %2d\n", d);

    bool_variable();
    for_loop();
    for_loop_nine_methods();
    return 0;
}

int bool_variable(void)
{
    // C99提供老stdbool.h头文件,该头文件定义了_Bool的别名bool,
    // 把true和false定义为1和0的符号常量
    // 包含了该头文件后,代码可以与C++兼容,true和false,bool为c++的关键字
    bool a;
    int b;
    printf("input decimal number:\n");
    // 1. 精简写法:
    while (scanf("%d", &b)){
        printf("true\n");
    }
    // 2. 非常啰嗦写法...
    // 不用小括号, ==运算符优先级也比=高
    //a = (scanf("%d", &b) == 1);
    //while (a){
    //    printf("true\n");
    //    a = scanf("%d", &b) == 1;
    //}
    // 3. 很啰嗦写法...
    //a = scanf("%d", &b) == 1;
    //while (a){
    //    printf("true\n");
    //    a = scanf("%d", &b) == 1;
    //}
    // 4. 啰嗦写法...
    //a = scanf("%d", &b);
    //while (a){
    //    printf("true\n");
    //    a = scanf("%d", &b);
    //}
    //越啰嗦,可读性越高,但写起来确实啰嗦啊...
    printf("false\n");
    return 0;
}

// 知识点总结:
// precedence of relational operators(关系运算符优先级)
// 关系运算符优先级比算术(arithmetic)运算符低,比赋值运算符高
// 优先级高的先结合
// 关系运算符之间的优先级:
// 高优先级组: < <= > >=
// 低优先级组: == !=
// 与其他大多数运算符一样,关系运算符的结合律也是从左到右 
// <c primer plus> P340 表6.2 运算符优先级

// while语句是一种入口条件循环
// while (test expression/test condition)
//      statement                         
// statement可以是简单语句,也可以是复合语句(花括号括起来)
// expression部分为假或0前,重复执行statement部分

// <c primer plus> P343
// 1.不确定循环(indefinite loop) while测试表达式为假0之前,不确定要循环多少次
//
// 2.计数循环(counting loop) 循环之前就知道要循环多少次
//  (1) 计数器初始化
//  (2) 测试条件(与有限值比较)
//  (3) 计数器递增(更新)
// 计数循环我们用for循环,虽然while循环(计数循环)也能实现 

//for循环可以把上述3个行为(初始化,测试,递增[更新])组合在一起
int for_loop(void)
{
    // a. 计数器初始化
    // b. 循环一次(测试表达式为真);测试条件为假,终止循环,跳过计数器更新,执行后面的代码
    // c. 计数器更新(递增)
    int a;
    // a = 1; 初始化只执行一次(once),循环开始前
    // for循环圆括号中的表达式也叫控制表达式,它们都是完整表达式
    // a++循环结束时求值
    for (a = 1; a <= 5; a++){
        printf("for loop: %d\n", a);
    }
    // 由此可看出,a <= 5表达式为假0,循环结束,后面的a++表达式不执行
    printf("out of for loop, a: %d\n", a);
    return 0;
}

int for_loop_nine_methods(void)
{
    int n, m = 2;
    //int n, m;
    char c;
    double f;
    // for循环 控制表达式   n--,n=n-2,n=n-10也可以,根据需求
    for (n = 5; n >= 0; n--){
        printf("decrement counter n-- : %d\n", n);
    } 
    // for循环 控制表达式   n++,n=n+2,n=n+10也可以,根据需求
    for (n = 5; n <= 10; n = n + 2){
        printf("increment counter n = n + 2 : %d\n", n);
    }
    // 可以用字符代替数字计数,(该程序能正常运行,是因为字符在计算机内部跟数字一样以二进制数存储)
    for (c = 'a'; c <= 'z'; c++){
        printf("character: %c, ASCII(decimal): %d\n", c, c);
    }
    // 上面三条测试条件都是测试 迭代(iteration)次数(控制循环次数) 
    // 还可以测试其他条件,例如 n * n < 100,测试限制n的平方的大小
    // 递增的量可以算术增长,也可以几何增长
    for (f = 1.0; f <= 10.0; f = f * 1.2){
        printf("f * 1.2 : %.13f %a\n", f, f);
    }
    // 第三个表达式可以使用任何合法的表达式,无论是什么表达式,每次迭代都会更新该表达式的值
    // int y = 10;
    // for (x = 1; y <= 50; y = ++x * 2 + 5)
    // 这里可以这么理解,计数器x的代数计算的值赋值给y,对y作测试
    // 可以正常运行,但编程风格不好
    for (n = 1; n <= 5;){
        // 计数器更新部分也可以放进循环体内
        n = n + 2;
    }
    printf("%d\n", n);
    // for循环的控制表达式,三个表达式可以使用不同的变量
    for (n = 1, f = 1.0; f <= 5.0; f = 2 * n * f){
        printf("OK_1!\n");
    }

    //clang编译器,m没有初始化,测试表达式的值为假0
    for (; m <= 5;){
    //for循环控制表达式三个表达式可以省略,但两个分号不能省略
    //测试条件为空语句,值为真,程序无限循环
    //for (;;){
    //语法上虽然可以省略三个表达式,但这样代码貌似没有任何实际意义啊...
        m++;
        printf("OK_2!\n");
    }

    return 0;
}
// *** for循环控制表达式总结(核心知识点,遵循一下三点原则):
// 1. 计数器初始化
//      1.1 第一个表达式也可以是其他表达式(即使函数表达式也可以)
// 2. 测试条件(测试表达式) 
//      2.1 如果测试条件为空语句,则值一直为真,程序无限循环
// 3. 计数器更新(递增:算术递增,几何递增都可以;可以把这个表达式放入循环体内)
// 注: 可以省略三个表达式,但两个分号不能省略(其它随便你折腾...)
//     1表达式 可以放在for语句前进行初始化
//     2表达式 空语句值一直为真
//     3表达式 可以放循环体内

// 个人总结(while和for的区别):
//      while (测试条件test condition)
//      for (控制表达式,三个表达式) 
//
//  while: 1.不确定循环; (程序运行完成前无法确定循环迭代次数)
//         2.计数循环;   (程序运行前就可知循环迭代次数,计数循环一般用for)






