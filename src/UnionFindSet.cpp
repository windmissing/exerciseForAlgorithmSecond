/* 
UnionFindSet.h 
并查集，非递归方法，含路径压缩，数组从0开始
*/ 
#include <iostream>   
using namespace std;  
  
#define MAXN 30005  
  
class UFS
{
public:
	int n;
	int p[MAXN+1];//集合根结点
	int rank[MAXN+1];  //集合中点的个数
public:
	UFS(int size = MAXN);
	void clear();
	int Find_Set(int x);
	//a并入b中，不区分大小
	void Union(int x, int y);
	void Make_Set(int x);
	void Link(int x, int y);
};
UFS::UFS(int size):n(size)
{
	//必须从0开始
	for(int i = 0; i <= n; i++)  
		Make_Set(i);  
}
void UFS::Make_Set(int x)
{
	p[x] = x;
	rank[x] = 0;
}
void UFS::clear()
{
	for(int i = 0; i <= n; i++)  
		Make_Set(i);
}
int UFS::Find_Set(int x)
{
	if(x != p[x])
		p[x] = Find_Set(p[x]);
	return p[x];
}
void UFS::Union(int x, int y)
{
	Link(Find_Set(x), Find_Set(y));
}
void UFS::Link(int x, int y)
{
	if(rank[x] > rank[y])
		p[y] = x;
	else
	{
		p[x] = y;
		if(rank[x] == rank[y])
			rank[y]++;
	} 
}
