#include <iostream>
#include <queue>
using namespace std;

#define N 100

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define NONE 0
#define TREE 1
#define BACK 2
#define FORWARD 3
#define CROSS 4

struct Edge
{
	int start;
	int end;
	int value;
	int type;
	Edge *next;
	Edge(int s, int e, int v)
		:start(s),end(e),value(v),type(NONE),next(NULL){}
};
struct Vertex
{
	int d, f;//第一次被发现的时间和结束检查的时间
	int color;//顶点的颜色
	int p;//指向遍历结果的父结点
	Edge *head;//指向以该顶点为起点的下一条边
	Vertex():color(WHITE),p(0),head(NULL){};
};
class Link_Graph
{
public:
	int time;
	int n;
	Vertex *V;
	Link_Graph(int num):n(num)
	{
		V = new Vertex[n+1];
	}
	~Link_Graph(){delete []V;}
	void AddSingleEdge(int start, int end, int value = 1)
	{
		Edge *NewEdge = new Edge(start, end, value);
		if(V[start].head == NULL || V[start].head->end > end)
		{
			NewEdge->next = V[start].head;
			V[start].head = NewEdge;
		}
		else
		{
			Edge *e = V[start].head, *pre = e;
			while(e != NULL && e->end < end)
			{
				pre = e;
				e = e->next;
			}
			if(e && e->end == end)
			{
				delete NewEdge;
				return;
			}
			NewEdge->next = e;
			pre->next = NewEdge;
		}
	}
	void AddDoubleEdge(int a, int b, int value = 1)
	{
		AddSingleEdge(a, b, value);
		AddSingleEdge(b, a, value);
	}
	void DeleteSingleEdge(int start, int end)
	{
		Edge *e = V[start].head, *pre = e;
		while(e && e->end < end)
		{
			pre = e;
			e = e->next;
		}
		if(e == NULL || e->end > end) return;
		if(e == V[start].head)
			V[start].head = e->next;
		else
			pre->next = e->next;
		delete e;
	}
	void DeleteDoubleEdge(int a, int b)
	{
		DeleteSingleEdge(a, b);
		DeleteSingleEdge(b, a);
	}
	//22.3
	void DFS();
	void DFS_Visit(int u);
	void Print_Vertex_Time();
	void Print_Edge_Type();
};

void Link_Graph::DFS()
{
	int u;
	//对每个顶点初始化
	for(u = 1; u <= n; u++)
	{
		V[u].color = WHITE;
		V[u].p =  NULL;
	}
	//时间戳初始化
	time = 0;
	//依次检索V中的顶点，发现白色顶点时，调用DFS_Visit访问该顶点
	for(u = 1; u <= n; u++)
		if(V[u].color == WHITE)
			DFS_Visit(u);
}

void Link_Graph::DFS_Visit(int u)
{
	int v;
	Edge *e;
	//将u置为灰色
	V[u].color = GRAY;
	//使全局变量time增值
	time++;
	//将time的新值记录为发现时间
	V[u].d = time;
	e = V[u].head;
	while(e)
	{
		v = e->end;
		//如果顶点为白色
		if(V[v].color == WHITE)
		{
			//递归访问顶点
			V[v].p = u;
			DFS_Visit(v);
			//树边
			e->type = TREE;
		}
		else if(V[v].color == GRAY)
		{
			//反向边
			e->type = BACK;
		}
		else if(V[v].color == BLACK)
		{
			//正向边
			if(V[u].d < V[v].d)
				e->type = FORWARD;
			//交叉边
			else
				e->type = CROSS;
		}
		e = e->next;
	}
	//以u为起点的所有边都被探寻后，置u为黑色
	V[u].color = BLACK;
	//并将完成时间记录在f[u]中
	time++;
	V[u].f = time;
}

void Link_Graph::Print_Vertex_Time()
{
	int i;
	for(i = 1; i <= n; i++)  
    {  
		//因为书中的例子中用从q开始的字母编号的，所以输出的时候有这样一个转换
        cout<<char('p'+i)<<':';  
        cout<<V[i].d<<' '<<V[i].f<<endl;  
    }  
}

void Link_Graph::Print_Edge_Type()
{
	int i;
	for(i = 1; i <= n; i++)  
    {  
        Edge *e = V[i].head;  
        while(e)  
        {  
            cout<<char(e->start+'p')<<"->"<<char(e->end+'p')<<": ";  
            switch (e->type)  
            {  
            case TREE:  
                cout<<"树边"<<endl;  
                break;  
            case BACK:  
                cout<<"反向边"<<endl;  
                break;  
            case FORWARD:  
                cout<<"正向边"<<endl;  
                break;  
            case CROSS:  
                cout<<"交叉边"<<endl;  
                break;  
            }  
            e = e->next;  
        }  
    }  
}
