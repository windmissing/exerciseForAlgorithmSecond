#########################################################################
# File Name: coverage.sh
# Author: yinahe
# mail: yina.he@nokia.com
# Created Time: Thu 29 Oct 2015 07:57:13 PM CST
#########################################################################
#!/bin/bash

cd result

rm -rf result

cp ../*.gcda ./
cp ../*.gcno ./
cp ../*/*.gcda ./
cp ../*/*.gcno ./
cp ../../src/*/*.gcda ./
cp ../../src/*/*.gcno ./
gcov ../*.cpp ../*/*.cpp ../../src/*/*.cpp

lcov -c -o log.info -d . 
genhtml log.info -o result
firefox result/index.html
