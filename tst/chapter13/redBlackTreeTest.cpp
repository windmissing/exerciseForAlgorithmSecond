#include <iostream>
using namespace std;

#include "gtest/gtest.h"
#include "redBlackTree.h"

TEST(initTree, rootShouldBeNull)
{
	CRedBlackTree tree;
	EXPECT_TRUE(CRedBlackTree::isNodeNull(tree.root));
}

TEST(initTree, shouldBeEmpty)
{
	CRedBlackTree tree;
	EXPECT_TRUE(CRedBlackTree::isNodeNull(tree.search(5)));
}

TEST(insert, shouldBeFound)
{
	CRedBlackTree tree;
	tree.insert(5);
	EXPECT_FALSE(CRedBlackTree::isNodeNull(tree.search(5)));
}

TEST(insert, allShouldBeFound)
{
	CRedBlackTree tree;
	tree.insert(5);
	tree.insert(6);
	tree.insert(4);
	EXPECT_FALSE(CRedBlackTree::isNodeNull(tree.search(4)));
	EXPECT_FALSE(CRedBlackTree::isNodeNull(tree.search(5)));
	EXPECT_FALSE(CRedBlackTree::isNodeNull(tree.search(6)));
}

TEST(remove, removeRootShouldEmpty)
{
	CRedBlackTree tree;
	tree.insert(5);
	tree.remove(tree.search(5));
	EXPECT_TRUE(CRedBlackTree::isNodeNull(tree.root));
}

TEST(remove, removeDataShouldNotFound)
{
	CRedBlackTree tree;
	tree.insert(5);
	tree.remove(tree.search(5));
	EXPECT_TRUE(CRedBlackTree::isNodeNull(tree.search(5)));
}

TEST(remove, unremoveDataShouldFound)
{
	CRedBlackTree tree;
	tree.insert(5);
	tree.insert(4);
	tree.remove(tree.search(5));
	EXPECT_FALSE(CRedBlackTree::isNodeNull(tree.search(4)));
}

TEST(remove, allUnremoveDataShouldFound)
{
	CRedBlackTree tree;
	tree.insert(5);
	tree.insert(4);
	tree.insert(6);
	tree.remove(tree.search(5));
	EXPECT_FALSE(CRedBlackTree::isNodeNull(tree.search(4)));
	EXPECT_FALSE(CRedBlackTree::isNodeNull(tree.search(6)));
}

