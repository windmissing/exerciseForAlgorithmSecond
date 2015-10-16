#include <iostream>
using namespace std;

#include "BigNumber.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"
// Tests factorial of negative numbers.
//
using ::testing::_;
using ::testing::SetArgPointee;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::Pointee;

#include "BigNumber.h"
#define MAX_SIZE 200

bool checkAllMemberZero(const CBigNumber & number)
{
	if(number.usedCells != 0)
		return false;
	for(int i = 0; i < MAX_SIZE; i++)
		if(number.cell[i] != 0)
			return false;
	return true;
}

bool isNumberEqual(const CBigNumber & number1, CBigNumber & number2)
{
	if(number1.usedCells != number2.usedCells)
		return false;
	for(int i = 0; i < number1.usedCells; i++)
		if(number1.cell[i] != number2.cell[i])
			return false;
	return true;
}

CBigNumber generateRadomNumber()
{
	CBigNumber radom;
	radom.usedCells = rand() % MAX_SIZE;
	for(int i = 0; i < radom.usedCells; i++)
		radom.cell[i] = rand();
	return radom;
}

TEST(initNumberWithNoParam, allMemberIsZero)
{
	CBigNumber number;
	EXPECT_TRUE(checkAllMemberZero(number));
}

TEST(initWithLongLong, initCellIsStoredInOneCell)
{
	long long initNumber = 1234567890123;
	CBigNumber number(initNumber);
	EXPECT_EQ(1, number.usedCells);
	EXPECT_EQ(initNumber, number.cell[0]);
}

TEST(initWithBigNumber, newNumberAndOriginNumberAreEqual)
{
	CBigNumber origin = generateRadomNumber();
	CBigNumber number(origin);
	EXPECT_TRUE(isNumberEqual(origin, number));
}

TEST(initWithString, numberLessThan18DigitIsStoredInOneCell)
{
	CBigNumber number("123456789");
	EXPECT_EQ(1, number.usedCells);
	EXPECT_EQ(123456789, number.cell[0]);
}

TEST(initWithString, numberMoreThan18DigitIsStoredInMoreCells)
{
	CBigNumber number("123456789""123456789123456789");
	EXPECT_EQ(2, number.usedCells);
	EXPECT_EQ(123456789123456789, number.cell[0]);
	EXPECT_EQ(123456789, number.cell[1]);
}

TEST(isUpOverflow, usedCellsMoreThanMaxCellCounts)
{
	CBigNumber number;
	number.usedCells = MAX_SIZE + 10;

	EXPECT_TRUE(number.isUpOverflow());
}

TEST(isNotUpOverflow, usedCellslessThanMaxCellCounts)
{
	CBigNumber number;
	number.usedCells = MAX_SIZE - 10;

	EXPECT_FALSE(number.isUpOverflow());
}

TEST(isPalindrome, usedOneCell)
{
	CBigNumber number(12345678987654321);
	EXPECT_TRUE(number.isPalindrome());
}

TEST(isPalindrome, usedMoreThanOneCells)
{
	CBigNumber number("111112222233333444445555544444333332222211111");
	EXPECT_TRUE(number.isPalindrome());
}

TEST(operatorAsign, everyMemberWillCopy)
{
	CBigNumber origin = generateRadomNumber();
	CBigNumber number = origin;

	EXPECT_TRUE(isNumberEqual(origin, number));
}

TEST(numberNotEqual, usedCellsNotEqual)
{
	CBigNumber number1, number2;
	number1.usedCells = 5;
	number2.usedCells = 10;

	EXPECT_FALSE(number1 == number2);
}

TEST(numberNotEqual, cellNotEqual)
{
	CBigNumber number1(12345), number2(54321);
	EXPECT_FALSE(number1 == number2);
}

TEST(getReverseNumber, usedOneCells)
{
	CBigNumber number(123456789);
	CBigNumber expectNumber(987654321);

	EXPECT_TRUE(expectNumber == number.getReverseNumber());
}


TEST(getReverseNumber, usedMoreThanOneCells)
{
	CBigNumber number("1234567890""1234567890""1234567890""123456");
	CBigNumber expectNumber("654321""0987654321""0987654321""0987654321");

	EXPECT_TRUE(expectNumber == number.getReverseNumber());
}

TEST(operatorAdd, usedCellsIs1WillWork)
{
	CBigNumber number1(123), number2(456), sum(123+456);
	EXPECT_TRUE(sum == number1 + number2);
}

TEST(operatorAdd, usedCellsMoreThan1WillWork)
{
	CBigNumber number1("11111111111111111111");
	CBigNumber number2("22222222222222222222");
	CBigNumber     sum("33333333333333333333");

	EXPECT_TRUE(sum == number1 + number2);
}

TEST(toLongLong, usedCellsIs1WillGetAll)
{
	CBigNumber number(123456789);

	EXPECT_EQ(123456789, number.toLongLong());
}

TEST(toLongLong, usedCellsMoreThan1WillGetLast18Digits)
{
	CBigNumber number("1234123456789987654321");

	EXPECT_EQ(123456789987654321, number.toLongLong());
}

TEST(operatorLess, usedMoreCellsIsBigger)
{
	CBigNumber number1, number2;
	number1.usedCells = 5;
	number2.usedCells = 10;

	EXPECT_TRUE(number1 < number2);
}

TEST(operatorLess, usediSameCellsWillDecideByCell)
{
	CBigNumber number1(123), number2(456);
	EXPECT_TRUE(number1 < number2);
}
