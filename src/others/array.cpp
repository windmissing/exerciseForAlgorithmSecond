#include <iostream>
#include <algorithm>
using namespace std;

#include <stdlib.h>
#include <string.h>
#include "array.h"

CArray::CArray(int size)
{
	start = 1;
	end = size;
	memset(data, 0, sizeof(data));
}

CArray::CArray(const int *initData, const int len)
{
	start = 1;
	end = len;
	for(int i = start; i <= end; i++)
		data[i] = initData[i-1];
}

void CArray::insertArray(CArray B)
{
	for(int i = 1; i <= B.end; i++)
		data[end+i] = B.data[i];
	end += B.end;
}

void CArray::sortData()
{
	sort(data+start, data+end);
}

void CArray::makeRadomData()
{
	for(int i = start; i <= end; i++)  
    {  
        data[i] = rand() % 100;  
    }
	sort(data+start, data+end+1);
}

void CArray::Print()
{
	for(int i = start; i <= end; i++)
		cout<<data[i]<<' ';
	cout<<endl;
}


int CArray::remainDataCount() const
{
	return end - start + 1;
}

