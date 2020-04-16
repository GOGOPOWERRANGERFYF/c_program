#include <stdio.h>
#define RATE1 1.0
#define RATE2 2.0
#define RATE3 3.0
#define STEP1 kwh_a * RATE1
#define STEP2 (kwh_b - kwh_a) * RATE2
#define STEP3 (kwh_c - kwh_b) * RATE3
int step_rate(void);

int main(void)
{
    step_rate();
    return 0;
}

int step_rate(void)
{
    const double kwh_a = 10.0, kwh_b = 20.0, kwh_c = 50.0;
    double kwh;

    printf("input kwh:\n");    
    // 11 --> 11.0  int --> double promotion升级
    // 11.0 --> 11  double --> int demotion降级
    // 输出为映射真值,与升级降级不同,不要弄混
    while (scanf("%lf", &kwh) == 1){
        if (kwh < 0){
            printf("wrong data!\n");
        }
        else if (kwh <= kwh_a){
            printf("count: %.3f\n", kwh * RATE1);
        }
        else if (kwh <= kwh_b){
            printf("count: %.3f\n", STEP1 + (kwh - kwh_a) * RATE2);
        }
        else if (kwh <= kwh_c){
            printf("count: %.3f\n", STEP1 + STEP2 + (kwh - kwh_b) * RATE3);
        }
        else {
            printf("count: %.3f\n", STEP1 + STEP2 + STEP3 + (kwh - kwh_c) * RATE3);
        }
    }
    // <c primer plus第六版> P424 
    // if else嵌套形式也可以实现,效果一样,但还是上面的else if清晰明了
    // if else嵌套形式有兴趣可以了解
    // 
    // if (expression)
    //     statement;
    // else
    //    if (expression)
    //         statement;
    //    else
    //         statement; 
    // 嵌套的if else语句被视为一条语句,因此可以不用花括号括起来,但括起来让代码更加清晰
    // 好了,说了这么多if else嵌套语句,总结,else if语句真香...
    printf("game over!\n");
    return 0;
}

// C99标准要求编译器至少支持127层嵌套

// if与else的匹配
// 没有花括号,else与离它最近的if匹配
// 有花括号,else与括号里包含if语句的第一个if
//