CXX = g++
CXXFLAGS = -g -L/opt/gtest/lib -lgtest -lgtest_main -lpthread -D__UT__ -fprofile-arcs  -ftest-coverage
INCS = -I./ \
	   -I/opt/gtest/include \
       -I../include/chapter6 \
	   -I../src/chapter6 \
       -I../include/chapter7 \
       -I../include/chapter10 \
       -I../include/chapter13 \
       -I../include/chapter16 \
       -I../include/chapter20 \
       -I../include/chapter22 \
       -I../include/chapter26

SRC_6 = ../src/chapter6/Exercise6_5_8.o
TST_6 = chapter6/Exercise6_5_8Test.o \
		chapter6/HeapTest.o

CHAPTER6 = $(SRC_6) $(TST_6)

SRC_7 = ../src/chapter7/quickSort.o
TST_7 = chapter7/quickSortTest.o 

CHAPTER7 = $(SRC_7) $(TST_7)

SRC_10 = ../src/chapter10/Exercise10_1_2.o
TST_10 = chapter10/Exercise10_1_2Test.o

CHAPTER10 = $(SRC_10) $(TST_10)

SRC_13 = ../src/chapter13/redBlackTree.o
TST_13 = chapter13/redBlackTreeTest.o

CHAPTER13 = $(SRC_13) $(TST_13)

SRC_16 = ../src/chapter16/Exercise16_2_6.o
TST_16 = chapter16/Exercise16_2_6Test.o

CHAPTER16 = $(SRC_16) $(TST_16)

SRC_20 = ../src/chapter20/FibHeap.o
TST_20 = chapter20/FibHeapTest.o

CHAPTER20 = $(SRC_20) $(TST_20)

SRC_22 = ../src/chapter22/Exercise22_3_6.o
TST_22 = chapter22/Exercise22_3_6Test.o

CHAPTER22 = $(SRC_22) $(TST_22)

SRC_26 = ../src/chapter26/MaxFlow.o
TST_26 = chapter26/MaxFlowTest.o

CHAPTER26 = $(SRC_26) $(TST_26)

OBJS = $(CHAPTER6) $(CHAPTER7) $(CHAPTER10) $(CHAPTER13) $(CHAPTER16) $(CHAPTER20) $(CHAPTER22) $(CHAPTER26)

testAll: $(OBJS)
		$(CXX) $(CXXFLAGS) -o testAll  Main_TestAll.cpp $(OBJS) $(INCS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)


clean:
		rm  testAll */*.o testAll.xml *.gcov ../src/*/*.o */*.gcno */*.gcda ../src/*/*.gcno ../src/*/*.gcda
