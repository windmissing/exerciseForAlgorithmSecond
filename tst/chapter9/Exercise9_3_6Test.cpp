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

static bool compareArray(const ARRAY & a, const ARRAY & b)
{
	if(a.size() != b.size())
		return false;
	for(int i = 0; i < a.size(); i++)
		if(a[i] != b[i])
			return false;
	return true;
}

static ARRAY setArray(int *initData, int len) 
{
	ARRAY ret;
	for(int i = 0; i < len; i++)
		ret.push_back(initData[i]);
	return ret;
}

static void printArray(const ARRAY & array)
{
	for(int i = 0; i < array.size(); i++)
		cout<<array[i]<<' ';
	cout<<endl;
}

TEST(noResult, noData)
{
	CArrayFor_9_3_6 array(0);
	ARRAY ret = solve9_3_6(array, 5);
	EXPECT_EQ(0, ret.size());
}

TEST(noResult, divideInto0Parts)
{
	const int initData[5] = {1, 2, 3, 4, 5};
	CArrayFor_9_3_6 array(initData, 5);

	ARRAY ret = solve9_3_6(array, 0);
	EXPECT_EQ(0, ret.size());
}

TEST(noResult, canNotDivideEqually)
{
	const int initData[5] = {1, 2, 3, 4, 5};
	CArrayFor_9_3_6 array(initData, 5);

	ARRAY ret = solve9_3_6(array, 3);
	EXPECT_EQ(0, ret.size());
}

TEST(noResult, oneDataDivideIntoOnePart)
{
	const int initData[1] = {3};
	CArrayFor_9_3_6 array(initData, 1);
	ARRAY expect;

	ARRAY ret = solve9_3_6(array, 1);

	EXPECT_TRUE(compareArray(expect, ret));
}

TEST(noResult, divideIntoOnePart)
{
	const int initData[5] = {1, 2, 3, 4, 5};
	CArrayFor_9_3_6 array(initData, 5);
	ARRAY expect;

	ARRAY ret = solve9_3_6(array, 1);
	EXPECT_TRUE(compareArray(expect, ret));
}

TEST(divideByTwoPart, oddCountShoutGetNothing)
{
	const int initData[5] = {1, 2, 3, 4, 5};
	CArrayFor_9_3_6 array(initData, 5);
	ARRAY expect;

	ARRAY ret = solve9_3_6(array, 2);
	EXPECT_TRUE(compareArray(expect, ret));
}

TEST(divideByTwoPart, evenCountShoutGetTheUpMiddle)
{
	const int initData[6] = {1, 2, 3, 4, 5, 6};
	CArrayFor_9_3_6 array(initData, 6);
	int expectData[1] = {3};
	ARRAY expect = setArray(expectData, 1);

	ARRAY ret = solve9_3_6(array, 2);
	EXPECT_TRUE(compareArray(expect, ret));
}

TEST(divideInto1Size, threeCountDivideIntoThreePartShoutGetFirstTwo)
{
	const int initData[3] = {1, 2, 3};
	CArrayFor_9_3_6 array(initData, 3);
	int expectData[2] = {1, 2};
	ARRAY expect = setArray(expectData, 2);

	ARRAY ret = solve9_3_6(array, 3);
	EXPECT_TRUE(compareArray(expect, ret));
}
TEST(divideInto1Size, getAllDataExceptLastOne)
{
	const int initData[5] = {1, 2, 3, 4, 5};
	CArrayFor_9_3_6 array(initData, 5);
	int expectData[4] = {1, 2, 3, 4};
	ARRAY expect = setArray(expectData, 4);

	ARRAY ret = solve9_3_6(array, 5);
	EXPECT_TRUE(compareArray(expect, ret));
//	printArray(ret);
}
#if 0
TEST(one_data_each_array, get_the_bigger_one)
{
	int a[1] = {3};
	int b[1] = {5};
	CArrayFor_9_3_8 A(a, 1), B(b, 1);

	EXPECT_EQ(5, solve_9_3_8(A, B));
	EXPECT_EQ(5, solve_9_3_8(B, A));
}

TEST(two_data_each_array, get_the_less_bigger_one_1)
{
	int a[2] = {1, 2};
	int b[2] = {3, 4};
	CArrayFor_9_3_8 A(a, 2), B(b, 2);

	EXPECT_EQ(3, solve_9_3_8(A, B));
}

TEST(two_data_each_array, get_the_less_bigger_one_2)
{
	int a[2] = {1, 3};
	int b[2] = {2, 4};
	CArrayFor_9_3_8 A(a, 2), B(b, 2);

	EXPECT_EQ(3, solve_9_3_8(A, B));
}

TEST(three_data_each_array, get_the_third_bigger_one_1)
{
	int a[3] = {1, 3, 5};
	int b[3] = {2, 4, 6};
	CArrayFor_9_3_8 A(a, 3), B(b, 3);

	EXPECT_EQ(4, solve_9_3_8(A, B));
}

TEST(three_data_each_array, get_the_third_bigger_one_2)
{
	int a[3] = {1, 2, 3};
	int b[3] = {4, 5, 6};
	CArrayFor_9_3_8 A(a, 3), B(b, 3);

	EXPECT_EQ(4, solve_9_3_8(A, B));
}

int regularMethod(CArrayFor_9_3_8 A, CArrayFor_9_3_8 B)
{
	CArrayFor_9_3_8 C = A;
	C.insertArray(B);
	C.sortData();
	return C.getDownMiddle();
}

TEST(radom_data_each_array, test)
{
	CArrayFor_9_3_8 A(5), B(5);
	A.makeRadomData();
	B.makeRadomData();
	int expectResult = regularMethod(A, B);

	EXPECT_EQ(expectResult, solve_9_3_8(A, B));
}
#endif
