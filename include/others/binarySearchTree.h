#include <iostream>
#include <string>
using namespace std;

struct BST_Node
{
	int key;//???
	int data;//????
	BST_Node *left;//???
	BST_Node *right;//???
	BST_Node *p;//???

	BST_Node(int x):key(x),data(x),left(NULL),right(NULL),p(NULL){}
};

//????????
class CBinarySearchTree
{
#ifdef __UT__
public:
#else
private:
#endif
	BST_Node *root;
	CBinarySearchTree():root(NULL){}	
	BST_Node *successor(BST_Node *x);
	BST_Node *search(BST_Node *x, int k);
	BST_Node *iterativeSearch(BST_Node *x, int k);
	BST_Node *iterativeMinimum(BST_Node *x);
	BST_Node *iterativeMaximum(BST_Node *x);
public:
	void iterativeInsert(BST_Node *z);
	BST_Node *remove(BST_Node *z);
	void inorderWalk(BST_Node *x);
	BST_Node *search(int k);
	BST_Node *iterativeSearch(int k);
};
