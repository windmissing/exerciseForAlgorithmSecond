#include "gtest/gtest.h"

#include <cmath>

#include "Exercise15_1.h"
/*
1 1 
2 7 
3 4 
6 3 
7 6 
8 2 
9 5
*/

#define     NUMOF(x)        (sizeof(x)/sizeof(*(x)))

static vector<coord> data2vector(int* data, int size)
{
	vector<coord> ret;
	for(int i = 0; i < size; i+=2)
	{
		coord pos = {data[i], data[i+1]};
		ret.push_back(pos);
	}
	return ret;
}
TEST(double_adjustable_euclidean_traveling_salesman, no_data_should_get_0)
{
	vector<coord> v;
	double ret = Double_adjustable_Euclidean_traveling_salesman(v);
	EXPECT_EQ(0, ret);
}

TEST(double_adjustable_euclidean_traveling_salesman, data_in_book_should_get_right_result)
{
	int data[] = {1, 1,
	            2, 7,
	            3, 4,
	            6, 3,
	            7, 6,
	            8, 2,
	            9, 5};
	vector<coord> v = data2vector(data, NUMOF(data));
	double ret = Double_adjustable_Euclidean_traveling_salesman(v);
//	EXPECT_GE(0.001, fabs(ret - 25.584));
}
