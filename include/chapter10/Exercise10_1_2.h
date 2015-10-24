/*************************************************************************
    > File Name: Exercise10_1_2.h
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Sat 24 Oct 2015 03:56:10 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//用一个数组实现两个栈
class arrayWithTwoStack
{
	//栈1和栈2的栈顶指针
	int top1, top2;//分别初始化为0和n+1
	int len;//数组长度
	int *s;//数组
	public:
	    arrayWithTwoStack(int size):top1(0),top2(size+1),len(size){s = new int[size+1];}
		bool isEmpty(int index);
		void push(int index, int data);
		int pop(int index);
};
