/*************************************************************************
    > File Name: Exercise8_3_4.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Wed 21 Oct 2015 08:51:51 AM CST
 ************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

int n, radix, length_A, digit = 2;
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
		D[j] = A[j] % (int)pow(radix*1.0, d) / (int)pow(radix*1.0, d-1);
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
		Stable_Sort(A, B, radix-1, i);
		//输入的是A，输出的是B，再次排序时要把输出数据放入输出数据中
		for(j = 1; j <= length_A; j++)
			A[j] = B[j];
	}
}

int main()
{
	cin>>n;
	length_A = n;
	int *A = new int[n+1];
	int *B = new int[n+1];
	bool flag[1000]  = {0};
	int i;
	//生产n个随机的数据范围在0到n^-1之间
	for(i = 1; i <= n; i++)
	{
		do
		{
			A[i] = rand() % (n*n);
		}while(flag[A[i]]);
		flag[A[i]] = 1;
	}
	Print(A, 1, n);
	radix = n;
	Radix_Sort(A, B);
	Print(A, 1, n);
	return 0;
}
