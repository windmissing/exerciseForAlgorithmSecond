//10.1????
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#define MAX_SIZE 1000
class CQueue
{
public:
	int tail;//?????
	int head;//?????
	int length;//????
	int *s;//??
	CQueue(int size = MAX_SIZE);
	~CQueue();
	bool isEmpty();
	void enqueue(int x);
	int dequeue();
};
