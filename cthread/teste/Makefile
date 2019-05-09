CC=gcc
LIB_DIR=../lib
INC_DIR=../include
BIN_DIR=../bin
SRC_DIR=./
TARGETS= ccreate yield cjoin_simples csem csetprio csem_com_prio
CFLAGS = -Wall -m32

all: ccreate yield cjoin_simples csetprio csem_com_prio csem

ccreate: ccreate.c $(LIB_DIR)/libcthread.a
	$(CC) -g -o ccreate ccreate.c -L$(LIB_DIR) -lcthread $(CFLAGS)

csem: csem.c $(LIB_DIR)/libcthread.a
	$(CC) -g -o csem csem.c -L$(LIB_DIR) -lcthread $(CFLAGS)

yield: yield.c $(LIB_DIR)/libcthread.a
	$(CC) -g -o yield yield.c -L$(LIB_DIR) -lcthread $(CFLAGS)

cjoin_simples: cjoin_simples.c $(LIB_DIR)/libcthread.a
	$(CC) -g -o cjoin_simples cjoin_simples.c -L$(LIB_DIR) -lcthread $(CFLAGS)

csetprio: csetprio.c $(LIB_DIR)/libcthread.a
	$(CC) -g -o csetprio csetprio.c -L$(LIB_DIR) -lcthread $(CFLAGS)

csem_com_prio: csem_com_prio.c $(LIB_DIR)/libcthread.a
	$(CC) -g -o csem_com_prio csem_com_prio.c -L$(LIB_DIR) -lcthread $(CFLAGS)

clean:
	rm -rf $(TARGETS)
