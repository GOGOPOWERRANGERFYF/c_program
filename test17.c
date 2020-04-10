#include <stdio.h>

int main(void)
{
    const double pass_line = 60.0;
    double score;
    int pass_count = 0, input_count = 0;

    printf("Input score:\n");
    while (scanf("%lf", &score) == 1){
        input_count++;
        if (score >= pass_line){
            pass_count++;
        }
    }

    if (input_count != 0){
        printf("How many scores: %d, ", input_count);
        printf("How many pass: %d", pass_count);
    }
    if (input_count == 0){
        printf("No score!");
    }

    return 0;
}


