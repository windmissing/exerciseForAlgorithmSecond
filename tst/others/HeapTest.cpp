#include <iostream>
using namespace std;

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Heap.h"
// Tests factorial of negative numbers.
//
using ::testing::_;
using ::testing::SetArgPointee;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::Pointee;

TEST(initHeap, currentSizeShouldBe0)
{
	CMaxHeap<int> H;
	EXPECT_EQ(0, H.currentSize);
}

TEST(initHeapWithSize, currentSizeShouldBe0)
{
	CMaxHeap<int> H(5, 0x7FFFFFFF);
	EXPECT_EQ(0, H.currentSize);
	EXPECT_EQ(5, H.maxSize);
}

TEST(initHeapWithMaxNode, allDataSetToMaxNode)
{
	CMaxHeap<int> H(5, 0x7FFFFFFF);
	for(int i = 0; i < H.maxSize; i++)
		EXPECT_EQ(0x7FFFFFFF, H.A[i]);
}

TEST(getMaxData, noDataShouldTheMaxNode)
{
	CMaxHeap<int> H(5, 0x7FFFFFFF);
	EXPECT_EQ(0x7FFFFFFF, H.Heap_Maximum());
}

TEST(getMaxData, oneDataShouldGetTheData)
{
	CMaxHeap<int> H(5, 0x7FFFFFFF);
	H.insert(3);
	EXPECT_EQ(3, H.Heap_Maximum());
}
