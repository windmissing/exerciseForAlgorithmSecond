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

void pushQueue(int bigIndex, int smallIndex)
{
	nextSecond[bigIndex] = nextSecond[smallIndex];
	nextSecond[smallIndex] = bigIndex;
}
int compare(vector<int> array, int a, int b)
{
	int smallIndex = array[a] < array[b] ? a : b;
	int bigIndex = array[a] > array[b] ? a : b;

	pushQueue(bigIndex, smallIndex);

	return smallIndex;
}

bool twoMoreElementsLeft(int head)
{
	return nextTarget[head] != -1;
}

bool getTopTwoElements(int a, int &b)
{
	b = nextTarget[a];
	if(a == -1 || b == -1)
		return false;
}

void removeSmallerOne(int &head, int a, int pre, int b, int ret)
{
	if(a == head)
		head = ret;
	else
		nextTarget[pre] = ret;
	nextTarget[ret] = nextTarget[b];
}

int findSmallest(vector<int> array)
{
	int head = headTarget;
	while(twoMoreElementsLeft(head))
	{
		int a = head, pre , b, ret;
		while(getTopTwoElements(a, b))
		{
			ret = compare(array, a, b);
			removeSmallerOne(head, a, pre, b, ret);
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
