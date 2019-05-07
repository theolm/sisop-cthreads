//
// Created by theolm on 5/7/19.
//

#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Esse teste cria 4 threads. Todas as threads fazem a mesma coisa,
 * printam 20 vezes uma letra no console, e a cada 5 prints dao um yield.
 *
 * A primeira e segunda Thread devem printar direto os 20 caracteres sem intercalacao, pois como
 * elas sao de prioridade alta mesmo dando yield elas voltam para a fila de alta prioridade,
 * como a main e de baixa prioridade, ela so cria a proxima thread apos a primeira de alta prioridade terminar.
 *
 * As outras duas de baixa prioridade devem intercalar entre si e a main, terminando assim a execucao antes
 * de exibir todos os seus caracteres.
 */

void* funcA(void *arg) {
    int i;
    for(i = 0 ; i < 20 ; i++) {
        printf("A");
        if(i%5 == 0) {
            cyield();
        }
    }
}

void* funcB(void *arg) {
    int i;
    for(i = 0 ; i < 20 ; i++) {
        printf("B");
        if(i%5 == 0) {
            cyield();
        }
    }
}

void* funcC(void *arg) {
    int i;
    for(i = 0 ; i < 20 ; i++) {
        printf("C");
        if(i%5 == 0) {
            cyield();
        }
    }
}

void* funcD(void *arg) {
    int i;
    for(i = 0 ; i < 20 ; i++) {
        printf("D");
        if(i%5 == 0) {
            cyield();
        }
    }
}

int main(int argc, char *argv[]) {
    int a = ccreate(funcA, NULL, 0);
    int b = ccreate(funcB, NULL, 0);
    int c = ccreate(funcC, NULL, 2);
    int d = ccreate(funcD, NULL, 2);

    printf("\n-------------- FINAL DA MAIN -----------------\n");
    exit(0);
}