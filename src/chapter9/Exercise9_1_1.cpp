#include <iostream>
using namespace std;

#include "Exercise9_1_1.h"

int *nextTarget;
int *nextSecond;
int headTarget = 0;
void prepare(int size)
{
	nextTarget = new int[size];
	for(int i = 0; i < size; i++)
		nextTarget[i] = i + 1;
	nextTarget[size-1] = -1;
	nextSecond = new int[size];
	for(int i = 0; i < size; i++)
		nextSecond[i] = -1;
}

void release()
{
	delete []nextTarget;
	delete []nextSecond;
}

int Find_S2(vector<int> array);

int solve9_1_1(vector<int> array)
{
	if(array.size() < 2)
		return 0;
	prepare(array.size());
	//运行算法并输出结果
	int ret = Find_S2(array);
	release();
	return ret;
}

int compare(vector<int> array, int a, int b)
{
	if(array[a] < array[b])
	{
		nextSecond[b] = nextSecond[a];
		nextSecond[a] = b;
		return a;
	}
	else
	{
		nextSecond[a] = nextSecond[b];
		nextSecond[b] = a;
		return b;
	}
}
//求第二小值
int Find_S2(vector<int> array)
{
	int head = headTarget;
	while(nextTarget[head] != -1)
	{
		int a = head, pre = head, b;
		while(a != -1 && nextTarget[a] != -1)
		{
			b = nextTarget[a];
			int ret = compare(array, a, b);
			if(a == head)
				head = ret;
			else
				nextTarget[pre] = ret;
			nextTarget[ret] = nextTarget[b];
			a = nextTarget[b];
			pre = ret;
		}
	}
	head = nextSecond[head];
	int min = array[head];
	while(nextSecond[head] != -1)
	{
		head = nextSecond[head];
		if(array[head] < min)
			min = array[head];
	}
	return min;
}
