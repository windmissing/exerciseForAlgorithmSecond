#include <iostream>
using namespace std;

#include <string.h>

#define NMAX 210

class Mat_Flow
{
public:
	int n;//点的个数。其中0是源点，1是汇点
	int map[NMAX][NMAX];//网络费用
	int net[NMAX][NMAX];//剩余网络
	int path[NMAX];//增广路径，path[v]=u说明(u,v)在增广路径上
	int ecost[NMAX];//源点到各点的最短路径

	Mat_Flow(int num):n(num)
	{
		memset(map, 0, sizeof(map));
	}
	void AddSingleEdge(int start, int end, int value = 1)
	{
		map[start][end] = value;
	}
	void MakeGraph(int m);
	bool bellman_ford();
	int max_flow();
};

