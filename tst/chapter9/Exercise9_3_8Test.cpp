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

