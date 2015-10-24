/*************************************************************************
    > File Name: Exercise16_2_6.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Thu 22 Oct 2015 06:21:45 PM CST
 ************************************************************************/
#include "gtest/gtest.h"
#include "Exercise16_2_6.h"

#define     NUMOF(x)        (sizeof(x)/sizeof(*(x)))

TEST(no_material, empty)
{
	EXPECT_EQ(0, partialPackage(0, 0, NULL));
	EXPECT_EQ(0, partialPackage(5, 0, NULL));
}

TEST(very_small_package, empty)
{
	node material[] = {{0, 0},
		               {3, 5},
	                   {2, 4},
	                   {1, 7}};
	EXPECT_EQ(0, partialPackage(0, NUMOF(material), material));
}

TEST(very_small_package, half_of_one)
{
	node material[] = {{0, 0},
		               {3, 5},
	                   {2, 4},
	                   {2, 7}};
	EXPECT_EQ(3.5, partialPackage(1, NUMOF(material), material));
}

TEST(very_big_package, only_one_material)
{
	node material[] = {{0, 0},
	                   {1, 7}};
	EXPECT_EQ(7, partialPackage(100, NUMOF(material), material));
}

TEST(very_big_package, more_than_one_material)
{
	node material[] = {{0, 0},
		               {3, 5},
	                   {2, 4},
	                   {1, 7}};
	EXPECT_EQ(16, partialPackage(100, NUMOF(material), material));
}

TEST(not_enough_package, one_and_half)
{
	node material[] = {{0, 0},
		               {3, 5},
	                   {2, 4},
	                   {2, 7}};
	EXPECT_EQ(9, partialPackage(3, NUMOF(material), material));
}

