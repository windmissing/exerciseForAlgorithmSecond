#include "gtest/gtest.h"

using namespace std;
#include <vector>
#include "Exercise22_4_2.h"

#define     NUMOF(x)        (sizeof(x)/sizeof(*(x)))

using namespace exercise22_4_2;
class G_test_22_4_2 : public Graph
{
public:
	G_test_22_4_2(int n):Graph(n){}
	void inputTestData(vector<int> v);
};

static vector<int> data2Vector(char *data, int len)
{
	vector<int> ret;
	for(int i = 0; i < len; i++)
		ret.push_back(data[i] - 'l');
	return ret;
}

void G_test_22_4_2::inputTestData(vector<int> v)
{
	for(int i = 0; i < v.size(); i+=2)
	{
		Edge *E = new Edge(v[i], v[i+1]);
		InsertEdge(E);
	}
}

TEST(empty_graph, result_should_be_0)
{
	G_test_22_4_2 *G = new G_test_22_4_2(0);
	EXPECT_EQ(0, G->countWays(0, 0));
	delete G;
}

TEST(data_in_book, result_should_be_4)
{
	char data[] = 
	{
		'm', 'q',
		'm', 'r',
		'm', 'x',
		'n', 'q',
		'n', 'u',
		'n', 'o',
		'o', 'r',
		'o', 's',
		'o', 'v',
		'p', 'o',
		'p', 'z',
		'q', 't',
		'r', 'y',
		'r', 'u',
		's', 'r',
		'v', 'x',
		'v', 'w',
		'w', 'z',
		'y', 'v'
	};
	vector<int> v = data2Vector(data, NUMOF(data));
	G_test_22_4_2 *G = new G_test_22_4_2(14);
	G->inputTestData(v);
	EXPECT_EQ(3, G->countWays(4, 10));
	delete G;
}
