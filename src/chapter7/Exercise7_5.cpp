/*************************************************************************
    > File Name: Exercise7_5.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Tue 20 Oct 2015 08:52:48 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//三数取中
int GetMid(int *A, int p, int r)
{
	int a = -1, b = -1, c = -1;
	while(a < p)a = rand() % (r+1);
	while(b < p)b = rand() % (r+1);
	while(c < p)c = rand() % (r+1);
	if((A[a]-A[b])*(A[a]-A[c])<=0)return a;
	if((A[b]-A[a])*(A[b]-A[c])<=0)return b;
	if((A[c]-A[a])*(A[c]-A[b])<=0)return c;
}
//划分
int Partition(int *A, int p, int r)
{
	//选择A[r]作为主元
	int m = GetMid(A, p , r);
	swap(A[m], A[r]);
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
//快速排序
void QuickSort(int *A, int p, int r)
{
	//长度小于k的子数组不排序
	if(r > p)
	{
		//以某个主元为标准，把数组分为两部分，左边都比主元小，右边都比主元大
		int q = Partition(A, p, r);
		//分别对左边和右边排序
		QuickSort(A, p, q-1);
		QuickSort(A, q+1, r);
	}
}
