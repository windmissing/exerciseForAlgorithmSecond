CXX = g++
CXXFLAGS = -g -L/opt/gtest/lib -lgtest -lgtest_main -lpthread -D__UT__
INCS = -I./ \
	   -I/opt/gtest/include \
       -I../include/chapter6 \
	   -I../src/chapter6 \
       -I../include/chapter7 \
       -I../include/chapter16 \
       -I../include/chapter22

SRC_6 = ../src/chapter6/Exercise6_5_8.o
TST_6 = chapter6/Exercise6_5_8Test.o \
		chapter6/HeapTest.o

CHAPTER6 = $(SRC_6) $(TST_6)

SRC_7 = ../src/chapter7/quickSort.o
TST_7 = chapter7/quickSortTest.o 

CHAPTER7 = $(SRC_7) $(TST_7)

SRC_16 = ../src/chapter16/Exercise16_2_6.o
TST_16 = chapter16/Exercise16_2_6Test.o

CHAPTER16 = $(SRC_16) $(TST_16)

SRC_22 = ../src/chapter22/Exercise22_3_6.o
TST_22 = chapter22/Exercise22_3_6Test.o

CHAPTER22 = $(SRC_22) $(TST_22)

OBJS = $(CHAPTER6) $(CHAPTER7) $(CHAPTER16) $(CHAPTER22)

testAll: $(OBJS)
		$(CXX) $(CXXFLAGS) -o testAll  Main_TestAll.cpp $(OBJS) $(INCS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)


clean:
		rm  testAll */*.o testAll.xml
