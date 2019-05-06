#
# Makefile para programas exemplo
# 

CC=gcc
LIB_DIR=../lib
CFLAGS = -Wall -m32 -DDEBUG

all: exemplo mandel teste_vetor barbeiro filosofos prodcons series

exemplo: exemplo.c $(LIB_DIR)/libcthread.a
	$(CC) -o exemplo exemplo.c -L$(LIB_DIR) -lcthread $(CFLAGS)

teste_vetor: teste_vetor.c $(LIB_DIR)/libcthread.a
	$(CC) -o teste_vetor teste_vetor.c -L$(LIB_DIR) -lcthread $(CFLAGS)

mandel: mandel.c $(LIB_DIR)/libcthread.a
	$(CC) -o mandel mandel.c -L$(LIB_DIR) -lcthread -lm $(CFLAGS)

barbeiro: barbeiro.c $(LIB_DIR)/libcthread.a
	$(CC) -o barbeiro barbeiro.c -L$(LIB_DIR) -lcthread -lm $(CFLAGS)

filosofos: filosofos.c $(LIB_DIR)/libcthread.a
	$(CC) -o filosofos filosofos.c -L$(LIB_DIR) -lcthread -lm $(CFLAGS)

prodcons: prodcons.c $(LIB_DIR)/libcthread.a
	$(CC) -o prodcons prodcons.c -L$(LIB_DIR) -lcthread -lm $(CFLAGS)

series: series.c $(LIB_DIR)/libcthread.a
	$(CC) -o series series.c -L$(LIB_DIR) -lcthread -lm $(CFLAGS)
	
clean:
	rm -rf exemplo mandel teste_vetor barbeiro filosofos prodcons series *.o *~




