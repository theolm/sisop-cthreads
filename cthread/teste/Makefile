CC=gcc
LIB_DIR=../lib
INC_DIR=../include
BIN_DIR=../bin
SRC_DIR=./
CFLAGS = -Wall

all: names

names: names.c $(LIB_DIR)/libcthread.a
	$(CC) -o names names.c -L$(LIB_DIR) -lcthread -Wall

clean:
	rm -rf $(BIN_DIR)/*.o $(SRC_DIR)/*~ $(INC_DIR)/*~ *~
