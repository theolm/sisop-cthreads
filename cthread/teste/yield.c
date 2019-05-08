//
// Created by theolm on 5/7/19.
//

#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Esse teste cria 5 threads. Todas as threads fazem a mesma coisa,
 * printam 20 vezes uma letra no console, e a cada 2 prints dao um yield.
 *
 * A primeira e segunda Thread devem printar direto os 20 caracteres sem intercalacao, pois como
 * elas sao de prioridade alta mesmo dando yield elas voltam para a fila de alta prioridade,
 * Depois deve aparecer 20 C seguidos pois existe apenas uma thread de media prioridade.
 * E por ultimo deve aparecer 2 D e alterar execucao com a main e terminar o programa,
 * pois a ultima thread esta na fila de baixa prioridade com a main.
 *
 * As outras duas de baixa prioridade devem intercalar entre si e a main, terminando assim a execucao antes
 * de exibir todos os seus caracteres.
 */

void *funcA(void *arg) {
    int i;
    for (i = 1; i < 21; i++) {
        printf("A");
        if (i % 2 == 0) {
            cyield();
        }
    }
}

void *funcB(void *arg) {
    int i;
    for (i = 1; i < 21; i++) {
        printf("B");
        if (i % 2 == 0) {
            cyield();
        }
    }
}

void *funcC(void *arg) {
    int i;
    for (i = 1; i < 21; i++) {
        printf("C");
        if (i % 2 == 0) {
            cyield();
        }
    }
}

void *funcD(void *arg) {
    int i;
    for (i = 1; i < 21; i++) {
        printf("D");
        if (i % 2 == 0) {
            cyield();
        }
    }
}


int main(int argc, char *argv[]) {
    int a = ccreate(funcA, NULL, 0);
    int b = ccreate(funcB, NULL, 0);
    int c = ccreate(funcC, NULL, 1);
    int d = ccreate(funcD, NULL, 2);
    cyield();

    printf("\n-------------- FINAL DA MAIN -----------------\n");
    exit(0);
}