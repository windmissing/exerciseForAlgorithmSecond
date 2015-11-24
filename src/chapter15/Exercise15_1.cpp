#include <iostream>
using namespace std;

#define N 11
//一个活动用一个结点表示
struct node
{
	int id;
	int start;
	int finish;
}A[N+1];
//递归贪心算法，在第i个活动执行结束之后的贪心策略，初始时i=0
void Reccursive_Activity_Selector(int i, int n)
{
	//找到第一个开始时间在第i个活动结束之后的活动
	int m = i+1;
	while(m <= n && A[m].start < A[i].finish)
		m++;
	//若找到了
	if(m <= n)
	{
		//将这个活动作为执行活动
		cout<<m<<' ';
		//递归第m个活动执行结束之后的贪心策略
		return Reccursive_Activity_Selector(m, n);
	}
	cout<<endl;
	return;
}
//迭代的贪心算法
void Greedy_Activity_Selector()
{
	//在第i个活动执行结束之后的贪心策略，初始时i=0
	int n = N, i = 0, m;
	for(m = 1; m <= n; m++)
	{
		//找到第一个开始时间在第i个活动结束之后的活动
		if(A[m].start >= A[i].finish)
		{
			//将这个活动作为执行活动
			cout<<A[m].id<<' ';
			//递归第m个活动执行结束之后的贪心策略
			i = m;
		}
	}
	cout<<endl;
}
/*
0 0 //虚构活动a0
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
*/
int main()
{
	int i;
	//输入测试数据
	for(i = 0; i <= N; i++)
	{
		A[i].id = i;
		if(i == 0){A[i].start = 0;A[i].finish = 0;}
		else cin>>A[i].start>>A[i].finish;
	}
	Reccursive_Activity_Selector(0, N);
	Greedy_Activity_Selector();
	return 0;
}
