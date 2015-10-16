#include <vector>
using namespace std;

#include "Heap.h"

#define DIGIT 10
#define RADIX 10

template<typename Type> void heapSort(Type *data, int size)
{
	CMaxHeap<Type> H;
	for(int i = 0; i < size; i++)
		H.insert(data[i]);

	for(int i = 0; i < data[i]; i++)
		data[i] = H.extract();
}

template<typename Type> void quickSort(Type *data, int size)
{
	quickSort(data, 0, size);
}

template<typename Type> void quickSort(Type *data, int start, int end)
{
	if(start < end)  
    {  
        //以某个主元为标准，把数组分为两部分，左边都比主元小，右边都比主元大   
        int mid = Partition(data, start, end);  
        //分别对左边和右边排序   
        QuickSort(data, start, mid-1);  
        QuickSort(data, mid+1, end);  
    }  
}

template<typename Type> int Partition(Type *data, int start, int end)  
{  
    //选择data[r]作为主元   
    Type principalComponent  = data[end];  
    int i = start - 1, j;  
    for(j = start; j < end; j++)  
    {  
        //小于主元的放在左边   
        if(data[j] <= principalComponent)  
        {  
            i++;  
            //把大于主元的交换到右边   
            swap(data[i],data[j]);  
        }  
    }  
    swap(data[i+1], data[end]);  
    //返回最终主元的位置   
    return i+1;  
}

#define ARRAY vector<int>
void radixSort(ARRAY& data, int maxDigit);

void countingSort(int *A, int size);
