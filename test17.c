#include <stdio.h>

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
    return 0;
}

// if语句被称为branching statement分支语句或selection statement选择语句
// if (expression)
//     statement
