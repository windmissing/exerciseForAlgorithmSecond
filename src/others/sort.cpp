#include "sort.h"
#include <cmath>

void moveIndexNext(int *data, int *A, int size);
void moveIndexPrev(int *data, int *A, int size);

//����������õ��ȶ�����
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
	//C[j]��ʾ����D[j]������A�г��ֵĴ���
	for(i = 0; i < data.size(); i++)
	{
		ret[data[i]]++;
	}
	//C[i]��ʾ����<=i�����ֳ��ֹ��Ĵ���
	for(i = 1; i < RADIX; i++)
		ret[i] = ret[i] + ret[i-1];

	return ret;
}
ARRAY stableSort(ARRAY data, int digit)
{
	int j;

	//D[j]��ʾ��[j]��Ԫ�صĵ�iλ����
	ARRAY D = makeD(data, digit);

	//C[i]��ʾ����<=i�����ֳ��ֹ��Ĵ���
	ARRAY C = makeC(D);

	//��ʼ��BΪ0��B�������������
	ARRAY B(data.size(), 0);
	for(j = data.size()-1; j >= 0; j--)
	{
		//���<=D[j]�����ֵĸ�����x,��ô�����A[j]Ӧ�ó����ڵ�x��λ�ã���B[x]=A[j]
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

//��������
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
	//��C�����ʼ��Ϊ0�����ڼ���
	int *C = new int[k+1];
	for(i = 0; i <= k; i++)
		C[i] = 0;
	//C[j]��ʾ����j������A�г��ֵĴ���
	for(j = 1; j <= size; j++)
		C[A[j]]++;
	//C[i]��ʾ����<=i�����ֳ��ֹ��Ĵ���
	for(i = 1; i <= k; i++)
		C[i] = C[i] + C[i-1];
	//��ʼ��BΪ0��B�������������
	for(i = 1; i <= size; i++)
		B[i] = 0;
	for(j = size; j >= 1; j--)
	{
		//���<=A[j]�����ֵĸ�����x,��ô�����A[j]Ӧ�ó����ڵ�x��λ�ã���B[x]=A[j]
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
	delete C;
}
