// 
//			|--> 数据项1 (数据不可分割的最小单位)
//      |--> 数据元素1--| 
// 	|		|--> 数据项2
// 	|
// 数据-|
// 	|
//	|		|--> 数据项1
//      |--> 数据元素2--|
// 			|--> 数据项2
// 数据对象: 性质相同的数据元素的集合，是数据的子集
// 性质相同(数据元素具有相同数量和类型的数据项)
//
// 1.逻辑结构
// 2.物理结构/存储结构(这里的存储器是指主存/内存,硬盘等外部存储通常用文件结构来描述):
// 	1. 顺序存储结构
// 	2. 链式存储结构 

// ADT (abstract data type:抽象数据类型)
// 算法(algorithm)是解决特定问题求解步骤的描述,在计算机中表现为
// 指令(instruction)的有限序列,并且每条序列表示一个或多个操作。
#include <stdio.h>
int sum_version1(void);
int sum_version2(void);

void main(void)
{
    sum_version1();
}

int sum_version1(void)
{
    // i变量为数列的项
    // n为数列值最大的项
    int sum, i, n = 100; 
    return 0;
}

int sum_version2(void)
{
    return 0;
}

// n为输入规模; 
// f(n)基本操作的数量 f(n)=n  f(n)=1 f(n)=n^2
// 基本操作的数量必须表示成输入规模的函数
//
// 函数的渐进增长《大话数据结构》P28
// 随着n越来越大,函数中的常数和其他次要项常常可以忽略
