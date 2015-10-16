CXX = g++
CXXFLAGS = -g -L/opt/gtest/lib -lgtest -lgtest_main -lpthread
INCS = -I./ -I../../include -I/opt/gtest/include
OBJS = #../../src/Addition.o Addition_Test.o ../../src/Multiply.o Multiply_Test.o

testAll: $(OBJS)
		$(CXX) $(CXXFLAGS) $(INCS) -o testAll  Main_TestAll.cpp $(OBJS) $(INCS)

.cpp.o:
		$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:
		rm testAll *.o testAll.xml
