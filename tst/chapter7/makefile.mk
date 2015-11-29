INCS += -I../include/chapter7

SRC_DIR_7 = ../src/chapter7
TST_DIR_7 = chapter7

SRC_7 = $(SRC_DIR_7)/quickSort.o \
		$(SRC_DIR_7)/Exercise7_1_2.o \
		$(SRC_DIR_7)/Exercise7_6.o 


TST_7 = $(TST_DIR_7)/quickSortTest.o \
		$(TST_DIR_7)/Exercise7_1_2Test.o \
		$(TST_DIR_7)/Exercise7_6Test.o

CHAPTER7 = $(SRC_7) $(TST_7)

