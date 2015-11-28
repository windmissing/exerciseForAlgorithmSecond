/*************************************************************************
    > File Name: section14_1.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Mon 23 Nov 2015 07:53:37 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define BLACK 0
#define RED 1

//红黑树结点结构
struct ostNode
{
	//红黑树的基础结构
	ostNode *left;
	ostNode *right;
	ostNode *parent;
	int key;
	int info;
	bool color;
	int size;//以x为根的子树的（内部）结点数（包括x本身），即子树的大小
	ostNode *init;
	ostNode(ostNode *init, int k)
		:init(init),left(init),right(init),parent(init),key(k),color(BLACK),size(1){}
	~ostNode()
	{
		if(left != init) delete left;
		if(right != init) delete right;
	}
};
//顺序统计量树结构
class Os_Tree
{
#ifdef __UT__
public:
#else
private:
#endif
	ostNode *root;//根结点
	static ostNode *nil;//哨兵
	ostNode *getPositionToInsert(ostNode *z);
	void insertChild(ostNode *parent, ostNode *child);
	ostNode *search(ostNode *x, int k);
	ostNode * findTheNodeToRemove(ostNode *z);
	void removeReally(ostNode *toRemove);
	ostNode *getChild(ostNode *parent);
	ostNode *successor(ostNode *x);
	ostNode *minimum(ostNode *x);
	void insertFixup(ostNode *z);
	void leftRotate(ostNode *x);
	void rightRotate(ostNode *x);
	void removeFixup(ostNode *x);
	ostNode *select(ostNode *x, int i);
public:
	Os_Tree(){nil->size = 0;root = nil;};
	~Os_Tree();
	void insert(int key, int info /* = 0 */);
	ostNode *search(int k);
	ostNode *remove(ostNode *z);
	static bool isNodeNull(ostNode *z);
	ostNode *select(int i);
};


