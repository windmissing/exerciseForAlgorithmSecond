/*************************************************************************
    > File Name: ../src/chapter14/exercise14_2.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Sat 28 Nov 2015 04:44:08 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#include "exercise14_2.h"
#include "section14_1.h"

vector<int> josefInOsTree(vector<int> input, int m)
{
	//生成一棵动态顺序统计树
	Os_Tree *T = new Os_Tree;
	//将1.,n依次插入到树中
	for(int i = 0; i < input.size(); i++)
		T->insert(i, input[i]);
	int t = input.size(), start = 0;
	//还有剩余结点
	while(t)
	{
		//计算下一个要删除的结点在剩余结点中的位置
		start = (start + m - 1) % t;
		//找到这个结点
		ostNode *ret = T->select(start+1);
		cout<<ret->key<<' ';
		//删除这个结点
		T->remove(ret);
		t--;
	}
	cout<<endl;
}
