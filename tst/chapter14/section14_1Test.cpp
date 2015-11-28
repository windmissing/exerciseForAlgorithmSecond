/*************************************************************************
    > File Name: section14_1.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Mon 23 Nov 2015 07:53:37 PM CST
 ************************************************************************/
#include "section14_1.h"
/*
int main()
{
	//生成一棵动态顺序统计树
	Os_Tree *T = new Os_Tree;
	int m, n, i;
	while(cin>>n>>m)
	{
		//将1.,n依次插入到树中
		for(i = 1; i <= n; i++)
		{
			node *z = new node(T->nil, i);
			Os_Tree_Insert(T, z);
		}
		int t = n, start = 0;
		//还有剩余结点
		while(t)
		{
			//计算下一个要删除的结点在剩余结点中的位置
			start = (start + m - 1) % t;
			//找到这个结点
			node *ret = Os_Tree_Select(T->root, start+1);
			cout<<ret->key<<' ';
			//删除这个结点
			Os_Tree_Delete(T, ret);
			t--;
		}
		cout<<endl;
	}
	return 0;
}
*/
