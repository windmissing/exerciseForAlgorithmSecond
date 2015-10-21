#include <iostream>
#include <stack>
using namespace std;

#include "Exercise22_3_6.h"

stack<Edge*> S;//用栈代替递归实现DFS
int depth = 0;

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
	//使全局变量depth增值
	depth++;
	//将depth的新值记录为发现时间
	u->d = depth;
	//当前元素出发的第一条边入栈
	Edge *E = u->head;
	if(E)
		S.push(E);
	while(!S.empty())
	{
		//取栈顶元素
		Edge *e = S.top();
		//检查和栈顶元素相邻的每个顶点v
		Vertex *v = G->V[e->end];
		//如果顶点为白色
		if(v->color == WHITE)
		{
			//递归访问顶点
			v->color = GRAY;
			depth++;
			v->d = depth;
			v->p = u;
			e->type = 1;
			//将下一条边入栈，下一条边可能有两种情况
			if(v->head)
				S.push(v->head);
			else
			{
				while(e && e->next == NULL)
				{
					depth++;
					G->V[e->end]->f = depth;
					G->V[e->end]->color = BLACK;
					S.pop();
					if(S.empty())e = NULL;
					else e = S.top();
				}
				if(e && e->next)
					S.push(e->next);
			}

		}
		else
		{
			//判断边的类型
			if(v->color == BLACK)
			{
				if(u->d < v->d)
					e->type = 3;
				else
					e->type = 4;
			}
			else if(v->color == GRAY)
				e->type = 2;
			//出栈，并将下一条边入栈
			while(e && e->next == NULL)
			{
				depth++;
				G->V[e->start]->f = depth;
				G->V[e->start]->color = BLACK;
				S.pop();
				if(S.empty())e = NULL;
				else e = S.top();
			}
			if(e && e->next)
			{
				S.pop();
				S.push(e->next);
			}
		}
	}
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
	depth = 0;
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
