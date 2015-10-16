#include "sort.h"
#include <cmath>

void moveIndexNext(int *data, int *A, int size);
void moveIndexPrev(int *data, int *A, int size);

//基数排序调用的稳定排序
void countingSort(int *A, int *B, int k, int size);

ARRAY makeD(ARRAY data, int digit)
{
	ARRAY ret(data.size());
	for(int j = 0; j < data.size(); j++)
	{
		ret[j] = data[j] % (int)pow(10.0, digit+1) / (int)pow(10.0, digit);
	}
	return ret;
}

ARRAY makeC(ARRAY data)
{
	ARRAY ret(RADIX, 0);
	int i;
	//C[j]表示数字D[j]在数组A中出现的次数
	for(i = 0; i < data.size(); i++)
	{
		ret[data[i]]++;
	}
	//C[i]表示所以<=i的数字出现过的次数
	for(i = 1; i < RADIX; i++)
		ret[i] = ret[i] + ret[i-1];

	return ret;
}
ARRAY stableSort(ARRAY data, int digit)
{
	int j;

	//D[j]表示第[j]个元素的第i位数字
	ARRAY D = makeD(data, digit);

	//C[i]表示所以<=i的数字出现过的次数
	ARRAY C = makeC(D);

	//初始化B为0，B用于输出排序结果
	ARRAY B(data.size(), 0);
	for(j = data.size()-1; j >= 0; j--)
	{
		//如果<=D[j]的数字的个数是x,那么排序后A[j]应该出现在第x个位置，即B[x]=A[j]
		B[C[D[j]]-1] = data[j];
		C[D[j]]--;
	}
	return B;
}

void radixSort(ARRAY& data, int maxDigit)
{
	for(int i = 0; i < maxDigit; i++)
	{
		ARRAY ret = stableSort(data, i);
		data = ret;
	}
}

void moveIndexNext(int *data, int *A, int size)
{
	for(int i = size; i > 0; i--)
		A[i] = data[i-1];
	A[0] = 0;
}

void moveIndexPrev(int *data, int *A, int size)
{
	for(int i = 0; i < size; i++)
		data[i] = A[i+1];
}

//计数排序
void countingSort(int *A, int size)
{
	int k = 10;
//	moveIndexNext(A, size);
	int *B = new int[size+1];
	countingSort(A, B, k, size);
	for(int i = 1; i <= size; i++)
		A[i] = B[i+1];
	delete []B;
}

void countingSort(int *A, int *B, int k, int size)
{
	int i, j;
	//将C数组初始化为0，用于计数
	int *C = new int[k+1];
	for(i = 0; i <= k; i++)
		C[i] = 0;
	//C[j]表示数字j在数组A中出现的次数
	for(j = 1; j <= size; j++)
		C[A[j]]++;
	//C[i]表示所以<=i的数字出现过的次数
	for(i = 1; i <= k; i++)
		C[i] = C[i] + C[i-1];
	//初始化B为0，B用于输出排序结果
	for(i = 1; i <= size; i++)
		B[i] = 0;
	for(j = size; j >= 1; j--)
	{
		//如果<=A[j]的数字的个数是x,那么排序后A[j]应该出现在第x个位置，即B[x]=A[j]
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
	delete C;
}
