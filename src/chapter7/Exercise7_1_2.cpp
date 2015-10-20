/*************************************************************************
    > File Name: Exercise7_1_2.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Tue 20 Oct 2015 08:48:00 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//划分
int Partition(int *A, int p, int r)
{
	//选择A[r]作为主元
	int x = A[r];
	int i = p - 1, j;
	bool flag = 0;
	for(j = p; j < r; j++)
	{
		//小于主元的放在左边
		if(A[j] < x || (A[j] == x && flag))
		{
			i++;
			//把大于主元的交换到右边
			swap(A[i],A[j]);
			if(A[j] == x)flag = !flag;
		}
	}
	swap(A[i+1], A[r]);
	//返回最终主元的位置
	return i+1;
} 
