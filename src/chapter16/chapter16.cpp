#include <iostream>
using namespace std;

#include "chapter16.h"

void Reccursive_Activity_Selector(const vector<activity> &A, int i, vector<int> &ret)
{
	//找到第一个开始时间在第i个活动结束之后的活动
	int m = i+1, n = A.size();
	while(m < n && A[m].start < A[i].finish)
		m++;
	//若找到了
	if(m < n)
	{
		//将这个活动作为执行活动
		ret.push_back(m);
		//递归第m个活动执行结束之后的贪心策略
		return Reccursive_Activity_Selector(A, m, ret);
	}
	return;
}

//递归贪心算法，在第i个活动执行结束之后的贪心策略，初始时i=0
vector<int> Reccursive_Activity_Selector(vector<activity> A)
{
	vector<int> ret;
	Reccursive_Activity_Selector(A, 0, ret);
	return ret;
}

//迭代的贪心算法
vector<int> Greedy_Activity_Selector(vector<activity> A)
{
	vector<int> ret;
	//在第i个活动执行结束之后的贪心策略，初始时i=0
	int n = A.size(), i = 0, m;
	for(m = 1; m < n; m++)
	{
		//找到第一个开始时间在第i个活动结束之后的活动
		if(A[m].start >= A[i].finish)
		{
			//将这个活动作为执行活动
			ret.push_back(A[m].id);
			//递归第m个活动执行结束之后的贪心策略
			i = m;
		}
	}
	return ret;
}
