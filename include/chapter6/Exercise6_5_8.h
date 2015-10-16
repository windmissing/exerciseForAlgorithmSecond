#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <list>

struct node
{
	int list;
	int value;
	node(){	}
	node(const node& A){list = A.list; value = A.value;}
	bool operator < (node& B)const
	{
		return value<B.value;
	}
	bool operator > (const node& B)const
	{
		return value>B.value;
	}
	bool operator == (const node& B)const
	{
		return value == B.value;
	}
	static node getMaxNode()
	{
		node ret;
		ret.value = 0x7FFFFFFF;
		return ret;
	}
};

#define ARRAY vector<node>

ARRAY solve_6_5_8(vector<ARRAY> inputParam);
