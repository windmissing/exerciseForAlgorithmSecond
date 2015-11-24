#include <iostream>
using namespace std;

#include "gtest/gtest.h"
#include "chapter16.h"

#define     NUMOF(x)        (sizeof(x)/sizeof(*(x)))

/*
0 0 //虚构活动a0
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
*/
/*
int main()
{
	int i;
	//输入测试数据
	for(i = 0; i <= N; i++)
	{
		A[i].id = i;
		if(i == 0){A[i].start = 0;A[i].finish = 0;}
		else cin>>A[i].start>>A[i].finish;
	}
	Reccursive_Activity_Selector(0, N);
	Greedy_Activity_Selector();
	return 0;
}*/

static vector<activity> data2vector(int* data, int len)
{
	vector<activity> ret;
	activity a = {0, 0, 0};
	ret.push_back(a);
	for(int i = 0; i < len; i+=2)
	{
		a.id = (i/2) + 1;
		a.start = data[i];
		a.finish = data[i+1];
		ret.push_back(a);
	}
	return ret;
}

TEST(greedy_activity_selector, no_activity_should_return_nothing)
{
	vector<activity> param;
	vector<int> ret = Greedy_Activity_Selector(param);
	EXPECT_EQ(0, ret.size());
}

TEST(greedy_activity_selector, test_in_book__should_result_right)
{
	int data[] = {1, 4,
		        3, 5,
				0, 6,
				5, 7,
				3, 8,
				5, 9,
				6, 10,
				8, 11,
				8, 12,
				2, 13,
				12, 14
	};
	vector<activity> param = data2vector(data, NUMOF(data));
	vector<int> ret = Greedy_Activity_Selector(param);
	int exp[] = {1, 4, 8, 11};
	EXPECT_EQ(4, ret.size());
	for(int i = 0; i < 4; i++)
	{
		EXPECT_EQ(exp[i], ret[i]);
	}
}

TEST(reccursive_activity_selector, no_activity_should_return_nothing)
{
	vector<activity> param;
	vector<int> ret = Reccursive_Activity_Selector(param);
	EXPECT_EQ(0, ret.size());
}

TEST(reccursive_activity_selector, test_in_book__should_result_right)
{
	int data[] = {1, 4,
		        3, 5,
				0, 6,
				5, 7,
				3, 8,
				5, 9,
				6, 10,
				8, 11,
				8, 12,
				2, 13,
				12, 14
	};
	vector<activity> param = data2vector(data, NUMOF(data));
	vector<int> ret = Reccursive_Activity_Selector(param);
	int exp[] = {1, 4, 8, 11};
	EXPECT_EQ(4, ret.size());
	for(int i = 0; i < 4; i++)
	{
		EXPECT_EQ(exp[i], ret[i]);
	}
}
