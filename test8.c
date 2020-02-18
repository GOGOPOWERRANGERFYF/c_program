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
    int age_a, age_b, age_c, age_d;
    float f_asset_a, f_asset_b, f_asset_c, f_asset_d;
    double d_asset_a;
    char name_a[10], name_b[10], name_c[10], name_d[10];
    printf("sizeof(f_asset_a): %zd,sizeof(d_asset_a): %zd\n",
     sizeof(f_asset_a), sizeof(d_asset_a));
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
    // 程序下一次读取时,从这个放回的非数字字符读取
    // 因此输入 32 40000fyf (正常的输入方式 -->:32 40000 fyf)
    // scanf()函数读取的结果也是正确的
    scanf("%d %lf %s", &age_a, &d_asset_a, name_a);
    // scanf() double类型转换说明要加修饰符l %lf,与pirntf()不同
    // conversion specification 转换说明
    // modifier 修饰符
    // *《c primer plus第六版》P220 scanf()转换说明,修饰符
    printf("Age: %d, Asset: %.2f, Name: %s\n", age_a, d_asset_a, name_a);
    // 打印变量的指针(地址)  
    // %p 指针
    printf("integer variable age virtual address: %p\n", &age_a);
    // %s %d 转换说明顺序
    // scanf()函数先读取非空白字符,读取一个,保存,再读取下一个字符
    // 读取到空白字符,读取结束(与转换说明%s匹配的字符串字段读取结束)
    // 再读取下一个与转换说明%d匹配的整数字段
    printf("input name age: ");
    scanf("%s %d", name_b, &age_b);
    printf("Name: %s, Age: %d\n", name_b, age_b);
    // %d %s 转换说明顺序
    // 如果输入A,scanf()函数读取到A后,将停止读取,并将A放回输入
    // 不会把值赋给指定变量
    // ***如果scanf()函数带多个转换说明,C规定在第一个出错出停止读取输入
    printf("input age name: ");
    scanf("%d %s", &age_c, name_c);
    printf("Age: %d, Name: %s\n", age_c, name_c);
    
    printf("age(%%d): %d\n", age_d);
    printf("age(%%x): %x\n", age_d);
    printf("&age(%%x): %x\n", &age_d);
    // %d 一个转换说明
    // 输入A,scanf()函数停止读取,把A字符放回输入
    // 程序下一次读取时,从这个A字符开始读取
    // 如果程序只有%d输入转换符,scanf()函数就一直无法越过A字符
    printf("input age: ");
    scanf("%d", &age_d);
    printf("age(%%d): %d\n", age_d);
    printf("age(%%x): %x\n", age_d);
    printf("&age(%%x): %x\n", &age_d);

    scanf("%s", &name_d);
    printf("name_d(%%s): %s\n", name_d);
    
    return;
}





