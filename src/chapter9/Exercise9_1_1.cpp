#include <iostream>
using namespace std;

#include "Exercise9_1_1.h"

int *nextTarget;
int *nextSecond;
int headTarget = 0;

void prepare(int size)
{
	headTarget = 0;
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

int findSmallest(vector<int> array);
int findSecondSmaller(vector<int> array, int smallestIndex);

int solve9_1_1(vector<int> array)
{
	if(array.size() < 2)
		return 0;
	prepare(array.size());
	//运行算法并输出结果
	int smallestIndex = findSmallest(array);
	int secondSmaller = findSecondSmaller(array, smallestIndex);
	release();
	return secondSmaller;
}

int compare(vector<int> array, int a, int b)
{
	int smallIndex = array[a] < array[b] ? a : b;
	int bigIndex = array[a] > array[b] ? a : b;

	nextSecond[bigIndex] = nextSecond[smallIndex];
	nextSecond[smallIndex] = bigIndex;

	nextTarget[smallIndex] = nextTarget[b];
	return smallIndex;
}

int findSmallest(vector<int> array)
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
			a = nextTarget[b];
			pre = ret;
		}
	}
	return head;
}

int findSecondSmaller(vector<int> array, int smallestIndex)
{
	int head = smallestIndex;
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
