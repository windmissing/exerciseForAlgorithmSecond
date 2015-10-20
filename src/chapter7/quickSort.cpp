/*************************************************************************
    > File Name: quickSort.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Tue 20 Oct 2015 08:46:14 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//输出过程
void Print(int *A, int len)
{
	for(int i = 0; i < len; i++)
	{
		if(i)cout<<' ';
		else cout<<"==> A = {";
		cout<<A[i];
	}
	cout<<'}'<<endl;
}

/************************7.1普通快排************************************************/
//划分
int Partition(int *A, int p, int r)
{
	//选择A[r]作为主元
	int x = A[r];
	int i = p - 1, j;
	for(j = p; j < r; j++)
	{
		//小于主元的放在左边
		if(A[j] <= x)
		{
			i++;
			//把大于主元的交换到右边
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1], A[r]);
	//返回最终主元的位置
	return i+1;
}

void QuickSort(int *A, int p, int r)
{
	if(p < r)
	{
		//以某个主元为标准，把数组分为两部分，左边都比主元小，右边都比主元大
		int q = Partition(A, p, r);
		//分别对左边和右边排序
		QuickSort(A, p, q-1);
		QuickSort(A, q+1, r);
	}
}

/********************7.3随机快排******************************************************/
//划分
int Randomized_Partition(int *A, int p , int r)
{
	//随机选择一个数作为主元
	int i = rand() % (r-p+1) + p;
	swap(A[r], A[i]);
	return Partition(A, p, r);
}
//排序，原理与普通快排相同，只是调用的划分方法不同
void Randomized_QuickSort(int *A, int p, int r)
{
	if(p < r)
	{
		int q = Randomized_Partition(A, p, r);
		Randomized_QuickSort(A, p, q-1);
		Randomized_QuickSort(A, q+1, r);
	}
}
