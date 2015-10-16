#include "Young.h"
#include <iostream>
using namespace std;

enum directionType
{
	EAST = 0,
	SOUTH,
	WEST,
	NORTH
};

structCoordinate directionStep[4] = {structCoordinate(0, 1),
									structCoordinate(1, 0),
									structCoordinate(0, -1),
									structCoordinate(-1, 0)};

structCoordinate getNeibourCoordinate(directionType direction, structCoordinate currentPosition)
{
	currentPosition.h_index += directionStep[direction].h_index;
	currentPosition.w_index += directionStep[direction].w_index;
	return currentPosition;
}

Young::Young(int h, int w):height(h),width(w)
{
	if(height < 1 || height > SIZE_OF_YOUNG)
		height = SIZE_OF_YOUNG;
	if(width < 1 || width > SIZE_OF_YOUNG)
		width = SIZE_OF_YOUNG;
	for(int i = 1; i <= height; i++)
		for(int j = 1; j <= width; j++)
			Y[i][j] = INIT_DATA;
}

void Young::fillData(int *data, int size)
{
	int i, j, cnt = 0;
	for(i = 1; i <= height; i++)
	{
		if(cnt >= size)
			break;
		for(j = 1; j <= width; j++)
		{
			if(cnt >= size)
				break;
			Y[i][j] = data[cnt];
			cnt++;
		}
	}
	build();
}

int Young::extractMin()
{
	structCoordinate minDataPosition(1, 1);
	int minData = getDataFromPosition(minDataPosition);
	setDataInPosition(minDataPosition, INIT_DATA);
	YoungifyWithSon(minDataPosition);
	return minData;
}

bool Young::findKey(int key)
{
	structCoordinate currentPosition(height, 1);
	while(isInRange(currentPosition) == true)
	{
		if(getDataFromPosition(currentPosition) == key)
			return true;
		else if(getDataFromPosition(currentPosition) < key)
			currentPosition = getNeibourCoordinate(EAST, currentPosition);
		else if(getDataFromPosition(currentPosition) > key)
			currentPosition = getNeibourCoordinate(NORTH, currentPosition);
	}
	return false;
}

errorType Young::insert(int key)
{
	structCoordinate currentPosition(height, width);
	if(getDataFromPosition(currentPosition) < INIT_DATA)
		return SIZE_OVERFLOW;

	setDataInPosition(currentPosition, key);
	YoungifyWithParent(currentPosition);
	return SUCCESS;
}

errorType Young::decreaseKey(structCoordinate position, int key)
{
	if(false == isInRange(position))
		return OUT_OF_SIZE;
	if(getDataFromPosition(position) < key)
		return PARAM_ERROR;

	setDataInPosition(position, key);
	YoungifyWithParent(position);
	return SUCCESS;
}

int Young::getMinimum()
{
	return Y[1][1];
}

vector<int> Young::sort()
{
	vector<int> ret;
	while(getMinimum() != INIT_DATA)
	{
		ret.push_back(extractMin());
	}
	return ret;
}

errorType Young::deleteData(structCoordinate position)
{
	if(false == isInRange(position))
		return OUT_OF_SIZE;
	if(getDataFromPosition(position) == INIT_DATA)
		return PARAM_ERROR;

	setDataInPosition(position, INIT_DATA);
	YoungifyWithSon(position);
}

bool Young::isInRange(structCoordinate position)
{
	if(position.h_index < 1 || position.w_index < 1)
		return false;
	if(position.h_index > height || position.w_index > width)
		return false;
	return true;
}

void Young::build()
{
	int h, w, step;

	int maxHeight = height, minHeight = 1;
	int maxWidth = width, minWidth = 1;
	int maxStep = maxHeight + maxWidth;
	int minStep = minHeight + minWidth;

	for(step = maxStep; step >= minStep; step--)
	{
		for(h = minHeight; h <= maxHeight; h++)
		{
			w = step - h;
			if(w > maxWidth)continue;
			if(w < minWidth)break;
			YoungifyWithSon(structCoordinate(h, w));
		}
	}
}

void Young::YoungifyWithSon(structCoordinate position)
{
	int Min = getDataFromPosition(position);
	int i = position.h_index, j = position.w_index;
	structCoordinate minDataPosition = position;

	structCoordinate southNeibour = getNeibourCoordinate(SOUTH, position);
	if(isInRange(southNeibour) &&
		getDataFromPosition(southNeibour) < getDataFromPosition(minDataPosition))
	{
		minDataPosition = southNeibour;
	}

	structCoordinate eastNeibour = getNeibourCoordinate(EAST, position);
	if(isInRange(eastNeibour) &&
		getDataFromPosition(eastNeibour) < getDataFromPosition(minDataPosition))
	{
		minDataPosition = eastNeibour;
	}

	if(getDataFromPosition(position) != getDataFromPosition(minDataPosition))
	{
		swapDatainPosition(position, minDataPosition);
		YoungifyWithSon(minDataPosition);
	}
}

void Young::YoungifyWithParent(structCoordinate position)
{
	structCoordinate maxDataPosition = position;
	while(true)
	{
		structCoordinate northNeibour = getNeibourCoordinate(NORTH, position);
		if(isInRange(northNeibour) && 
			getDataFromPosition(maxDataPosition) < getDataFromPosition(northNeibour))
		{
			maxDataPosition = northNeibour;
		}

		structCoordinate westNeibour = getNeibourCoordinate(WEST, position);
		if(isInRange(westNeibour) && 
			getDataFromPosition(maxDataPosition) < getDataFromPosition(westNeibour))
		{
			maxDataPosition = westNeibour;
		}

		if(getDataFromPosition(maxDataPosition) == getDataFromPosition(position))
			break;
		swapDatainPosition(maxDataPosition, position);
		position = maxDataPosition;
	}
}

void Young::setDataInPosition(structCoordinate position, int data)
{
	Y[position.h_index][position.w_index] = data;
}

int Young::getDataFromPosition(structCoordinate position)
{
	return Y[position.h_index][position.w_index];
}

void Young::swapDatainPosition(structCoordinate c1, structCoordinate c2)
{
	int data1 = getDataFromPosition(c1);
	int data2 = getDataFromPosition(c2);
	setDataInPosition(c1, data2);
	setDataInPosition(c2, data1);
}

void Young::Print()
{
	for(int i = 1; i <= height; i++)
	{
		for(int j = 1; j <= width; j++)
			cout<<Y[i][j]<<' ';
		cout<<endl;
	}
}