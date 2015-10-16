//10.1????
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#include "stack.h"

CStack::CStack(int size)
	:top(0)
{
	s = new int[size+1];
}

CStack::~CStack()
{
	delete []s;
}

bool CStack::isEmpty()
{
	return (top == 0);
}

void CStack::push(int x)
{
	top++;
	s[top] = x;
}

int CStack::pop()
{
	if(isEmpty())
	{
		cout<<"underflow"<<endl;
		return 0;
	}
	else
	{
		top--;
		return s[top+1];
	}
}

void CStack::Print(CStack S)
{
	int i;
	for(i = 1; i <= S.top; i++)
		cout<<S.s[i]<<' ';
	cout<<endl;
}
//?????????
//??
//??
