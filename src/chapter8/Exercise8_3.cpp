#include <cmath>
#include <stdlib.h>

#include "Chapter8.h"
#include "sort.h"

#define DATA_COUNT 10

void Print(const ARRAY & A);
static void makeRadomData();
ARRAY countingSortByDigit(const ARRAY& A);
int Digit(int x);
ARRAY makeD(const ARRAY & A);
static ARRAY makeC(const ARRAY& D);
ARRAY extractNumWithSameDigit(ARRAY & wholeArray);
ARRAY::iterator getNextIteratorSafely(const ARRAY& array, ARRAY::iterator it);

ARRAY solve8_3(const ARRAY & A)
{
	ARRAY ret;
	//先进行计数排序，把长度相同的数字排在一起
	vector<int> B = countingSortByDigit(A);

	while(B.size() != 0)
	{
		ARRAY subArray = extractNumWithSameDigit(B);
		radixSort(subArray, Digit(subArray[0]));
		ret.insert(ret.end(), subArray.begin(), subArray.end());
	}
	return ret;
}

void makeRadomData()
{
//	for(int i = 1; i <= DATA_COUNT; i++)
//		A[i] = rand() % (int)pow(10.0, rand()%5+1);
//	Print();
}

ARRAY countingSortByDigit(const ARRAY& A)
{
	ARRAY D = makeD(A);
	ARRAY C = makeC(D);
	ARRAY B(A.size(), 0);
	for(int j = A.size() - 1; j >= 0; j--)
	{
		B[C[D[j]]-1] = A[j];
		C[D[j]]--;
	}
	return B;
}

ARRAY makeD(const ARRAY & A)
{
	ARRAY ret(A.size());
	for(int i = 0; i < A.size(); i++)
	{
		ret[i] = Digit(A[i]);
	}
	return ret;
}

ARRAY makeC(const ARRAY& D)
{
	ARRAY ret(RADIX, 0);
	int i;
	for(i = 0; i < D.size(); i++)
		ret[D[i]]++;
	for(i = 1; i < RADIX; i++)
		ret[i] = ret[i] + ret[i-1];
	return ret;
}

void Print(const ARRAY & A)
{
	int i;
	for(i = 0; i < A.size(); i++)
		cout<<A[i]<<' ';
	cout<<endl;
}

int Digit(int x)
{
	int ret = 0;
	while(x)
	{
		ret++;
		x = x / 10;
	}
	return ret;
}

ARRAY extractNumWithSameDigit(ARRAY & whole)
{
	ARRAY::iterator end = whole.begin();
	while(end != whole.end() && Digit(*(end+1)) == Digit(whole[0]))
		end++;
	ARRAY sub(whole.begin(), getNextIteratorSafely(whole, end));
	whole.erase(whole.begin(), getNextIteratorSafely(whole, end));
	return sub;
}

ARRAY::iterator getNextIteratorSafely(const ARRAY& array, ARRAY::iterator it)
{
	if(it == array.end())
		return it;
	else
		return it+1;
}
