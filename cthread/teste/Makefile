CC=gcc
LIB_DIR=../lib
INC_DIR=../include
BIN_DIR=../bin
SRC_DIR=./
TARGETS= ccreate yield cjoin_simples ccreate_test csetprio
CFLAGS = -Wall -m32 -DDEBUG

all: ccreate yield cjoin_simples csetprio

ccreate: ccreate.c $(LIB_DIR)/libcthread.a
	$(CC) -g -o ccreate ccreate.c -L$(LIB_DIR) -lcthread $(CFLAGS)

ccreate_test: ccreate_test.c $(LIB_DIR)/libcthread.a
	$(CC) -g -o ccreate_test ccreate_test.c -L$(LIB_DIR) -lcthread $(CFLAGS)

yield: yield.c $(LIB_DIR)/libcthread.a
	$(CC) -g -o yield yield.c -L$(LIB_DIR) -lcthread $(CFLAGS)

cjoin_simples: cjoin_simples.c $(LIB_DIR)/libcthread.a
	$(CC) -g -o cjoin_simples cjoin_simples.c -L$(LIB_DIR) -lcthread $(CFLAGS)

csetprio: csetprio.c $(LIB_DIR)/libcthread.a
	$(CC) -g -o csetprio csetprio.c -L$(LIB_DIR) -lcthread $(CFLAGS)

clean:
	rm -rf $(TARGETS)
