/*************************************************************************
    > File Name: chapter7/quickSortTest.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Sat 24 Oct 2015 12:12:04 PM CST
 ************************************************************************/
#include "gtest/gtest.h"
#include "quickSort.h"

#define     NUMOF(x)        (sizeof(x)/sizeof(*(x)))

bool check_equal(int *src, int *dst, int len)
{
	for(int i = 0; i < len; i++)
		if(src[i] != dst[i])
			return false;
	return true;
}

TEST(no_data_to_sort, no_error)
{
	int src[] = {};
	QuickSort(src, 1, NUMOF(src) - 1);
	Randomized_QuickSort(src, 1, NUMOF(src) - 1);
}

TEST(one_data_to_sort, data_not_change)
{
	int src[] = {0, 1};
	int dst[] = {0, 1};
	QuickSort(src, 1, NUMOF(src) -1);
	EXPECT_TRUE(check_equal(src, dst, NUMOF(src)));

	int src2[] = {0, 1};
	Randomized_QuickSort(src2, 1, NUMOF(src) - 1);
	EXPECT_TRUE(check_equal(src2, dst, NUMOF(src)));
}

TEST(more_than_one_data_to_sort, data_sorted)
{
	int src[] = {0, 1, 4, 7, 6, 2};
	int dst[] = {0, 1, 2, 4, 6, 7};
	QuickSort(src, 1, NUMOF(src) -1);
	EXPECT_TRUE(check_equal(src, dst, NUMOF(src)));

	int src2[] = {0, 1, 4, 7, 6, 2};
	Randomized_QuickSort(src2, 1, NUMOF(src) - 1);
	EXPECT_TRUE(check_equal(src2, dst, NUMOF(src)));
}

TEST(more_than_one_data_to_sort, with_same_data)
{
	int src[] = {0, 1, 4, 6, 6, 2};
	int dst[] = {0, 1, 2, 4, 6, 6};
	QuickSort(src, 1, NUMOF(src) -1);
	EXPECT_TRUE(check_equal(src, dst, NUMOF(src)));

	int src2[] = {0, 1, 4, 6, 6, 2};
	Randomized_QuickSort(src2, 1, NUMOF(src) - 1);
	EXPECT_TRUE(check_equal(src2, dst, NUMOF(src)));
}

//void QuickSort(int *A, int p, int r)
