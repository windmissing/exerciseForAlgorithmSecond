#include <iostream>  
using namespace std; 
#include <string>

//6种操作的代价，依次是copy,replace,delete,insert,twiddle,kill  
int cost[6] = {1,1,1,1,1,1};  
int c[15][15] = {0};  


void init(int ls, int ld)
{
	int i = 0, j = 0;  
    //初始化c[0][0]=0  
    //c[i,0] = i * cost(delete)  
    for(i = 1; i <= ls; i++)  
        c[i][0] = i * cost[2];  
    //c[0,j] = j * cost[insert]  
    for(j = 1; j <= ld; j++)  
        c[0][j] = i * cost[3];  
}

int copyOperation(int i, int j, char s, char d)
{
	int ret = c[i+1][j+1];
	if(s == d)  
    {  
        int temp = c[i][j] + cost[0];  
        if(temp < ret)  
            ret = temp;  
    }
	return ret;
}

int replaceOperation(int i, int j, char s, char d)
{
	int ret = c[i+1][j+1];
	if(s != d)  
    {  
        int temp = c[i][j] + cost[1];  
        if(temp < ret)  
            ret = temp;  
    }
	return ret;
}

int deleteOperation(int i, int j)
{
	int ret = c[i+1][j+1];
	int temp = c[i][j+1] + cost[2];  
    if(temp < ret)  
		ret = temp; 
	return ret;
}

int insertOperation(int i, int j)
{
	int ret = c[i+1][j+1];
	int temp = c[i+1][j] + cost[3]; 
    if(temp < ret)  
		ret = temp; 
	return ret;
}

int twiddleOperation(int i, int j, char a, char b, char cc, char d)
{
	int ret = c[i+1][j+1];
	//src[i] == dst[j-1] && src[i-1] == dst[j]
	 if(i && j && a == b && cc == d)  
     {  
          int temp = c[i-1][j-1] + cost[4];  
                if(temp < c[i+1][j+1])  
                    c[i+1][j+1] = temp;  
            }  
	return ret;
}
//字符从0开始计数，c[][]从1开始  
int DP(string src, string dst)  
{  
    int i = 0, j = 0;  
	init(src.length(), dst.length());
    //DP  
    for(i = 0; i < src.length(); i++)  
    {  
        for(j = 0; j < dst.length(); j++)  
        {  
            c[i+1][j+1] = 0x7fffffff;

			c[i+1][j+1] = copyOperation(i, j, src[i], dst[j]);
			c[i+1][j+1] = replaceOperation(i, j, src[i], dst[j]);
			c[i+1][j+1] = deleteOperation(i, j);
			c[i+1][j+1] = insertOperation(i, j);
			c[i+1][j+1] = twiddleOperation(i, j, src[i], dst[j-1], src[i-1], dst[j]);
        }  
    }  
    //kill  
    int ret = c[src.length()][dst.length()];  
    for(i = 1; i < src.length(); i++)  
        if(c[i][dst.length()] + cost[5] < ret)  
            ret = c[i][dst.length()] + cost[5];  
    return ret;  
}  
void Print(int lx, int lz)  
{  
    int i, j;  
    for(i = 1; i <= lx; i++)  
    {  
        for(j = 1; j <= lz; j++)  
            cout<<c[i][j]<<' ';  
        cout<<endl;  
    }  
}  
