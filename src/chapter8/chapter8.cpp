/*************************************************************************
    > File Name: Chapter8.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Wed 21 Oct 2015 08:48:49 AM CST
 ************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

#include "chapter8.h"

/*
int length_A, digit;

void Print(int *A, int start, int end)
{
	int i;
	for(i = start; i <= end; i++)
	{
		if(i == start)cout<<'{';
		else cout<<' ';
		cout<<A[i];
	}
	cout<<'}'<<endl;
}
*/
//计数排序
void Counting_Sort(int *A, int *B, int length_A, int k)
{
	int i, j;
	//将C数组初始化为0，用于计数
	int *C = new int[k+1];
	for(i = 0; i <= k; i++)
		C[i] = 0;
	//C[j]表示数字j在数组A中出现的次数
	for(j = 1; j <= length_A; j++)
		C[A[j]]++;
	//C[i]表示所以<=i的数字出现过的次数
	for(i = 1; i <= k; i++)
		C[i] = C[i] + C[i-1];
	//初始化B为0，B用于输出排序结果
	for(i = 1; i <= length_A; i++)
		B[i] = 0;
	for(j = length_A; j >= 1; j--)
	{
		//如果<=A[j]的数字的个数是x,那么排序后A[j]应该出现在第x个位置，即B[x]=A[j]
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
	delete C;
}
/*
//基数排序调用的稳定排序
void Stable_Sort(int *A, int *B, int k, int d)
{
	int i, j;
	//将C数组初始化为0，用于计数
	int *C = new int[k+1];
	for(i = 0; i <= k; i++)
		C[i] = 0;
	int *D = new int[length_A+1];
	for(j = 1; j <= length_A; j++)
	{
		//D[j]表示第[j]个元素的第i位数字
		D[j] = A[j] % (int)pow(10.0, d) / (int)pow(10.0, d-1);
		//C[j]表示数字D[j]在数组A中出现的次数
		C[D[j]]++;
	}
	//C[i]表示所以<=i的数字出现过的次数
	for(i = 1; i <= k; i++)
		C[i] = C[i] + C[i-1];
	//初始化B为0，B用于输出排序结果
	for(i = 1; i <= length_A; i++)
		B[i] = 0;
	for(j = length_A; j >= 1; j--)
	{
		//如果<=D[j]的数字的个数是x,那么排序后A[j]应该出现在第x个位置，即B[x]=A[j]
		B[C[D[j]]] = A[j];
		C[D[j]]--;
	}
	delete []C;
	delete []D;
}
//基数排序
void Radix_Sort(int *A, int *B)
{
	int i, j;
	//依次对每一位进行排序，从低位到高位
	for(i = 1; i <= digit; i++)
	{
		Stable_Sort(A, B, 9, i);
		//输入的是A，输出的是B，再次排序时要把输出数据放入输出数据中
		for(j = 1; j <= length_A; j++)
		A[j] = B[j];
	}
}
*/


