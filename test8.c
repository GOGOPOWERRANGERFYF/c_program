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
    // 内存区域:
    //  [...|数字字符|空白字符|数字字符|空白字符|字母字符|...]
    // 举例: scanf()函数 使用%d转换说明
    // 我想输入整数32
    // 使用键盘键入文本字符1和8
    //    3        2 
    // 数字字符  数字字符
    // 空白字符会被scanf()函数跳过
    // 遇到第一个数字字符或+/-符号字符开始读取,保存后再读取下一个字符
    // 读取到非数字字符,scanf()函数把非数字字符放回输入
    // 因此输入 32 40000fyf (正常的输入方式 -->:32 40000 fyf)
    // scanf()函数读取的结果也是正确的
    scanf("%d %lf %s", &age, &d_asset, name);
    // scanf() double类型转换说明要加修饰符l %lf,与pirntf()不同
    // conversion specification 转换说明
    // modifier 修饰符
    // *《c primer plus第六版》P220 scanf()转换说明,修饰符
    printf("Age: %d, Asset: %.2f, Name: %s\n",
     age, d_asset, name);
    // 打印变量的指针(地址)  
    // %p 指针
    printf("integer variable age virtual address: %p\n", &age);
    printf("input name age: ");
    scanf("%s %d", name, &age);
    printf("Name: %s, Age: %d\n",
     name, age);
    return;
}





