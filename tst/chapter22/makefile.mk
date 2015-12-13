INCS += -I../include/chapter22

SRC_DIR_22 = ../src/chapter22
TST_DIR_22 = chapter22

SRC_22 = $(SRC_DIR_22)/Exercise22_3_6.o \
		 $(SRC_DIR_22)/Exercise22_4_2.o


TST_22 = $(TST_DIR_22)/Exercise22_3_6Test.o \
		 $(TST_DIR_22)/Exercise22_4_2Test.o

CHAPTER22 = $(SRC_22) $(TST_22)

