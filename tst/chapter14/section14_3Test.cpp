/*************************************************************************
    > File Name: ../../tst/chapter14/section14_3Test.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Tue 01 Dec 2015 07:36:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
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
