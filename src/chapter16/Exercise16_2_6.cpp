/*************************************************************************
    > File Name: Exercise16_2_6.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Thu 22 Oct 2015 06:21:45 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include<stdlib.h>
#include "Exercise16_2_6.h"

int Partition(node *A, int p, int r)
{
	node x = A[r];
	int i = p-1, j;
	for(j = p; j < r; j++)
	{
		//划分的依据是avg = value / weight
		double t1 = x.value * 1.0 / x.weight;
		double t2 = A[j].value * 1.0 / A[j].weight;
		if(t2 >= t1)
		{
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i+1], A[r]);
	return i+1;
}

int Randomized_Partition(node *A, int p, int r)
{
	//随机选择数组中一个数作为主元
	int i = rand() % (r-p+1) + p;
	i = r;
	swap(A[r], A[i]);
	//划分
	return Partition(A, p, r);
}
//i是从1开使计数的，不是从p开始
double Randomized_Select(node *A, int p, int r, int weight, int value)
{
	if(p == r)
	{
		if(A[p].weight <= weight)
			return value + A[p].value;
		else
			return value + (double)A[p].value * weight / A[p].weight;
	}
	else if(p > r)
		return value;
	//以某个元素为主元，把数组分为两组，A[p..q-1] < A[q] < A[q+1..r]，返回主元在整个数组中的位置
	int q = Randomized_Partition(A, p, r);
	//主元是整个数组中的第q个元素
	int i, w = 0, v = 0;
	//求SG
	for(i = p; i < q; i++)
	{
		w = w + A[i].weight;
		v = v + A[i].value;
	}
	if(w == weight)//正是所求的元素
		return value + v;
	//主元物品取一部分
	else if(w < weight && w + A[q].weight >= weight)
		return value + v + (double)A[q].value * (weight-w) / A[q].weight;
	else if(w > weight)//所求元素<主元，则在A[p..q-1]中继续寻找
		return Randomized_Select(A, p, q-1, weight, value);
	else//所求元素>主元，则在A[q+1..r]中继续寻找
		return Randomized_Select(A, q+1, r, weight - w - A[q].weight, value + v + A[q].value);
}

double partialPackage(int weight, int len, node *material)
{
	if(weight == 0 || len == 0)
		return 0;
	return Randomized_Select(material, 1, len-1, weight, 0);
}

