#include "gtest/gtest.h"

using namespace std;
#include <vector>

#include "Exercise22_3_6.h"

#define     NUMOF(x)        (sizeof(x)/sizeof(*(x)))

class G_for_test : public Graph
{
public:
	void inputTestData(vector<int> v);
	void testVisitTime(int vId, int start, int end);
	void testEdgeType(int *type, int len);
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
	for(int i = 0; i < v.size(); i+=2)
	{
		Edge *E = new Edge(v[i], v[i+1]);
		InsertEdge(this, E);
		//无向图，要加两条边
//		E = new Edge(end, start);
//		InsertEdge(this, E);
	}
}

void G_for_test::testVisitTime(int vId, int start, int end)
{
	EXPECT_EQ(start, V[vId]->d);
	EXPECT_EQ(end, V[vId]->f);
}

/*
 * 1:"树边" 2:"反向边" 3:"正向边" 4:"交叉边"
 * */
void G_for_test::testEdgeType(int *type, int len)
{
	int cnt = 0;
	for(int i = 1; i <= N; i++)
	{
		Edge *e = V[i]->head;
		while(e)
		{
			EXPECT_EQ(type[cnt], e->type) << e->start << ' '<< e->end <<' '<<e->type;
			cnt++;
			if(cnt >= len)break;
			e = e->next;
		}
		if(cnt >= len)break;
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
	DFS(G);
	G->testVisitTime(1, 1, 16);
	G->testVisitTime(2, 17, 20);
	G->testVisitTime(3, 2, 7);
	G->testVisitTime(4, 8, 15);
	G->testVisitTime(5, 18, 19);
	G->testVisitTime(6, 3, 6);
	G->testVisitTime(7, 4, 5);
	G->testVisitTime(8, 9, 12);
	G->testVisitTime(9, 13, 14);
	G->testVisitTime(10, 10, 11);

	int edgeType[] = {1, 1, 3, 1, 4, 1, 1, 1, 4, 1, 2, 1, 2, 2};
	G->testEdgeType(edgeType, NUMOF(edgeType));
	delete G;
}
