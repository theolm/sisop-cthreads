CC=gcc
LIB_DIR=../lib
INC_DIR=../include
BIN_DIR=../bin
SRC_DIR=./
TARGETS= names ccreate_test
CFLAGS = -Wall -m32 -DDEBUG

all: names ccreate_test

names: names.c $(LIB_DIR)/libcthread.a
	$(CC) -o names names.c -L$(LIB_DIR) -lcthread $(CFLAGS)

ccreate_test: ccreate_test.c $(LIB_DIR)/libcthread.a
	$(CC) -o ccreate_test ccreate_test.c -L$(LIB_DIR) -lcthread $(CFLAGS)

clean:
	rm -rf $(TARGETS)
