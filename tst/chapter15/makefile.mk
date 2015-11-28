INCS += -I../include/chapter15 

SRC_DIR_15 = ../src/chapter15
TST_DIR_15 = chapter15

SRC_15 = $(SRC_DIR_15)/Exercise15_1.o 

TST_15 = $(TST_DIR_15)/Exercise15_1Test.o 

CHAPTER15 = $(SRC_15) $(TST_15)

