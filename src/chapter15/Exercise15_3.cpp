#include <iostream>  
using namespace std;  
//6种操作的代价，依次是copy,replace,delete,insert,twiddle,kill  
int cost[6] = {1,1,1,1,1,1};  
int s[15][15] = {0};  
//字符从0开始计数，s[][]从1开始  
int DP(char *x, char *z, int lx, int lz)  
{  
    int i = 0, j = 0,temp;  
    //初始化s[0][0]=0  
    //s[i,0] = i * cost(delete)  
    for(i = 1; i <= lx; i++)  
        s[i][0] = i * cost[2];  
    //s[0,j] = j * cost[insert]  
    for(j = 1; j <= lz; j++)  
        s[0][j] = i * cost[3];  
    //DP  
    for(i = 0; i < lx; i++)  
    {  
        for(j = 0; j < lz; j++)  
        {  
            s[i+1][j+1] = 0x7fffffff;  
            //copy  
            if(x[i] == z[j])  
            {  
                temp = s[i][j] + cost[0];  
                if(temp < s[i+1][j+1])  
                    s[i+1][j+1] = temp;  
            }  
            //replace  
            if(x[i] != z[j])  
            {  
                temp = s[i][j] + cost[1];  
                if(temp < s[i+1][j+1])  
                        s[i+1][j+1] = temp;  
            }  
            //delete  
            temp = s[i][j+1] + cost[2];  
            if(temp < s[i+1][j+1])  
                    s[i+1][j+1] = temp;  
            //insert  
            temp = s[i+1][j] + cost[3];  
            if(temp < s[i+1][j+1])  
                    s[i+1][j+1] = temp;  
            //twidle  
            if(i && j && x[i] == z[j-1] && x[i-1] == z[j])  
            {  
                temp = s[i-1][j-1] + cost[4];  
                if(temp < s[i+1][j+1])  
                    s[i+1][j+1] = temp;  
            }  
        }  
    }  
    //kill  
    int ret = s[lx][lz];  
    for(i = 1; i < lx; i++)  
        if(s[i][lz] + cost[5] < ret)  
            ret = s[i][lz] + cost[5];  
    return ret;  
}  
void Print(int lx, int lz)  
{  
    int i, j;  
    for(i = 1; i <= lx; i++)  
    {  
        for(j = 1; j <= lz; j++)  
            cout<<s[i][j]<<' ';  
        cout<<endl;  
    }  
}  
int main()  
{  
    char a[] = "algorithm";  
    char b[] = "altruistic";  
    int la = strlen(a), lb = strlen(b);  
    cout<<DP(a, b, la, lb)<<endl;  
    Print(la, lb);  
    return 0;  
}  