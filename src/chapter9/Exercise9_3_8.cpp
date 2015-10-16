#include <iostream>
#include <algorithm>
using namespace std;

#include "Chapter9.h"
#include "array.h"

CArrayFor_9_3_8::CArrayFor_9_3_8(int size):CArray(size)
{

}

CArrayFor_9_3_8::CArrayFor_9_3_8(int *initData, int len)
	:CArray(initData, len)
{

}

void CArrayFor_9_3_8::cutPrevHalf()
{
	start = start + (end - start + 1) / 2; 
}

void CArrayFor_9_3_8::cutBackHalf()
{
	end = end - (end-start + 1) / 2; 
}

int CArrayFor_9_3_8::getStart()
{
	return data[start];
}

int CArrayFor_9_3_8::getEnd()
{
	return data[end];
}

int CArrayFor_9_3_8::getUpMiddle()
{
	return data[(start+end)/2];
}

int CArrayFor_9_3_8::getDownMiddle()
{
	return data[(start+end+1)/2];
}

CArrayFor_9_3_8 A(10), B(10);

int max(int a, int b);
void makeRadomData();
void printData();
int getSecondBigData(CArrayFor_9_3_8 A, CArrayFor_9_3_8 B);

void exercise_9_3_8()
{ 
	makeRadomData(); 
	printData(); 
 
    int ret = solve_9_3_8(A, B);  
    cout<<ret<<endl;    
}

void makeRadomData()
{
	A.makeRadomData();
	B.makeRadomData();
}


void printData()
{
    A.Print();  
    B.Print(); 
}

int solve_9_3_8(CArrayFor_9_3_8 A, CArrayFor_9_3_8 B)
{  
    int ret;  
    while(1)  
    {  
        if(A.remainDataCount() == 1)
		{
            ret = max(A.getStart(), B.getStart());
			return ret;
		}
        if(A.remainDataCount() == 2)  
        {  
            ret = getSecondBigData(A, B);  
            break;  
        }  
        int midA = A.getUpMiddle();  
        int midB = B.getUpMiddle();  
        if(midA == midB)  
        {  
            ret = midA;  
            break;  
        }  
        else if(midA < midB)  
        {  
			A.cutPrevHalf();
			B.cutBackHalf();
        }  
        else  
        {  
			A.cutBackHalf(); 
			B.cutPrevHalf();
        }  
    }  
    return ret;  
}

int getSecondBigData(CArrayFor_9_3_8 A, CArrayFor_9_3_8 B)
{
	int a = A.getStart();
	int b = A.getEnd();
	int c = B.getStart();
	int d = B.getEnd();

	if(b < c)
		return c;
	if(d < a)
		return a;
	if(b < d)
		return b;
	return d;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
