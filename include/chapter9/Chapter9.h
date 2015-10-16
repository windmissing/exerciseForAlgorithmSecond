#include <vector>
using namespace std;

#include "array.h"

int solve9_1_1(vector<int> array);

class CArrayFor_9_3_6:public CArray
{
public:
	CArrayFor_9_3_6(int size);
	CArrayFor_9_3_6(const int *initData, const int len);
	CArrayFor_9_3_6(const CArrayFor_9_3_6 & origin);
	CArrayFor_9_3_6 getPart(int start, int end)const;

};

class CArrayFor_9_3_8:public CArray
{
public:
	CArrayFor_9_3_8(int size);
	CArrayFor_9_3_8(int *initData, int len);
	void cutPrevHalf();
	void cutBackHalf();
	int getStart();
	int getEnd();
	int getUpMiddle();
	int getDownMiddle();

};

void exercise_9_3_8();
int solve_9_3_8(CArrayFor_9_3_8 A, CArrayFor_9_3_8 B);

#define ARRAY vector<int>
ARRAY solve9_3_6(CArrayFor_9_3_6 & array, int k);
