#include <iostream>
using namespace std;
#include "MaxFlow.h"
#define INT_MAX 0x7FFFFFFF

void Mat_Flow::MakeGraph(int m)
{
	int start, end, value;
	while(m--)
	{
		cin>>start>>end>>value;
		AddSingleEdge(start, end, value);
	}
}
bool Mat_Flow::bellman_ford()
{
	int i, j;
	memset(path, -1, sizeof(path));
	fill(ecost, ecost+NMAX, INT_MAX);
	ecost[0] = 0;

	bool flag = true;
	while(flag)
	{
		flag = false;
		for(i = 0; i <= n; i++)
		{
			if(ecost[i] == INT_MAX)
				continue;
			for(j = 0; j <= n; j++)
			{
				if(net[i][j] > 0 && ecost[i] + 1 < ecost[j])
				{
					flag = true;
					ecost[j] = ecost[i] + 1;
					path[j] = i;
				}
			}
		}
	}
	return ecost[n] != INT_MAX;
}

int Mat_Flow::max_flow()
{
	int i, j;
	//初始时，剩余网络即为整个网络
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= n; j++)
			net[i][j] = map[i][j];
	}
	int maxflow = 0;
	//while there exists a path p from s to t int the residual network G1
	//从剩余网络中找到一条增广路径，增广路径存在在path中
	while(bellman_ford())
	{
		//do c|f(p) <- min {c|f(u,v):(u,v) is in p}
		//计算增广路径上的净流
		int v = n, cfp = INT_MAX, u;
		while(v != 0)
		{
			//path存储的是增广路径，path[v]=u说明(u,v)在增广路径上
			u = path[v];
			cfp = min(cfp, net[u][v]);
			v = u;
		}
		//更新最大流的大小
		maxflow += cfp;
		//更新剩余网络
		//for each edge(u,v) in p
		v = n;
		while(v != 0)
		{
			u = path[v];
			//f[u,v] <- f[u,v] + cfp
			net[u][v] -= cfp;
			net[v][u] += cfp;
			//f[v,u] <- -f[u,v]
			v = u;
		}
	}
	return maxflow;
}
