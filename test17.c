#include <stdio.h>
int putchar_getchar(void);

int main(void)
{
    const double pass_line = 60.0;
    double score;
    int pass_count = 0, input_count = 0;

    printf("Input score:\n");
    // 输入int,scanf函数会把输入值promotion升级为double类型
    while (scanf("%lf", &score) == 1){
        input_count++;
        if (score >= pass_line){
            pass_count++;
        }
    }

    //if (input_count != 0){
    //    printf("How many scores: %d, ", input_count);
    //    printf("How many pass: %d", pass_count);
    //}
    //if (input_count == 0){
    //    printf("No score!");
    //}

    if (input_count != 0){
        printf("How many scores: %d, ", input_count);
        printf("How many pass: %d", pass_count);
    }
    else {
        printf("No score!");
    }

    putchar_getchar();
    return 0;
}

// if语句被称为branching statement分支语句或selection statement选择语句
// if (expression)
//     statement
//
// if (expression)
//     statement
// else
//     statement
//
// if (expression){
//     statement
// }
// else {
//     statement
// }
//
// statement可以是简单语句或复合语句
// 复合语句必须用花括号括起来成为一个块,跟循环语句是一样的

// getchar()和putchar()函数只处理字符 (它们通常是预处理宏,不是真正的函数,第16章有函数的宏的知识点)
// ch = getchar()与scanf("%c", &ch)效果相同
// putchar(ch)与printf("%c", ch)效果相同
int getchar_putchar(void)
{
    char ch;
    ch = getchar();
    putchar(ch);
    return 0;
}



