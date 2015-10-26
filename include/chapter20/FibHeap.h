/*************************************************************************
    > File Name: fibHeap.h
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Sun 25 Oct 2015 10:28:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

enum errorType
{
	SUCCESS = 0,
	PARAM_ERROR,
	POINTER_NULL
};

struct node  
{  
	int key;
	node *pParent; 
	node *pChild; 
	node *pLeft; 
	node *pRight;
	int degree;
	bool isOneChildDeleted;
	bool isHandled;
	node(int n)
		:key(n),pParent(NULL),pChild(NULL),pLeft(this),pRight(this),degree(0),isOneChildDeleted(false),isHandled(0){}
};

class CFibHeap
{
	int dataCount;
	node *pMinNode;

	void consolidate();
	void link(node *y, node *x);
	void moveNodeToRootList(node *pNode);
	bool isNodeInHeap(node *pNode);
	void addNodeToRootList(node *pNode);
	void addListToRootList(node *pNode);
	void removeNodeFromRootList(node *pRootNode);
	void addChildToParent(node *pChild, node *pParent);
	void deleteChildFromParent(node *pNode);
	bool isNeedMoveToRootLost(node *pNode);
	public:
	CFibHeap():dataCount(0),pMinNode(NULL){};
	errorType insert(node *x);
	int getDataCount();
	errorType merge(CFibHeap *H2);
	node* extract();
	errorType decreaseKey(node *pNodeToDecrease, int newKey);
	errorType deleteNode(node *pNode);
};
