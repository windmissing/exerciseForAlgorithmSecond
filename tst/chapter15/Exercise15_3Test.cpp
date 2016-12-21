#include <iostream>  
using namespace std;  
#include "assert.h"

int DP(string x, string z);
void Print(int lx, int lz);

static void test1()
{
    string src = "algorithm";  
    string dst = "altruistic";  
    assert( 10 == DP(src, dst));    
}

void Exercise15_3Test()
{
	test1();
}