#include <iostream>
using namespace std;

#define N 10
#define WHITE 0
#define GRAY 1
#define BLACK 2

//边结点结构
class Edge
{
public:
	int start;//有向图的起点
	int end;//有向图的终点
	Edge *next;//指向同一个起点的下一条边
	int type;//边的类型
	Edge(int s, int e):start(s),end(e),next(NULL){}
};
//顶点结点结构
class Vertex
{
public:
	int id;
	Edge *head;//指向以该顶点为起点的下一条边
	int color;//顶点的颜色
	Vertex *p;//指向遍历结果的父结点
	int d, f;//第一次被发现的时间和结束检查的时间
	Vertex(int i):head(NULL),color(WHITE),p(NULL),d(0x7fffffff),id(i){}
};
//图结构
class Graph
{
public:
	Vertex *V[N+1];//N个顶点
	Graph()
	{
		int i;
		for(i = 1; i <= N; i++)
			V[i] = new Vertex(i);
	}
	~Graph()
	{
		int i;
		for(i = 1; i <= N; i++)
			delete V[i];
	}
};

void InsertEdge(Graph *G, Edge *E);
void DFS(Graph *G);
