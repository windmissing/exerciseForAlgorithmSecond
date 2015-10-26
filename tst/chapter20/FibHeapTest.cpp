/*************************************************************************
    > File Name: chapter20/fibHeapTest.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Sun 25 Oct 2015 10:32:19 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include "gtest/gtest.h"
#include "FibHeap.h"

TEST(initFibHeap, currentSizeShouldBe0)
{
	CFibHeap H;
	EXPECT_EQ(0, H.getDataCount());
}

TEST(getTopData, oneDataShouldGetTheData)
{
	CFibHeap H;
	node *pN = new node(3);
	EXPECT_EQ(SUCCESS, H.insert(pN));
	node *pTop = H.extract();
	EXPECT_EQ(3, pTop->key);
	delete pTop;
}

TEST(merge, merge)
{
	CFibHeap H1;
	node *pN1 = new node(5);
	H1.insert(pN1);

	CFibHeap H2;
	node *pN2 = new node(3);
	H2.insert(pN2);

	EXPECT_EQ(SUCCESS, H1.merge(&H2));

	node *pTop = H1.extract();
	EXPECT_EQ(3, pTop->key);
	delete pTop;

	pTop = H1.extract();
	EXPECT_EQ(5, pTop->key);
	delete pTop;
}
