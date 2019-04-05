# sisop-cthreads

### MakeFile
Cada c file precisa ter uma regra adicional

Exemplo:
```sh
CC=gcc
LIB_DIR=./lib
INC_DIR=./include
BIN_DIR=./bin
SRC_DIR=./src
TARGET=./bin/teste
CFLAGS = -Wall

#adicionar no all todos os arquivos  a serem compilados e suas dependencias
all : teste

teste : teste.o
        gcc -o teste teste.o 

teste.o : teste.c
        gcc -c teste.c

clean :
        rm teste *.o

all: teste


# Comando basico
regra: dependencias compilador -o file_de_saida file_de_entrada 
```

Exemplo completo (sem variáveis de ambiente):
```sh
edit : main.o kbd.o command.o display.o \
       insert.o search.o files.o utils.o
        gcc -o edit main.o kbd.o command.o display.o \
                   insert.o search.o files.o utils.o

main.o : main.c defs.h
        gcc -c main.c
kbd.o : kbd.c defs.h command.h
        gcc -c kbd.c
command.o : command.c defs.h command.h
        gcc -c command.c
display.o : display.c defs.h buffer.h
        gcc -c display.c
insert.o : insert.c defs.h buffer.h
        gcc -c insert.c
search.o : search.c defs.h buffer.h
        gcc -c search.c
files.o : files.c defs.h buffer.h command.h
        gcc -c files.c
utils.o : utils.c defs.h
        gcc -c utils.c
clean :
        rm edit main.o kbd.o command.o display.o \
           insert.o search.o files.o utils.o
```

Flags de compilação
```sh
-Wall : Ativa warnings de compilação
-o : Escreve o build output em um arquivo
-O : seta nivel de otimização
-c : compila sem linking
```
