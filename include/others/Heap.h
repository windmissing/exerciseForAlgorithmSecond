//ͷ�ļ�
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
//ʹ��i���Ϊ������������Ϊ�ѣ�����������ȷ��i�����������Ѿ��Ƕ�
//�ݹ鷽��
/*
time:O(lgn)
*/
template<typename Type> void CMaxHeap<Type>::heapify(int index)
{
	int l = LEFT(index), r = RIGHT(index), largest;
	//ѡ��i��i����i�������������ֵ���Ľ��
	if(l <= currentSize && compareNode(A[l], A[index]) == BIGGER)
		largest = l;
	else largest = index;
	if(r <= currentSize && compareNode(A[r], A[largest]) == BIGGER)
		largest = r;
	//���������Ѿ�����ѵ�����������ֹͣ
	//����
	if(largest != index)
	{
		//����ֵ���Ľ�㽻��
		swap(A[index], A[largest]);
		//���������ƻ������Ķѣ����µ�������
		heapify(largest);
	}
}

//��Ԫ��i�Ĺؼ������ӵ�key��Ҫ��key>=A[i]
template<typename Type> void CMaxHeap<Type>::increaseKey(int index, Type key)
{
	A[index] = key;
	//�����Ƚϣ���A[PARENT(i)]<A[i]���򽻻�
	//�����е�ĳ�����ʱA[PARENT(i)]>A[i]��������ѭ��
	while(PARENT(index) > 0 && compareNode(A[PARENT(index)], A[index]) == SMALLER)
	{
		swap(A[PARENT(index)], A[index]);
		index = PARENT(index);
	}
}

//��key���뵽����A��
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
//����A�����ؼ��֣�ʱ��O(1)
template<typename Type> Type CMaxHeap<Type>::Heap_Maximum()
{
	return A[1];
}
//ȥ��������A�����ؼ��֣�ʱ��O(lgn)
template<typename Type> Type CMaxHeap<Type>::extract()
{
	Type ret;
	if(currentSize < 1)
	{
		cout<<"heap underflow"<<endl;
		return ret;
	}
	//ȡ�����ֵ
	Type max = A[1];
	//�����һ��Ԫ�ز������ֵ��λ��
	A[1] = A[currentSize];
	A[currentSize] = maxNode;
	currentSize--;
	//���µ��������
	heapify(1);
	//�������ֵ
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
