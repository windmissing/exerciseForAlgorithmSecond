#include <iostream>
using namespace std;

#include "gtest/gtest.h"

#include "Exercise7_6.h"

bool meet(const ARRAY & array)
{
	for(int i = 1; i < array.size(); i++)
	{
		if(array[0] > array[1])
		{
			return false;
		}
	}
	return true;
}

ARRAY setArray(int *start, int *end, int size)
{
	ARRAY ret;
	for(int i = 0; i < size; i++)
	{
		section s;
		s.start = start[i];
		s.end = end[i];
		ret.push_back(s);
	}
	return ret;
}
TEST(noData, shoudNotChange)
{
	ARRAY array;
	Exercise7_6(array);
	EXPECT_TRUE(meet(array));
}

TEST(oneData, shouldNotChange)
{
	int start[1] = {3};
	int end[1] =   {4};
	ARRAY array = setArray(start, end, 1);
	Exercise7_6(array);
	EXPECT_TRUE(meet(array));
}

TEST(twoData, dataNotEqualShouldSort)
{
	int start[2] = {3, 1};
	int end[2] =   {4, 2};
	ARRAY array = setArray(start, end, 2);
	Exercise7_6(array);
	EXPECT_TRUE(meet(array));
}

TEST(twoData, equal)
{
	int start[2] = {1, 2};
	int end[2] =   {4, 3};
	ARRAY array = setArray(start, end, 2);
	Exercise7_6(array);
	EXPECT_TRUE(meet(array));
}

TEST(moreData, a)
{
	int start[3] = {2, 7, 1};
	int end[3] =   {2, 7, 8};
	ARRAY array = setArray(start, end, 3);
	Exercise7_6(array);
	EXPECT_TRUE(meet(array));
}

TEST(moreData, b)
{
	int start[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int end[10] =   {14, 13, 12, 11, 10, 9, 8, 7, 6, 5};
	ARRAY array = setArray(start, end, 10);
	Exercise7_6(array);
	EXPECT_TRUE(meet(array));
}
