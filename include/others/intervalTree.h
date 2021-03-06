#include <iostream>
using namespace std;

#define BLACK 0
#define RED 1

int Max(int a, int b, int c)
{
	if(a > b)
		return a > c ? a : c;
	else
		return b > c ? b : c;
}
//????
struct interval
{
	int low;
	int high;
	interval(int l, int h):low(l), high(h){}
};
//???????
struct node
{
	node *left;
	node *right;
	node *p;
	int key;
	bool color;
	interval inte;
	int max;
	node(node *init, int l, int h):left(init),right(init),p(init),key(l),inte(l,h),max(h),color(BLACK){}
};
//a?b????,???,??1
bool Overlap(interval a, interval b)
{
	//a?b???
	if(a.high < b.low)
		return 0;
	//a?b???
	if(a.low > b.high)
		return 0;
	return 1;
}

//?????
class Interval_Tree
{
public:
	node *root;//???
	node *nil;//??
	/*????*/
	Interval_Tree(){nil = new node(NULL, -1, -1);root = nil;};
	/*???????*/
	void Left_Rotate(node *x);//??
	void Right_Rotate(node *x);//??
	void Insert_Fixup(node *z);//????
	void Insert(node *z);//??
	void Delete_Fixup(node *x);//????
	node *Delete(node *z);//??
	void Print();//??
	void Print(node *x);//??
	node *Search(node *x, int k);//?x??????????k???
	node *Tree_Successor(node *x);//???
	node *Tree_Minimum(node *x);//????????
	/*???????*/
	node *Interval_Search(interval i);
};
//??,?y = x->right, ????x?y???????????
//????????:x,y,y->left,?node={p,l,r},??????:
//x={x->p,x->left,y}??{y,x->left,y->left}
//y={x,y->left,y->right}??{x->p,x,y->right}
//y->left={y,y->left->left,y->left->right}??{x,y->left->left,y->left->right}
void Interval_Tree::Left_Rotate(node *x)
{
	//?y = x->right
	node *y = x->right;
	//????????????????,?????????
	x->right = y->left;
	if(y->left != nil)
		y->left->p = x;
	y->p = x->p;
	if(x->p == nil)//????:x????
		root = y;
	else if(x == x->p->left)
		x->p->left = y;
	else 
		x->p->right = y;
	y->left = x;
	x->p = y;
	//????????
	y->max = x->max;
	x->max = Max(x->inte.high, x->left->max, x->right->max);
}
//??,?y = x->left, ????x?y???????????
//?????????
void Interval_Tree::Right_Rotate(node *x)
{
	node *y = x->left;
	x->left = y->right;
	if(y->right != nil)
		y->right->p = x;
	y->p = x->p;
	if(x->p == nil)
		root = y;
	else if(x == x->p->right)
		x->p->right = y;
	else 
		x->p->left = y;
	y->right = x;
	x->p = y;
	//????????
	y->max = x->max;
	x->max = Max(x->inte.high, x->left->max, x->right->max);
}
//?????
void Interval_Tree::Insert_Fixup(node *z)
{
	node *y;
	//?????????,??????2???,???????2,????
	while(z->p->color == RED)
	{
		//p[z]?????,?????
		if(z->p == z->p->p->left)
		{
			//?y?z????
			y = z->p->p->right;
			//?????,z???y????
			if(y->color == RED)
			{
				//?p[z]?y????????z?p[z]???????
				z->p->color = BLACK;
				y->color = BLACK;
				//?p[p[z]]?????????5
				z->p->p->color = RED;
				//?p[p[z]]???????z???while??
				z = z->p->p;
			}
			else
			{
				//?????:z???????,?z????
				if(z == z->p->right)
				{
					//?p[z]??,???????
					z = z->p;
					Left_Rotate(z);
				}
				//?????:z???????,?z????
				//??p[z]?p[p[z]]???,???
				z->p->color = BLACK;
				z->p->p->color = RED;
				Right_Rotate(z->p->p);
			}
		}
		//p[z]?????,?????,?????
		else if(z->p == z->p->p->right)
		{
			y = z->p->p->left;
			if(y->color == RED)
			{
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else
			{
				if(z == z->p->left)
				{
					z = z->p;
					Right_Rotate(z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				Left_Rotate(z->p->p);
			}
		}
	}
	//???????
	root->color = BLACK;
}
//??????
void Interval_Tree::Insert(node *z)
{
	node *y = nil, *x = root;
	//?????????,???????????
	while(x != nil)
	{
		x->max = max(x->max, z->max);
		y = x;
		if(z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->p = y;
	if(y == nil)
		root = z;
	else if(z->key < y->key)
		y->left = z;
	else
		y->right = z;
	z->left = nil;
	z->right = nil;
	//???????????
	z->color = RED;
	//?????????,????
	Insert_Fixup(z);
}
//??????,x????????,????????????????
void Interval_Tree::Delete_Fixup(node *x)
{
	node *w;
	//??????????????????????,??????????,?????????
	while(x != root && x->color == BLACK)
	{
		//?x???????(?????????)
		if(x == x->p->left)
		{
			//?w?x???,??w???,?????????
			//???????x????????,???????x???????
			w = x->p->right;
			//?????:w????
			if(w->color == RED)
			{
				//??w?p[x]???
				w->color = BLACK;
				x->p->color = RED;
				//?p[x]??????
				Left_Rotate(x->p);
				//?w?x????
				w = x->p->right;
				//??2.3.4??????
			}
			//????:w???,w??????????
			if(w->left->color == BLACK && w->right->color == BLACK)
			{
				//??w?x???
				//w??????,??????,x????????,?????????
				w->color = RED;
				//?p[x]??????
				x = x->p;
				//???x????????,??for??????
			}
			//?????,w????,w->left????,w->right????
			else
			{
				if(w->right->color == BLACK)
				{
					//??w?left[x]???
					w->left->color = BLACK;
					w->color = RED;
					//?w??????
					Right_Rotate(w);
					//?w?x????
					w = x->p->right;
					//??????????
				}
				//?????:w????,w->left????,w->right????
				//??w?p[x]???
				w->color =x->p->color;
				x->p->color = BLACK;
				w->right->color = BLACK;
				//?p[x]??????
				Left_Rotate(x->p);
				//????????,?x????????????
				x = root;
			}
		}
		//?x???????(?????????)
		else if(x == x->p->right)
		{
			//?w?x???,??w???,?????????
			//???????x????????,???????x???????
			w = x->p->left;
			//?????:w????
			if(w->color == RED)
			{
				//??w?p[x]???
				w->color = BLACK;
				x->p->color = RED;
				//?p[x]??????
				Right_Rotate(x->p);
				//?w?x????
				w = x->p->left;
				//??2.3.4??????
			}
			//????:w???,w??????????
			if(w->right->color == BLACK && w->left->color == BLACK)
			{
				//??w?x???
				//w??????,??????,x????????,?????????
				w->color = RED;
				//?p[x]??????
				x = x->p;
				//???x????????,??for??????
			}
			//?????,w????,w->right????,w->left????
			else
			{
				if(w->left->color == BLACK)
				{
					//??w?right[x]???
					w->right->color = BLACK;
					w->color = RED;
					//?w??????
					Left_Rotate(w);
					//?w?x????
					w = x->p->left;
					//??????????
				}
				//?????:w????,w->right????,w->left????
				//??w?p[x]???
				w->color =x->p->color;
				x->p->color = BLACK;
				w->left->color = BLACK;
				//?p[x]??????
				Right_Rotate(x->p);
				//????????,?x????????????
				x = root;
			}
		}
	}
	//????????
	x->color = BLACK;
}
//????   
node *Interval_Tree::Tree_Minimum(node *x)  
{  
    //????????????   
	while(x->left != nil)  
        x = x->left;  
    return x;  
} 
//???????x?????,?????key[x]??????   
node *Interval_Tree::Tree_Successor(node *x)  
{  
    //??????   
	if(x->right != nil)  
        //????????   
        return Tree_Minimum(x->right);  
    //??x???????x???y,??y?x???????,?y??????   
    node *y = x->p;  
    while(y != NULL && x == y->right)  
    {  
        x = y;  
        y = y->p;  
    }  
    return y;  
}  
//??????????   
node *Interval_Tree::Search(node *x, int k)  
{  
    //???????????,????????????   
	if(x->key == -1 || k == x->key)  
        return x;  
    //????????????????   
    if(k < x->key)  
        return Search(x->left, k);  
    //????????????????   
    else  
        return Search(x->right, k);  
} 
//??????
node *Interval_Tree::Delete(node *z)
{
	//??????????,???????????????
	node *x, *y, *p;
	if(z->left == nil || z->right == nil)
	{
		y = z;
		p = y->p;
		p->max = p->inte.high;
		p = p->p;
		while(p->max == y->max)
		{
			p->max = Max(p->max, p->left->max, p->right->max);
			p = p->p;
		}
	}
	else y = Tree_Successor(z);
	//????????
	p = y->p;
	p->max = p->inte.high;
	p = p->p;
	while(p->max == y->max)
	{
		p->max = Max(p->max, p->left->max, p->right->max);
		p = p->p;
	}
	//??y??
	if(y->left != nil)
		x = y->left;
	else x = y->right;
	x->p = y->p;
	if(y->p == nil)
		root = x;
	else if(y == y->p->left)
		y->p->left = x;
	else
		y->p->right = x;
	//??
	if(y != z)
	{
		z->inte = y->inte;
		z->key = y->key;
		z->max = y->max;
		p = z->p;
		while(p->max < z->max)
		{
			p->max = z->max;
			p = p->p;
		}
	}
	//????????????,?????
	if(y->color == BLACK)
		Delete_Fixup(x);
	return y;
}
void Interval_Tree::Print(node *x)
{
	if(x->key == -1)
		return;
	Print(x->left);
	cout<<x->inte.low<<' '<<x->inte.high<<endl;
	Print(x->right);
}

void Interval_Tree::Print()
{
	Print(root);
	cout<<endl;
}

//??????
node *Interval_Tree::Interval_Search(interval i)
{
	//??????
	node *x = root;
	//????????
	while(x != nil && !Overlap(i, x->inte))
	{
		//?????
		if(x->left != nil && x->left->max >= i.low)
			x = x->left;
		//?????
		else
			x = x->right;
	}
	return x;
}