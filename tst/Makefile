CXX = g++
CXXFLAGS = -g -L/opt/gtest/lib -lgtest -lgtest_main -lpthread -D__UT__
INCS = -I./ -I../include/chapter6 -I/opt/gtest/include -I../src/chapter6

SRC_6 = ../src/chapter6/Exercise6_5_8.o
TST_6 = chapter6/Exercise6_5_8Test.o \
		chapter6/HeapTest.o

CHAPTER6 = $(SRC_6) $(TST_6)

OBJS = $(CHAPTER6)

testAll: $(OBJS)
		$(CXX) $(CXXFLAGS) -o testAll  Main_TestAll.cpp $(OBJS) $(INCS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)


clean:
		rm  testAll */*.o testAll.xml
