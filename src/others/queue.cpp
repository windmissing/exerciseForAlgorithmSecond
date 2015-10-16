//10.1????
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#include "queue.h"

CQueue::CQueue(int size)
	:tail(1),head(1),length(size)
{
	s = new int[size+1];
}

CQueue::~CQueue()
{
	delete s;
}

bool CQueue::isEmpty()
{
	if(tail == head)
		return true;
	return false;
}

void CQueue::enqueue(int x)
{
	s[tail] = x;
	if(tail == length)
		tail = 1;
	else tail++;
}

int CQueue::dequeue()
{
	int x = s[head];
	if(head == length)
		head = 1;
	else head++;
	return x;
}

//??????????
void Print(CQueue Q)
{
	int i;
	if(Q.tail >= Q.head)
	{
		for(i = Q.head; i < Q.tail;i++)
			cout<<Q.s[i]<<' ';
		cout<<endl;
	}
	//???????,????????????
	else
	{
		for(i = Q.head; i <= Q.length; i++)
			cout<<Q.s[i]<<' ';
		for(i = 1; i < Q.tail; i++)
			cout<<Q.s[i]<<' ';
		cout<<endl;
	}
}
//????????
//???
//???
