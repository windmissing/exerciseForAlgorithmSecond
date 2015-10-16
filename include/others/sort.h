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
        //��ĳ����ԪΪ��׼���������Ϊ�����֣���߶�����ԪС���ұ߶�����Ԫ��   
        int mid = Partition(data, start, end);  
        //�ֱ����ߺ��ұ�����   
        QuickSort(data, start, mid-1);  
        QuickSort(data, mid+1, end);  
    }  
}

template<typename Type> int Partition(Type *data, int start, int end)  
{  
    //ѡ��data[r]��Ϊ��Ԫ   
    Type principalComponent  = data[end];  
    int i = start - 1, j;  
    for(j = start; j < end; j++)  
    {  
        //С����Ԫ�ķ������   
        if(data[j] <= principalComponent)  
        {  
            i++;  
            //�Ѵ�����Ԫ�Ľ������ұ�   
            swap(data[i],data[j]);  
        }  
    }  
    swap(data[i+1], data[end]);  
    //����������Ԫ��λ��   
    return i+1;  
}

#define ARRAY vector<int>
void radixSort(ARRAY& data, int maxDigit);

void countingSort(int *A, int size);
