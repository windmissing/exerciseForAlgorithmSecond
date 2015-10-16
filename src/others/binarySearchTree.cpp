#include "binarySearchTree.h"

/*************12.1 ?????****************************************************************/
//???????
void CBinarySearchTree::inorderWalk(BST_Node *x)
{
	if(x != NULL)
	{
		//????????????
		inorderWalk(x->left);
		//??????
		cout<<x->key<<endl;
		//????????????
		inorderWalk(x->right);
	}
}
/********12.2 ???????****************************************************************/
BST_Node *CBinarySearchTree::search(int k)
{
	return search(root, k);
}
//??????????
BST_Node *CBinarySearchTree::search(BST_Node *x, int k)
{
	//???????????,????????????
	if(x == NULL || k == x->key)
		return x;
	//????????????????
	if(k < x->key)
		return search(x->left, k);
	//????????????????
	else
		return search(x->right, k);
}
BST_Node *CBinarySearchTree::iterativeSearch(int k)
{
	return iterativeSearch(k);
}
//???????????
BST_Node *CBinarySearchTree::iterativeSearch(BST_Node *x, int k)
{
	//???????????????
	while(x != NULL && k != x->key)
	{
		//????????????????
		if(k < x->key)
			x = x->left;
		//????????????????
		else
			x = x->right;
	}
	return x;
}
//???????
BST_Node *CBinarySearchTree::iterativeMinimum(BST_Node *x)
{
	//????????????
	while(x->left != NULL)
		x = x->left;
	return x;
}
//???????
BST_Node *iterativeMaximum(BST_Node *x)
{
	//????????????
	while(x->right != NULL)
		x = x->right;
	return x;
}
//???????x?????,?????key[x]??????
BST_Node *CBinarySearchTree::successor(BST_Node *x)
{
	//??????
	if(x->right != NULL)
		//????????
		return iterativeMinimum(x->right);
	//??x???????x???y,??y?x???????,?y??????
	BST_Node *y = x->p;
	while(y != NULL && x == y->right)
	{
		x = y;
		y = y->p;
	}
	return y;
}
/*********12.3?????**********************************************************/
//????????,???
void CBinarySearchTree::iterativeInsert(BST_Node *z)
{
	//????????
	BST_Node *x = root, *y = NULL;
	//?x??,x???????,x???z->p
	while(x != NULL)
	{
		y = x;
		if(z->key == x->key)
		{
			cout<<"error:exist"<<endl;
			return;
		}
		if(z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	//????,????????
	z->p = y;
	if(y == NULL)
		root = z;
	else if(z->key < y->key)
		y->left = z;
	else y->right = z;
}
//????????,?????????z,???z???
//???z????????????
BST_Node *CBinarySearchTree::remove(BST_Node *z)
{
	BST_Node *x, *y;
	//?z????????,????????z
	if(z->left == NULL || z->right == NULL)
		y = z;
	//?z?????,????????z???
	else
		y = successor(z);
	//?x??"????????"???(??????)
	if(y->left != NULL)
		x = y->left;
	else
		x = y->right;
	//????,?????
	if(x != NULL)//?"????????"????
		x->p = y->p;
	if(y->p == NULL)//?"????????"????
		root = x;
	else if(y == y->p->left)
		y->p->left = x;
	else y->p->right = x;
	//"?????????"??"??????",?????
	if(y != z)
	{
		z->key = y->key;
		z->data = y->data;
	}
	return y;
}