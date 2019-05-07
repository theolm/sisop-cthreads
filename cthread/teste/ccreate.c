//
// Created by theolm on 5/7/19.
//

#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Este teste cria 50 threads com tids diferentes, todas de alta prioridade,
 * Cada ccreate recebe a funcao que printa 10 A na tela,
 * ao retornar para main printa o tid da thread criada.
 */

void* func(void *arg) {
    int i;
    for(i = 0 ; i < 10 ; i++) {
        printf("A");
    }
    printf(" ");
}

int main(int argc, char *argv[]) {

    int j;
    for(j = 0; j < 50 ; j++) {
        int tid = ccreate(func, (void *)&j, 0);
        if(tid > 0) {
            printf("Thread com tid %d criada.\n", tid);
        } else {
            printf("Erro ao criar thread\n");
        }

    }

    printf("\n-------------- FINAL DA MAIN -----------------\n");
    exit(0);
}