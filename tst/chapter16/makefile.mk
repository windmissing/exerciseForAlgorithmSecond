SRC_DIR_16 = ../src/chapter16
TST_DIR_16 = chapter16

SRC_16 = $(SRC_DIR_16)/Exercise16_2_6.o \
		 $(SRC_DIR_16)/chapter16.o

TST_16 = $(TST_DIR_16)/Exercise16_2_6Test.o \
		 $(TST_DIR_16)/chapter16Test.o

CHAPTER16 = $(SRC_16) $(TST_16)

