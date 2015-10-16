#include <iostream>
#include <vector>
using namespace std;

#include <stdlib.h>

#include "Exercise6_5_8.h"
#include "Heap.h"

#define K 10
#define DATA_COUNT 100

ostream& operator<<(ostream & s, const node & n)
{
	s << n.value;
	return s;
}

//5������ÿ�������ͷ������Head��
int mergeResult[DATA_COUNT+1] = {0};
CMaxHeap<node> H(K, node::getMaxNode());

vector<ARRAY> buildTestData();
void showTestData(vector<ARRAY> inputParam);
void insertListHeadToHeap(vector<ARRAY> &inputParam, int listIndex);
void showResult();
void recordMergeResult(int data);
ARRAY solve_6_5_8(vector<ARRAY> inputParam);

int K_Merge_6_5_8()
{
	vector<ARRAY> inputParam = buildTestData();
	showTestData(inputParam);

	ARRAY result = solve_6_5_8(inputParam);

	showResult();
	return 0;
}

ARRAY solve_6_5_8(vector<ARRAY> inputParam)
{
	ARRAY ret;
	while(H.isEmpty() == false)
		H.extract();

	for(int i = 0; i < inputParam.size(); i++)
		insertListHeadToHeap(inputParam, i);
	while(H.isEmpty() == false)
	{
		node top = H.extract();
		ret.push_back(top);
		insertListHeadToHeap(inputParam, top.list);
	}
	return ret;
}

vector<ARRAY> buildTestData()
{
	int value, list;
		//������Ҫ�ϲ�������
	vector<ARRAY > ret(K);
	for(value = DATA_COUNT; value >0; value--)
	{
		list = rand() % K;
		node newNode;// = {list, value};
		newNode.list = list;
		newNode.value = value;
		ret[list].push_back(newNode);
	}
	return ret;
}

void showTestData(vector<ARRAY> inputParam)
{
	cout<<"��ʾ����������"<<endl;
	for(int i = 0; i < inputParam.size(); i++)
	{
		ARRAY array = inputParam[i];
		for(int j = 0; j < array.size(); j++)
			cout<<array[j].value<<' ';
		cout<<endl;
	}
}

void insertListHeadToHeap(vector<ARRAY> &inputParam, int  listIndex)
{
	ARRAY &array = inputParam[listIndex];
	if(array.size() != 0)
	{
		H.insert(array[0]);
		array.erase(array.begin());
	}
}

void showResult()
{
	//����ϲ����
	cout<<"����ϲ����"<<endl;
	for(int i = 1; i <= mergeResult[0];i++)
		cout<<mergeResult[i]<<' ';
	cout<<endl;
}

void recordMergeResult(int data)
{
	mergeResult[++mergeResult[0]] = data;
}
