#include <iostream>
using namespace std;

#include "Chapter7.h"

static void quickSort(ARRAY & array, int left, int right);
static divid partition(ARRAY &array, int left, int right);
void moveToLeft(ARRAY &array, int& index, divid &pivotIndex);
void moveToRight(ARRAY &array, int& index, divid &pivotIndex);
section getPublicSection(const section &a, const section & b);
static void exchange(section &a, section &b);

void Exercise7_6(ARRAY & array)
{
	if(array.size() == 0)
		return;
	quickSort(array, 0, array.size()-1);
}

static void quickSort(ARRAY & array, int left, int right)
{
	if(left == right)
		return;
	divid pivotIndex = partition(array, left, right);
	if(pivotIndex.a > 0)
		quickSort(array, left, pivotIndex.a);
	if(pivotIndex.b > 0)
		quickSort(array, pivotIndex.b, right);
}

static divid partition(ARRAY &array, int left, int right)
{
	section pivot = array[right];
	divid ret = {left - 1, right + 1};
	int index = left;
	while(index < ret.b)
	{
		if(array[index] < pivot)
			moveToLeft(array, index, ret);
		else if(array[index] > pivot)
			moveToRight(array, index, ret);
		else
		{
			pivot = getPublicSection(pivot, array[index]);
			index++;
		}
	}
	if(ret.a < left)ret.a = -1;
	if(ret.b > right)ret.b = -1;
	return ret;
}

void moveToLeft(ARRAY &array, int &index, divid &pivotIndex)
{
	pivotIndex.a++;
	exchange(array[pivotIndex.a], array[index]);
	index++;
}

void moveToRight(ARRAY &array, int &index, divid &pivotIndex)
{
	pivotIndex.b--;
	exchange(array[pivotIndex.b], array[index]);
}

section getPublicSection(const section &a, const section & b)
{
	section ret;
	ret.end = min(a.end, b.end);
	ret.start = max(a.start, b.start);
	return ret;
}

static void exchange(section &a, section &b)
{
	section temp;
	temp = a;
	a = b;
	b = temp;
}

