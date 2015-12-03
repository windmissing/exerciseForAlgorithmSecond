/*************************************************************************
    > File Name: section22_4.cpp
    > Created Time: Mon 23 Nov 2015 07:57:00 PM CST
 ************************************************************************/

//用邻接表实现图的转置
#include <iostream>
using namespace std;

#define N 14
#define WHITE 0
#define GRAY 1
#define BLACK 2


//边结点结构
struct Edge
{
	int start;//有向图的起点
	int end;//有向图的终点
	Edge *next;//指向同一个起点的下一条边
	int type;//边的类型
	Edge(int s, int e):start(s),end(e),next(NULL){}
};
//顶点结点结构
struct Vertex
{
	int id;
	Edge *head;//指向以该顶点为起点的下一条边
	int color;//顶点的颜色
	Vertex *p;//指向遍历结果的父结点
	int d, f;//第一次被发现的时间和结束检查的时间
	Vertex(int i):head(NULL),color(WHITE),p(NULL),d(0x7fffffff),id(i){}
};
//图结构
struct Graph
{
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

int time = 0;

//插入边
void InsertEdge(Graph *G, Edge *E)
{
	//如果没有相同起点的边
	if(G->V[E->start]->head == NULL)
		G->V[E->start]->head =E;
	//如果有，加入到链表中，递增顺序排列，便于查重
	else
	{
		//链表的插入，不解释
		Edge *e1 = G->V[E->start]->head, *e2 = e1;
		while(e1 && e1->end < E->end)
		{
			e2 = e1;
			e1 = e1->next;
		}
		if(e1 && e1->end == E->end)
			return;
		if(e1 == e2)
		{
			E->next = e1;
			G->V[E->start]->head =E;
		}
		else
		{
			e2->next = E;
			E->next = e1;
		}
	}
}
//访问某顶点
void DFS_Visit(Graph *G, Vertex *u)
{
	//将u置为黑色
	u->color = GRAY;
	//使全局变量time增值
	time++;
	//将time的新值记录为发现时间
	u->d = time;
	//检查和u相邻的每个顶点v
	Vertex *v;
	Edge *e = u->head;
	while(e)
	{
		v = G->V[e->end];
		//如果顶点为白色
		if(v->color == WHITE)
		{
			//递归访问顶点
			v->p = u;
			DFS_Visit(G, v);
			//树边
			e->type = 1;
		}
		else if(v->color == GRAY)
		{
			//反向边
			e->type = 2;
		}
		else if(v->color == BLACK)
		{
			//正向边
			if(u->d < v->d)
				e->type = 3;
			//交叉边
			else
				e->type = 4;
		}
		e = e->next;
	}
	//以u为起点的所有边都被探寻后，置u为黑色
	u->color = BLACK;
	//并将完成时间记录在f[u]中
	time++;
	//按最后访问时间f输出
	cout<<(char)(u->id + 'l')<<' ';
	u->f = time;
}
//深度优先搜索
void DFS(Graph *G)
{
	int i;
	//对每个顶点初始化
	for(i = 1; i <= N; i++)
	{
		G->V[i]->color = WHITE;
		G->V[i]->p = NULL;
	}
	//时间戳初始化
	time = 0;
	//依次检索V中的顶点，发现白色顶点时，调用DFS_Visit访问该顶点
	for(i = 1; i <= N; i++)
	{
		if(G->V[i]->color == WHITE)
			DFS_Visit(G, G->V[i]);
	}
}
//输出
void Print(Graph *G)
{
	int i;
	//遍历每个顶点
	for(i = 1; i <= N; i++)
	{
		cout<<i<<':';
		//输出以i为起点的边的终点
		Edge *e = G->V[i]->head;
		while(e)
		{
			cout<<e->end<<' ';
			e = e->next;
		}
		cout<<endl;
	}
	cout<<endl;
}
/*
m r
m q
m x
n q
n u
n o
q t
o s
o v
o r
r u
r y
u t
p z
p o
s r
v w
v x
y v
w z
*/
int main()
{
	//构造一个空的图
	Graph *G = new Graph;
	Edge *E;
	Print(G);
	//输入边
	int i;
	char start, end;
	for(i = 1; i <= 20; i++)
	{
		cin>>start>>end;
		E = new Edge(start-'l', end-'l');
		InsertEdge(G, E);
		//无向图，要加两条边
//		E = new Edge(end, start);
//		InsertEdge(G, E);
	}
	Print(G);
	//深度优先搜索，并输出排序结果
	DFS(G);
	return 0;
}

