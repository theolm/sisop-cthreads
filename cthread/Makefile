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
TARGETS_O= ./bin/library.o ./bin/fifo_manager.o ./bin/setup_lib.o ./bin/escalonador.o
CFLAGS = -Wall -m32

all: setup_lib fifo_manager escalonador library libcthread

libcthread: $(BIN_DIR)/support.o $(BIN_DIR)/library.o $(BIN_DIR)/fifo_manager.o $(BIN_DIR)/escalonador.o $(BIN_DIR)/setup_lib.o
	ar crs $(LIB_DIR)/libcthread.a $(BIN_DIR)/library.o $(BIN_DIR)/support.o $(BIN_DIR)/fifo_manager.o $(BIN_DIR)/escalonador.o $(BIN_DIR)/setup_lib.o

library: $(BIN_DIR)/support.o $(BIN_DIR)/fifo_manager.o $(BIN_DIR)/escalonador.o $(SRC_DIR)/lib.c $(SRC_DIR)/setup_lib.c
	$(CC) -c -g $(SRC_DIR)/lib.c -o $(BIN_DIR)/library.o $(CFLAGS)

fifo_manager: $(BIN_DIR)/support.o $(SRC_DIR)/fifo_manager.c $(SRC_DIR)/setup_lib.c
	$(CC) -c -g $(SRC_DIR)/fifo_manager.c -o $(BIN_DIR)/fifo_manager.o $(CFLAGS)

escalonador: $(BIN_DIR)/support.o $(SRC_DIR)/fifo_manager.c $(SRC_DIR)/escalonador.c $(SRC_DIR)/setup_lib.c
	$(CC) -c -g $(SRC_DIR)/escalonador.c -o $(BIN_DIR)/escalonador.o $(CFLAGS)

setup_lib: $(BIN_DIR)/support.o $(SRC_DIR)/fifo_manager.c $(SRC_DIR)/escalonador.c $(SRC_DIR)/setup_lib.c
	$(CC) -c -g $(SRC_DIR)/setup_lib.c -o $(BIN_DIR)/setup_lib.o $(CFLAGS)

clean:
	rm -rf $(TARGETS_O) $(LIB_DIR)/*
