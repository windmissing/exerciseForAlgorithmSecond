#include <iostream>
using namespace std;

#include "Chapter8.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"
// Tests factorial of negative numbers.
//
using ::testing::_;
using ::testing::SetArgPointee;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::Pointee;

#define ARRAY vector<int>

static void printArray(const ARRAY& array)
{
	for(int i = 0; i < array.size(); i++)
		cout<< array[i]<<' ';
	cout<<endl;
}

ARRAY setArray(int *initArray, int len)
{
	ARRAY ret;
	for(int i = 0; i < len; i++)
		ret.push_back(initArray[i]);
	return ret;
}

bool compare(ARRAY A, ARRAY B)
{
	if(A.size() != B.size())
		return false;
	for(int i = 0; i < A.size(); i++)
		if(A[i] != B[i])
			return false;
	return true;
}

TEST(one_data, dataShouldNotChange)
{
	int initArray[1] = {1};
	vector<int> inputParam = setArray(initArray, 1);

	ARRAY result = solve8_3(inputParam);
	EXPECT_TRUE(compare(result, inputParam));
	printArray(result);
}

TEST(dataWithDifferentDigit, sortByDigitCount)
{
	int initArray[2] = {11, 1};
	vector<int> inputParam = setArray(initArray, 2);
	int expectArray[2] = {1, 11};
	ARRAY expect = setArray(expectArray, 2);

	ARRAY result = solve8_3(inputParam);
	EXPECT_TRUE(compare(expect, result));
}

TEST(moreDataWithDifferentDigit, dataShouldSort)
{
	int initArray[4] = {1234, 5, 678, 90};
	vector<int> inputParam = setArray(initArray, 4);
	int expectArray[4] = {5, 90, 678, 1234};
	ARRAY expect = setArray(expectArray, 4);

	ARRAY result = solve8_3(inputParam);
	EXPECT_TRUE(compare(expect, result));
}

TEST(allDataInOneDigit, dataShouldSort)
{
	int initArray[4] = {3, 2, 1, 0};
	vector<int> inputParam = setArray(initArray, 4);
	int expectArray[4] = {0, 1, 2, 3};
	ARRAY expect = setArray(expectArray, 4);

	ARRAY result = solve8_3(inputParam);
	EXPECT_TRUE(compare(expect, result));
}
