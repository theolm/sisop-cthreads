#
# Makefile de EXEMPLO
#
# OBRIGATÓRIO ter uma regra "all" para geração da biblioteca e de uma
# regra "clean" para remover todos os objetos gerados.
#
# É NECESSARIO ADAPTAR ESSE ARQUIVO de makefile para suas necessidades.
#  1. Cuidado com a regra "clean" para não apagar o "support.o"
#
# OBSERVAR que as variáveis de ambiente consideram que o Makefile está no diretótio "cthread"
# 

CC=gcc
LIB_DIR=./lib
INC_DIR=./include
BIN_DIR=./bin
SRC_DIR=./src
TARGETS_O= ./bin/library.o
CFLAGS = -Wall

all: library libcthread

libcthread:
	ar crs $(LIB_DIR)/libcthread.a $(BIN_DIR)/library.o

library: $(BIN_DIR)/support.o $(SRC_DIR)/lib.c
	$(CC) -c $(SRC_DIR)/lib.c -o $(BIN_DIR)/library.o $(CFLAGS)

clean:
	rm -rf $(TARGETS_O) $(LIB_DIR)/*
