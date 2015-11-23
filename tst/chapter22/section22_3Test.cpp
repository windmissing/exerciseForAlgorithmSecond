#include <iostream>
using namespace std;

#include "Link_Graph.h"

int main()  
{  
	int n, m, i;
    char start, end;  
	//输入点的个数和边的个数
	cin>>n>>m;
    //构造一个空的图  
    Link_Graph *G = new Link_Graph(n);  
    //输入边  
    for(i = 1; i <= m; i++)  
    {  
        cin>>start>>end;  
		G->AddSingleEdge(start-'p', end-'p');   
    }  
    //深度优先搜索  
    G->DFS();  
    //输出每个顶点的第一次访问时间和访问结束的时间  
	G->Print_Vertex_Time();
    //输出每条边的类型
	G->Print_Edge_Type();
	delete G;
    return 0;  
}  
