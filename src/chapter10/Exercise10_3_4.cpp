#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#include "Chapter10.h"

CCompactMultipleArray::CCompactMultipleArray(int n)
{
	key = new int[n];
	next = new int[n];
	prev = new int[n];
}

CCompactMultipleArray::~CCompactMultipleArray()
{
	delete key;
	delete next;
	delete prev;
}

void CCompactMultipleArray::insert(int x)
{
	//????
	if(f == size-1)
	{
		cout<<"error:overflow"<<endl;
		return;
	}
	//??????,????
	++f;
	//??????????,???,?????????,???????f+1??
	key[f] = x;
	prev[f] = -1;
	next[f] = head;
	if(head >= 0)
		prev[head] = f;
	head = f;
}
//??????
void CCompactMultipleArray::remove(int x)
{
	//?????????
	if(f == -1)
	{
		cout<<"error:underflow"<<endl;
		return;
	}
	int i;
	//??????????
	for(i = 0; i <= f; i++)
	{
		if(key[i] != x)continue;
		//????????i???
		//????,???i???
		if(prev[i] != -1)
			next[prev[i]] = next[i];
		if(next[i] != -1)
			prev[next[i]] = prev[i];
		//??i??f???,??????,???????
		//??i???f???,???f??????i??????
		if(i < f)
		{
			//??f??????i???
			key[i] = key[f];
			next[i] = next[f];
			prev[i] = prev[f];
			//????f???,????i
			if(prev[f] != -1)
				next[prev[f]] = i;
			if(next[f] != -1)
				prev[next[f]] = i;
			
		}
		//???????,????
		f--;
		break;
	}
}
/*
//??,???????,?????????
void Print(int *key, int *next, int *prev)
{
	int i;
	for(i = 0; i <= f; i++)
		cout<<i<<": "<<key[i]<<' '<<next[i]<<' '<<prev[i]<<endl;
}*/
/*
int main()
{
	int x;
	string str;
	//??????
	head = -1;f = -1;
	while(1)
	{
		cin>>str;
		if(str == "I")
		{
			x = rand() % 100;
			cout<<x<<endl;
			Insert(key, next, prev, x);
		}
		else if(str == "D")
		{
			cin>>x;
			Delete(key, next, prev, x);
		}
		else if(str == "P")
		{
			Print(key, next, prev);
		}
	}
	return 0;
}*/
