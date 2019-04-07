# sisop-cthreads

### MakeFile
Cada c file precisa ter uma regra adicional, tambem precisa adicionar o .o de cada regra ao TARGETS_O para que a regra clean limpe todos os arquivos gerados no bin (exeto pelo support.o).

A regra all deve conter todas as regras para que seja possivel gerar todos os .o e ligalos na lib estatica libcthread.a

Exemplo:
```sh
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
```


Flags de compilação
```sh
-Wall : Ativa warnings de compilação
-o : Escreve o build output em um arquivo
-O : seta nivel de otimização
-c : compila sem linking
```
