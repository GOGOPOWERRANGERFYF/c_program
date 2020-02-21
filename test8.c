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
void scanf_format_character_string(void);
void scanf_conversion_specification_character(void);

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
    // ***如果scanf()函数带多个转换说明,C规定在第一个出错处停止读取输入(后面的读取全部停止)
    printf("input age name: ");
    scanf("%d %s", &age_c, name_c);
    printf("Age: %d, Name: %s\n", age_c, name_c);
    
    printf("age(%%d): %d\n", age_d);
    printf("age(%%x): %x\n", age_d);
    printf("&age(%%x): %x\n", &age_d);
    // %d 一个转换说明(注:这里假设每个scanf函数只有一个转换说明,因此一次读取就是一个scanf函数调用)
    // 输入A,scanf()函数停止读取,把A字符放回输入
    // 程序下一次读取时,从这个A字符开始读取
    // 如果程序只有%d输入转换符,scanf()函数就一直无法越过A字符
    printf("input age: ");
    scanf("%d", &age_d);
    printf("age(%%d): %d\n", age_d);
    printf("age(%%x): %x\n", age_d);
    printf("&age(%%x): %x\n", &age_d);
    
    // %s
    // scanf()函数跳过空白字符,直到遇到第一个非空白字符
    // 读取,保存,再读取下一个字符,保存
    // 直到再次遇到空白字符,这个空白字符不保存
    // (这个空白字符放不放回输入不知道,书上没写。。。不过放不放也没啥意义)
    printf("input name: ");
    scanf("%s", &name_d);
    printf("name_d(%%s): %s\n", name_d);
    scanf_format_character_string();
    scanf_conversion_specification_character();
    return;
}
// 注: 在C语言中,scanf()并不是最常用的输入函数,但它能读取不同类型的数据
//     C语言还有其它的输入函数,例如: getchar()和fgets(),会在后面的章节中介绍

void scanf_format_character_string(void)
{
    int i_a, i_b;
    // scanf格式字符串中的普通字符
    // scanf函数允许在格式字符串中加入普通字符
    // * 格式字符串中,除空白字符外的字符必须与输入字符串严格匹配
    // * 空白字符包括(空格字符,制表字符,换行字符和没有空白字符的特殊情况)
    printf("input i_a(int), i_b(int);");
    printf("(%%d,%%d): ");
    // 要求第一个输入项后面紧贴着输入一个,(逗号)
    // 与书本上的输入方式有差别,应该是编译器的实现不同...(个人推测 00')
    scanf("%d,%d", &i_a, &i_b);
    printf("i_a,i_b: %d,%d\n", i_a, i_b);
    
    printf("input i_a(int), i_b(int);");
    printf("(%%d:%%d): ");
    scanf("%d:%d", &i_a, &i_b);
    printf("%d %d\n", i_a, i_b);
    return;
}

void scanf_conversion_specification_character(void)
{
    int i_a, i_b, i_c, i_d;
    char c_a, c_b;

    printf("input char i_a i_b(%%d%%d):");
    scanf("%d%d", &i_a, &i_b);
    printf("%d,%d\n", i_a, i_b);
    printf("input char i_a i_b(%%d %%d):");
    scanf("%d %d", &i_c, &i_d);
    printf("%d,%d\n", i_c, i_d);
    
    // scanf("%c") 和scanf(" %c")是有区别的 
    // (注: scanf函数的%c是特殊情况,其它转换说明无这种区别)
    // %c读取一个字符,包括回车键生成的换行符
    // 假设执行到上一个scanf函数,我们输入数据,按回车,
    // 生成的换行字符会存入输入缓冲区
    // scanf("%c")会读取这个换行字符
    // scanf(" %c")则可正确读取,不会读取输入缓冲区中的换行字符(ascii码)
    // scanf转换说明前没有空格
    printf("input char c_a(%%c):");
    scanf("%c", &c_a);
    printf("c_a(%%c):%c\n", c_a);
    //换行符ascii码是10,C语言换行符是'\n'
    printf("c_a(%%hhu):%hhu\n", c_a);
    // scanf转换说明前有空格
    printf("input char c_b( %%c):");
    scanf(" %c", &c_b);
    printf("c_b(%%c):%c\n", c_b);
    // 'A' ascii码是65
    // %hhu printf和scanf都有这个转换说明
    // 作用:输出或输入一个一个字节的无符号整数
    printf("c_b(%%hhu):%hhu\n", c_b);
    return;
}





