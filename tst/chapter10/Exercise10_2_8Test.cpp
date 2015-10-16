#include <iostream>
using namespace std;

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Chapter10.h"
// Tests factorial of negative numbers.
//
using ::testing::_;
using ::testing::SetArgPointee;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::Pointee;

#define INSERT 0
#define DELETE 1

struct operation_t
{
	int oper;
	int param;
};

#define OPERATION_VEC vector<operation_t>
#define RESULT_VEC vector<int>

typedef int OUTPUTTYPE;

template<typename Type>vector<Type> prepare(Type * data, int len)
{
	vector<Type> ret;
	for(int i = 0; i < len; i++)
		ret.push_back(data[i]);
	return ret;
}

RESULT_VEC testStep(const OPERATION_VEC & inputDataVec)
{
	RESULT_VEC outputVec;
	listOfOnePointerDoubleLink list;
	for(int i = 0; i < inputDataVec.size(); i++)
	{
		switch(inputDataVec[i].oper)
		{
		case INSERT:
			list.Insert(inputDataVec[i].param);
			break;
		case DELETE:
			list.Delete(inputDataVec[i].param);
			break;
		}
	}
	outputVec = list.Print();
	return outputVec;
}

static bool compareVector(const RESULT_VEC & expect, const RESULT_VEC & result)
{
	if(expect.size() != result.size())
		return false;
	for(int i = 0; i < expect.size(); i++)
	{
		if(expect[i] != result[i])
			return false;
	}
	return true;
}

static void printArray(vector<int> array)
{
	for(int i = 0; i < array.size(); i++)
		cout<<array[i];
	cout<<endl;
}

TEST(noOperation, shouldNoResult)
{
	OPERATION_VEC operationVec;
	RESULT_VEC expect;
	RESULT_VEC output = testStep(operationVec);
	EXPECT_TRUE(compareVector(expect, output));
}
TEST(onlyInsert, insertOnceshouldGetOneData)
{
	operation_t operation[1] = {{INSERT, 1}};
	OPERATION_VEC operationVec = prepare<operation_t>(operation, 1);
	
	OUTPUTTYPE expect[1] = {1};
	RESULT_VEC expectVec = prepare<OUTPUTTYPE>(expect, 1);
	
	RESULT_VEC output = testStep(operationVec);
	EXPECT_TRUE(compareVector(expectVec, output));
}

TEST(OnlyInsert, Insert5NumberShouldGet5Data)
{
	operation_t operation[5] = {{INSERT, 1},
								{INSERT, 2},
								{INSERT, 3},
								{INSERT, 4},
								{INSERT, 5}};
	OPERATION_VEC operationVec = prepare<operation_t>(operation, 5);

	OUTPUTTYPE expect[5] = {5, 4, 3, 2, 1};
	RESULT_VEC expectVec = prepare<OUTPUTTYPE>(expect, 5);

	RESULT_VEC output = testStep(operationVec);
	EXPECT_TRUE(compareVector(expectVec, output));
}

TEST(Delete, deleteLastNodeWillSecuss)
{
	operation_t operation[2] = {{INSERT, 1},
								{DELETE, 1}};
	OPERATION_VEC operationVec = prepare<operation_t>(operation, 2);
	
	RESULT_VEC expect;
	
	RESULT_VEC output = testStep(operationVec);
	EXPECT_TRUE(compareVector(expect, output));
}

TEST(Delete, deleteFrontNodeWillSecuss)
{
	operation_t operation[4] = {{INSERT, 1},
								{INSERT, 2},
								{INSERT, 3},
								{DELETE, 3}};
	OPERATION_VEC operationVec = prepare<operation_t>(operation, 4);
	
	OUTPUTTYPE expect[2] = {2, 1};
	RESULT_VEC expectVec = prepare<OUTPUTTYPE>(expect, 2);

	RESULT_VEC output = testStep(operationVec);
	EXPECT_TRUE(compareVector(expectVec, output));
}

TEST(Delete, deleteTailNodeWillSecuss)
{
	operation_t operation[4] = {{INSERT, 1},
								{INSERT, 2},
								{INSERT, 3},
								{DELETE, 1}};
	OPERATION_VEC operationVec = prepare<operation_t>(operation, 4);

	OUTPUTTYPE expect[2] = {3, 2};
	RESULT_VEC expectVec = prepare<OUTPUTTYPE>(expect, 2);

	RESULT_VEC output = testStep(operationVec);
	EXPECT_TRUE(compareVector(expectVec, output));
}

TEST(Delete, deleteMidNodeWillSecuss)
{
	operation_t operation[4] = {{INSERT, 1},
								{INSERT, 2},
								{INSERT, 3},
								{DELETE, 2}};
	OPERATION_VEC operationVec = prepare<operation_t>(operation, 4);

	OUTPUTTYPE expect[2] = {3, 1};
	RESULT_VEC expectVec = prepare<OUTPUTTYPE>(expect, 2);

	RESULT_VEC output = testStep(operationVec);
	EXPECT_TRUE(compareVector(expectVec, output));
}
