#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define ARRAY_SIZE 15
#include "Exercise15_1.h"

//用于排序
static bool cmp(coord a, coord b)
{
	return a.x < b.x;
}
//计算d[i][j]
double dis(const vector<coord> &s, int i, int j)
{
	double temp = pow((s[i].x-s[j].x)*1.0, 2) + pow((s[i].y-s[j].y)*1.0, 2);
	return sqrt(temp);
}

double Double_adjustable_Euclidean_traveling_salesman(vector<coord> s)
{
	return 0;
	//int n = s.size();
	//if(n == 0)return 0;
//	int i, j, k;
	//根据x从小到大排序
//	sort(s.begin(), s.end(), cmp);
	double ans[ARRAY_SIZE][ARRAY_SIZE] = {0};
#if 0
	for(i = 0; i < n; i++)
	{
		//s[0][0]=0
		//(2)当j=i时，s[i][j]=s[i][i]=s[i][i-1]+d[i-1][i]
		if(i)ans[i][i] = ans[i][i-1] + dis(s, i-1, i);
		//(3)当j=i+1时,s[i][j]=MIN(s[i][k]+d[k][j])，其中0<=k<i
		double min = 0x7fffffff, temp;
		//s[0][1]=d[0][1]
		if(i < n - 1)
		{
			if(i == 0)
				min = dis(s, 0, 1);
			else
			{
				for(k = 0; k < i; k++)
				{
					temp = ans[i][k] + dis(s, k, i+1);
					if(temp < min)
						min = temp;
				}
			}
			//s[i][j]=s[j][i]
			ans[i][i+1] = min;
			ans[i+1][i] = min;//(1)s[i][j] = s[j][i]
		}
		//(4)当j>i+1时，s[i][j]=s[i][j-1]+d[j-1][j]
		for(j = i + 2; j < n; j++)
		{
			//s[i][j]=s[j][i]
			ans[i][j] = ans[i][j-1] + dis(s, j-1, j);
			ans[j][i] = ans[i][j];
		}
	}
#endif
	//cout<<ans[n-1][n-1]<<endl;
	//return ans[n-1][n-1];
}
