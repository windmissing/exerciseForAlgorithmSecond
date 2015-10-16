#include <vector>
using namespace std;

#define SIZE_OF_YOUNG 100
#define INIT_DATA 0x7fffffff

enum errorType
{
	SUCCESS = 0,
	SIZE_OVERFLOW,
	OUT_OF_SIZE,
	PARAM_ERROR,
};

struct structCoordinate
{
	int h_index;
	int w_index;
	structCoordinate(int h, int w):h_index(h),w_index(w){}
};

class Young
{	
	int Y[SIZE_OF_YOUNG+1][SIZE_OF_YOUNG+1];
	int height, width;

	bool isInRange(structCoordinate position);
	void build();
	void YoungifyWithSon(structCoordinate position);
	void YoungifyWithParent(structCoordinate position);
	void setDataInPosition(structCoordinate position, int data);
	int getDataFromPosition(structCoordinate position);
	void swapDatainPosition(structCoordinate c1, structCoordinate c2);
	void Print();
public:
	Young(int h = SIZE_OF_YOUNG, int w = SIZE_OF_YOUNG);
	void fillData(int *data, int size);
	int extractMin();
	bool findKey(int key);
	errorType insert(int key);
	errorType decreaseKey(structCoordinate position, int key);
	int getMinimum();
	vector<int> sort();
	errorType deleteData(structCoordinate position);
};