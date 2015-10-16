#include <iostream>
using namespace std;

#include "Chapter9.h"

//第一遍求最小值的结果用树表示
struct node
{
	int key;
	node *next;//指向同一层中的下一个元素
	node *p;
	node *left;
	node *right;
	node(int k):key(k),next(NULL),p(NULL),left(NULL),right(NULL){}
};

node* prepareLeaves(const vector<int> & array);
int Find_S2(node *head);

int solve9_1_1(vector<int> array)
{
	cout<<array.size()<<endl;
	if(array.size() < 2)
		return 0;
	node *head = prepareLeaves(array);
	//运行算法并输出结果
	int ret = Find_S2(head);
	//release(head);
	return ret;
}

node* prepareLeaves(const vector<int> & array)
{
	node *head = NULL;
	for(int i = 0; i < array.size(); i++)
	{
		//构造成树的最底层结点
		node *p = new node(array[i]);
		p->next = head;
		head = p;
	}
	return head;
}

//求第二小值
int Find_S2(node *head)
{
	node *p, *q, *r, *t;
	//step1：求最小值
	//两两比较，较小的一个进入下一轮，这个循环当只剩下一个元素时结束
	while(head->next != NULL)
	{
		//从第一个元素开始，head指向比完后较小的那一组数据中的第一个
		p = head;head = NULL;
		while(p)
		{
			//如果这组数据有奇数个，最后一个元素直接晋级
			if(p->next == NULL)
			{
				r = new node(p->key);
				r->left = p;
				p->p = r;
				p = p->next;
			}
			//p与p->next比较，较小的元素晋级
			else
			{
				q = p->next;
				r = new node(min(p->key, q->key));
				r->left = p;
				r->right = q;
				p->p = r;
				q->p = r;
				p = q->next;
			}
			//head指向比完后较小的那一组数据中的第一个，t用于把head指向的数据链成链表
			if(head == NULL)
			{
				head = r;
				t=  head;
			}
			else
			{
				t->next = r;
				t = r;
			}
		}
	}
	//step2：求最第二小值
	//Min用于存储最小值，Min2用于存储第二小值
	int Min = head->key, Min2 = 0x7fffffff;
	//从根结点向下比较
	p = head;
	//比较到叶子结点时循环结束
	while(p->left != NULL)
	{
		//当前结点的值来源于右孩子
		if(p->right && p->right->key == Min)
		{
			Min2 = min(Min2, p->left->key);
			p = p->right;
		}
		//当前结点的值来源于左孩子
		else
		{
			//由左孩子直接晋级的情况
			if(p->right)
				Min2 = min(Min2, p->right->key);
			p = p->left;
		}
	}
	return Min2;
}
#if 0
//测试
int main()
{
	int A[8] = {0};

	return 0;
}
#endif
