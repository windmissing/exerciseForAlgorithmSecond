#include <cmath>
#include <stdlib.h>

#include "Chapter8.h"
#include "sort.h"

#define DATA_COUNT 10

static void makeRadomData();
void Print(int *A, int start, int end);

static int A[DATA_COUNT+1] = {0};
bool flag[1000]  = {0};

void makeRadomData()
{
	int i;
	bool flag[1000]  = {0};
	for(i = 0; i < DATA_COUNT; i++)
	{
		do
		{
			A[i] = rand() % (DATA_COUNT*DATA_COUNT);
		}while(flag[A[i]]);
		flag[A[i]] = 1;
	}
}

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

