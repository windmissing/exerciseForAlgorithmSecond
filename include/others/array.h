#pragma once

#define ARRAY_SIZE 50

class CArray
{
protected:
public:
	int start;
	int end;
	int data[ARRAY_SIZE+1];
	CArray(int size);
	CArray(const int *initData, const int len);
	void insertArray(CArray B);
	void sortData();
	void makeRadomData();
	void Print();
	virtual int remainDataCount() const;
};

