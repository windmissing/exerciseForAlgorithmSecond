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

#include "sort.h"

static ARRAY setArray(int *initArray, int len)
{
	ARRAY ret;
	for(int i = 0; i < len; i++)
	{
		ret.push_back(initArray[i]);
	}
	return ret;
}

static bool compare(ARRAY A, ARRAY B)
{
	if(A.size() != B.size())
		return false;
	for(int i = 0; i < A.size(); i++)
		if(A[i] != B[i])
			return false;
	return true;
}

void printArray(ARRAY array)
{
	for(int i = 0; i < array.size(); i++)
		cout<<array[i]<<' ';
	cout<<endl;
}

TEST(only_one_data_in_array, arrayShouldNotChange)
{
	int initArray[1] = {5};
	ARRAY array = setArray(initArray, 1);
	ARRAY expect = setArray(initArray, 1);

	radixSort(array, 2);
	EXPECT_TRUE(compare(expect, array));
}

TEST(allDataHaveOneDigit, smallerShouldBeFirst)
{
	int initArray[2] = {6, 5};
	ARRAY array = setArray(initArray, 2);
	int expectArray[2] = {5, 6};
	ARRAY expect = setArray(expectArray, 2);

	radixSort(array, 2);
	EXPECT_TRUE(compare(expect, array));
}

TEST(dataHaveDifferentDigit, lessDigitShouldBeFirst)
{
	int initArray[2] = {55, 5};
	ARRAY array = setArray(initArray, 2);
	int expectArray[2] = {5, 55};
	ARRAY expect = setArray(expectArray, 2);

	radixSort(array, 2);
	EXPECT_TRUE(compare(expect, array));
}

TEST(dataHaveDifferentDigit, moreDataTest)
{
	int initArray[4] = {55, 5, 123, 0};
	ARRAY array = setArray(initArray, 4);
	int expectArray[4] = {0, 5, 55, 123};
	ARRAY expect = setArray(expectArray, 4);

	radixSort(array, 3);
	EXPECT_TRUE(compare(expect, array));
}

TEST(sortLastDigit, onlyLastDigitSort)
{
	int initArray[4] = {55, 5, 123, 0};
	ARRAY array = setArray(initArray, 4);
	int expectArray[4] = {0, 123, 55, 5};
	ARRAY expect = setArray(expectArray, 4);

	radixSort(array, 1);
	EXPECT_TRUE(compare(expect, array));
}
