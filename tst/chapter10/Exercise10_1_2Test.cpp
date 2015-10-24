/*************************************************************************
    > File Name: Exercise10_1_2.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Sat 24 Oct 2015 03:57:06 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include "gtest/gtest.h"
#include "Exercise10_1_2.h"

#define     NUMOF(x)        (sizeof(x)/sizeof(*(x)))

TEST(no_operation, both_should_be_empty)
{
	arrayWithTwoStack S(5);
	EXPECT_TRUE(S.isEmpty(0));
	EXPECT_TRUE(S.isEmpty(1));
}

TEST(push_one_data_one_stack, one_stack_not_empty)
{
	arrayWithTwoStack S(5);
	S.push(1, 1);
	EXPECT_TRUE(S.isEmpty(0));
	EXPECT_FALSE(S.isEmpty(1));
}

TEST(pop_when_not_empty, should_get_latest_data)
{
	arrayWithTwoStack S(5);
	S.push(0, 1);
	S.push(1, 2);
	EXPECT_EQ(1, S.pop(0));
	EXPECT_EQ(2, S.pop(1));
}
