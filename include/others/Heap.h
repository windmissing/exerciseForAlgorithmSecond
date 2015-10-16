//头文件
#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;

#include "string.h"

#define N 1000

typedef enum compareResult
{
	EQUAL = 0,
	SMALLER = 1,
	BIGGER = 2
};

template<typename Type>class CMaxHeap
{
#ifdef __UT__
public:
#else
private:
#endif
	Type A[N+1];
	int currentSize;
	int maxSize;
	Type maxNode;

	void heapify(int index);
	void increaseKey(int index, Type key);
	compareResult compareNode(Type A, Type B);
public:
	CMaxHeap(){};
	CMaxHeap(int size, Type maxNode);
	void insert(Type key);
	Type Heap_Maximum();
	Type extract();
	bool isEmpty();
	void print();
};

#define PARENT(i) (i)>>1
#define LEFT(i) (i)<<1
#define RIGHT(i) ((i)<<1)+1

template<typename Type> CMaxHeap<Type>::CMaxHeap(int size, Type maxNode)
	:currentSize(0),maxSize(size)
{
	this->maxNode = maxNode;
	//maxNode.beMaxNode();
	for(int i = 0; i <= size; i++)
		A[i] = maxNode;
}
//使以i结点为根结点的子树成为堆，调用条件是确定i的左右子树已经是堆
//递归方法
/*
time:O(lgn)
*/
template<typename Type> void CMaxHeap<Type>::heapify(int index)
{
	int l = LEFT(index), r = RIGHT(index), largest;
	//选择i、i的左、i的右三个结点中值最大的结点
	if(l <= currentSize && compareNode(A[l], A[index]) == BIGGER)
		largest = l;
	else largest = index;
	if(r <= currentSize && compareNode(A[r], A[largest]) == BIGGER)
		largest = r;
	//如果根最大，已经满足堆的条件，函数停止
	//否则
	if(largest != index)
	{
		//根与值最大的结点交互
		swap(A[index], A[largest]);
		//交换可能破坏子树的堆，重新调整子树
		heapify(largest);
	}
}

//将元素i的关键字增加到key，要求key>=A[i]
template<typename Type> void CMaxHeap<Type>::increaseKey(int index, Type key)
{
	A[index] = key;
	//跟父比较，若A[PARENT(i)]<A[i]，则交换
	//若运行到某个结点时A[PARENT(i)]>A[i]，就跳出循环
	while(PARENT(index) > 0 && compareNode(A[PARENT(index)], A[index]) == SMALLER)
	{
		swap(A[PARENT(index)], A[index]);
		index = PARENT(index);
	}
}

//把key插入到集合A中
template<typename Type> void CMaxHeap<Type>::insert(Type key)
{
	if(maxSize == currentSize)
	{
		cout<<"heap is full"<<endl;
		return ;
	}
	currentSize++;
	increaseKey(currentSize, key);
}
//返回A中最大关键字，时间O(1)
template<typename Type> Type CMaxHeap<Type>::Heap_Maximum()
{
	return A[1];
}
//去掉并返回A中最大关键字，时间O(lgn)
template<typename Type> Type CMaxHeap<Type>::extract()
{
	Type ret;
	if(currentSize < 1)
	{
		cout<<"heap underflow"<<endl;
		return ret;
	}
	//取出最大值
	Type max = A[1];
	//将最后一个元素补到最大值的位置
	A[1] = A[currentSize];
	A[currentSize] = maxNode;
	currentSize--;
	//重新调整根结点
	heapify(1);
	//返回最大值
	return max;
}

template<typename Type> bool CMaxHeap<Type>::isEmpty()
{
	if(currentSize < 1)
		return true;
	return false;
}

template<typename Type> void CMaxHeap<Type>::print()
{
	for(int i = 1; i <= currentSize; i++)
		cout<<A[i]<<' ';
	cout<<endl;
}
	
template<typename Type> compareResult CMaxHeap<Type>::compareNode(Type A, Type B)
{
	if(A == maxNode && B == maxNode)
		return EQUAL;
	if(A == maxNode)
		return BIGGER;
	if(B == maxNode)
		return SMALLER;
	if(A < B)
		return SMALLER;
	if(A > B)
		return BIGGER;
	return EQUAL;
}
