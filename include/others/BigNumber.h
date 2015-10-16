#pragma once
#include <string.h>
using namespace std;

#define MAX_CELL_COUNT 200
#define DIGIT_PER_CELL 18

class CBigNumber
{
//protected:
	public:
	long long cell[MAX_CELL_COUNT];
	bool isInRecord();
	int numberInCells2Digits(int *digit);
	void reverseDigit(int *digit, int len);
	CBigNumber digit2Number(int *digit, int len);
public:
	int usedCells;
	CBigNumber();
	CBigNumber(const CBigNumber &B);
	CBigNumber(long long normalData);
	CBigNumber(string number);
	bool isUpOverflow();
	bool isPalindrome();
	void print();
	CBigNumber &operator=(const CBigNumber & B);
	bool operator==(const CBigNumber & B);
	CBigNumber getReverseNumber();
	CBigNumber operator+(const CBigNumber & number);
	long long toLongLong() const;
	bool operator<(const CBigNumber & number) const;
};


