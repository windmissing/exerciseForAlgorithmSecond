#include <iostream>
using namespace std;

#define BLACK 0
#define RED 1

struct node
{
	node *left;
	node *right;
	node *p;
	int key;
	bool color;
	node *init;
	node(int k, node *init = NULL):init(init),left(init),right(init),p(init),key(k),color(BLACK){}
	~node()
	{
		if(left != init) delete left;
		if(right != init) delete right;
	}
	void print(){
		cout<<key<<endl;
	}
};

class CRedBlackTree
{
#ifdef __UT__
public:
#else
private:
#endif
	node *root;
	static node *nil;
	node *getPositionToInsert(node *z);
	void insertChild(node *parent, node *child);
	node *search(node *x, int k);
	node * findTheNodeToRemove(node *z);
	void removeReally(node *toRemove);
	node *getChild(node *parent);
	node *successor(node *x);
	node *minimum(node *x);
	void insertFixup(node *z);
	void leftRotate(node *x);
	void rightRotate(node *x);
	void removeFixup(node *x);
public:
	CRedBlackTree();
	~CRedBlackTree();
	void insert(int key);
	node *search(int k);
	void remove(node *z);
	static bool isNodeNull(node *z);
};
