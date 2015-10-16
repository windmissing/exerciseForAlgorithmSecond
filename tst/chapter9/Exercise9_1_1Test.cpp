#include <iostream>
using namespace std;

#include "Chapter9.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"
// Tests factorial of negative numbers.
//
using ::testing::_;
using ::testing::SetArgPointee;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::Pointee;

vector<int> initArray(int *data, int len)
{
	vector<int> ret;
	for(int i = 0; i < len; i++)
		ret.push_back(data[i]);
	return ret;
}

TEST(noInput, shouleReturn0)
{
	vector<int> array;
	EXPECT_EQ(0, solve9_1_1(array));
}

TEST(oneData, shouleReturn0)
{
	int data[1] = {1};
	vector<int> array = initArray(data, 1);
	EXPECT_EQ(0, solve9_1_1(array));
	cout<<solve9_1_1(array)<<endl;
}

TEST(evenDataCount, secondDataInFirst)
{
	int data[4] = {2, 1, 3, 4};
	vector<int> array = initArray(data, 4);
	EXPECT_EQ(2, solve9_1_1(array));
}

TEST(evenDataCount, secondDataInLast)
{
	int data[4] = {1, 3, 4, 2};
	vector<int> array = initArray(data, 4);
	EXPECT_EQ(2, solve9_1_1(array));
}

TEST(evenDataCount, secondDataInSecond)
{
	int data[4] = {1, 2, 4, 3};
	vector<int> array = initArray(data, 4);
	EXPECT_EQ(2, solve9_1_1(array));
}

TEST(evenDataCount, secondDataInSecondLast)
{
	int data[4] = {1, 4, 2, 3};
	vector<int> array = initArray(data, 4);
	EXPECT_EQ(2, solve9_1_1(array));
}

TEST(oddDataCount, secondDataInFirst)
{
	int data[5] = {2, 1, 4, 5, 3};
	vector<int> array = initArray(data, 5);
	EXPECT_EQ(2, solve9_1_1(array));
}

TEST(oddDataCount, secondDataInLast)
{
	int data[5] = {3, 1, 4, 5, 2};
	vector<int> array = initArray(data, 5);
	EXPECT_EQ(2, solve9_1_1(array));
}
