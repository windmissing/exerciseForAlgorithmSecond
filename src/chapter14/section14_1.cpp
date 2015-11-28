/*************************************************************************
    > File Name: section14_1.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Mon 23 Nov 2015 07:53:37 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include "section14_1.h"

ostNode * Os_Tree::nil = new ostNode(NULL, -1);
//对附加信息的维护
void Maintaining(ostNode *x)
{
	while(x->key >= 0)
	{
		x->size = x->left->size + x->right->size + 1;
		x = x->parent;
	}
}
//左旋，令y = x->right, 左旋是以x和y之间的链为支轴进行旋转
//涉及到的结点包括：x,y,y->left，令ostNode={p,l,r},具体变化如下：
//x={x->parent,x->left,y}变为{y,x->left,y->left}
//y={x,y->left,y->right}变为{x->parent,x,y->right}
//y->left={y,y->left->left,y->left->right}变为{x,y->left->left,y->left->right}
void Os_Tree::leftRotate(ostNode *x)
{
	//令y = x->right
	ostNode *y = x->right;
	//按照上面的方式修改三个结点的指针，注意修改指针的顺序
	x->right = y->left;
	if(y->left != nil)
		y->left->parent = x;
	y->parent = x->parent;
	if(x->parent == nil)//特殊情况：x是根结点
		root = y;
	else if(x == x->parent->left)
		x->parent->left = y;
	else 
		x->parent->right = y;
	y->left = x;
	x->parent = y;
	//对附加信息的维护
	y->size = x->size;
	x->size = x->left->size + x->right->size + 1;
}
//右旋，令y = x->left, 左旋是以x和y之间的链为支轴进行旋转
//旋转过程与上文类似
void Os_Tree::rightRotate(ostNode *x)
{
	ostNode *y = x->left;
	x->left = y->right;
	if(y->right != nil)
		y->right->parent = x;
	y->parent = x->parent;
	if(x->parent == nil)
		root = y;
	else if(x == x->parent->right)
		x->parent->right = y;
	else 
		x->parent->left = y;
	y->right = x;
	x->parent = y;
	//对附加信息的维护
	y->size = x->size;
	x->size = x->left->size + x->right->size + 1;
}
//红黑树调整
void Os_Tree::insertFixup(ostNode *z)
{
	ostNode *y;
	//唯一需要调整的情况，就是违反性质2的时候，如果不违反性质2，调整结束
	while(z->parent->color == RED)
	{
		//parent[z]是左孩子时，有三种情况
		if(z->parent == z->parent->parent->left)
		{
			//令y是z的叔结点
			y = z->parent->parent->right;
			//第一种情况，z的叔叔y是红色的
			if(y->color == RED)
			{
				//将parent[z]和y都着为黑色以解决z和parent[z]都是红色的问题
				z->parent->color = BLACK;
				y->color = BLACK;
				//将parent[parent[z]]着为红色以保持性质5
				z->parent->parent->color = RED;
				//把parent[parent[z]]当作新增的结点z来重复while循环
				z = z->parent->parent;
			}
			else
			{
				//第二种情况：z的叔叔是黑色的，且z是右孩子
				if(z == z->parent->right)
				{
					//对parent[z]左旋，转为第三种情况
					z = z->parent;
					leftRotate(z);
				}
				//第三种情况：z的叔叔是黑色的，且z是左孩子
				//交换parent[z]和parent[parent[z]]的颜色，并右旋
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				rightRotate(z->parent->parent);
			}
		}
		//parent[z]是右孩子时，有三种情况，与上面类似
		else if(z->parent == z->parent->parent->right)
		{
			y = z->parent->parent->left;
			if(y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if(z == z->parent->left)
				{
					z = z->parent;
					rightRotate(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				leftRotate(z->parent->parent);
			}
		}
	}
	//根结点置为黑色
	root->color = BLACK;
}

//插入一个结点
void Os_Tree::insert(int key, int info)
{
	ostNode *z = new ostNode(nil, key);
	z->info = info;
	//将新插入的结点转为红色
	z->color = RED;
	if(root == nil)
		root = z;
	else
	{
		ostNode *y = getPositionToInsert(z);
		insertChild(y, z);
	}
	//从新插入的结点开始，向上调整
	insertFixup(z);
	Maintaining(z);
}
ostNode * Os_Tree::getPositionToInsert(ostNode *z)
{
	ostNode *y = nil, *x = root;
	//找到应该插入的位置，与二叉查找树的插入相同
	while(x != nil)
	{
		y = x;
		if(z->key < x->key)
			x = x->left;
		else if(z->key > x->key)
			x = x->right;
	}
	return y;
}

void Os_Tree::insertChild(ostNode *parent, ostNode *child)
{
	child->parent = parent;
	if(child->key < parent->key)
		parent->left = child;
	else
		parent->right = child;
	child->left = nil;
	child->right = nil;
}

//对树进行调整，x指向一个红黑结点，调整的过程是将额外的黑色沿树上移
void Os_Tree::removeFixup(ostNode *x)
{
	ostNode *w;
	//如果这个额外的黑色在一个根结点或一个红结点上，结点会吸收额外的黑色，成为一个黑色的结点
	while(x != root && x->color == BLACK)
	{
		//若x是其父的左结点（右结点的情况相对应）
		if(x == x->parent->left)
		{
			//令w为x的兄弟，根据w的不同，分为三种情况来处理
			//执行删除操作前x肯定是没有兄弟的，执行删除操作后x肯定是有兄弟的
			w = x->parent->right;
			//第一种情况：w是红色的
			if(w->color == RED)
			{
				//改变w和parent[x]的颜色
				w->color = BLACK;
				x->parent->color = RED;
				//对parent[x]进行一次左旋
				leftRotate(x->parent);
				//令w为x的新兄弟
				w = x->parent->right;
				//转为2.3.4三种情况之一
			}
			//第二情况：w为黑色，w的两个孩子也都是黑色
			if(w->left->color == BLACK && w->right->color == BLACK)
			{
				//去掉w和x的黑色
				//w只有一层黑色，去掉变为红色，x有多余的一层黑色，去掉后恢复原来颜色
				w->color = RED;
				//在parent[x]上补一层黑色
				x = x->parent;
				//现在新x上有个额外的黑色，转入for循环继续处理
			}
			//第三种情况，w是黑色的,w->left是红色的,w->right是黑色的
			else
			{
				if(w->right->color == BLACK)
				{
					//改变w和left[x]的颜色
					w->left->color = BLACK;
					w->color = RED;
					//对w进行一次右旋
					rightRotate(w);
					//令w为x的新兄弟
					w = x->parent->right;
					//此时转变为第四种情况
				}
				//第四种情况：w是黑色的,w->left是黑色的,w->right是红色的
				//修改w和parent[x]的颜色
				w->color =x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				//对parent[x]进行一次左旋
				leftRotate(x->parent);
				//此时调整已经结束，将x置为根结点是为了结束循环
				x = root;
			}
		}
		//若x是其父的左结点（右结点的情况相对应）
		else if(x == x->parent->right)
		{
			//令w为x的兄弟，根据w的不同，分为三种情况来处理
			//执行删除操作前x肯定是没有兄弟的，执行删除操作后x肯定是有兄弟的
			w = x->parent->left;
			//第一种情况：w是红色的
			if(w->color == RED)
			{
				//改变w和parent[x]的颜色
				w->color = BLACK;
				x->parent->color = RED;
				//对parent[x]进行一次左旋
				rightRotate(x->parent);
				//令w为x的新兄弟
				w = x->parent->left;
				//转为2.3.4三种情况之一
			}
			//第二情况：w为黑色，w的两个孩子也都是黑色
			if(w->right->color == BLACK && w->left->color == BLACK)
			{
				//去掉w和x的黑色
				//w只有一层黑色，去掉变为红色，x有多余的一层黑色，去掉后恢复原来颜色
				w->color = RED;
				//在parent[x]上补一层黑色
				x = x->parent;
				//现在新x上有个额外的黑色，转入for循环继续处理
			}
			//第三种情况，w是黑色的,w->right是红色的,w->left是黑色的
			else
			{
				if(w->left->color == BLACK)
				{
					//改变w和right[x]的颜色
					w->right->color = BLACK;
					w->color = RED;
					//对w进行一次右旋
					leftRotate(w);
					//令w为x的新兄弟
					w = x->parent->left;
					//此时转变为第四种情况
				}
				//第四种情况：w是黑色的,w->right是黑色的,w->left是红色的
				//修改w和parent[x]的颜色
				w->color =x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				//对parent[x]进行一次左旋
				rightRotate(x->parent);
				//此时调整已经结束，将x置为根结点是为了结束循环
				x = root;
			}
		}
	}
	//吸收了额外的黑色
	x->color = BLACK;
}
//找最小值   
ostNode *Os_Tree::minimum(ostNode *x)  
{  
    //只要有比当前结点小的结点   
	while(x->left != nil)  
        x = x->left;  
    return x;  
} 
//查找中序遍历下x结点的后继，后继是大于key[x]的最小的结点   
ostNode *Os_Tree::successor(ostNode *x)  
{  
    //如果有右孩子   
	if(x->right != nil)  
        //右子树中的最小值   
        return minimum(x->right);  
    //如果x的右子树为空且x有后继y，那么y是x的最低祖先结点，且y的左儿子也是   
    ostNode *y = x->parent;  
    while(y != NULL && x == y->right)  
    {  
        x = y;  
        y = y->parent;  
    }  
    return y;  
}  

ostNode *Os_Tree::search(int k)  
{  
	return search(root, k);
}

//递归地查询二叉查找树   
ostNode *Os_Tree::search(ostNode *x, int k)  
{  
    //找到叶子结点了还没找到，或当前结点是所查找的结点   
	if(x->key == -1 || k == x->key)  
        return x;  
    //所查找的结点位于当前结点的左子树   
    if(k < x->key)  
        return search(x->left, k);  
    //所查找的结点位于当前结点的左子树   
    else  
        return search(x->right, k);  
} 
//红黑树的删除
ostNode *Os_Tree::remove(ostNode *z)
{
	ostNode * toRemove = findTheNodeToRemove(z);
	ostNode *child = getChild(toRemove);
	if(toRemove != z)
		z->key = toRemove->key;
	removeReally(toRemove);
	if(toRemove != z)
		Maintaining(z);
	if(toRemove->color == BLACK)
		removeFixup(child);
}

ostNode * Os_Tree::findTheNodeToRemove(ostNode *z)
{
	//找到结点的位置并删除，这一部分与二叉查找树的删除相同
	ostNode *x, *y;
	if(z->left == nil || z->right == nil)
		return z;
	else 
		return successor(z);
}

ostNode * Os_Tree::getChild(ostNode *parent)
{
	if(parent->left != nil)
		return parent->left;
	else 
		return parent->right;
}

void Os_Tree::removeReally(ostNode *toRemove)
{
	ostNode *child = getChild(toRemove);
	child->parent = toRemove->parent;
	if(toRemove->parent == nil)
		root = child;
	else if(toRemove == toRemove->parent->left)
		toRemove->parent->left = child;
	else
		toRemove->parent->right = child;
	Maintaining(toRemove->parent);
}

ostNode *Os_Tree::select(int i)
{
	select(root, i);
}

//查找以x为根结点的树中第i大的结点  
ostNode *Os_Tree::select(ostNode *x, int i)  
{  
    //令x左子树中点的个数为r-1,  
    int r = x->left->size +1;  
    //那么x是x树中第r大的结点  
    if(r == i)  
        return x;  
    //第i大的元素在x->left中  
    else if(i < r)  
        return select(x->left, i);  
    //第i大的元素在x->right中  
    else  
        return select(x->right, i - r);  
}  

