#include "gtest/gtest.h"
#include <vector>
using namespace std;

#include "MaxFlow.h"
#define     NUMOF(x)        (sizeof(x)/sizeof(*(x)))
/*
5 10
0 1 16
0 2 13
1 3 12
1 2 10
2 1 4
3 2 9
2 4 14
3 5 20
4 3 7
4 5 4
*/
struct testNode
{
	int start, end, value;
};
vector<testNode> v;

vector<testNode> data2Vector(testNode *data, int len)
{
	vector<testNode> ret;
	for(int i = 0; i < len; i++)
	{
	    ret.push_back(data[i]);
	}
	return ret;
}

class flowForTest : public Mat_Flow
{
	public:
		flowForTest(int n):Mat_Flow(n){}
		void MakeGraph(vector<testNode> v)
		{
			int start, end, value;
			for(int i = 0; i < v.size(); i++)
			{
				testNode temp = v[i];
				AddSingleEdge(temp.start, temp.end, temp.value);
			}
		}
};

TEST(case_in_book, case_in_book)
{
	testNode data[] = {{0,1,16},
		0,2,13,
		1,3,12,
		1,2,10,
		2,1,4,
		3,2,9,
		2,4,14,
		3,5,20,
		4,3,7,
		4,5,4
	};
		flowForTest *F = new flowForTest(5);
		vector<testNode> v = data2Vector(data, NUMOF(data));
		F->MakeGraph(v);
		
		EXPECT_EQ(23, F->max_flow());
		delete F;
}
