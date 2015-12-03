/*************************************************************************
    > File Name: section22_5.cpp
    > Created Time: Mon 23 Nov 2015 07:55:49 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define N 10
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
bool flag = 0;
int Sort[N+1] = {N};

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
//转置   
Graph* Reverse(Graph *G)  
{  
    Graph *ret = new Graph;  
    int i;  
    //遍历图G中的每一条边，以终点为起点，以起点为终点，加入到新图RET中   
    for(i = 1; i <= N; i++)  
    {  
        Edge *E = G->V[i]->head;  
        while(E)  
        {  
            Edge *e = new Edge(E->end, E->start);  
            InsertEdge(ret, e);  
            E = E->next;  
        }  
    }  
    return ret;  
}
//访问某顶点
void DFS_Visit(Graph *G, Vertex *u)
{
	//在第一次访问时输出
	if(flag)cout<<char('p'+u->id)<<' ';
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
	u->f = time;
	//把结果按照f从大到小的顺序保存于Sort数组中
	if(flag == 0)
	{
		Sort[Sort[0]] = u->id;
		Sort[0]--;
	}
}
//深度优先搜索
void DFS(Graph *G)
{
	int i;
	//对每个顶点初始化
	for(i = 1; i <= N; i++)
	{
		G->V[i]->id = i;
		G->V[i]->color = WHITE;
		G->V[i]->p = NULL;
	}
	//时间戳初始化
	time = 0;
	//依次检索V中的顶点，发现白色顶点时，调用DFS_Visit访问该顶点
	for(i = 1; i <= N; i++)
	{
		
		int j;
		//第一次是以正常顺序
		if(flag == 0)
			j = i;
		//第二次是以f从大到小的顺序，这个顺序在第一次dfs次保存于Sort数组中
		else j = Sort[i];
		//发现白色顶点时，调用DFS_Visit访问该顶点
		if(G->V[j]->color == WHITE)
		{
			DFS_Visit(G, G->V[j]);
			if(flag)cout<<endl;
		}
	}
}
void Strongly_Connected_Component(Graph *G)
{
	//第一次DFS，计算每个顶点的f
	DFS(G);
    //转置，计算GT   
    Graph *G2 = Reverse(G);  
	//第一次的DFS和第二次的DFS有细微不同，用flag区分
	flag = 1;
	//第二次的DFS，按照f从大到小的顺序
	DFS(G2);
}

/* 
q s 
s v 
v w 
w s 
q w 
q t 
t y 
y q 
t x 
x z 
z x 
u y 
r y 
r u 
*/  

int main()  
{  
    //构造一个空的图   
    Graph *G = new Graph;  
	Edge *E;
    //输入边   
    int i;  
    char start, end;  
    for(i = 1; i <= 14; i++)  
    {  
        cin>>start>>end;  
        E = new Edge(start-'p', end-'p');  
        InsertEdge(G, E);  
        //无向图，要加两条边   
//      E = new Edge(end, start);   
//      InsertEdge(G, E);   
    }  
	//计算强联通分量
	Strongly_Connected_Component(G);
    return 0;  
}  


