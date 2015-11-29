/*************************************************************************
    > File Name: chapter8/chapter8Test.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Sun 29 Nov 2015 12:07:19 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include "gtest/gtest.h"

#include "chapter8.h"
/*
int main()
{
	cin>>length_A>>digit;
	int *A = new int[length_A+1];
	int *B = new int[length_A+1];
	int i;
	//随机产生length_A个digit位的数据
	for(i = 1; i <= length_A; i++)
	{
		A[i] = 0;
		while(A[i] < (int)pow(10.0, digit-1))
			A[i] = rand() % (int)pow(10.0, digit);
	}
	Print(A, 1, length_A);
//	Counting_Sort(A, B, 9);
	Radix_Sort(A, B);
	Print(A, 1, length_A);
	delete []A;
	delete []B;
	return 0;
}*/

TEST(counting_sort, sort)
{
	int A[] = {0, 5, 4, 3, 2, 1};
	int B[6] = {};
	int C[] = {0, 1, 2, 3, 4, 5};
	Counting_Sort(A, B, 5, 10);
	for(int i = 1; i <= 5; i++)
		EXPECT_EQ(C[i], B[i]);
}

