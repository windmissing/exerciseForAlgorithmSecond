#include <iostream>
using namespace std;


#include "gtest/gtest.h"
#include "gmock/gmock.h"
// Tests factorial of negative numbers.
//
using ::testing::_;
using ::testing::SetArgPointee;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::Pointee;

#include "Chapter7.h"
#if 0
ARRAY setArray(int *initArray, int len, int list)
{
	ARRAY ret;
	for(int i = 0; i < len; i++)
	{
		node newNode;
		newNode.value = initArray[i];
		newNode.list = list;
		ret.push_back(newNode);
	}
	return ret;
}

bool compare(ARRAY A, ARRAY B)
{
	if(A.size() != B.size())
		return false;
	for(int i = 0; i < A.size(); i++)
		if(A[i].value != B[i].value)
			return false;
	return true;
}

TEST(only_one_array, only_one_data_in_array)
{
	int initArray[1] = {5};
	ARRAY array = setArray(initArray, 1, 0);
	vector<ARRAY> inputParam;
	inputParam.push_back(array);

	ARRAY result = solve_6_5_8(inputParam);
	EXPECT_TRUE(compare(array, result));
}

void printArray(ARRAY array)
{
	for(int i = 0; i < array.size(); i++)
		cout<<array[i].value<<' ';
	cout<<endl;
}

TEST(two_array, only_one_data_in_array)
{
	int initArray1[1] = {5};
	ARRAY array1 = setArray(initArray1, 1, 0);
	int initArray2[1] = {4};
	ARRAY array2 = setArray(initArray2, 1, 1);
	vector<ARRAY> inputParam;
	inputParam.push_back(array1);
	inputParam.push_back(array2);

	ARRAY result = solve_6_5_8(inputParam);

	int expectArray[2] = {5, 4};
	ARRAY expect = setArray(expectArray, 2, 0);
	EXPECT_TRUE(compare(expect, result));
}

TEST(two_array, negitave_data_in_array)
{
	int initArray1[5] = {13, 10, 7, -1, -4};
	ARRAY array1 = setArray(initArray1, 5, 0);
	int initArray2[10] = {15, 14, 12, 11, 9, 8, 6, 0, -2, -3};
	ARRAY array2 = setArray(initArray2, 10, 1);
	vector<ARRAY> inputParam;
	inputParam.push_back(array1);
	inputParam.push_back(array2);

	ARRAY result = solve_6_5_8(inputParam);

	int expectArray[15] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 0, -1, -2, -3, -4};
	ARRAY expect = setArray(expectArray, 15, 0);
	EXPECT_TRUE(compare(expect, result));
}

TEST(three_array, different_data_count_in_array)
{
	int initArray1[6] = {10, 9, 8, 4, 3, 2};
	ARRAY array1 = setArray(initArray1, 6, 0);
	int initArray2[2] = {7, 1};
	ARRAY array2 = setArray(initArray2, 2, 1);
	int initArray3[4] = {6, 5, 0, -1};
	ARRAY array3 = setArray(initArray3, 4, 2);
	vector<ARRAY> inputParam;
	inputParam.push_back(array1);
	inputParam.push_back(array2);
	inputParam.push_back(array3);

	ARRAY result = solve_6_5_8(inputParam);

	int expectArray[15] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1};
	ARRAY expect = setArray(expectArray, 12, 0);
	EXPECT_TRUE(compare(expect, result));
}
#endif

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
