/*************************************************************************
    > File Name: Exercise10_1_2.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Sat 24 Oct 2015 03:48:01 PM CST
 ************************************************************************/
#include<iostream>
using namespace std;
#include  "Exercise10_1_2.h"

bool arrayWithTwoStack::isEmpty(int index)
{
	if(index == 0 && top1 < 1)
		return true;
	if(index == 1 && top2 > len)
		return true;
	return false;
}

void arrayWithTwoStack::push(int index, int data)
{
	//已满
	if(top1 > top2)// cout<<"error:overflow"<<endl;
		return;
	//对栈1操作
	if(index == 0)
	{
		//top
		top1++;
		s[top1] = data;
	}
	//对栈2操作
	else
	{
		top2--;
		s[top2] = data;
	}
}

//出栈，index为0表示对第1个栈进行操作，index为1表示对第2个栈进行操作
int arrayWithTwoStack::pop(int index)
{
	int ret;
	//对栈1操作
	if(index == 0)
	{
		//栈1为空
		if(top1 < 0)
		{
			//cout<<"error:underflow"<<endl;
			return -1;
		}
		else
		{
			ret = s[top1];
			top1--;
		}
	}
	//对栈2操作
	else
	{
		//栈2为空
		if(top2 > len)
		{
			//cout<<"error:underflow"<<endl;
			return -1;
		}
		else
		{
			ret = s[top2];
			top2++;
		}
	}
	return ret;
}
