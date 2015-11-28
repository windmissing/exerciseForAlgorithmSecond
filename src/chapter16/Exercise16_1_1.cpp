/*************************************************************************
    > File Name: Exercise16_1_1.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Tue 24 Nov 2015 07:16:57 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

#define N 11  
//一个活动用一个结点表示  
struct node  
{  
    int id;  //id号，因为要排序
    int start;  //开始时间
    int finish;  //结束时间
}A[N+2];  
bool cmp(node a, node b)
{
	return a.finish < b.finish;
}
int s[N+2][N+2] = {0};
//16.1-1
void DP()
{
	int step, i, j, k;
	//根据Sij的定义，当j<i+2时，Sij为空集，c[i][j]=0
	for(step = 2; step <= N+1; step++)
	{
		//根据公式16.3计算c[i][j]
		for(i = 0; i <= N; i++)
		{
			j = step + i;
			if(j <= N+1)
			{
				//根据Sij的定义，当A[i].finish>A[j].start时，Sij为空集，c[i][j]=0
				if(A[i].finish <= A[j].start)
				{					
					for(k = i + 1; k < j; k++)
					{
						//根据公式16.3，取k的条件是Ak属于Sij
						if(A[k].start < A[i].finish || A[k].finish > A[j].start)
							continue;
						//根据公式16.3计算
						int temp = s[i][k] + s[k][j] + 1;
						if(temp > s[i][j])
							s[i][j] = temp;
					}
				}
			}
		}
	}
	cout<<s[0][N+1]<<endl;
}
//输出结果
void Print(int start, int end)
{
	if(s[start][end] == 1 && end - start == 2)
	{
		cout<<start+1<<' ';
		return ;
	}
	int k;
	//Sij中的一个活动Ak，若选择这个活动，能保证c[i][j]取到最大值
	for(k = start + 1; k < end; k++)
	{
		if(A[k].start < A[start].finish || A[k].finish > A[end].start)
			continue;
		if(s[start][k] + s[k][end] + 1 == s[start][end])
		{
			//输出第K个活动之前的活动
			Print(start, k);
			//输出第k个活动的id
			cout<<A[k].id<<' ';
			//输出第K个活动之前的活动
			Print(k, end);
			break;
		}
	}
}
/*  
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
    int i = 0;  
    //输入测试数据 
	//增加活动A0，f[A0] = 0
	A[i].id = A[i].start = A[i].finish = 0;
	//输入活动的开始时间和结束时间
    for(i = 1; i <= N; i++)  
    {  
        A[i].id = i;  
        cin>>A[i].start>>A[i].finish;  
    }  
	//增加结束活动AN+1，s[AN+1] = 0x7fffffff
	A[i].id = i;
	A[i].start = A[i].finish = 0x7fffffff;
	//按结束时间从小到大排序
	sort(A, A+N+2, cmp);
	//DP
	DP();
	//输出结果
	Print(0, N+1);
	cout<<endl;
    return 0;  
}  

