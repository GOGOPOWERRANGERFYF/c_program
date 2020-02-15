#include<stdio.h>
//  《c primer plus第六版》P217 第三段重点
//  *键盘只能生成文本字符: 字母,数字,标点符号
//  要输入整数1024
//  键盘键入字符 1 0 2 4
//  scanf函数 把 字符串 转化成 整数1024
//  character 字符; character string 字符串.
//
//printf()和scanf()函数参数：
//  [1] printf()函数使用变量,常量,表达式
//  [2] scanf()函数使用指向变量的指针
//
//scanf()读取基本类型变量的值,在变量名前加&
//scanf()读取字符串,储存到字符数组中,不使用&
void main(void)
{
    int age;
    float f_asset;
    double d_asset;
    char name[10];
    printf("sizeof(f_asset): %zd,sizeof(d_asset): %zd\n",
     sizeof(f_asset), sizeof(d_asset));
    printf("input age  asset  name: ");
    // 每个输入项之间至少一个空白(换行符、空格、制表符)
    // scanf()函数使用空白把输入分成多个字段
    // 依次把转换说明和字段匹配时跳过空白
    scanf("%d %lf %s", &age, &d_asset, name);
    printf("Age: %d, Asset: %.2f, Name: %s.\n",
     age, d_asset, name);
    return;
}





