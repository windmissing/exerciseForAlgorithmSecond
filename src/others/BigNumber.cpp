#include <iostream>
#include "BigNumber.h"

using namespace std;

#define  UP_LIMIT 1000000000000000000
#define MAX_DIGIT_COUNT MAX_CELL_COUNT*DIGIT_PER_CELL

CBigNumber::CBigNumber()
{
	usedCells = 0;
	memset(cell, 0, sizeof(cell));
}

CBigNumber::CBigNumber(const CBigNumber &B)
{
	usedCells = B.usedCells;
	memset(cell, 0, sizeof(cell));
	for(int i = 0; i < B.usedCells; i++)
		cell[i] = B.cell[i];
}

CBigNumber::CBigNumber(long long normalData)
{
	memset(cell, 0, sizeof(cell));
	cell[0] = normalData;
	usedCells = 1;
}

CBigNumber::CBigNumber(string number)
{
	int digit[MAX_DIGIT_COUNT] = {0};
	int len = number.length();
	for(int i = 0; i < len; i++)
	{
		digit[len -i - 1] = number[i] - '0';
	}
	*this = digit2Number(digit, number.length());
}

CBigNumber CBigNumber::operator+(const CBigNumber & number)
{
	CBigNumber ret;
	for(int i = 0; i < usedCells; i++)
	{
		ret.cell[i] += cell[i] + number.cell[i];
		if(ret.cell[i] > UP_LIMIT)
		{
			ret.cell[i] = ret.cell[i] - UP_LIMIT;
			ret.cell[i+1]++;
		}
	}
	ret.usedCells = usedCells;
	if(ret.cell[ret.usedCells] > 0)
		ret.usedCells++;
	return ret;
}

bool CBigNumber::operator<(const CBigNumber & number) const
{
	if(usedCells !=  number.usedCells)
		return usedCells < number.usedCells;

	for(int i = usedCells - 1; i >= 0; i--)
	{
		if(cell[i] != number.cell[i])
			return cell[i] < number.cell[i];
	}
	return false;
}

long long CBigNumber::toLongLong() const
{
	return cell[0];
}

void CBigNumber::print()
{
	for(int i = 0; i < usedCells; i++)
		cout<<cell[i];
}
CBigNumber& CBigNumber::operator=(const CBigNumber & B)
{
	usedCells = B.usedCells;
	memset(cell, 0, sizeof(cell));
	for(int i = 0; i < usedCells; i++)
		cell[i] = B.cell[i];
	return *this;
}
bool CBigNumber::operator==(const CBigNumber & B)
{
	if(usedCells != B.usedCells)
		return false;
	for(int i = 0; i < usedCells; i++)
		if(cell[i] != B.cell[i])
			return false;
	return true;
}
bool CBigNumber::isUpOverflow()
{
	if(usedCells >= MAX_CELL_COUNT)
		return true;
	return false;
}
bool CBigNumber::isPalindrome()
{
	CBigNumber reverse = getReverseNumber();
	if(reverse == *this)
		return true;
	else
		return false;
}

CBigNumber CBigNumber::getReverseNumber()
{
	CBigNumber ret;
	
	int digit[MAX_DIGIT_COUNT] = {0};
	int len = numberInCells2Digits(digit);
	reverseDigit(digit, len);
	ret = digit2Number(digit, len);

	return ret;
}

int CBigNumber::numberInCells2Digits(int *digit)
{
	int start = 0;
	for(int i = 0; i < usedCells; i++)
	{
		start = i * DIGIT_PER_CELL;
		long long temp = cell[i];
		while(temp)
		{
			digit[start++] = temp % 10;
			temp = temp / 10;
		}
	}
	return start;
}
	
void CBigNumber::reverseDigit(int *digit, int len)
{
	int midIndex = (len - 1) / 2;
	for(int i = 0; i <= midIndex; i++)
		swap(digit[i], digit[len - 1 - i]);
}

CBigNumber CBigNumber::digit2Number(int *digit, int len)
{
	CBigNumber ret;
	memset(ret.cell, 0, sizeof(ret.cell));
	for(int i = 0; i < len; i+=DIGIT_PER_CELL)
	{
		for(int j = i + DIGIT_PER_CELL-1; j >= i; j--)
		{
			if(j >= len)continue;
			ret.cell[ret.usedCells] = ret.cell[ret.usedCells] * 10 + digit[j];
		}
		ret.usedCells++;
	}
	return ret;
}

