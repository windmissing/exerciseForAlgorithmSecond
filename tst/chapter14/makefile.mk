INCS += -I../include/chapter14 

SRC_DIR_14 = ../src/chapter14
TST_DIR_14 = chapter14

SRC_14 = $(SRC_DIR_14)/section14_1.o 

TST_14 = $(TST_DIR_14)/section14_1Test.o 

CHAPTER14 = $(SRC_14) $(TST_14)

