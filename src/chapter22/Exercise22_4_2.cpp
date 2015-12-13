#include <iostream>
using namespace std;
#include <queue>
#include "Exercise22_4_2.h"
using namespace exercise22_4_2;

namespace exercise22_4_2
{
//插入边
void Graph::InsertEdge(Edge *E)
{
	V[E->end]->indegree++;
	//如果没有相同起点的边
	if(V[E->start]->head == NULL)
		V[E->start]->head =E;
	//如果有，加入到链表中，递增顺序排列，便于查重
	else
	{
		//链表的插入，不解释
		Edge *e1 = V[E->start]->head, *e2 = e1;
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
			V[E->start]->head =E;
		}
		else
		{
			e2->next = E;
			E->next = e1;
		}
	}
}

int Graph::countWays(int start, int end)
{
	int count[MAX_NUM_OF_VERTEX+1] = {0};
	count[start] = 1;
	queue <int> Q;
	for(int i = 1;i <= numOfVertex; i++ )
	{
		if(V[i]->indegree == 0)
			Q.push(i);
	}
	while(Q.empty() == false)
	{
		int q = Q.front();
		Q.pop();
		if(q == end)
			return count[q];
		Edge *head = V[q]->head;
		while(head != NULL)
		{
			V[head->end]->indegree--;
			count[head->end] += count[q];
			if(V[head->end]->indegree == 0)
				Q.push(head->end);
			head = head->next;
		}
	}
	return 0;
}
};
