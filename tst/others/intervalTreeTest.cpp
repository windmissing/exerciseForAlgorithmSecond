#include <iostream>
using namespace std;

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "intervalTree.h"
// Tests factorial of negative numbers.
//
using ::testing::_;
using ::testing::SetArgPointee;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::Pointee;

#if 0
#include <iostream>
#include "Interval_Tree.h"
using namespace std;

int main()
{
	char ch;
	int x, y;
	//生成一棵顺序统计树
	Interval_Tree *T = new Interval_Tree;
	while(1)
	{
		cin>>ch;
		switch(ch)
		{
			//插入一个元素
		case 'I':
			{
				//cin>>x>>y;
				x = rand() % 100;
				y = rand() % 100;
				if(x > y)swap(x, y);
				node *z = new node(T->nil, x, y);
				T->Insert(z);
				break;
			}
			//删除一个元素
		case 'D':
			{
				cin>>x;
				node *z = T->Search(T->root, x);
				if(z == NULL)
					cout<<"not exist"<<endl;
				else
					T->Delete(z);
				break;
			}
			//求第一个与[x,y]相交的区间
		case 'S':
			{
				cin>>x>>y;
				node *z = T->Interval_Search(interval(x, y));
				if(z == NULL)
					cout<<"not exist"<<endl;
				else
					cout<<z->inte.low<<' '<<z->inte.high<<endl;
				break;
			}
		case 'P':
			T->Print();
			break;
		default:
			break;
		}
	}
	return 0;
}
#endif
#if 0
/*
static bool nodeCanBeFound(const CRedBlackTree & tree, int key)
{
	node * ret = tree.search(key);
	return CRedBlackTree::isNodeNull(ret);
}
*/
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
#endif
