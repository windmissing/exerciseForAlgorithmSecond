#include "gtest/gtest.h"

using namespace std;
#include "Exercise22_3_6.h"
#include <vector>
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

#define     NUMOF(x)        (sizeof(x)/sizeof(*(x)))

class G_for_test : public Graph
{
public:
	void inputTestData(vector<int> v);
};

vector<int> data2Vector(char *data, int len)
{
	vector<int> ret;
	for(int i = 0; i < len; i++)
		ret.push_back(data[i] - 'p');
	return ret;
}

void G_for_test::inputTestData(vector<int> v)
{
	for(int i = 1; i <= v.size(); i+=2)
	{
		Edge *E = new Edge(v[i], v[i+1]);
		InsertEdge(this, E);
		//无向图，要加两条边
//		E = new Edge(end, start);
//		InsertEdge(this, E);
	}
}

TEST(data_in_book, data_in_book)
{
	char data[] = 
	{
		'q', 's',
		's', 'v',
		'v', 'w',
		'w', 's',
		'q', 'w',
		'q', 't',
		't', 'y',
		'y', 'q',
		't', 'x',
		'x', 'z',
		'z', 'x',
		'u', 'y',
		'r', 'y',
		'r', 'u'
	};
	vector<int> v = data2Vector(data, NUMOF(data));
	G_for_test *G = new G_for_test();
	G->inputTestData(v);
	//DFS(G);
}
#if 0
int main()
{
	//构造一个空的图
	Graph *G = new Graph;
	Print(G);
	//输入边
	int i;
	char start, end;
	for(i = 1; i <= 14; i++)
	{
		cin>>start>>end;
		E = new Edge(start-'p', end-'p');
		InsertEdge(G, E);
		//无向图，要加两条边
//		E = new Edge(end, start);
//		InsertEdge(G, E);
	}
	Print(G);
	//深度优先搜索
	DFS(G);
	//输出每个顶点的第一次访问时间和访问结束的时间
	for(i = 1; i <= N; i++)
	{
		cout<<char('p'+i)<<':';
		cout<<G->V[i]->d<<' '<<G->V[i]->f<<endl;
	}
	for(i = 1; i <= N; i++)
	{
		Edge *e = G->V[i]->head;
		while(e)
		{
			cout<<char(e->start+'p')<<"->"<<char(e->end+'p')<<": ";
			switch (e->type)
			{
			case 1:
				cout<<"树边"<<endl;
				break;
			case 2:
				cout<<"反向边"<<endl;
				break;
			case 3:
				cout<<"正向边"<<endl;
				break;
			case 4:
				cout<<"交叉边"<<endl;
				break;
			}
			e = e->next;
		}
	}
	return 0;
}
#endif
