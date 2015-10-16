/*************************************************************************
    > File Name: Main_TestAll.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Thu 15 Oct 2015 05:05:22 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include <limits.h>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
