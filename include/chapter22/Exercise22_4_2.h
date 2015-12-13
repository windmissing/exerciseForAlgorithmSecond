#include <iostream>
using namespace std;

namespace exercise22_4_2
{
#define MAX_NUM_OF_VERTEX 100

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
	int indegree;
	Edge *head;//指向以该顶点为起点的下一条边
	Vertex():head(NULL),indegree(0){}
};

//图结构
class Graph
{
	int numOfVertex;
public:
	Vertex *V[MAX_NUM_OF_VERTEX+1];//N个顶点
	Graph(int n):numOfVertex(n)
	{
		int i;
		for(i = 1; i <= n; i++)
			V[i] = new Vertex();
	}
	~Graph()
	{
		int i;
		for(i = 1; i <= numOfVertex; i++)
			delete V[i];
	}
void InsertEdge(Edge *E);
int countWays(int start, int end);
};
};
