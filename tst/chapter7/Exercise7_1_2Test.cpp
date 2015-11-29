/*************************************************************************
    > File Name: Exercise7_1_2Test.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Sun 29 Nov 2015 11:25:50 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include "gtest/gtest.h"
#include "Exercise7_1_2.h"

TEST(quick_sort_7_1_2, one_data_should_not_error)
{
	int data[] = {1};
	QuickSort7_1_2(data, 0, 0);
	EXPECT_EQ(1, data[0]);
}

TEST(quick_sort_7_1_2, two_data_should_sort)
{
	int data[] = {2, 1};
	QuickSort7_1_2(data, 0, 1);
	EXPECT_EQ(1, data[0]);
	EXPECT_EQ(2, data[1]);
}
